////////////////////////////////////////////////////////////////////////////
//	Module 		: editor_environment_sound_channels_source.hpp
//	Created 	: 04.01.2008
//  Modified 	: 04.01.2008
//	Author		: Dmitriy Iassenev
//	Description : editor environment sound channels source class
////////////////////////////////////////////////////////////////////////////

#ifndef EDITOR_WEATHER_SOUND_CHANNELS_SOURCE_HPP_INCLUDED
#define EDITOR_WEATHER_SOUND_CHANNELS_SOURCE_HPP_INCLUDED

#ifdef INGAME_EDITOR

#include "editor/property_holder.hpp"

namespace editor {

class property_holder_collection;

namespace environment {
namespace sound_channels {

class source : public editor::property_holder_holder {
public:
    source(std::string source);
    source(const source&) = delete;
    source& operator=(const source&) = delete;
    ~source();
    void fill(editor::property_holder_collection* collection);
    LPCSTR id() const { return m_source.c_str(); }

private:
    typedef editor::property_holder property_holder_type;

public:
    virtual property_holder_type* object();

private:
    property_holder_type* m_property_holder;
    std::string m_source;
}; // class source
} // namespace sound_channels
} // namespace environment
} // namespace editor

#endif // #ifdef INGAME_EDITOR

#endif // ifndef EDITOR_WEATHER_SOUND_CHANNELS_SOURCE_HPP_INCLUDED