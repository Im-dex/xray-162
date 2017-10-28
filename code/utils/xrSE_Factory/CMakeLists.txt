cmake_minimum_required(VERSION 3.8)

project(xrSE_Factory)

set(COMMON_OBJECTFACTORY ../../engine/xrServerEntities/clsid_game.h
                         ../../engine/xrServerEntities/object_factory.h
                         ../../engine/xrServerEntities/object_factory_impl.h
                         ../../engine/xrServerEntities/object_factory_inline.h
                         ../../engine/xrServerEntities/object_factory_space.h
                         ../../engine/xrServerEntities/object_factory.cpp
                         ../../engine/xrServerEntities/object_factory_register.cpp
                         ../../engine/xrServerEntities/object_factory_script.cpp)

set(SERVERSTUFF_COMMON_ALIFESTUFF_MONSTER_BRAIN ../../engine/xrServerEntities/alife_monster_brain.h
                                                ../../engine/xrServerEntities/alife_monster_brain_inline.h
                                                ../../engine/xrServerEntities/alife_monster_brain.cpp)

set(SERVERSTUFF_SERVERENTITIES_OBJECTS ../../engine/xrServerEntities/xrServer_Object_Base.h
                                       ../../engine/xrServerEntities/xrServer_Objects.h
                                       ../../engine/xrServerEntities/xrServer_Object_Base.cpp
                                       ../../engine/xrServerEntities/xrServer_Objects.cpp
                                       ../../engine/xrServerEntities/xrServer_Objects_script.cpp
                                       ../../engine/xrServerEntities/xrServer_Objects_script2.cpp)

set(SERVERSTUFF_SERVERENTITIES_OBJECTS_ALIFE ../../engine/xrServerEntities/xrServer_Objects_ALife.h
                                             ../../engine/xrServerEntities/xrServer_Objects_ALife.cpp
                                             ../../engine/xrServerEntities/xrServer_Objects_ALife_script.cpp
                                             ../../engine/xrServerEntities/xrServer_Objects_ALife_script2.cpp
                                             ../../engine/xrServerEntities/xrServer_Objects_ALife_script3.cpp)

set(SERVERSTUFF_SERVERENTITIES_SCRIPTS_SCRIPT_VALUE_WRAPPER script_value_wrapper.h
                                                            script_value_wrapper_inline.h)

set(SERVERSTUFF_COMMON_SERVERSTUFF ../../engine/xrServerEntities/character_info.h
                                   ../../engine/xrServerEntities/character_info_defs.h
                                   ../../engine/xrServerEntities/shared_data.h
                                   ../../engine/xrServerEntities/specific_character.h
                                   ../../engine/xrServerEntities/xml_str_id_loader.h
                                   ../../engine/xrServerEntities/xrMessages.h
                                   ../../engine/xrServerEntities/xrServer_Space.h
                                   xrUIXmlParser.h
                                   ../../engine/xrServerEntities/character_info.cpp
                                   ../../engine/xrServerEntities/specific_character.cpp
                                   xrUIXmlParser.cpp)

set(COMMON_ASSOCIATIVE_VECTOR ../../engine/xrServerEntities/associative_vector.h
                              ../../engine/xrServerEntities/associative_vector_compare_predicate.h
                              ../../engine/xrServerEntities/associative_vector_compare_predicate_inline.h
                              ../../engine/xrServerEntities/associative_vector_inline.h)

set(SERVERSTUFF_SERVERENTITIES_SCRIPTS_SCRIPT_VALUE script_value.h
                                                    script_value_inline.h)

set(SERVERSTUFF_COMMON_PHYSICSSTUFF ../../engine/xrServerEntities/PHNetState.h
                                    ../../engine/xrServerEntities/PHSynchronize.h
                                    ../../engine/xrServerEntities/PHNetState.cpp
                                    ../../engine/xrServerEntities/PHSynchronize.cpp)

set(SERVERSTUFF_COMMON_ALIFESTUFF_HUMAN_BRAIN ../../engine/xrServerEntities/alife_human_brain.h
                                              ../../engine/xrServerEntities/alife_human_brain_inline.h
                                              ../../engine/xrServerEntities/alife_human_brain.cpp)

set(SCRIPTS_SCRIPTDEBUGGER ../../engine/xrServerEntities/mslotutils.h
                           ../../engine/xrServerEntities/script_callStack.h
                           ../../engine/xrServerEntities/script_debugger.h
                           ../../engine/xrServerEntities/script_debugger_messages.h
                           ../../engine/xrServerEntities/script_debugger_threads.h
                           ../../engine/xrServerEntities/script_lua_helper.h
                           script_debugger_utils.h
                           script_file.h
                           ../../engine/xrServerEntities/script_callStack.cpp
                           ../../engine/xrServerEntities/script_debugger.cpp
                           ../../engine/xrServerEntities/script_debugger_threads.cpp
                           ../../engine/xrServerEntities/script_lua_helper.cpp
                           script_debugger_utils.cpp
                           script_file.cpp)

set(SCRIPTS ../../engine/xrServerEntities/script_export_macroses.h
            ../../engine/xrServerEntities/script_export_space.h
            ../../engine/xrServerEntities/script_space_forward.h
            script_space.h)

set(SERVERSTUFF_COMMON_NETWORKSTUFF NET_Compressor.h)

set(SCRIPTS_SCRIPTCLASSES_SCRIPTFMATRIX ../../engine/xrServerEntities/script_fmatrix.h
                                        ../../engine/xrServerEntities/script_fmatrix_script.cpp)

set(SCRIPTS_SCRIPTCLASSES_SCRIPTNETPACKET ../../engine/xrServerEntities/script_net_packet.h
                                          ../../engine/xrServerEntities/script_net_packet_script.cpp)

set(SCRIPTS_SCRIPTCLASSES_SCRIPTINIFILE ../../engine/xrServerEntities/script_ini_file.h
                                        ../../engine/xrServerEntities/script_ini_file_inline.h
                                        ../../engine/xrServerEntities/script_ini_file.cpp
                                        ../../engine/xrServerEntities/script_ini_file_script.cpp)

set(SERVERSTUFF_COMMON_ALIFESTUFF ../../engine/xrServerEntities/alife_space.h
                                  ../../engine/xrServerEntities/game_graph_space.h
                                  ../../engine/xrServerEntities/alife_space.cpp)

set(COMMON_OBJECTFACTORY_OBJECT_ITEM_CLIENT_SERVER ../../engine/xrServerEntities/object_item_client_server.h
                                                   ../../engine/xrServerEntities/object_item_client_server_inline.h)

set(COMMON_OBJECTFACTORY_OBJECT_ITEM_SINGLE ../../engine/xrServerEntities/object_item_single.h
                                            ../../engine/xrServerEntities/object_item_single_inline.h)

set(SCRIPTS_LUA_STUDIO ../../engine/xrServerEntities/lua_studio.h
                       ../../engine/xrServerEntities/lua_studio.cpp)

set(SCRIPTS_SCRIPTCLASSES_SCRIPTINIFILE_SCRIPTTOKENLIST ../../engine/xrServerEntities/script_token_list.h
                                                        ../../engine/xrServerEntities/script_token_list_inline.h
                                                        ../../engine/xrServerEntities/script_token_list.cpp
                                                        ../../engine/xrServerEntities/script_token_list_script.cpp)

set(SERVERSTUFF_COMMON_GAMESTUFF ../../engine/xrServerEntities/game_base_space.h
                                 ../../engine/xrServerEntities/inventory_space.h
                                 bone.h)

set(SERVERSTUFF_SERVERENTITIES_EDITOR_PROPERTIES ../../engine/xrServerEntities/ItemListTypes.h
                                                 ../../engine/xrServerEntities/PropertiesListTypes.h
                                                 ../../engine/xrServerEntities/WaveForm.h
                                                 ../../engine/xrServerEntities/xrEProps.h)

set(COMMON_OBJECTFACTORY_OBJECT_ITEM_SCRIPT ../../engine/xrServerEntities/object_item_script.h
                                            ../../engine/xrServerEntities/object_item_script.cpp)

set(SCRIPTS_SCRIPTCLASSES_SCRIPTREADER ../../engine/xrServerEntities/script_reader.h
                                       ../../engine/xrServerEntities/script_reader_script.cpp)

set(SERVERSTUFF_SERVERENTITIES ../../engine/xrServerEntities/InfoPortionDefs.h
                               ../../engine/xrServerEntities/ShapeData.h
                               ../../engine/xrServerEntities/xrServer_Objects_Abstract.h
                               ../../engine/xrServerEntities/xrServer_Objects_ALife_All.h
                               ../../engine/xrServerEntities/xrServer_script_macroses.h
                               ../../engine/xrServerEntities/gametype_chooser.h
                               ../../engine/xrServerEntities/xrServer_Objects_Abstract.cpp
                               ../../engine/xrServerEntities/gametype_chooser.cpp)

set(SCRIPTS_SCRIPTCLASSES_SCRIPTINIFILE_SCRIPTRTOKENLIST ../../engine/xrServerEntities/script_rtoken_list.h
                                                         ../../engine/xrServerEntities/script_rtoken_list_inline.h
                                                         ../../engine/xrServerEntities/script_rtoken_list_script.cpp)

set(SERVERSTUFF_COMMON_ALIFESTUFF_ARTEFACT_ORDER alife_artefact_order.h
                                                 alife_artefact_order.cpp)

set(SCRIPTS_SCRIPTTHREAD ../../engine/xrServerEntities/script_thread.h
                         ../../engine/xrServerEntities/script_thread_inline.h
                         ../../engine/xrServerEntities/script_thread.cpp)

set(SERVERSTUFF_SERVERENTITIES_MOVEMENT_MANAGER_HOLDER ../../engine/xrServerEntities/alife_movement_manager_holder.h)

set(SERVERSTUFF_SERVERENTITIES_OBJECTS_ALIFE_MONSTERS ../../engine/xrServerEntities/xrServer_Objects_ALife_Monsters.h
                                                      ../../engine/xrServerEntities/xrServer_Objects_ALife_Monsters.cpp
                                                      ../../engine/xrServerEntities/xrServer_Objects_ALife_Monsters_script.cpp
                                                      ../../engine/xrServerEntities/xrServer_Objects_ALife_Monsters_script2.cpp
                                                      ../../engine/xrServerEntities/xrserver_objects_alife_monsters_script3.cpp
                                                      ../../engine/xrServerEntities/xrServer_Objects_ALife_Monsters_script4.cpp)

set(SERVERSTUFF_SERVERENTITIES_OBJECTS_ALIFE_ITEMS ../../engine/xrServerEntities/xrServer_Objects_ALife_Items.h
                                                   ../../engine/xrServerEntities/xrServer_Objects_ALife_Items.cpp
                                                   ../../engine/xrServerEntities/xrServer_Objects_ALife_Items_script.cpp
                                                   ../../engine/xrServerEntities/xrServer_Objects_ALife_Items_script2.cpp
                                                   ../../engine/xrServerEntities/xrServer_Objects_ALife_Items_script3.cpp)

set(SCRIPTS_SCRIPTENGINE ../../engine/xrServerEntities/script_engine.h
                         ../../engine/xrServerEntities/script_engine_export.h
                         ../../engine/xrServerEntities/script_engine_inline.h
                         ../../engine/xrServerEntities/script_engine_space.h
                         ../../engine/xrServerEntities/script_engine.cpp
                         ../../engine/xrServerEntities/script_engine_export.cpp
                         ../../engine/xrServerEntities/script_engine_script.cpp)

set(SCRIPTS_SCRIPTPROCESS ../../engine/xrServerEntities/script_process.h
                          ../../engine/xrServerEntities/script_process_inline.h
                          ../../engine/xrServerEntities/script_process.cpp)

set(SCRIPTS_SCRIPTCLASSES_SCRIPTFLAGS ../../engine/xrServerEntities/script_flags.h
                                      ../../engine/xrServerEntities/script_flags_script.cpp)

set(COMMON_ASPACE ai_space.h
                  ai_space_inline.h
                  ai_space.cpp)

set(SERVERSTUFF_SERVERENTITIES_OBJECTS_ALIFE_SMARTCOVER ../../engine/xrServerEntities/xrServer_Objects_Alife_Smartcovers.h
                                                        ../../engine/xrServerEntities/xrServer_Objects_Alife_Smartcovers.cpp
                                                        ../../engine/xrServerEntities/xrServer_Objects_Alife_Smartcovers_script.cpp)

set(SCRIPTS_SCRIPTCLASSES_SCRIPTFVECTOR ../../engine/xrServerEntities/script_fcolor.h
                                        ../../engine/xrServerEntities/script_fvector.h
                                        ../../engine/xrServerEntities/script_fcolor_script.cpp
                                        ../../engine/xrServerEntities/script_fvector_script.cpp)

set(COMMON defines.h)

set(COMMON_OBJECTFACTORY_OBJECT_ITEM_ABSTRACT ../../engine/xrServerEntities/object_item_abstract.h
                                              ../../engine/xrServerEntities/object_item_abstract_inline.h)

set(SERVERSTUFF_SERVERFACTORY ../../engine/xrServerEntities/xrServer_Factory.cpp)

set(COMMON_ACOMPONENTS_SPACERESTRICTIONMANAGER ../../engine/xrServerEntities/restriction_space.h)

set(CORE ../../engine/xrServerEntities/pch_script.h
         stdafx.h
         xr_LuaAllocator.h
         xrSE_Factory.h
         xrSE_Factory_import_export.h
         ../../engine/xrServerEntities/pch_script.cpp
         stdafx.cpp
         xrSE_Factory.cpp)

set(SCRIPTS_SCRIPTTHREAD_SCRIPTSTACKTRACKER ../../engine/xrServerEntities/script_stack_tracker.h
                                            ../../engine/xrServerEntities/script_stack_tracker_inline.h
                                            ../../engine/xrServerEntities/script_stack_tracker.cpp)

set(SERVERSTUFF_SERVERENTITIES_SCRIPTS_SCRIPT_VALUE_CONTAINER ../../engine/xrServerEntities/script_value_container.h
                                                              ../../engine/xrServerEntities/script_value_container_impl.h)

set(SERVERSTUFF_SERVERENTITIES_SCRIPTS_SCRIPT_PROPERTIES_LIST_HELPER script_properties_list_helper.h
                                                                     properties_list_helper_script.cpp
                                                                     script_properties_list_helper.cpp)

set(COMMON_ASOUND ../../engine/xrServerEntities/ai_sounds.h)

set(COMMON_OBJECTBROKER ../../engine/xrServerEntities/object_broker.h
                        ../../engine/xrServerEntities/object_cloner.h
                        ../../engine/xrServerEntities/object_comparer.h
                        ../../engine/xrServerEntities/object_destroyer.h
                        ../../engine/xrServerEntities/object_interfaces.h
                        ../../engine/xrServerEntities/object_loader.h
                        ../../engine/xrServerEntities/object_saver.h
                        ../../engine/xrServerEntities/object_type_traits.h)

set(COMMON_SMARTCAST ../../engine/xrServerEntities/smart_cast.h)

set(SCRIPTS_SCRIPTSTORAGE ../../engine/xrServerEntities/script_storage.h
                          ../../engine/xrServerEntities/script_storage_inline.h
                          ../../engine/xrServerEntities/script_storage_space.h
                          ../../engine/xrServerEntities/opt.lua.h
                          ../../engine/xrServerEntities/opt_inline.lua.h
                          ../../engine/xrServerEntities/script_storage.cpp)

set(SCRIPTS_SCRIPTCLASSES_SCRIPTSOUNDTYPE ../../engine/xrServerEntities/script_sound_type.h
                                          ../../engine/xrServerEntities/script_sound_type_script.cpp)

source_group("Common\\ObjectFactory" FILES ${COMMON_OBJECTFACTORY})
source_group("ServerStuff\\Common\\ALifeStuff\\monster_brain" FILES ${SERVERSTUFF_COMMON_ALIFESTUFF_MONSTER_BRAIN})
source_group("ServerStuff\\ServerEntities\\objects" FILES ${SERVERSTUFF_SERVERENTITIES_OBJECTS})
source_group("ServerStuff\\ServerEntities\\objects_alife" FILES ${SERVERSTUFF_SERVERENTITIES_OBJECTS_ALIFE})
source_group("ServerStuff\\ServerEntities\\scripts\\script_value_wrapper" FILES ${SERVERSTUFF_SERVERENTITIES_SCRIPTS_SCRIPT_VALUE_WRAPPER})
source_group("ServerStuff\\Common\\ServerStuff" FILES ${SERVERSTUFF_COMMON_SERVERSTUFF})
source_group("Common\\associative_vector" FILES ${COMMON_ASSOCIATIVE_VECTOR})
source_group("ServerStuff\\ServerEntities\\scripts\\script_value" FILES ${SERVERSTUFF_SERVERENTITIES_SCRIPTS_SCRIPT_VALUE})
source_group("ServerStuff\\Common\\PhysicsStuff" FILES ${SERVERSTUFF_COMMON_PHYSICSSTUFF})
source_group("ServerStuff\\Common\\ALifeStuff\\human_brain" FILES ${SERVERSTUFF_COMMON_ALIFESTUFF_HUMAN_BRAIN})
source_group("Scripts\\ScriptDebugger" FILES ${SCRIPTS_SCRIPTDEBUGGER})
source_group("Scripts" FILES ${SCRIPTS})
source_group("ServerStuff\\Common\\NetworkStuff" FILES ${SERVERSTUFF_COMMON_NETWORKSTUFF})
source_group("Scripts\\ScriptClasses\\ScriptFmatrix" FILES ${SCRIPTS_SCRIPTCLASSES_SCRIPTFMATRIX})
source_group("Scripts\\ScriptClasses\\ScriptNetPacket" FILES ${SCRIPTS_SCRIPTCLASSES_SCRIPTNETPACKET})
source_group("Scripts\\ScriptClasses\\ScriptIniFile" FILES ${SCRIPTS_SCRIPTCLASSES_SCRIPTINIFILE})
source_group("ServerStuff\\Common\\ALifeStuff" FILES ${SERVERSTUFF_COMMON_ALIFESTUFF})
source_group("Common\\ObjectFactory\\object_item_client_server" FILES ${COMMON_OBJECTFACTORY_OBJECT_ITEM_CLIENT_SERVER})
source_group("Common\\ObjectFactory\\object_item_single" FILES ${COMMON_OBJECTFACTORY_OBJECT_ITEM_SINGLE})
source_group("Scripts\\lua_studio" FILES ${SCRIPTS_LUA_STUDIO})
source_group("Scripts\\ScriptClasses\\ScriptIniFile\\ScriptTokenList" FILES ${SCRIPTS_SCRIPTCLASSES_SCRIPTINIFILE_SCRIPTTOKENLIST})
source_group("ServerStuff\\Common\\GameStuff" FILES ${SERVERSTUFF_COMMON_GAMESTUFF})
source_group("ServerStuff\\ServerEntities\\editor_properties" FILES ${SERVERSTUFF_SERVERENTITIES_EDITOR_PROPERTIES})
source_group("Common\\ObjectFactory\\object_item_script" FILES ${COMMON_OBJECTFACTORY_OBJECT_ITEM_SCRIPT})
source_group("Scripts\\ScriptClasses\\ScriptReader" FILES ${SCRIPTS_SCRIPTCLASSES_SCRIPTREADER})
source_group("ServerStuff\\ServerEntities" FILES ${SERVERSTUFF_SERVERENTITIES})
source_group("Scripts\\ScriptClasses\\ScriptIniFile\\ScriptRTokenList" FILES ${SCRIPTS_SCRIPTCLASSES_SCRIPTINIFILE_SCRIPTRTOKENLIST})
source_group("ServerStuff\\Common\\ALifeStuff\\artefact_order" FILES ${SERVERSTUFF_COMMON_ALIFESTUFF_ARTEFACT_ORDER})
source_group("Scripts\\ScriptThread" FILES ${SCRIPTS_SCRIPTTHREAD})
source_group("ServerStuff\\ServerEntities\\movement_manager_holder" FILES ${SERVERSTUFF_SERVERENTITIES_MOVEMENT_MANAGER_HOLDER})
source_group("ServerStuff\\ServerEntities\\objects_alife_monsters" FILES ${SERVERSTUFF_SERVERENTITIES_OBJECTS_ALIFE_MONSTERS})
source_group("ServerStuff\\ServerEntities\\objects_alife_items" FILES ${SERVERSTUFF_SERVERENTITIES_OBJECTS_ALIFE_ITEMS})
source_group("Scripts\\ScriptEngine" FILES ${SCRIPTS_SCRIPTENGINE})
source_group("Scripts\\ScriptProcess" FILES ${SCRIPTS_SCRIPTPROCESS})
source_group("Scripts\\ScriptClasses\\ScriptFlags" FILES ${SCRIPTS_SCRIPTCLASSES_SCRIPTFLAGS})
source_group("Common\\ASpace" FILES ${COMMON_ASPACE})
source_group("ServerStuff\\ServerEntities\\objects_alife_smartcover" FILES ${SERVERSTUFF_SERVERENTITIES_OBJECTS_ALIFE_SMARTCOVER})
source_group("Scripts\\ScriptClasses\\ScriptFvector" FILES ${SCRIPTS_SCRIPTCLASSES_SCRIPTFVECTOR})
source_group("Common" FILES ${COMMON})
source_group("Common\\ObjectFactory\\object_item_abstract" FILES ${COMMON_OBJECTFACTORY_OBJECT_ITEM_ABSTRACT})
source_group("ServerStuff\\ServerFactory" FILES ${SERVERSTUFF_SERVERFACTORY})
source_group("Common\\AComponents\\SpaceRestrictionManager" FILES ${COMMON_ACOMPONENTS_SPACERESTRICTIONMANAGER})
source_group("Core" FILES ${CORE})
source_group("Scripts\\ScriptThread\\ScriptStackTracker" FILES ${SCRIPTS_SCRIPTTHREAD_SCRIPTSTACKTRACKER})
source_group("ServerStuff\\ServerEntities\\scripts\\script_value_container" FILES ${SERVERSTUFF_SERVERENTITIES_SCRIPTS_SCRIPT_VALUE_CONTAINER})
source_group("ServerStuff\\ServerEntities\\scripts\\script_properties_list_helper" FILES ${SERVERSTUFF_SERVERENTITIES_SCRIPTS_SCRIPT_PROPERTIES_LIST_HELPER})
source_group("Common\\ASound" FILES ${COMMON_ASOUND})
source_group("Common\\ObjectBroker" FILES ${COMMON_OBJECTBROKER})
source_group("Common\\SmartCast" FILES ${COMMON_SMARTCAST})
source_group("Scripts\\ScriptStorage" FILES ${SCRIPTS_SCRIPTSTORAGE})
source_group("Scripts\\ScriptClasses\\ScriptSoundType" FILES ${SCRIPTS_SCRIPTCLASSES_SCRIPTSOUNDTYPE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ../../3rd-party/luajit/include ../../engine/xrServerEntities)
link_directories(../../lib)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_DEBUG} -DLUABIND_NO_ERROR_CHECKING")
add_definitions(-DXRSE_FACTORY_EXPORTS -D_SECURE_SCL=0)
add_compile_options("/Yustdafx.h" /fp:fast /GR)

set(SCRIPT_PCH ${CMAKE_CURRENT_BINARY_DIR}/$<$<CONFIG:Debug>:DEBUG>$<$<CONFIG:RELWITHDEBINFO>:RelWithDebInfo>/xrSE_Factory_script.pch)

set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)
set_source_files_properties(../../engine/xrServerEntities/pch_script.cpp PROPERTIES COMPILE_FLAGS "/Ycpch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(xrSE_Factory.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/object_factory_register.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/object_factory_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/xrServer_Objects_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/xrServer_Objects_script2.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/xrServer_Objects_ALife_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/xrServer_Objects_ALife_script2.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/xrServer_Objects_ALife_script3.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/script_lua_helper.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/script_fmatrix_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/script_net_packet_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/script_ini_file_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/lua_studio.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/script_token_list_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/object_item_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/script_reader_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/script_rtoken_list_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/script_thread.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/xrServer_Objects_ALife_Monsters_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/xrServer_Objects_ALife_Monsters_script2.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/xrserver_objects_alife_monsters_script3.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/xrServer_Objects_ALife_Monsters_script4.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/xrServer_Objects_ALife_Items_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/xrServer_Objects_ALife_Items_script2.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/xrServer_Objects_ALife_Items_script3.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/script_engine.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/script_engine_export.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/script_engine_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/script_process.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/script_flags_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/xrServer_Objects_Alife_Smartcovers.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/xrServer_Objects_Alife_Smartcovers_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/script_fcolor_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/script_fvector_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/script_stack_tracker.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/script_storage.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")
set_source_files_properties(../../engine/xrServerEntities/script_sound_type_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH}\"")

add_library(xrSE_Factory SHARED ${COMMON_ACOMPONENTS_SPACERESTRICTIONMANAGER}
                                ${COMMON_OBJECTFACTORY_OBJECT_ITEM_ABSTRACT}
                                ${SCRIPTS_SCRIPTCLASSES_SCRIPTFLAGS}
                                ${COMMON_OBJECTFACTORY_OBJECT_ITEM_SINGLE}
                                ${SERVERSTUFF_SERVERENTITIES_OBJECTS_ALIFE_MONSTERS}
                                ${SCRIPTS_SCRIPTTHREAD_SCRIPTSTACKTRACKER}
                                ${SERVERSTUFF_COMMON_NETWORKSTUFF}
                                ${SERVERSTUFF_COMMON_ALIFESTUFF_HUMAN_BRAIN}
                                ${SERVERSTUFF_COMMON_ALIFESTUFF_MONSTER_BRAIN}
                                ${SERVERSTUFF_COMMON_GAMESTUFF}
                                ${SCRIPTS_SCRIPTPROCESS}
                                ${COMMON}
                                ${SERVERSTUFF_SERVERENTITIES_SCRIPTS_SCRIPT_PROPERTIES_LIST_HELPER}
                                ${SCRIPTS_SCRIPTCLASSES_SCRIPTINIFILE_SCRIPTTOKENLIST}
                                ${SERVERSTUFF_SERVERENTITIES_SCRIPTS_SCRIPT_VALUE}
                                ${CORE}
                                ${SERVERSTUFF_SERVERENTITIES_OBJECTS_ALIFE_ITEMS}
                                ${SCRIPTS_SCRIPTCLASSES_SCRIPTINIFILE_SCRIPTRTOKENLIST}
                                ${SCRIPTS_SCRIPTENGINE}
                                ${SCRIPTS_SCRIPTCLASSES_SCRIPTSOUNDTYPE}
                                ${SERVERSTUFF_SERVERENTITIES_SCRIPTS_SCRIPT_VALUE_WRAPPER}
                                ${SERVERSTUFF_COMMON_PHYSICSSTUFF}
                                ${SCRIPTS_SCRIPTDEBUGGER}
                                ${COMMON_OBJECTFACTORY_OBJECT_ITEM_CLIENT_SERVER}
                                ${SERVERSTUFF_SERVERENTITIES}
                                ${SERVERSTUFF_SERVERENTITIES_OBJECTS_ALIFE_SMARTCOVER}
                                ${SCRIPTS_SCRIPTCLASSES_SCRIPTFMATRIX}
                                ${COMMON_OBJECTFACTORY_OBJECT_ITEM_SCRIPT}
                                ${COMMON_OBJECTBROKER}
                                ${SERVERSTUFF_SERVERENTITIES_OBJECTS}
                                ${SERVERSTUFF_SERVERFACTORY}
                                ${SCRIPTS_SCRIPTSTORAGE}
                                ${SCRIPTS_LUA_STUDIO}
                                ${SCRIPTS_SCRIPTCLASSES_SCRIPTREADER}
                                ${COMMON_ASSOCIATIVE_VECTOR}
                                ${COMMON_ASPACE}
                                ${COMMON_SMARTCAST}
                                ${SCRIPTS_SCRIPTCLASSES_SCRIPTINIFILE}
                                ${SERVERSTUFF_COMMON_SERVERSTUFF}
                                ${COMMON_ASOUND}
                                ${SERVERSTUFF_SERVERENTITIES_OBJECTS_ALIFE}
                                ${SERVERSTUFF_SERVERENTITIES_SCRIPTS_SCRIPT_VALUE_CONTAINER}
                                ${SERVERSTUFF_SERVERENTITIES_MOVEMENT_MANAGER_HOLDER}
                                ${SCRIPTS_SCRIPTTHREAD}
                                ${COMMON_OBJECTFACTORY}
                                ${SERVERSTUFF_COMMON_ALIFESTUFF}
                                ${SCRIPTS}
                                ${SCRIPTS_SCRIPTCLASSES_SCRIPTFVECTOR}
                                ${SERVERSTUFF_SERVERENTITIES_EDITOR_PROPERTIES}
                                ${SERVERSTUFF_COMMON_ALIFESTUFF_ARTEFACT_ORDER}
                                ${SCRIPTS_SCRIPTCLASSES_SCRIPTNETPACKET})
set_target_properties(xrSE_Factory PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
target_link_libraries(xrSE_Factory xrCore luabind xrXMLParser shlwapi)