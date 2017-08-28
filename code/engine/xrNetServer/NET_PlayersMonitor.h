#ifndef NET_PLAYERS_MONITOR
#define NET_PLAYERS_MONITOR

#include "net_shared.h"
#include "NET_Common.h"
#include "../xrCore/fastdelegate.h"

class IClient;

class PlayersMonitor {
private:
    typedef xr_vector<IClient*> players_collection_t;
    std::recursive_mutex csPlayers;
    players_collection_t net_Players;
    players_collection_t net_Players_disconnected;
    bool now_iterating_in_net_players;
    bool now_iterating_in_net_players_disconn;
#ifdef DEBUG
    DWORD iterator_thread_id;
#endif
public:
    PlayersMonitor() {
        now_iterating_in_net_players = false;
        now_iterating_in_net_players_disconn = false;
#ifdef DEBUG
        iterator_thread_id = 0;
#endif
    }
#ifdef DEBUG
    bool IsCurrentThreadIteratingOnClients() const {
        if (now_iterating_in_net_players || now_iterating_in_net_players_disconn) {
            if (iterator_thread_id == GetCurrentThreadId()) {
                return true;
            }
        }
        return false;
    }
#endif
    template <typename ActionFunctor>
    void ForEachClientDo(ActionFunctor& functor) {
        // Msg("-S- Entering to csPlayers [%d]", GetCurrentThreadId());
        csPlayers.lock();
        // LogStackTrace(
        //	make_string("-S- Entered to csPlayers [%d]", GetCurrentThreadId()).c_str());
        now_iterating_in_net_players = true;
#ifdef DEBUG
        iterator_thread_id = GetCurrentThreadId();
#endif
        for (players_collection_t::iterator i = net_Players.begin(), ie = net_Players.end();
             i != ie; ++i) {
            VERIFY2(*i != NULL, "IClient ptr is NULL");
            functor(*i);
        }
        now_iterating_in_net_players = false;
        // Msg("-S- Leaving from csPlayers [%d]", GetCurrentThreadId());
        csPlayers.unlock();
    }
    void ForEachClientDo(fastdelegate::FastDelegate1<IClient*, void>& fast_delegate) {
        // Msg("-S- Entering to csPlayers [%d]", GetCurrentThreadId());
        std::lock_guard<decltype(csPlayers)> lock(csPlayers);
        // LogStackTrace(
        //	make_string("-S- Entered to csPlayers [%d]", GetCurrentThreadId()).c_str());
        now_iterating_in_net_players = true;
#ifdef DEBUG
        iterator_thread_id = GetCurrentThreadId();
#endif
        for (players_collection_t::iterator i = net_Players.begin(), ie = net_Players.end();
             i != ie; ++i) {
            VERIFY2(*i != NULL, "IClient ptr is NULL");
            fast_delegate(*i);
        }
        now_iterating_in_net_players = false;
        // Msg("-S- Leaving from csPlayers [%d]", GetCurrentThreadId());
    }
    template <typename SearchPredicate, typename ActionFunctor>
    u32 ForFoundClientsDo(SearchPredicate const& predicate, ActionFunctor& functor) {
        u32 ret_count = 0;
        // Msg("-S- Entering to csPlayers [%d]", GetCurrentThreadId());
        csPlayers.lock();
        // LogStackTrace(
        //	make_string("-S- Entered to csPlayers [%d]", GetCurrentThreadId()).c_str());
        now_iterating_in_net_players = true;
#ifdef DEBUG
        iterator_thread_id = GetCurrentThreadId();
#endif
        players_collection_t::iterator players_endi = net_Players.end();
        players_collection_t::iterator temp_iter =
            std::find_if(net_Players.begin(), players_endi, predicate);

        while (temp_iter != players_endi) {
            VERIFY2(*temp_iter != NULL, "IClient ptr is NULL");
            functor(*temp_iter);
            temp_iter = std::find_if(++temp_iter, players_endi, predicate);
        }
        now_iterating_in_net_players = false;
        // Msg("-S- Leaving from csPlayers [%d]", GetCurrentThreadId());
        csPlayers.unlock();
        return ret_count;
    }

    template <typename SearchPredicate>
    IClient* FindAndEraseClient(SearchPredicate const& predicate) {
        // Msg("-S- Entering to csPlayers [%d]", GetCurrentThreadId());
        std::lock_guard<decltype(csPlayers)> lock(csPlayers);
        // LogStackTrace(
        //	make_string("-S- Entered to csPlayers [%d]", GetCurrentThreadId()).c_str());
        VERIFY(!now_iterating_in_net_players);
        now_iterating_in_net_players = true;
#ifdef DEBUG
        iterator_thread_id = GetCurrentThreadId();
#endif
        players_collection_t::iterator client_iter =
            std::find_if(net_Players.begin(), net_Players.end(), predicate);
        IClient* ret_client = NULL;
        if (client_iter != net_Players.end()) {
            ret_client = *client_iter;
            net_Players.erase(client_iter);
        }
        now_iterating_in_net_players = false;
        // Msg("-S- Leaving from csPlayers [%d]", GetCurrentThreadId());
        return ret_client;
    }
    template <typename SearchPredicate>
    IClient* GetFoundClient(SearchPredicate const& predicate) {
        // Msg("-S- Entering to csPlayers [%d]", GetCurrentThreadId());
        csPlayers.lock();
        // LogStackTrace(
        //	make_string("-S- Entered to csPlayers [%d]", GetCurrentThreadId()).c_str());
        players_collection_t::iterator client_iter =
            std::find_if(net_Players.begin(), net_Players.end(), predicate);
        IClient* ret_client = NULL;
        if (client_iter != net_Players.end()) {
            ret_client = *client_iter;
        }
        // Msg("-S- Leaving from csPlayers [%d]", GetCurrentThreadId());
        csPlayers.unlock();
        return ret_client;
    }
    void AddNewClient(IClient* new_client) {
        // Msg("-S- Entering to csPlayers [%d]", GetCurrentThreadId());
        std::lock_guard<decltype(csPlayers)> lock(csPlayers);
        // LogStackTrace(
        //	make_string("-S- Entered to csPlayers [%d]", GetCurrentThreadId()).c_str());
        VERIFY(!now_iterating_in_net_players);
        net_Players.push_back(new_client);
        // Msg("-S- Leaving from csPlayers [%d]", GetCurrentThreadId());
    }

    /*template<typename ActionFunctor>
    void		ForEachDisconnectedClientDo		(ActionFunctor & functor)
    {
            //Msg("-S- Entering to csPlayers [%d]", GetCurrentThreadId());
            csPlayers.Enter();
            //LogStackTrace(
            //	make_string("-S- Entered to csPlayers [%d]", GetCurrentThreadId()).c_str());
            now_iterating_in_net_players_disconn	=	true;
#ifdef DEBUG
            iterator_thread_id = GetCurrentThreadId();
#endif
            std::for_each(net_Players_disconnected.begin(), net_Players_disconnected.end(),
functor); now_iterating_in_net_players_disconn	=	false;
            //Msg("-S- Leaving from csPlayers [%d]", GetCurrentThreadId());
            csPlayers.Leave();
    }
    template<typename SearchPredicate>
    IClient*	FindAndEraseDisconnectedClient	(SearchPredicate const & predicate)
    {
            //Msg("-S- Entering to csPlayers [%d]", GetCurrentThreadId());
            csPlayers.Enter();
            //LogStackTrace(
            //	make_string("-S- Entered to csPlayers [%d]", GetCurrentThreadId()).c_str());
            VERIFY(!now_iterating_in_net_players_disconn);
            now_iterating_in_net_players_disconn	=	true;
#ifdef DEBUG
            iterator_thread_id = GetCurrentThreadId();
#endif
            players_collection_t::iterator client_iter = std::find_if(
                    net_Players_disconnected.begin(),
                    net_Players_disconnected.end(),
                    predicate);
            IClient* ret_client = NULL;
            if (client_iter != net_Players_disconnected.end())
            {
                    ret_client = *client_iter;
                    net_Players_disconnected.erase(client_iter);
            }
            now_iterating_in_net_players_disconn	=	false;
            //Msg("-S- Leaving from csPlayers [%d]", GetCurrentThreadId());
            csPlayers.Leave();
            return ret_client;
    }
    template<typename SearchPredicate>
    IClient*	GetFoundDisconnectedClient		(SearchPredicate const & predicate)
    {
            //Msg("-S- Entering to csPlayers [%d]", GetCurrentThreadId());
            csPlayers.Enter();
            //LogStackTrace(
            //	make_string("-S- Entered to csPlayers [%d]", GetCurrentThreadId()).c_str());
            now_iterating_in_net_players_disconn	=	true;
#ifdef DEBUG
            iterator_thread_id = GetCurrentThreadId();
#endif
            players_collection_t::iterator client_iter = std::find_if(
                    net_Players_disconnected.begin(),
                    net_Players_disconnected.end(),
                    predicate);
            now_iterating_in_net_players_disconn	=	false;
            IClient* ret_client = NULL;
            if (client_iter != net_Players_disconnected.end())
                    ret_client = *client_iter;
            //Msg("-S- Leaving from csPlayers [%d]", GetCurrentThreadId());
            csPlayers.Leave();
            return ret_client;
    }
    void		AddNewDisconnectedClient		(IClient* new_client)
    {
            //Msg("-S- Entering to csPlayers [%d]", GetCurrentThreadId());
            csPlayers.Enter();
            //LogStackTrace(
            //	make_string("-S- Entered to csPlayers [%d]", GetCurrentThreadId()).c_str());
            VERIFY(!now_iterating_in_net_players_disconn);
            net_Players_disconnected.push_back(new_client);
            //Msg("-S- Leaving from csPlayers [%d]", GetCurrentThreadId());
            csPlayers.Leave();
    }*/

    u32 ClientsCount() {
        // Msg("-S- Entering to csPlayers [%d]", GetCurrentThreadId());
        std::lock_guard<decltype(csPlayers)> lock(csPlayers);
        // LogStackTrace(
        //	make_string("-S- Entered to csPlayers [%d]", GetCurrentThreadId()).c_str());
        u32 ret_count = net_Players.size();
        // Msg("-S- Leaving from csPlayers [%d]", GetCurrentThreadId());
        return ret_count;
    }
    // WARNING! for iteration in vector use ForEachClientDo !
    // This function can be used carefully (single call)
    /*IClient*	GetClientByIndex				(u32 index)
    {
            csPlayers.Enter();
            IClient* ret_client = net_Players[index];
            csPlayers.Leave();
            return ret_client;
    }*/
}; // class PlayersMonitor

#endif //#ifndef NET_PLAYERS_MONITOR