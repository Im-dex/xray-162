cmake_minimum_required(VERSION 3.8)

project(xrEngine)

set(INTERFACES_RENDER IRenderable.h
                      Render.h
                      IRenderable.cpp
                      Render.cpp)

set(RENDERREF_EXECUTION__AND__3D_VISUALS Fmesh.h
                                         fmesh.cpp)

set(ENGINE_TEXT_EDITOR_LINE_EDITOR_CONTROL line_edit_control.h
                                           line_edit_control.cpp)

set(EDITOR_ENVIRONMENT_SUNS_MANAGER_SUN editor_environment_suns_sun.hpp
                                        editor_environment_suns_sun.cpp)

set(EDITOR_ENVIRONMENT_SUNS_MANAGER_SUN_FLARES editor_environment_suns_flares.hpp
                                               editor_environment_suns_flares.cpp)

set(RENDERREF_EXECUTION__AND__3D_DEVICE device.h
                                        StatGraph.h
                                        Stats.h
                                        device.cpp
                                        Device_create.cpp
                                        Device_destroy.cpp
                                        Device_Initialize.cpp
                                        Device_Misc.cpp
                                        Device_overdraw.cpp
                                        Device_wndproc.cpp
                                        StatGraph.cpp
                                        Stats.cpp)

set(GAME_API_GAMEMATERIALS GameMtlLib.h
                           GameMtlLib.cpp
                           GameMtlLib_Engine.cpp)

set(EDITOR_ENVIRONMENT_SUNS_MANAGER_SUN_FLARES_FLARE editor_environment_suns_flare.hpp
                                                     editor_environment_suns_flare.cpp)

set(INTERFACES_RENDER_VISUALS_SKELETON EnnumerateVertices.h)

set(INTERFACES_RENDER_VISIBILITY vis_common.h)

set(INTERFACES_RENDER_EXECUTION__AND__3D_SHADERS_TEXTURES tntQAVI.h
                                                          xrImage_Resampler.h
                                                          xrTheora_Stream.h
                                                          xrTheora_Surface.h
                                                          xrTheora_Surface_mmx.h
                                                          tntQAVI.cpp
                                                          xrImage_Resampler.cpp
                                                          xrTheora_Stream.cpp
                                                          xrTheora_Surface.cpp
                                                          xrTheora_Surface_mmx.cpp)

set(EDITOR_ENVIRONMENT_MANAGER editor_environment_manager.hpp
                               editor_environment_manager.cpp)

set(INTERFACES_RENDER_PARTICLE_SYSTEM PS_instance.h
                                      PS_instance.cpp)

set(EDITOR_ENVIRONMENT_EFFECTS_MANAGER editor_environment_effects_manager.hpp
                                       editor_environment_effects_manager.cpp)

set(ENGINE_CORE Engine.h
                EngineAPI.h
                EventAPI.h
                Engine.cpp
                EngineAPI.cpp
                EventAPI.cpp
                mailSlot.cpp)

set(GAME_API_ENVIRONMENT Environment.h
                         xrHemisphere.h
                         Environment.cpp
                         Environment_misc.cpp
                         Environment_render.cpp
                         xrHemisphere.cpp)

set(EDITOR_ENVIRONMENT_AMBIENTS_AMBIENT_EFFECT_ID editor_environment_ambients_effect_id.hpp
                                                  editor_environment_ambients_effect_id.cpp)

set(EDITOR_ENGINE_IMPL engine_impl.hpp
                       engine_impl.cpp)

set(EDITOR_ENVIRONMENT_THUNDERBOLTS_COLLECTION editor_environment_thunderbolts_collection.hpp
                                               editor_environment_thunderbolts_collection.cpp)

set(ENGINE_COLLISION_CORE cl_intersect.h)

set(EDITOR_ENVIRONMENT_THUNDERBOLTS editor_environment_thunderbolts_manager.hpp
                                    editor_environment_thunderbolts_manager.cpp)

set(INTERFACES_RENDER_FONT_OUTPUT GameFont.h
                                  MbHelpers.h
                                  GameFont.cpp
                                  MbHelpers.cpp)

set(ENGINE_TEXT_EDITOR_LINE_EDITOR line_editor.h
                                   line_editor.cpp)

set(RENDERREF_EXECUTION__AND__3D_VISUALS_SKELETON SkeletonMotionDefs.h
                                                  SkeletonMotions.h
                                                  SkeletonMotions.cpp)

set(EDITOR_ENVIRONMENT_WEATHERS_WEATHER_TIME editor_environment_weathers_time.hpp
                                             editor_environment_weathers_time.cpp)

set(EDITOR_ENVIRONMENT_DETAIL editor_environment_detail.hpp
                              editor_environment_detail.cpp)

set(GAME_API_ANIMATOR bone.h
                      envelope.h
                      motion.h
                      ObjectAnimator.h
                      bone.cpp
                      Envelope.cpp
                      interp.cpp
                      motion.cpp
                      ObjectAnimator.cpp)

set(INTERFACES_RENDER_LIGHTING LightAnimLibrary.h
                               LightAnimLibrary.cpp)

set(GAME_API_HUD CustomHUD.h
                 CustomHUD.cpp)

set(EDITOR_ENVIRONMENT_WEATHERS_WEATHER editor_environment_weathers_weather.hpp
                                        editor_environment_weathers_weather.cpp)

set(ENGINE_NOISE perlin.h
                 perlin.cpp)

set(EDITOR_PROPERTY_COLLECTION property_collection.hpp
                               property_collection_forward.hpp
                               property_collection_inline.hpp)

set(INTERFACES_INPUT IInputReceiver.h
                     xr_input.h
                     xr_input_xinput.h
                     IInputReceiver.cpp
                     Xr_input.cpp
                     xr_input_xinput.cpp)

set(GAME_API_DEMO FDemoPlay.h
                  FDemoRecord.h
                  FDemoPlay.cpp
                  FDemoRecord.cpp)

set(ENGINE_TEXT_EDITOR_EDIT_ACTIONS edit_actions.h
                                    edit_actions.cpp)

set(GENERAL_RESOURCES resource.h
                      resource.rc
                      splash_xrcs_en.bmp
                      stalker_cs.ico)

set(ENGINE_CONSOLE XR_IOConsole.h
                   XR_IOConsole.cpp
                   XR_IOConsole_callback.cpp
                   XR_IOConsole_control.cpp
                   XR_IOConsole_get.cpp)

set(GAME_API_OBJECTS IGame_ObjectPool.h
                     IGame_Persistent.h
                     pure_relcase.h
                     xr_object.h
                     xr_object_list.h
                     IGame_ObjectPool.cpp
                     pure_relcase.cpp
                     xr_object.cpp
                     xr_object_list.cpp)

set(RENDERREF_DOUG_LEA_MEMORY_ALLOCATOR doug_lea_memory_allocator.h
                                        doug_lea_memory_allocator.c)
set_source_files_properties(doug_lea_memory_allocator.c PROPERTIES COMPILE_FLAGS /Y-)

set(EDITOR_ENVIRONMENT_SUNS_MANAGER_SUN_GRADIENT editor_environment_suns_gradient.hpp
                                                 editor_environment_suns_gradient.cpp)

set(ENGINE_CONSOLE_COMMANDS xr_ioc_cmd.h
                            xr_ioc_cmd.cpp)

set(INTERFACES_RENDER_EXECUTION__AND__3D_TEXTCONSOLE Text_Console.h
                                                     Text_Console.cpp
                                                     Text_Console_WndProc.cpp)

set(EDITOR_ENVIRONMENT_THUNDERBOLTS_THUNDERBOLT_ID editor_environment_thunderbolts_thunderbolt_id.hpp
                                                   editor_environment_thunderbolts_thunderbolt_id.cpp)

set(EDITOR_ENVIRONMENT_LEVELS_MANAGER editor_environment_levels_manager.hpp
                                      editor_environment_levels_manager.cpp)

set(GAME_API_CAMERAS CameraBase.h
                     CameraDefs.h
                     CameraManager.h
                     Effector.h
                     EffectorPP.h
                     CameraBase.cpp
                     CameraManager.cpp
                     Effector.cpp
                     EffectorPP.cpp)

set(ENGINE Properties.h
           pure.h
           std_classes.h
           pure.cpp)

set(INTERFACES_COLLIDABLE ICollidable.h
                          ICollidable.cpp)

set(EDITOR_IDE ide.hpp)

set(EDITOR_ENVIRONMENT_AMBIENTS_AMBIENT_SOUND_ID editor_environment_ambients_sound_id.hpp
                                                 editor_environment_ambients_sound_id.cpp)

set(EDITOR_ENVIRONMENT_SOUND_CHANNELS_MANAGER editor_environment_sound_channels_manager.hpp
                                              editor_environment_sound_channels_manager.cpp)

set(GAME_API_COLLISION cf_dynamic_mesh.h
                       xr_collide_form.h
                       cf_dynamic_mesh.cpp
                       xr_collide_form.cpp)

set(EDITOR_ENVIRONMENT_SUNS_MANAGER_SUN_BLEND editor_environment_suns_blend.hpp
                                              editor_environment_suns_blend.cpp)

set(INTERFACES_SHEDULER ISheduled.h
                        xrSheduler.h
                        ISheduled.cpp
                        xrSheduler.cpp)

set(EDITOR_ENVIRONMENT_THUNDERBOLTS_THUNDERBOLT editor_environment_thunderbolts_thunderbolt.hpp
                                                editor_environment_thunderbolts_thunderbolt.cpp)

set(EDITOR_ENVIRONMENT_EFFECTS_MANAGER_EFFECT editor_environment_effects_effect.hpp
                                              editor_environment_effects_effect.cpp)

set(INTERFACES_PHYSICS IObjectPhysicsCollision.h
                       IPHdebug.h
                       IPhysicsGeometry.h
                       IPhysicsShell.h
                       phdebug.cpp)

set(EDITOR_ENVIRONMENT_AMBIENTS editor_environment_ambients_manager.hpp
                                editor_environment_ambients_manager.cpp)

set(GAME_API_ENVIRONMENT_EFFECTS Rain.h
                                 thunderbolt.h
                                 xr_efflensflare.h
                                 Rain.cpp
                                 thunderbolt.cpp
                                 xr_efflensflare.cpp)

set(ROOT_SPECIAL_CONV ClientServer.txt
                      "Effects description.txt"
                      features.txt
                      TODO.txt)

set(EDITOR_ENVIRONMENT_AMBIENTS_AMBIENT editor_environment_ambients_ambient.hpp
                                        editor_environment_ambients_ambient.cpp)

set(GAME_API_DEBUG ObjectDump.h
                   ObjectDump.cpp)

set(EDITOR_ENVIRONMENT_SOUND_CHANNELS_MANAGER_CHANNEL_SOURCE editor_environment_sound_channels_source.hpp
                                                             editor_environment_sound_channels_source.cpp)

set(ENGINE_CORE_SCRIPTING ai_script_lua_extension.h
                          ai_script_lua_space.h
                          ai_script_space.h
                          ai_script_lua_debug.cpp
                          ai_script_lua_extension.cpp)

set(GENERAL _d3d_extensions.h
            dedicated_server_only.h
            defines.h
            mp_logging.h
            no_single.h
            stdafx.h
            trivial_encryptor.h
            x_ray.h
            defines.cpp
            stdafx.cpp
            x_ray.cpp)

set(EDITOR_ENVIRONMENT_SUNS_MANAGER editor_environment_suns_manager.hpp
                                    editor_environment_suns_manager.cpp)

set(EDITOR_ENVIRONMENT_THUNDERBOLTS_THUNDERBOLT_GRADIENT editor_environment_thunderbolts_gradient.hpp
                                                         editor_environment_thunderbolts_gradient.cpp)

set(INTERFACES_RENDER_EXECUTION__AND__3D_SHADERS Shader_xrLC.h
                                                 WaveForm.h)

set(GAME_API_FEELERS Feel_Sound.h
                     Feel_Touch.h
                     Feel_Vision.h
                     Feel_Touch.cpp
                     Feel_Vision.cpp)

set(OPENAUTOMATE xrSASH.h
                 xrSASH.cpp)

set(EDITOR_ENVIRONMENT_SOUND_CHANNELS_MANAGER_CHANNEL editor_environment_sound_channels_channel.hpp
                                                      editor_environment_sound_channels_channel.cpp)

set(EDITOR_ENVIRONMENT_WEATHERS editor_environment_weathers_manager.hpp
                                editor_environment_weathers_manager.cpp)

set(GAME_API IGame_Level.h
             xrLevel.h
             IGame_Level.cpp
             IGame_Level_check_textures.cpp
             IGame_Persistent.cpp)

source_group("Interfaces\\Render" FILES ${INTERFACES_RENDER})
source_group("RenderRef\\Execution &amp; 3D\\Visuals" FILES ${RENDERREF_EXECUTION__AND__3D_VISUALS})
source_group("Engine\\text_editor\\line_editor_control" FILES ${ENGINE_TEXT_EDITOR_LINE_EDITOR_CONTROL})
source_group("editor\\environment\\suns_manager\\sun" FILES ${EDITOR_ENVIRONMENT_SUNS_MANAGER_SUN})
source_group("editor\\environment\\suns_manager\\sun\\flares" FILES ${EDITOR_ENVIRONMENT_SUNS_MANAGER_SUN_FLARES})
source_group("RenderRef\\Execution &amp; 3D\\Device" FILES ${RENDERREF_EXECUTION__AND__3D_DEVICE})
source_group("Game API\\GameMaterials" FILES ${GAME_API_GAMEMATERIALS})
source_group("editor\\environment\\suns_manager\\sun\\flares\\flare" FILES ${EDITOR_ENVIRONMENT_SUNS_MANAGER_SUN_FLARES_FLARE})
source_group("Interfaces\\Render\\Visuals\\Skeleton" FILES ${INTERFACES_RENDER_VISUALS_SKELETON})
source_group("Interfaces\\Render\\Visibility" FILES ${INTERFACES_RENDER_VISIBILITY})
source_group("Interfaces\\Render\\Execution &amp; 3D\\Shaders\\Textures" FILES ${INTERFACES_RENDER_EXECUTION__AND__3D_SHADERS_TEXTURES})
source_group("editor\\environment\\manager" FILES ${EDITOR_ENVIRONMENT_MANAGER})
source_group("Interfaces\\Render\\Particle system" FILES ${INTERFACES_RENDER_PARTICLE_SYSTEM})
source_group("editor\\environment\\effects_manager" FILES ${EDITOR_ENVIRONMENT_EFFECTS_MANAGER})
source_group("Engine\\Core" FILES ${ENGINE_CORE})
source_group("Game API\\Environment" FILES ${GAME_API_ENVIRONMENT})
source_group("editor\\environment\\ambients\\ambient\\effect_id" FILES ${EDITOR_ENVIRONMENT_AMBIENTS_AMBIENT_EFFECT_ID})
source_group("editor\\engine_impl" FILES ${EDITOR_ENGINE_IMPL})
source_group("editor\\environment\\thunderbolts\\collection" FILES ${EDITOR_ENVIRONMENT_THUNDERBOLTS_COLLECTION})
source_group("Engine\\Collision Core" FILES ${ENGINE_COLLISION_CORE})
source_group("editor\\environment\\thunderbolts" FILES ${EDITOR_ENVIRONMENT_THUNDERBOLTS})
source_group("Interfaces\\Render\\Font output" FILES ${INTERFACES_RENDER_FONT_OUTPUT})
source_group("Engine\\text_editor\\line_editor" FILES ${ENGINE_TEXT_EDITOR_LINE_EDITOR})
source_group("RenderRef\\Execution &amp; 3D\\Visuals\\Skeleton" FILES ${RENDERREF_EXECUTION__AND__3D_VISUALS_SKELETON})
source_group("editor\\environment\\weathers\\weather\\time" FILES ${EDITOR_ENVIRONMENT_WEATHERS_WEATHER_TIME})
source_group("editor\\environment\\detail" FILES ${EDITOR_ENVIRONMENT_DETAIL})
source_group("Game API\\Animator" FILES ${GAME_API_ANIMATOR})
source_group("Interfaces\\Render\\Lighting" FILES ${INTERFACES_RENDER_LIGHTING})
source_group("Game API\\HUD" FILES ${GAME_API_HUD})
source_group("editor\\environment\\weathers\\weather" FILES ${EDITOR_ENVIRONMENT_WEATHERS_WEATHER})
source_group("Engine\\Noise" FILES ${ENGINE_NOISE})
source_group("editor\\property_collection" FILES ${EDITOR_PROPERTY_COLLECTION})
source_group("Interfaces\\Input" FILES ${INTERFACES_INPUT})
source_group("Game API\\Demo" FILES ${GAME_API_DEMO})
source_group("Engine\\text_editor\\edit_actions" FILES ${ENGINE_TEXT_EDITOR_EDIT_ACTIONS})
source_group("General\\Resources" FILES ${GENERAL_RESOURCES})
source_group("Engine\\Console" FILES ${ENGINE_CONSOLE})
source_group("Game API\\Objects" FILES ${GAME_API_OBJECTS})
source_group("RenderRef\\doug_lea_memory_allocator" FILES ${RENDERREF_DOUG_LEA_MEMORY_ALLOCATOR})
source_group("editor\\environment\\suns_manager\\sun\\gradient" FILES ${EDITOR_ENVIRONMENT_SUNS_MANAGER_SUN_GRADIENT})
source_group("Engine\\Console\\commands" FILES ${ENGINE_CONSOLE_COMMANDS})
source_group("Interfaces\\Render\\Execution &amp; 3D\\TextConsole" FILES ${INTERFACES_RENDER_EXECUTION__AND__3D_TEXTCONSOLE})
source_group("editor\\environment\\thunderbolts\\thunderbolt_id" FILES ${EDITOR_ENVIRONMENT_THUNDERBOLTS_THUNDERBOLT_ID})
source_group("editor\\environment\\levels_manager" FILES ${EDITOR_ENVIRONMENT_LEVELS_MANAGER})
source_group("Game API\\Cameras" FILES ${GAME_API_CAMERAS})
source_group("Engine" FILES ${ENGINE})
source_group("Interfaces\\Collidable" FILES ${INTERFACES_COLLIDABLE})
source_group("editor\\ide" FILES ${EDITOR_IDE})
source_group("editor\\environment\\ambients\\ambient\\sound_id" FILES ${EDITOR_ENVIRONMENT_AMBIENTS_AMBIENT_SOUND_ID})
source_group("editor\\environment\\sound_channels_manager" FILES ${EDITOR_ENVIRONMENT_SOUND_CHANNELS_MANAGER})
source_group("Game API\\Collision" FILES ${GAME_API_COLLISION})
source_group("editor\\environment\\suns_manager\\sun\\blend" FILES ${EDITOR_ENVIRONMENT_SUNS_MANAGER_SUN_BLEND})
source_group("Interfaces\\Sheduler" FILES ${INTERFACES_SHEDULER})
source_group("editor\\environment\\thunderbolts\\thunderbolt" FILES ${EDITOR_ENVIRONMENT_THUNDERBOLTS_THUNDERBOLT})
source_group("editor\\environment\\effects_manager\\effect" FILES ${EDITOR_ENVIRONMENT_EFFECTS_MANAGER_EFFECT})
source_group("Interfaces\\Physics" FILES ${INTERFACES_PHYSICS})
source_group("editor\\environment\\ambients" FILES ${EDITOR_ENVIRONMENT_AMBIENTS})
source_group("Game API\\Environment\\Effects" FILES ${GAME_API_ENVIRONMENT_EFFECTS})
source_group("" FILES ${ROOT_SPECIAL_CONV})
source_group("editor\\environment\\ambients\\ambient" FILES ${EDITOR_ENVIRONMENT_AMBIENTS_AMBIENT})
source_group("Game API\\Debug" FILES ${GAME_API_DEBUG})
source_group("editor\\environment\\sound_channels_manager\\channel\\source" FILES ${EDITOR_ENVIRONMENT_SOUND_CHANNELS_MANAGER_CHANNEL_SOURCE})
source_group("Engine\\Core\\Scripting" FILES ${ENGINE_CORE_SCRIPTING})
source_group("General" FILES ${GENERAL})
source_group("editor\\environment\\suns_manager" FILES ${EDITOR_ENVIRONMENT_SUNS_MANAGER})
source_group("editor\\environment\\thunderbolts\\thunderbolt\\gradient" FILES ${EDITOR_ENVIRONMENT_THUNDERBOLTS_THUNDERBOLT_GRADIENT})
source_group("Interfaces\\Render\\Execution &amp; 3D\\Shaders" FILES ${INTERFACES_RENDER_EXECUTION__AND__3D_SHADERS})
source_group("Game API\\Feelers" FILES ${GAME_API_FEELERS})
source_group("OpenAutomate" FILES ${OPENAUTOMATE})
source_group("editor\\environment\\sound_channels_manager\\channel" FILES ${EDITOR_ENVIRONMENT_SOUND_CHANNELS_MANAGER_CHANNEL})
source_group("editor\\environment\\weathers" FILES ${EDITOR_ENVIRONMENT_WEATHERS})
source_group("Game API" FILES ${GAME_API})

include_directories(${DXSDK_INCLUDE_DIR} ../../3rd-party/luajit/include)
link_directories(${DXSDK_LIB_DIR} ../../lib)
add_definitions(-DENGINE_BUILD -D_SECURE_SCL=0)

add_compile_options(/fp:fast /GR "/Yustdafx.h")
set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)

add_executable(xrEngine xrEngine.manifest
                        ${GAME_API_OBJECTS}
                        ${INTERFACES_RENDER}
                        ${EDITOR_ENVIRONMENT_SUNS_MANAGER}
                        ${ENGINE_TEXT_EDITOR_LINE_EDITOR_CONTROL}
                        ${RENDERREF_EXECUTION__AND__3D_VISUALS}
                        ${RENDERREF_EXECUTION__AND__3D_DEVICE}
                        ${INTERFACES_INPUT}
                        ${EDITOR_ENVIRONMENT_SUNS_MANAGER_SUN_FLARES}
                        ${ENGINE}
                        ${EDITOR_ENVIRONMENT_MANAGER}
                        ${EDITOR_ENVIRONMENT_AMBIENTS_AMBIENT_EFFECT_ID}
                        ${GAME_API_CAMERAS}
                        ${GENERAL}
                        ${INTERFACES_COLLIDABLE}
                        ${EDITOR_ENVIRONMENT_WEATHERS_WEATHER}
                        ${GAME_API_ANIMATOR}
                        ${ENGINE_TEXT_EDITOR_EDIT_ACTIONS}
                        ${EDITOR_ENVIRONMENT_EFFECTS_MANAGER_EFFECT}
                        ${EDITOR_ENVIRONMENT_SOUND_CHANNELS_MANAGER_CHANNEL}
                        ${ENGINE_TEXT_EDITOR_LINE_EDITOR}
                        ${GAME_API_FEELERS}
                        ${INTERFACES_RENDER_EXECUTION__AND__3D_SHADERS}
                        ${EDITOR_ENVIRONMENT_THUNDERBOLTS}
                        ${EDITOR_ENVIRONMENT_SUNS_MANAGER_SUN_BLEND}
                        ${ENGINE_NOISE}
                        ${EDITOR_ENVIRONMENT_SOUND_CHANNELS_MANAGER_CHANNEL_SOURCE}
                        ${INTERFACES_RENDER_PARTICLE_SYSTEM}
                        ${EDITOR_ENVIRONMENT_THUNDERBOLTS_THUNDERBOLT_GRADIENT}
                        ${GENERAL_RESOURCES}
                        ${EDITOR_ENVIRONMENT_THUNDERBOLTS_THUNDERBOLT_ID}
                        ${GAME_API_ENVIRONMENT_EFFECTS}
                        ${INTERFACES_RENDER_VISIBILITY}
                        ${EDITOR_ENVIRONMENT_SUNS_MANAGER_SUN}
                        ${GAME_API_ENVIRONMENT}
                        ${EDITOR_ENVIRONMENT_WEATHERS}
                        ${GAME_API_COLLISION}
                        ${EDITOR_ENVIRONMENT_THUNDERBOLTS_COLLECTION}
                        ${INTERFACES_RENDER_LIGHTING}
                        ${EDITOR_ENVIRONMENT_SOUND_CHANNELS_MANAGER}
                        ${EDITOR_ENVIRONMENT_WEATHERS_WEATHER_TIME}
                        ${GAME_API_HUD}
                        ${ENGINE_CONSOLE}
                        ${ENGINE_CORE_SCRIPTING}
                        ${EDITOR_ENVIRONMENT_AMBIENTS_AMBIENT_SOUND_ID}
                        ${INTERFACES_RENDER_EXECUTION__AND__3D_TEXTCONSOLE}
                        ${EDITOR_ENVIRONMENT_LEVELS_MANAGER}
                        ${ENGINE_CORE}
                        ${EDITOR_ENVIRONMENT_DETAIL}
                        ${EDITOR_ENGINE_IMPL}
                        ${EDITOR_ENVIRONMENT_EFFECTS_MANAGER}
                        ${ENGINE_COLLISION_CORE}
                        ${ROOT_SPECIAL_CONV}
                        ${EDITOR_ENVIRONMENT_AMBIENTS_AMBIENT}
                        ${GAME_API_GAMEMATERIALS}
                        ${RENDERREF_DOUG_LEA_MEMORY_ALLOCATOR}
                        ${GAME_API_DEMO}
                        ${EDITOR_ENVIRONMENT_AMBIENTS}
                        ${RENDERREF_EXECUTION__AND__3D_VISUALS_SKELETON}
                        ${EDITOR_ENVIRONMENT_THUNDERBOLTS_THUNDERBOLT}
                        ${GAME_API}
                        ${OPENAUTOMATE}
                        ${EDITOR_IDE}
                        ${EDITOR_ENVIRONMENT_SUNS_MANAGER_SUN_FLARES_FLARE}
                        ${EDITOR_ENVIRONMENT_SUNS_MANAGER_SUN_GRADIENT}
                        ${GAME_API_DEBUG}
                        ${ENGINE_CONSOLE_COMMANDS}
                        ${INTERFACES_RENDER_EXECUTION__AND__3D_SHADERS_TEXTURES}
                        ${INTERFACES_PHYSICS}
                        ${INTERFACES_RENDER_FONT_OUTPUT}
                        ${EDITOR_PROPERTY_COLLECTION}
                        ${INTERFACES_SHEDULER}
                        ${INTERFACES_RENDER_VISUALS_SKELETON})
set_target_properties(xrEngine PROPERTIES ENABLE_EXPORTS YES)
set_target_properties(xrEngine PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
add_dependencies(xrEngine luajit)
target_link_libraries(xrEngine vfw32 libogg libtheora oalib d3dx9 d3d9 dinput8 dxguid
                               shlwapi xrCore xrCDB xrSound xrAPI xrNetServer winmm luabind)