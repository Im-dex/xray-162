////////////////////////////////////////////////////////////////////////////
//	Module 		: editor_environment_weathers_weather.hpp
//	Created 	: 11.01.2008
//  Modified 	: 11.01.2008
//	Author		: Dmitriy Iassenev
//	Description : editor environment weathers weather class
////////////////////////////////////////////////////////////////////////////

#ifndef EDITOR_ENVIRONMENT_WEATHERS_WEATHER_HPP_INCLUDED
#define EDITOR_ENVIRONMENT_WEATHERS_WEATHER_HPP_INCLUDED

#ifdef INGAME_EDITOR

#include "editor/property_holder.hpp"
#include "property_collection_forward.hpp"

namespace editor {
namespace environment {

class manager;

namespace weathers {

class manager;
class time;

class weather : public editor::property_holder_holder {
public:
    typedef editor::property_holder property_holder_type;

public:
    weather(environment::manager* manager, std::string id);
    weather(const weather&) = delete;
    weather& operator=(const weather&) = delete;
    virtual ~weather();
    void load();
    void save();
    void fill(::editor::property_holder_collection* holder);
    const std::string& id() const { return m_id; }
    std::string unique_id(const std::string& current, const std::string& id) const;
    std::string generate_unique_id() const;
    virtual property_holder_type* object() { return m_property_holder; }
    bool save_time_frame(const std::string& frame_id, char* buffer, u32 const& buffer_size);
    bool paste_time_frame(const std::string& frame_id, char const* buffer, u32 const& buffer_size);
    void reload_time_frame(const std::string& frame_id);
    void reload();
    bool add_time_frame(char const* buffer, u32 const& buffer_size);

private:
    bool valid_id(const std::string& id_) const;
    bool try_hours(u32& hours, u32& minutes, u32& seconds, std::string& result) const;
    bool try_minutes(u32& hours, u32& minutes, u32& seconds, std::string& result) const;
    std::string try_all(u32& hours, u32& minutes, u32& seconds) const;
    std::string generate_unique_id(const std::string& start) const;

private:
    LPCSTR xr_stdcall id_getter() const;
    void xr_stdcall id_setter(LPCSTR value);

public:
    typedef std::vector<time*> container_type;

public:
    container_type const& times() const { return m_times; }

private:
    typedef property_collection<container_type, weather> collection_type;

private:
    std::string m_id;
    container_type m_times;
    collection_type* m_collection;
    property_holder_type* m_property_holder;

public:
    environment::manager& m_manager;
}; // class weather
} // namespace weathers
} // namespace environment
} // namespace editor

#endif // #ifdef INGAME_EDITOR

#endif // ifndef EDITOR_ENVIRONMENT_WEATHERS_WEATHER_HPP_INCLUDED