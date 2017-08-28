#include "stdafx.h"
#pragma hdrstop

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) { return TRUE; }

extern xrSkin1W xrSkin1W_x86;
extern xrSkin2W xrSkin2W_x86;
extern xrSkin3W xrSkin3W_x86;
extern xrSkin4W xrSkin4W_x86;

#ifdef _M_IX86

extern xrSkin1W xrSkin1W_SSE;
extern xrSkin2W xrSkin2W_SSE;
extern xrSkin3W xrSkin3W_SSE;
extern xrSkin4W xrSkin4W_SSE;

#endif

extern xrSkin4W xrSkin4W_thread;

xrSkin4W* skin4W_func = NULL;

extern xrPLC_calc3 PLC_calc3_x86;
extern xrPLC_calc3 PLC_calc3_SSE;

extern "C" {
__declspec(dllexport) void __cdecl xrBind_PSGP(xrDispatchTable* T, processor_info* ID) {
    // generic
    T->skin1W = xrSkin1W_x86;
    T->skin2W = xrSkin2W_x86;
    T->skin3W = xrSkin3W_x86;
    T->skin4W = xrSkin4W_x86;
    skin4W_func = xrSkin4W_x86;
    T->PLC_calc3 = PLC_calc3_x86;

    // SSE
    if (ID->hasFeature(CpuFeature::Sse)) {
#ifdef _M_IX86
        T->skin1W = xrSkin1W_SSE;
        T->skin2W = xrSkin2W_SSE;
        T->skin3W = xrSkin3W_SSE;
        T->skin4W = xrSkin4W_SSE;
        skin4W_func = xrSkin4W_SSE;
#endif
        T->PLC_calc3 = PLC_calc3_SSE;
    }

    // Init helper threads
    ttapi_Init(ID);

    if (ttapi_GetWorkersCount() > 1) {
        // We can use threading
        T->skin4W = xrSkin4W_thread;
    }
}
};
