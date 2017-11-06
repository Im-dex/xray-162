////////////////////////////////////////////////////////////////////////////
//	Module 		: xr_graph_merge.h
//	Created 	: 25.01.2003
//  Modified 	: 25.01.2003
//	Author		: Dmitriy Iassenev
//	Description : Merging level graphs for off-line AI NPC computations
////////////////////////////////////////////////////////////////////////////

#pragma once

struct CLevelInfo {
    u8 m_id;
    std::string m_name;
    Fvector m_offset;
    std::string m_section;

    CLevelInfo(const u8 id, std::string name, const Fvector& offset, std::string section)
        : m_id(id), m_name(std::move(name)), m_offset(offset), m_section(std::move(section)) {}

    bool operator<(const CLevelInfo& info) const { return m_id < info.m_id; }
};

extern void xrMergeGraphs(LPCSTR game_graph_id, LPCSTR name, bool rebuild);