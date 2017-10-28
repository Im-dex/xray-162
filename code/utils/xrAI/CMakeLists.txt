cmake_minimum_required(VERSION 3.8)

project(xrAI)

set(ALIFE_SEARCH_GRAPHS_LEVEL_GRAPH level_graph.cpp
                                    level_graph_vertex.cpp
                                    level_graph.h
                                    level_graph_inline.h
                                    level_graph_space.h
                                    level_graph_vertex_inline.h)

set(ALIFE_SEARCH_DATA_STORAGES_DATA_STORAGE_CONSTRUCTORS data_storage_constructor.h)

set(ALIFE_SHARED_ALIFE_ALIFE_SPACE ../../engine/xrServerEntities/alife_space.cpp
                                   ../../engine/xrServerEntities/alife_space.h)

set(ALIFE_SEARCH_GRAPHS_GAME_GRAPH ../../engine/xrServerEntities/game_graph_space.h
                                   game_graph.h
                                   game_graph_inline.h)

set(ALIFE_SEARCH_DATA_STORAGES_PATH_BUILDERS_VERTEX_PATH vertex_path.h
                                                         vertex_path_inline.h)

set(COMPILER_QUAD_TREE quadtree.h
                       quadtree_inline.h)

set(ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_GENERIC path_manager_generic.h
                                                    path_manager_generic_inline.h)

set(ALIFE_SEARCH_DATA_STORAGES_DATA_STORAGE_CONSTRUCTORS_MANAGER_BUILDER_ALLOCATOR manager_builder_allocator_constructor.h
                                                                                   manager_builder_allocator_constructor_inline.h)

set(ALIFE_SHARED_ALIFE_ALIFE_ARTEFACT_ORDER alife_artefact_order.cpp
                                            alife_artefact_order.h)

set(ALIFE_SEARCH_DATA_STORAGES_DATA_STORAGE_CONSTRUCTORS_BUILDER_ALLOCATOR builder_allocator_constructor.h
                                                                           builder_allocator_constructor_inline.h)

set(COMPILER_KERNEL_RESOURCE_FILES resource.h
                                   resource.rc)

set(ALIFE_SEARCH_DATA_STORAGES_PATH_BUILDERS_EDGE_PATH edge_path.h
                                                       edge_path_inline.h)

set(ALIFE_SPAWN_PATROL_PATHS_PATROL_PATH_STORAGE patrol_path_storage.cpp
                                                 patrol_path_storage.h
                                                 patrol_path_storage_inline.h)

set(ALIFE_SHARED_COMMON ../../engine/xrServerEntities/clsid_game.h
                        ../../engine/xrServerEntities/smart_cast.h
                        profiler.h)

set(ALIFE_SEARCH_GRAPH_ENGINE graph_engine.h
                              graph_engine_inline.h
                              graph_engine_space.h)

set(ALIFE_SHARED_ALIFE_ALIFE_MONSTER_BRAIN ../../engine/xrServerEntities/alife_monster_brain.cpp
                                           ../../engine/xrServerEntities/alife_monster_brain.h
                                           ../../engine/xrServerEntities/alife_monster_brain_inline.h)

set(ALIFE_SPAWN_SPAWN_PATCHER spawn_patcher.cpp
                              spawn_patcher.h)

set(ALIFE_SPAWN_GAME_SPAWN_CONSTRUCTOR game_spawn_constructor.cpp
                                       game_spawn_constructor.h
                                       game_spawn_constructor_inline.h)

set(ALIFE_SHARED_BUFFER_VECTOR buffer_vector.cpp)

set(ALIFE_SEARCH_PATH_MANAGERS path_manager.h)

set(ALIFE_SHARED ../../engine/xrServerEntities/restriction_space.h)

set(ALIFE_SPAWN_PATROL_PATHS_PATROL_POINT patrol_point.cpp
                                          patrol_point.h
                                          patrol_point_inline.h)

set(ALIFE_SHARED_OBJECTBROKER ../../engine/xrServerEntities/object_broker.h
                              ../../engine/xrServerEntities/object_cloner.h
                              ../../engine/xrServerEntities/object_comparer.h
                              ../../engine/xrServerEntities/object_destroyer.h
                              ../../engine/xrServerEntities/object_interfaces.h
                              ../../engine/xrServerEntities/object_loader.h
                              ../../engine/xrServerEntities/object_saver.h
                              ../../engine/xrServerEntities/object_type_traits.h)

set(ALIFE_SPAWN_LEVEL_SPAWN_CONSTRUCTOR level_spawn_constructor.cpp
                                        level_spawn_constructor.h
                                        level_spawn_constructor_inline.h)

set(ALIFE_SEARCH_DATA_STORAGES_VERTEX_ALLOCATORS_FIXED vertex_allocator_fixed.h
                                                       vertex_allocator_fixed_inline.h)

set(ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_LEVEL_PATH_MANAGER_LEVEL_STRAIGHT_LINE path_manager_level_straight_line.h
                                                                                   path_manager_level_straight_line_inline.h)

set(ALIFE_SHARED_SERVER ../../engine/xrServerEntities/PHNetState.cpp
                        ../../engine/xrServerEntities/PHSynchronize.cpp
                        ../../engine/xrServerEntities/game_base_space.h
                        ../../engine/xrServerEntities/PHNetState.h
                        ../../engine/xrServerEntities/PHSynchronize.h
                        ../../engine/xrServerEntities/xrMessages.h
                        NET_Compressor.h)

set(ALIFE_SHARED_ALIFE_ALIFE_HUMAN_BRAIN ../../engine/xrServerEntities/alife_human_brain.cpp
                                         ../../engine/xrServerEntities/alife_human_brain.h
                                         ../../engine/xrServerEntities/alife_human_brain_inline.h)

set(COMPILER_KERNEL_RANDOM32 random32.cpp
                             random32.h)

set(ALIFE_SEARCH_ALGORITHMS_DIJKSTRA dijkstra.h
                                     dijkstra_inline.h)

set(ALIFE_SEARCH_DATA_STORAGES_VERTEX_MANAGERS_HASH_FIXED vertex_manager_hash_fixed.h
                                                          vertex_manager_hash_fixed_inline.h)

set(ALIFE_CROSS xrCrossTable.cpp
                xrCrossTable.h)

set(ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_LEVEL_PATH_MANAGER_LEVEL_EVALUATOR path_manager_level_evaluator.h
                                                                               path_manager_level_evaluator_inline.h)

set(ALIFE_SHARED_INTRUSIVEPTR intrusive_ptr.h
                              intrusive_ptr_inline.h)

set(COMPILER_KERNEL_GENERIC_CDB cl_collector.cpp
                                cl_collector.h
                                cl_intersect.h)

set(ALIFE_SPAWN_PATROL_PATHS_PATROL_PATH patrol_path.cpp
                                         patrol_path.h
                                         patrol_path_inline.h)

set(ALIFE_SPAWN_SERVER_ENTITY_WRAPPER server_entity_wrapper.cpp
                                      server_entity_wrapper.h
                                      server_entity_wrapper_inline.h)

set(ALIFE_SEARCH_DATA_STORAGES_ALGORITHMS_PRIORITY_QUEUES_BINARY_HEAP data_storage_binary_heap.h
                                                                      data_storage_binary_heap_inline.h)

set(ALIFE_SEARCH_DATA_STORAGES_VERTEX_MANAGERS_FIXED vertex_manager_fixed.h
                                                     vertex_manager_fixed_inline.h)

set(ALIFE_MERGE xr_graph_merge.cpp
                xr_graph_merge.h)

set(ALIFE_SPAWN spawn_constructor_space.h)

set(COMPILER compiler.cpp
             compiler_build.cpp
             compiler_cover.cpp
             compiler_display.cpp
             compiler_light.cpp
             compiler_load.cpp
             compiler_save.cpp
             compiler_smooth.cpp
             motion_simulator.cpp
             ../../engine/xrEngine/xrLoadSurface.cpp
             AIMapExport.h
             compiler.h
             ETextureParams.h
             motion_simulator.h
             Shader_xrLC.h)

set(COMPILER_KERNEL_GENERIC _d3d_extensions.h
                            light.h
                            std_classes.h)

set(ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_GAME_PATH_MANAGER_GAME_LEVEL path_manager_game_level.h
                                                                         path_manager_game_level_inline.h)

set(ALIFE_GUID_GENERATOR guid_generator.cpp
                         guid_generator.h)

set(COMPILER_COVER_POINT cover_point.h
                         cover_point_inline.h)

set(ALIFE_SEARCH_GRAPHS_ABSTRACT_GRAPH_GRAPH_EDGE graph_edge.h
                                                  graph_edge_inline.h)

set(ALIFE_SHARED_SERVERENTITIES ../../engine/xrServerEntities/xrServer_Object_Base.cpp
                                ../../engine/xrServerEntities/xrServer_Objects.cpp
                                ../../engine/xrServerEntities/xrServer_Objects_Abstract.cpp
                                ../../engine/xrServerEntities/xrServer_Objects_ALife.cpp
                                ../../engine/xrServerEntities/xrServer_Objects_ALife_Items.cpp
                                ../../engine/xrServerEntities/xrServer_Objects_ALife_Monsters.cpp
                                ../../engine/xrServerEntities/character_info_defs.h
                                ../../engine/xrServerEntities/InfoPortionDefs.h
                                ../../engine/xrServerEntities/inventory_space.h
                                ../../engine/xrServerEntities/ItemListTypes.h
                                ../../engine/xrServerEntities/PropertiesListTypes.h
                                ../../engine/xrServerEntities/script_export_space.h
                                ../../engine/xrServerEntities/script_value_container.h
                                ../../engine/xrServerEntities/script_value_container_impl.h
                                ../../engine/xrServerEntities/ShapeData.h
                                ../../engine/xrServerEntities/WaveForm.h
                                ../../engine/xrServerEntities/xrEProps.h
                                ../../engine/xrServerEntities/xrServer_Object_Base.h
                                ../../engine/xrServerEntities/xrServer_Objects.h
                                ../../engine/xrServerEntities/xrServer_Objects_Abstract.h
                                ../../engine/xrServerEntities/xrServer_Objects_ALife.h
                                ../../engine/xrServerEntities/xrServer_Objects_ALife_All.h
                                ../../engine/xrServerEntities/xrServer_Objects_ALife_Items.h
                                ../../engine/xrServerEntities/xrServer_Objects_ALife_Monsters.h
                                ../../engine/xrServerEntities/xrServer_Space.h
                                bone.h)

set(COMPILER_KERNEL_LOG cl_log.cpp
                        cl_log.h)

set(ALIFE_SEARCH_DATA_STORAGES_ALGORITHMS_LISTS_SINGLE_LINKED_LIST data_storage_single_linked_list.h
                                                                   data_storage_single_linked_list_inline.h)

set(ALIFE_SEARCH_GRAPHS_ABSTRACT_GRAPH_GRAPH_VERTEX graph_vertex.h
                                                    graph_vertex_inline.h)

set(ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_LEVEL_PATH_MANAGER_LEVEL_FLOODER path_manager_level_flooder.h
                                                                             path_manager_level_flooder_inline.h)

set(ALIFE_SEARCH_GRAPHS_CROSS_TABLE game_level_cross_table.h
                                    game_level_cross_table_inline.h)

set(ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_PARAMS path_manager_params.h
                                                   path_manager_params_flooder.h
                                                   path_manager_params_game_level.h
                                                   path_manager_params_straight_line.h)

set(ALIFE_SEARCH_GRAPHS_ABSTRACT_GRAPH graph_abstract.h
                                       graph_abstract_inline.h)

set(ALIFE_SHARED_ASSOCIATIVE_VECTOR ../../engine/xrServerEntities/associative_vector.h
                                    ../../engine/xrServerEntities/associative_vector_compare_predicate.h
                                    ../../engine/xrServerEntities/associative_vector_compare_predicate_inline.h
                                    ../../engine/xrServerEntities/associative_vector_inline.h)

set(ALIFE_SPAWN_LEVEL_SPAWN_CONSTRUCTOR_SPACE_RESTRICTOR_WRAPPER space_restrictor_wrapper.cpp
                                                                 space_restrictor_wrapper.h
                                                                 space_restrictor_wrapper_inline.h)

set(ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_GAME_PATH_MANAGER_GAME_VERTEX_TYPE path_manager_game_vertex_type.h
                                                                               path_manager_game_vertex_type_inline.h)

set(ALIFE_SEARCH_ALGORITHMS_ASTAR a_star.h
                                  a_star_inline.h)

set(ALIFE_GRAPH game_graph_builder.cpp
                game_graph_builder.h
                game_graph_builder_inline.h)

set(ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_GAME path_manager_game.h
                                                 path_manager_game_inline.h)

set(ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_LEVEL path_manager_level.h
                                                  path_manager_level_inline.h)

set(ALIFE_SEARCH_DATA_STORAGES_ALGORITHMS_LISTS_BUCKET_LIST data_storage_bucket_list.h
                                                            data_storage_bucket_list_inline.h)

set(COMPILER_KERNEL StdAfx.cpp
                    tga.cpp
                    xrAI.cpp
                    xrThread.cpp
                    defines.h
                    factory_api.h
                    StdAfx.h
                    tga.h
                    xrAI.h
                    xrShaderTypes.h
                    xrThread.h)

set(ALIFE_SEARCH_DATA_STORAGES_ALGORITHMS_LISTS_DOUBLE_LINKED_LIST data_storage_double_linked_list.h
                                                                   data_storage_double_linked_list_inline.h)

set(ALIFE_VERIFY verify_level_graph.cpp)

file(GLOB MGC mgc/*.h mgc/*.cpp)

source_group("ALife\\search\\graphs\\level_graph" FILES ${ALIFE_SEARCH_GRAPHS_LEVEL_GRAPH})
source_group("ALife\\search\\data_storages\\data_storage_constructors" FILES ${ALIFE_SEARCH_DATA_STORAGES_DATA_STORAGE_CONSTRUCTORS})
source_group("ALife\\Shared\\ALife\\alife_space" FILES ${ALIFE_SHARED_ALIFE_ALIFE_SPACE})
source_group("ALife\\search\\graphs\\game_graph" FILES ${ALIFE_SEARCH_GRAPHS_GAME_GRAPH})
source_group("ALife\\search\\data_storages\\path_builders\\vertex_path" FILES ${ALIFE_SEARCH_DATA_STORAGES_PATH_BUILDERS_VERTEX_PATH})
source_group("Compiler\\quad_tree" FILES ${COMPILER_QUAD_TREE})
source_group("ALife\\search\\path_managers\\path_manager_generic" FILES ${ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_GENERIC})
source_group("ALife\\search\\data_storages\\data_storage_constructors\\manager_builder_allocator" FILES ${ALIFE_SEARCH_DATA_STORAGES_DATA_STORAGE_CONSTRUCTORS_MANAGER_BUILDER_ALLOCATOR})
source_group("ALife\\Shared\\ALife\\alife_artefact_order" FILES ${ALIFE_SHARED_ALIFE_ALIFE_ARTEFACT_ORDER})
source_group("ALife\\search\\data_storages\\data_storage_constructors\\builder_allocator" FILES ${ALIFE_SEARCH_DATA_STORAGES_DATA_STORAGE_CONSTRUCTORS_BUILDER_ALLOCATOR})
source_group("Compiler\\Kernel\\Resource Files" FILES ${COMPILER_KERNEL_RESOURCE_FILES})
source_group("ALife\\search\\data_storages\\path_builders\\edge_path" FILES ${ALIFE_SEARCH_DATA_STORAGES_PATH_BUILDERS_EDGE_PATH})
source_group("ALife\\Spawn\\patrol_paths\\patrol_path_storage" FILES ${ALIFE_SPAWN_PATROL_PATHS_PATROL_PATH_STORAGE})
source_group("ALife\\Shared\\Common" FILES ${ALIFE_SHARED_COMMON})
source_group("ALife\\search\\graph_engine" FILES ${ALIFE_SEARCH_GRAPH_ENGINE})
source_group("ALife\\Shared\\ALife\\alife_monster_brain" FILES ${ALIFE_SHARED_ALIFE_ALIFE_MONSTER_BRAIN})
source_group("ALife\\Spawn\\spawn_patcher" FILES ${ALIFE_SPAWN_SPAWN_PATCHER})
source_group("ALife\\Spawn\\game_spawn_constructor" FILES ${ALIFE_SPAWN_GAME_SPAWN_CONSTRUCTOR})
source_group("ALife\\Shared\\buffer_vector" FILES ${ALIFE_SHARED_BUFFER_VECTOR})
source_group("ALife\\search\\path_managers" FILES ${ALIFE_SEARCH_PATH_MANAGERS})
source_group("ALife\\Shared" FILES ${ALIFE_SHARED})
source_group("ALife\\Spawn\\patrol_paths\\patrol_point" FILES ${ALIFE_SPAWN_PATROL_PATHS_PATROL_POINT})
source_group("ALife\\Shared\\ObjectBroker" FILES ${ALIFE_SHARED_OBJECTBROKER})
source_group("ALife\\Spawn\\level_spawn_constructor" FILES ${ALIFE_SPAWN_LEVEL_SPAWN_CONSTRUCTOR})
source_group("ALife\\search\\data_storages\\vertex_allocators\\fixed" FILES ${ALIFE_SEARCH_DATA_STORAGES_VERTEX_ALLOCATORS_FIXED})
source_group("ALife\\search\\path_managers\\path_manager_level\\path_manager_level_straight_line" FILES ${ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_LEVEL_PATH_MANAGER_LEVEL_STRAIGHT_LINE})
source_group("ALife\\Shared\\Server" FILES ${ALIFE_SHARED_SERVER})
source_group("ALife\\Shared\\ALife\\alife_human_brain" FILES ${ALIFE_SHARED_ALIFE_ALIFE_HUMAN_BRAIN})
source_group("Compiler\\Kernel\\Random32" FILES ${COMPILER_KERNEL_RANDOM32})
source_group("ALife\\search\\algorithms\\Dijkstra" FILES ${ALIFE_SEARCH_ALGORITHMS_DIJKSTRA})
source_group("ALife\\search\\data_storages\\vertex_managers\\hash_fixed" FILES ${ALIFE_SEARCH_DATA_STORAGES_VERTEX_MANAGERS_HASH_FIXED})
source_group("ALife\\Cross" FILES ${ALIFE_CROSS})
source_group("ALife\\search\\path_managers\\path_manager_level\\path_manager_level_evaluator" FILES ${ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_LEVEL_PATH_MANAGER_LEVEL_EVALUATOR})
source_group("ALife\\Shared\\IntrusivePtr" FILES ${ALIFE_SHARED_INTRUSIVEPTR})
source_group("Compiler\\Kernel\\Generic\\CDB" FILES ${COMPILER_KERNEL_GENERIC_CDB})
source_group("ALife\\Spawn\\patrol_paths\\patrol_path" FILES ${ALIFE_SPAWN_PATROL_PATHS_PATROL_PATH})
source_group("ALife\\Spawn\\server_entity_wrapper" FILES ${ALIFE_SPAWN_SERVER_ENTITY_WRAPPER})
source_group("ALife\\search\\data_storages\\algorithms\\priority_queues\\binary_heap" FILES ${ALIFE_SEARCH_DATA_STORAGES_ALGORITHMS_PRIORITY_QUEUES_BINARY_HEAP})
source_group("ALife\\search\\data_storages\\vertex_managers\\fixed" FILES ${ALIFE_SEARCH_DATA_STORAGES_VERTEX_MANAGERS_FIXED})
source_group("ALife\\Merge" FILES ${ALIFE_MERGE})
source_group("ALife\\Spawn" FILES ${ALIFE_SPAWN})
source_group("Compiler" FILES ${COMPILER})
source_group("Compiler\\Kernel\\Generic" FILES ${COMPILER_KERNEL_GENERIC})
source_group("ALife\\search\\path_managers\\path_manager_game\\path_manager_game_level" FILES ${ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_GAME_PATH_MANAGER_GAME_LEVEL})
source_group("ALife\\guid_generator" FILES ${ALIFE_GUID_GENERATOR})
source_group("Compiler\\cover_point" FILES ${COMPILER_COVER_POINT})
source_group("ALife\\search\\graphs\\abstract_graph\\graph_edge" FILES ${ALIFE_SEARCH_GRAPHS_ABSTRACT_GRAPH_GRAPH_EDGE})
source_group("ALife\\Shared\\ServerEntities" FILES ${ALIFE_SHARED_SERVERENTITIES})
source_group("Compiler\\Kernel\\Log" FILES ${COMPILER_KERNEL_LOG})
source_group("ALife\\search\\data_storages\\algorithms\\lists\\single_linked_list" FILES ${ALIFE_SEARCH_DATA_STORAGES_ALGORITHMS_LISTS_SINGLE_LINKED_LIST})
source_group("ALife\\search\\graphs\\abstract_graph\\graph_vertex" FILES ${ALIFE_SEARCH_GRAPHS_ABSTRACT_GRAPH_GRAPH_VERTEX})
source_group("ALife\\search\\path_managers\\path_manager_level\\path_manager_level_flooder" FILES ${ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_LEVEL_PATH_MANAGER_LEVEL_FLOODER})
source_group("ALife\\search\\graphs\\cross_table" FILES ${ALIFE_SEARCH_GRAPHS_CROSS_TABLE})
source_group("ALife\\search\\path_managers\\path_manager_params" FILES ${ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_PARAMS})
source_group("ALife\\search\\graphs\\abstract_graph" FILES ${ALIFE_SEARCH_GRAPHS_ABSTRACT_GRAPH})
source_group("ALife\\Shared\\associative_vector" FILES ${ALIFE_SHARED_ASSOCIATIVE_VECTOR})
source_group("ALife\\Spawn\\level_spawn_constructor\\space_restrictor_wrapper" FILES ${ALIFE_SPAWN_LEVEL_SPAWN_CONSTRUCTOR_SPACE_RESTRICTOR_WRAPPER})
source_group("ALife\\search\\path_managers\\path_manager_game\\path_manager_game_vertex_type" FILES ${ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_GAME_PATH_MANAGER_GAME_VERTEX_TYPE})
source_group("ALife\\search\\algorithms\\A*" FILES ${ALIFE_SEARCH_ALGORITHMS_ASTAR})
source_group("ALife\\Graph" FILES ${ALIFE_GRAPH})
source_group("ALife\\search\\path_managers\\path_manager_game" FILES ${ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_GAME})
source_group("ALife\\search\\path_managers\\path_manager_level" FILES ${ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_LEVEL})
source_group("ALife\\search\\data_storages\\algorithms\\lists\\bucket_list" FILES ${ALIFE_SEARCH_DATA_STORAGES_ALGORITHMS_LISTS_BUCKET_LIST})
source_group("Compiler\\Kernel" FILES ${COMPILER_KERNEL})
source_group("ALife\\search\\data_storages\\algorithms\\lists\\double_linked_list" FILES ${ALIFE_SEARCH_DATA_STORAGES_ALGORITHMS_LISTS_DOUBLE_LINKED_LIST})
source_group("ALife\\Verify" FILES ${ALIFE_VERIFY})
source_group("mgc" FILES ${MGC})

include_directories(${DXSDK_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}
                    ../../engine/xrServerEntities ../../3rd-party/luajit/include)
link_directories(${DXSDK_LIB_DIR} ../../lib)

add_definitions(-DAI_COMPILER -D_SECURE_SCL=0)

add_compile_options("/Yustdafx.h" /fp:fast /GR "/Zc:forScope-")
set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)

add_executable(xrAI ${ALIFE_SEARCH_DATA_STORAGES_ALGORITHMS_LISTS_SINGLE_LINKED_LIST}
                    ${COMPILER_KERNEL_LOG}
                    ${COMPILER_COVER_POINT}
                    ${ALIFE_SPAWN_LEVEL_SPAWN_CONSTRUCTOR}
                    ${ALIFE_SPAWN_GAME_SPAWN_CONSTRUCTOR}
                    ${ALIFE_SEARCH_DATA_STORAGES_DATA_STORAGE_CONSTRUCTORS_MANAGER_BUILDER_ALLOCATOR}
                    ${ALIFE_SPAWN_SERVER_ENTITY_WRAPPER}
                    ${ALIFE_SPAWN_PATROL_PATHS_PATROL_PATH_STORAGE}
                    ${COMPILER}
                    ${ALIFE_SPAWN_PATROL_PATHS_PATROL_POINT}
                    ${ALIFE_SEARCH_GRAPHS_ABSTRACT_GRAPH_GRAPH_VERTEX}
                    ${ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_LEVEL_PATH_MANAGER_LEVEL_EVALUATOR}
                    ${ALIFE_SHARED_OBJECTBROKER}
                    ${ALIFE_SHARED_ALIFE_ALIFE_ARTEFACT_ORDER}
                    ${ALIFE_SHARED_SERVERENTITIES}
                    ${ALIFE_SEARCH_DATA_STORAGES_ALGORITHMS_LISTS_BUCKET_LIST}
                    ${ALIFE_CROSS}
                    ${ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_GAME_PATH_MANAGER_GAME_VERTEX_TYPE}
                    ${ALIFE_SEARCH_PATH_MANAGERS}
                    ${ALIFE_SEARCH_DATA_STORAGES_VERTEX_ALLOCATORS_FIXED}
                    ${ALIFE_SEARCH_DATA_STORAGES_VERTEX_MANAGERS_FIXED}
                    ${ALIFE_SEARCH_ALGORITHMS_DIJKSTRA}
                    ${ALIFE_SPAWN}
                    ${ALIFE_SEARCH_DATA_STORAGES_ALGORITHMS_LISTS_DOUBLE_LINKED_LIST}
                    ${COMPILER_KERNEL_GENERIC_CDB}
                    ${ALIFE_SHARED_ALIFE_ALIFE_MONSTER_BRAIN}
                    ${ALIFE_GRAPH}
                    ${COMPILER_KERNEL_RANDOM32}
                    ${ALIFE_SHARED_BUFFER_VECTOR}
                    ${ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_GAME}
                    ${ALIFE_SEARCH_GRAPHS_LEVEL_GRAPH}
                    ${COMPILER_QUAD_TREE}
                    ${ALIFE_SEARCH_GRAPHS_GAME_GRAPH}
                    ${ALIFE_GUID_GENERATOR}
                    ${ALIFE_SEARCH_GRAPHS_CROSS_TABLE}
                    ${ALIFE_SEARCH_GRAPHS_ABSTRACT_GRAPH_GRAPH_EDGE}
                    ${ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_GENERIC}
                    ${ALIFE_SHARED_INTRUSIVEPTR}
                    ${ALIFE_SPAWN_SPAWN_PATCHER}
                    ${ALIFE_SEARCH_DATA_STORAGES_PATH_BUILDERS_VERTEX_PATH}
                    ${ALIFE_SPAWN_PATROL_PATHS_PATROL_PATH}
                    ${COMPILER_KERNEL_GENERIC}
                    ${ALIFE_SHARED}
                    ${COMPILER_KERNEL}
                    ${ALIFE_SHARED_ASSOCIATIVE_VECTOR}
                    ${COMPILER_KERNEL_RESOURCE_FILES}
                    ${ALIFE_SEARCH_GRAPHS_ABSTRACT_GRAPH}
                    ${ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_LEVEL_PATH_MANAGER_LEVEL_FLOODER}
                    ${ALIFE_MERGE}
                    ${ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_LEVEL_PATH_MANAGER_LEVEL_STRAIGHT_LINE}
                    ${ALIFE_SPAWN_LEVEL_SPAWN_CONSTRUCTOR_SPACE_RESTRICTOR_WRAPPER}
                    ${ALIFE_SHARED_SERVER}
                    ${ALIFE_SHARED_COMMON}
                    ${ALIFE_SHARED_ALIFE_ALIFE_SPACE}
                    ${ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_LEVEL}
                    ${ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_GAME_PATH_MANAGER_GAME_LEVEL}
                    ${ALIFE_SEARCH_DATA_STORAGES_VERTEX_MANAGERS_HASH_FIXED}
                    ${ALIFE_SEARCH_ALGORITHMS_ASTAR}
                    ${ALIFE_SEARCH_PATH_MANAGERS_PATH_MANAGER_PARAMS}
                    ${ALIFE_SEARCH_DATA_STORAGES_PATH_BUILDERS_EDGE_PATH}
                    ${ALIFE_SEARCH_DATA_STORAGES_ALGORITHMS_PRIORITY_QUEUES_BINARY_HEAP}
                    ${ALIFE_SEARCH_DATA_STORAGES_DATA_STORAGE_CONSTRUCTORS}
                    ${ALIFE_SHARED_ALIFE_ALIFE_HUMAN_BRAIN}
                    ${ALIFE_VERIFY}
                    ${ALIFE_SEARCH_DATA_STORAGES_DATA_STORAGE_CONSTRUCTORS_BUILDER_ALLOCATOR}
                    ${ALIFE_SEARCH_GRAPH_ENGINE}
                    ${MGC})
set_target_properties(xrAI PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
target_link_libraries(xrAI xrCore xrCDB luabind FreeImage rpcrt4 comctl32 d3dx9 winmm imagehlp)