#include "stdafx.h"
#include "eventapi.h"
#include "xr_ioconsole.h"

extern void msRead();
extern void msCreate(LPCSTR name);

//---------------------------------------------------------------------
class ENGINE_API CEvent {
    friend class CEventAPI;

private:
    char* Name;
    xr_vector<IEventReceiver*> Handlers;
    u32 dwRefCount;

public:
    CEvent(const char* S);
    ~CEvent();

    LPCSTR GetFull() { return Name; }
    u32 RefCount() { return dwRefCount; }

    BOOL Equal(CEvent& E) { return stricmp(Name, E.Name) == 0; }

    void Attach(IEventReceiver* H) {
        if (std::find(Handlers.begin(), Handlers.end(), H) == Handlers.end())
            Handlers.push_back(H);
    }
    void Detach(IEventReceiver* H) {
        xr_vector<IEventReceiver*>::iterator I = std::find(Handlers.begin(), Handlers.end(), H);
        if (I != Handlers.end())
            Handlers.erase(I);
    }
    void Signal(u64 P1, u64 P2) {
        for (u32 I = 0; I < Handlers.size(); I++)
            Handlers[I]->OnEvent(this, P1, P2);
    }
};
//-----------------------------------------
CEvent::CEvent(const char* S) {
    Name = xr_strdup(S);
    _strupr(Name);
    dwRefCount = 1;
}
CEvent::~CEvent() { xr_free(Name); }

//-----------------------------------------
IC bool ev_sort(CEvent* E1, CEvent* E2) { return E1->GetFull() < E2->GetFull(); }

void CEventAPI::Dump() {
    std::sort(Events.begin(), Events.end(), ev_sort);
    for (u32 i = 0; i < Events.size(); i++)
        Msg("* [%d] %s", Events[i]->RefCount(), Events[i]->GetFull());
}

EVENT CEventAPI::Create(const char* N) {
    std::lock_guard<decltype(CS)> lock(CS);
    CEvent E(N);
    for (xr_vector<CEvent*>::iterator I = Events.begin(); I != Events.end(); I++) {
        if ((*I)->Equal(E)) {
            EVENT F = *I;
            F->dwRefCount++;
            return F;
        }
    }

    EVENT X = xr_new<CEvent>(N);
    Events.push_back(X);
    return X;
}
void CEventAPI::Destroy(EVENT& E) {
    std::lock_guard<decltype(CS)> lock(CS);
    E->dwRefCount--;
    if (E->dwRefCount == 0) {
        xr_vector<CEvent*>::iterator I = std::find(Events.begin(), Events.end(), E);
        R_ASSERT(I != Events.end());
        Events.erase(I);
        xr_delete(E);
    }
}

EVENT CEventAPI::Handler_Attach(const char* N, IEventReceiver* H) {
    std::lock_guard<decltype(CS)> lock(CS);
    EVENT E = Create(N);
    E->Attach(H);
    return E;
}

void CEventAPI::Handler_Detach(EVENT& E, IEventReceiver* H) {
    if (0 == E)
        return;
    std::lock_guard<decltype(CS)> lock(CS);
    E->Detach(H);
    Destroy(E);
}
void CEventAPI::Signal(EVENT E, u64 P1, u64 P2) {
    std::lock_guard<decltype(CS)> lock(CS);
    E->Signal(P1, P2);
}
void CEventAPI::Signal(LPCSTR N, u64 P1, u64 P2) {
    std::lock_guard<decltype(CS)> lock(CS);
    EVENT E = Create(N);
    Signal(E, P1, P2);
    Destroy(E);
}
void CEventAPI::Defer(EVENT E, u64 P1, u64 P2) {
    std::lock_guard<decltype(CS)> lock(CS);
    E->dwRefCount++;
    Events_Deferred.push_back(Deferred());
    Events_Deferred.back().E = E;
    Events_Deferred.back().P1 = P1;
    Events_Deferred.back().P2 = P2;
}
void CEventAPI::Defer(LPCSTR N, u64 P1, u64 P2) {
    std::lock_guard<decltype(CS)> lock(CS);
    EVENT E = Create(N);
    Defer(E, P1, P2);
    Destroy(E);
}

#ifdef DEBUG
void msParse(LPCSTR c) {
    if (0 == _stricmp(c, "exit")) {
        Console->Execute("quit");
    }
    if (0 == _stricmp(c, "quit")) {
        TerminateProcess(GetCurrentProcess(), 0);
        Console->Execute("quit");
    }
}
#endif

void CEventAPI::OnFrame() {
#ifdef DEBUG
    msRead();
#endif
    std::lock_guard<decltype(CS)> lock(CS);
    if (Events_Deferred.empty())
        return;
    for (u32 I = 0; I < Events_Deferred.size(); I++) {
        Deferred& DEF = Events_Deferred[I];
        Signal(DEF.E, DEF.P1, DEF.P2);
        Destroy(Events_Deferred[I].E);
    }
    Events_Deferred.clear();
}

BOOL CEventAPI::Peek(LPCSTR EName) {
    std::lock_guard<decltype(CS)> lock(CS);
    if (Events_Deferred.empty())
        return FALSE;
    for (u32 I = 0; I < Events_Deferred.size(); I++) {
        Deferred& DEF = Events_Deferred[I];
        if (_stricmp(DEF.E->GetFull(), EName) == 0)
            return TRUE;
    }

    return FALSE;
}

void CEventAPI::_destroy() {
    Dump();
    if (Events.empty())
        Events.clear();
    if (Events_Deferred.empty())
        Events_Deferred.clear();
}
