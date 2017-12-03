////////////////////////////////////////////////////////////////////////////
//	Module 		: editor_environment_suns_sun.hpp
//	Created 	: 13.12.2007
//  Modified 	: 04.01.2008
//	Author		: Dmitriy Iassenev
//	Description : editor environment suns sun class
////////////////////////////////////////////////////////////////////////////

#ifndef EDITOR_WEATHER_SUNS_SUN_HPP_INCLUDED
#define EDITOR_WEATHER_SUNS_SUN_HPP_INCLUDED

#ifdef INGAME_EDITOR

#include "editor/property_holder.hpp"
#include "xr_efflensflare.h"

namespace editor {

class property_holder;
class property_holder_collection;

namespace environment {
namespace suns {

class flare;
class manager;

class sun : public CLensFlare, public editor::property_holder_holder {
public:
    sun(manager const& manager, std::string section);
    sun(const sun&) = delete;
    sun& operator=(const sun&) = delete;
    ~sun();
    void load(CInifile& config);
    void save(CInifile& config);
    void fill(editor::property_holder_collection* collection);

private:
    LPCSTR xr_stdcall id_getter() const;
    void xr_stdcall id_setter(LPCSTR value);

public:
    const std::string& id() const { return m_id; }
    virtual property_holder* object();

private:
    std::string m_id;
    std::string m_shader;
    std::string m_texture;
    manager const& m_manager;
    editor::property_holder* m_property_holder;
    float m_radius;
    bool m_use;
    bool m_ignore_color;
}; // class sun

} // namespace suns
} // namespace environment
} // namespace editor

#endif // #ifdef INGAME_EDITOR

#endif // ifndef EDITOR_WEATHER_SUNS_SUN_HPP_INCLUDED