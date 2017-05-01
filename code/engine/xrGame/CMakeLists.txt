cmake_minimum_required(VERSION 3.8)

project(xrGame)

set(CORE_CLIENT_OBJECTS_ZONES_CUSTOMZONE CustomZone.h
                                         CustomZone.cpp)

set(CORE_CLIENT_LEVEL_LEVELNETWORKDEMO DemoInfo.h
                                       DemoInfo_Loader.h
                                       DemoPlay_Control.h
                                       Level_network_Demo.h
                                       Message_Filter.h
                                       DemoInfo.cpp
                                       DemoInfo_Loader.cpp
                                       DemoPLay_Control.cpp
                                       Level_network_Demo.cpp
                                       Message_Filter.cpp)

set(AI_ALIFE_INTERACTION_MANAGER alife_interaction_manager.h
                                 alife_interaction_manager_inline.h
                                 alife_interaction_manager.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_RPG7 WeaponRPG7.h
                                                                         WeaponRPG7.cpp
                                                                         WeaponRPG7_script.cpp)

set(AI_ALIFE_SERVER_ENTITIES_CREATURE_ABSTRACT alife_creature_abstract.cpp)

set(CORE_SERVER_SERVERENTITIES_OBJECTS_ALIFE ../xrServerEntities/xrServer_Objects_ALife.h
                                             ../xrServerEntities/xrServer_Objects_ALife.cpp
                                             ../xrServerEntities/xrServer_Objects_ALife_script.cpp
                                             ../xrServerEntities/xrServer_Objects_ALife_script2.cpp
                                             ../xrServerEntities/xrServer_Objects_ALife_script3.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DEVICES_TORCH Torch.h
                                                          Torch.cpp
                                                          torch_script.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_TABCONTROL ui/UITabButton.h
                                                     ui/UITabControl.h
                                                     ui/UITabButton.cpp
                                                     ui/UITabControl.cpp
                                                     ui/UITabControl_script.cpp)

set(AI_ACOMPONENTS_DAMAGEMANAGER damage_manager.h
                                 damage_manager_inline.h
                                 damage_manager.cpp)

set(AI_AGROUP_AGENT_MANAGER_AGENT_MEMBER_MANAGER_MEMBER_ORDER member_order.h
                                                              member_order_inline.h)

set(AI_ACOVER_SMART_COVER_STORAGE smart_cover_storage.h
                                  smart_cover_storage.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_WALTHER_99 WeaponWalther.h
                                                                                      WeaponWalther.cpp)

set(AI_AMONSTERS_MONSTERS_CONTROLLER_BASE_CONTROLLERS_ANIMATION ai/Monsters/Controller/controller_animation.h
                                                                ai/Monsters/Controller/controller_animation.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR_ANIMATION_PLANNER_COVER_ACTIONS smart_cover_planner_actions.h
                                                                                                                smart_cover_planner_actions_inline.h
                                                                                                                smart_cover_planner_actions.cpp)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_STEAL_SQUAD_REST ai/Monsters/States/monster_state_squad_rest.h
                                                        ai/Monsters/States/monster_state_squad_rest_follow.h
                                                        ai/Monsters/States/monster_state_squad_rest_follow_inline.h
                                                        ai/Monsters/States/monster_state_squad_rest_inline.h)

set(CORE_SERVER_GAMES_SERVER game_sv_base.h
                             game_sv_base_console_vars.h
                             game_sv_event_queue.h
                             game_sv_item_respawner.h
                             xr_time.h
                             game_sv_base.cpp
                             game_sv_base_console_vars.cpp
                             game_sv_event_queue.cpp
                             game_sv_item_respawner.cpp
                             xr_time.cpp)

set(AI_ANAVIGATION_PATHFINDING_DATASTORAGES_PRIORITY_QUEUES data_storage_double_linked_list.h
                                                            data_storage_double_linked_list_inline.h
                                                            data_storage_single_linked_list.h
                                                            data_storage_single_linked_list_inline.h)

set(AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_JUMP ai/Monsters/control_jump.h
                                                               ai/Monsters/control_jump.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_MONSTER_ACTION script_monster_action.h
                                                                 script_monster_action_inline.h
                                                                 script_monster_action.cpp
                                                                 script_monster_action_script.cpp)

set(AI_AMONSTERS_MONSTERS_CAT ai/Monsters/Cat/cat.h
                              ai/Monsters/Cat/cat_state_manager.h
                              ai/Monsters/Cat/cat.cpp
                              ai/Monsters/Cat/cat_state_manager.cpp)

set(AI_AGROUP_AGENT_MANAGER_AGENT_PLANNER_ACTIONS agent_manager_actions.h
                                                  agent_manager_actions.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTEFFECTOR_SCRIPTEFFECTORWRAPPER script_effector_wrapper.h
                                                                  script_effector_wrapper_inline.h
                                                                  script_effector_wrapper.cpp)

set(AI_ALIFE_SERVER_ENTITIES_TRADER_ABSTRACT alife_trader_abstract.cpp)

set(AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_WORLDPROPERTYEVALUATOR_MEMBER property_evaluator_member.h
                                                                                     property_evaluator_member_inline.h)

set(AI_AEVAL_FUNCTIONS_BASE ef_base.h)

set(AI_ACOMPONENTS_MOVEMENTMANAGER_LOCATIONSELECTORS_ABSTRACTLOCATIONSELECTOR abstract_location_selector.h
                                                                              abstract_location_selector_inline.h)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_RG6 WeaponRG6.h
                                                                               WeaponRG6.cpp
                                                                               WeaponRG6_script.cpp)

set(AI_AMONSTERS_MONSTERS_DOG ai/Monsters/Dog/dog.h
                              ai/Monsters/Dog/dog_state_manager.h
                              ai/Monsters/Dog/dog.cpp
                              ai/Monsters/Dog/dog_state_manager.cpp)

set(AI_ACOMPONENTS_DECISIONMANAGEMENT wrapper_abstract.h
                                      wrapper_abstract_inline.h)

set(AI_ACOMPONENTS_SOUNDPLAYER sound_player.h
                               sound_player_inline.h
                               sound_player.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_BY_SOUND stalker_danger_by_sound_planner.h
                                                                              stalker_danger_by_sound_planner.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DEVICES_DETECTORS ui/ArtefactDetectorUI.h
                                                              CustomDetector.h
                                                              ui/ArtefactDetectorUI.cpp
                                                              CustomDetector.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_AUTOMATIC WeaponMagazined.h
                                                                            WeaponMagazinedWGrenade.h
                                                                            WeaponMagazined.cpp
                                                                            WeaponMagazinedWGrenade.cpp)

set(CORE_CLIENT_OBJECTS_PHYSICS_CLIMABLE ClimableObject.h
                                         ClimableObject.cpp)

set(AI_ALIFE_SERVER_ENTITIES_OBJECT alife_object.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA_FACTIONWAR ui/FactionState.h
                                                      ui/FactionState_inline.h
                                                      ui/UIFactionWarWnd.h
                                                      ui/UIWarState.h
                                                      ui/FactionState.cpp
                                                      ui/UIFactionWarWnd.cpp
                                                      ui/UIWarState.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_BASE_RESTRICTION stalker_movement_restriction.h
                                                                 stalker_movement_restriction_inline.h)

set(CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_AI_OBSTACLE_MIN_OBB min_obb.cpp)

set(AI_ALIFE_INVENTORY_UPGRADE_PROPERTY inventory_upgrade_property.h
                                        inventory_upgrade_property_inline.h
                                        inventory_upgrade_property.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_PM WeaponPM.h
                                                                       WeaponPM.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTFS fs_registrator.h
                                      fs_registrator_script.cpp)

set(AI_AMONSTERS_MONSTERS_BURER ai/Monsters/Burer/burer.h
                                ai/Monsters/Burer/burer_state_manager.h
                                ai/Monsters/Burer/burer.cpp
                                ai/Monsters/Burer/burer_state_manager.cpp)

set(CORE_CLIENT_CAMERAS CameraFirstEye.h
                        cameralook.h
                        CameraFirstEye.cpp
                        cameralook.cpp)

set(AI_AMONSTERS_MONSTERS_CONTROLLER_SCRIPT ai/Monsters/Controller/controller_script.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_STATIONARYMGUN WeaponStatMgun.h
                                                                   WeaponStatMgun.cpp
                                                                   WeaponStatMgunFire.cpp
                                                                   WeaponStatMgunIR.cpp)

set(CORE_COMMON_PROFILER profiler.h
                         profiler_inline.h
                         profiler.cpp)

set(AI_AMONSTERS_HUMANS_TRADER Ai/Trader/ai_trader.h
                               ai/trader/trader_animation.h
                               Ai/Trader/ai_trader.cpp
                               ai/trader/ai_trader_script.cpp
                               ai/trader/trader_animation.cpp)

set(CORE_CLIENT_OBJECTS_INVENTORY_ATTACHMENTOWNER attachment_owner.h
                                                  attachment_owner_inline.h
                                                  attachment_owner.cpp)

set(AI_ALIFE_SERVER_ENTITIES_GROUP_ABSTRACT alife_group_abstract.cpp)

set(AI_AGROUP_AGENT_MANAGER_AGENT_LOCATION_MANAGER agent_location_manager.h
                                                   agent_location_manager_inline.h
                                                   agent_location_manager.cpp)

set(CORE_COMMON_SHARED ../xrServerEntities/shared_data.h)

set(AI_AMONSTERS_COMMON_BASE_MONSTER ai/Monsters/BaseMonster/base_monster.h
                                     ai/Monsters/BaseMonster/base_monster_inline.h
                                     ai/Monsters/BaseMonster/base_monster.cpp
                                     ai/Monsters/BaseMonster/base_monster_anim.cpp
                                     ai/Monsters/BaseMonster/base_monster_debug.cpp
                                     ai/Monsters/BaseMonster/base_monster_feel.cpp
                                     ai/Monsters/BaseMonster/base_monster_misc.cpp
                                     ai/Monsters/BaseMonster/base_monster_net.cpp
                                     ai/Monsters/BaseMonster/base_monster_path.cpp
                                     ai/Monsters/BaseMonster/base_monster_script.cpp
                                     ai/Monsters/BaseMonster/base_monster_startup.cpp
                                     ai/Monsters/BaseMonster/base_monster_think.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_THREATEN ai/Monsters/control_threaten.h
                                                                   ai/Monsters/control_threaten.cpp)

set(AI_ASCRIPT_SCRIPTTHREAD_SCRIPTSTACKTRACKER ../xrServerEntities/script_stack_tracker.h
                                               ../xrServerEntities/script_stack_tracker_inline.h
                                               ../xrServerEntities/script_stack_tracker.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_ABILITIES_INVISIBILITY ai/Monsters/invisibility.h
                                                          ai/Monsters/invisibility.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_EXPLOSIVES ExplosiveItem.h
                                                       wallmark_manager.h
                                                       Explosive.cpp
                                                       ExplosiveItem.cpp
                                                       ExplosiveScript.cpp
                                                       wallmark_manager.cpp)

set(CORE_COMMON_RANDOM_32BIT random32.h
                             random32.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_ADDONS_SCOPE Scope.h
                                                                               Scope.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_TRACKBAR ui/UITrackBar.h
                                                   ui/UITrackButton.h
                                                   ui/UITrackBar.cpp
                                                   ui/UITrackButton.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTMONSTERHITINFO script_monster_hit_info.h
                                                  script_monster_hit_info_script.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_ABILITIES_CONTROLLED ai/Monsters/controlled_entity.h
                                                        ai/Monsters/controlled_entity_inline.h)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTBINDEROBJECT_SCRIPTBINDEROBJECTWRAPPER script_binder_object_wrapper.h
                                                                          script_binder_object_wrapper.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER_SCRIPT stalker_animation_script.h
                                                        stalker_animation_script_inline.h)

set(CORE_SERVER_GAMES_CLIENT_SINGLE game_cl_single.h
                                    game_cl_single.cpp)

set(AI_AMONSTERS_MONSTERS_POLTERGEIST ai/Monsters/Poltergeist/poltergeist.h
                                      ai/Monsters/Poltergeist/poltergeist_movement.h
                                      ai/Monsters/Poltergeist/poltergeist_state_manager.h
                                      ai/Monsters/Poltergeist/poltergeist_state_rest.h
                                      ai/Monsters/Poltergeist/poltergeist.cpp
                                      ai/Monsters/Poltergeist/poltergeist_movement.cpp
                                      ai/Monsters/Poltergeist/poltergeist_state_manager.cpp)

set(AI_ANAVIGATION_GAMEGRAPH game_graph.h
                             game_graph_inline.h
                             ../xrServerEntities/game_graph_space.h
                             game_graph_script.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_OBSTACLES_OBSTACLE_AVOIDERS_DYNAMIC dynamic_obstacles_avoider.h
                                                                                    dynamic_obstacles_avoider_inline.h
                                                                                    dynamic_obstacles_avoider.cpp)

set(AI_AMONSTERS_MONSTERS_BURER_ATTACK ai/Monsters/Burer/burer_state_attack.h
                                       ai/monsters/burer/burer_state_attack_antiaim.h
                                       ai/monsters/burer/burer_state_attack_antiaim_inline.h
                                       ai/Monsters/Burer/burer_state_attack_gravi.h
                                       ai/Monsters/Burer/burer_state_attack_gravi_inline.h
                                       ai/Monsters/Burer/burer_state_attack_inline.h
                                       ai/Monsters/Burer/burer_state_attack_melee.h
                                       ai/Monsters/Burer/burer_state_attack_melee_inline.h
                                       ai/Monsters/Burer/burer_state_attack_run_around.h
                                       ai/Monsters/Burer/burer_state_attack_run_around_inline.h
                                       ai/monsters/burer/burer_state_attack_shield.h
                                       ai/monsters/burer/burer_state_attack_shield_inline.h
                                       ai/Monsters/Burer/burer_state_attack_tele.h
                                       ai/Monsters/Burer/burer_state_attack_tele_inline.h)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTPARTICLES script_particles.h
                                             script_particles_inline.h
                                             script_particles.cpp
                                             script_particles_script.cpp)

set(AI_AMONSTERS_COMMON_CUSTOM CustomMonster.h
                               CustomMonster_inline.h
                               CustomMonster.cpp
                               CustomMonster_VCPU.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_VAL WeaponVal.h
                                                                               WeaponVal.cpp)

set(CORE_COMMON_CONSOLE_COMMANDS console_commands.cpp)

set(AI_AMONSTERS_COMMON_SCRIPT_SCRIPT_OBJECT script_object.h
                                             script_object.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_ACRIPT_ANIMATION_ACTION script_animation_action.h
                                                                   script_animation_action_inline.h
                                                                   script_animation_action.cpp
                                                                   script_animation_action_script.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_LISTBOX ui/UIListBox.h
                                                  ui/UIListBoxItem.h
                                                  ui/UIListBoxItemMsgChain.h
                                                  ui/UIListBox.cpp
                                                  ui/UIListBox_script.cpp
                                                  ui/UIListBoxItem.cpp
                                                  ui/UIListBoxItemMsgChain.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_CRITICALWOUND ai/Monsters/control_critical_wound.h
                                                                        ai/Monsters/control_critical_wound.cpp)

set(AI_AMONSTERS_MONSTERS_BLOODSUCKER_CAPTURE_JUMP ai/monsters/bloodsucker/bloodsucker_state_capture_jump.h
                                                   ai/monsters/bloodsucker/bloodsucker_state_capture_jump_inline.h)

set(CORE_COMMON_OBJECTFACTORY ../xrServerEntities/clsid_game.h
                              ../xrServerEntities/object_factory.h
                              ../xrServerEntities/object_factory_impl.h
                              ../xrServerEntities/object_factory_inline.h
                              ../xrServerEntities/object_factory_space.h
                              ../xrServerEntities/object_factory.cpp
                              ../xrServerEntities/object_factory_register.cpp
                              ../xrServerEntities/object_factory_script.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_ANOMALY stalker_anomaly_planner.h
                                                              stalker_anomaly_planner.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTINIFILE_SCRIPTTOKENLIST ../xrServerEntities/script_token_list.h
                                                           ../xrServerEntities/script_token_list_inline.h
                                                           ../xrServerEntities/script_token_list.cpp
                                                           ../xrServerEntities/script_token_list_script.cpp)

set(CORE_SERVER_GAMES_CLIENT_BASE game_cl_base.h
                                  game_cl_base_weapon_usage_statistic.h
                                  game_cl_base.cpp
                                  game_cl_base_weapon_usage_statistic.cpp
                                  game_cl_base_weapon_usage_statistic_save.cpp)

set(CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_AI_OBSTACLE ai_obstacle.h
                                                    ai_obstacle_inline.h
                                                    ai_obstacle.cpp)

set(AI_AMONSTERS_MONSTERS_PSEUDOGIGANT ai/Monsters/PseudoGigant/pseudo_gigant.h
                                       ai/Monsters/PseudoGigant/pseudo_gigant_step_effector.h
                                       ai/Monsters/PseudoGigant/pseudogigant_state_manager.h
                                       ai/Monsters/PseudoGigant/pseudo_gigant.cpp
                                       ai/Monsters/PseudoGigant/pseudo_gigant_step_effector.cpp
                                       ai/Monsters/PseudoGigant/pseudogigant_state_manager.cpp)

set(CORE_COMMON_OBJECTFACTORY_OBJECT_ITEM_CLIENT_SERVER ../xrServerEntities/object_item_client_server.h
                                                        ../xrServerEntities/object_item_client_server_inline.h)

set(CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYITEM inventory_item.h
                                                inventory_item_impl.h
                                                inventory_item_inline.h
                                                inventory_item.cpp
                                                inventory_item_upgrade.cpp)

set(AI_ANAVIGATION_GRAPHABSTRACT_GRAPHEDGE graph_edge.h
                                           graph_edge_inline.h)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_GENERAL_LOOK ai/Monsters/States/state_look_point.h
                                                    ai/Monsters/States/state_look_point_inline.h
                                                    ai/Monsters/States/state_look_unprotected_area.h
                                                    ai/Monsters/States/state_look_unprotected_area_inline.h)

set(AI_ALIFE_INVENTORY_UPGRADE_UPGRADE_BASE inventory_upgrade_base.h
                                            inventory_upgrade_base_inline.h
                                            inventory_upgrade_base.cpp)

set(CORE_CLIENT_OBJECTS_VEHICLES_HELI helicopter.h
                                      Helicopter.cpp
                                      Helicopter2.cpp
                                      helicopter_script.cpp
                                      HelicopterMovementManager.cpp
                                      HelicopterWeapon.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS Artefact.h
                                                      artefact_activation.h
                                                      Artefact.cpp
                                                      artefact_activation.cpp
                                                      artefact_script.cpp)

set(AI_AMONSTERS_MONSTERS_BOAR ai/Monsters/Boar/boar.h
                               ai/Monsters/Boar/boar_state_manager.h
                               ai/Monsters/Boar/boar.cpp
                               ai/Monsters/Boar/boar_state_manager.cpp)

set(CORE_CLIENT_OBJECTS_ZONES_GRAVIZONE GraviZone.h
                                        GraviZone.cpp)

set(AI_ALIFE_SIMULATOR_BASE_REGISTRIES_SPAWN_REGISTRY alife_spawn_registry.h
                                                      alife_spawn_registry_inline.h
                                                      alife_spawn_registry.cpp
                                                      alife_spawn_registry_spawn.cpp)

set(AI_ACOVER_SMART_COVER_STORAGE_DESCRIPTION smart_cover_description.h
                                              smart_cover_description_inline.h
                                              smart_cover_description.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_WINDOWS ui/UIDialogWnd.h
                                                  ui/UIFrameLineWnd.h
                                                  ui/UIFrameWindow.h
                                                  ui/UIWindow.h
                                                  ui/UIDialogWnd.cpp
                                                  ui/UIFrameLineWnd.cpp
                                                  ui/UIFrameWindow.cpp
                                                  ui/UIWindow.cpp
                                                  ui/UIWindow_script.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_INVENTORYUTILITIES ui/UIHelper.h
                                                          ui/UIInventoryUtilities.h
                                                          ui/UIHelper.cpp
                                                          ui/UIInventoryUtilities.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS stalker_base_action.h
                                                      stalker_base_action.cpp)

set(AI_AMONSTERS_MONSTERS_CONTROLLER_STATE_ATTACK_COVER ai/Monsters/Controller/controller_state_attack_camp.h
                                                        ai/Monsters/Controller/controller_state_attack_camp_inline.h
                                                        ai/Monsters/Controller/controller_state_attack_fire.h
                                                        ai/Monsters/Controller/controller_state_attack_fire_inline.h
                                                        ai/Monsters/Controller/controller_state_attack_hide.h
                                                        ai/Monsters/Controller/controller_state_attack_hide_inline.h
                                                        ai/Monsters/Controller/controller_state_attack_hide_lite.h
                                                        ai/Monsters/Controller/controller_state_attack_hide_lite_inline.h
                                                        ai/Monsters/Controller/controller_state_attack_moveout.h
                                                        ai/Monsters/Controller/controller_state_attack_moveout_inline.h)

set(CORE_CLIENT_OBJECTS_PHYSICS_SCRIPTS physics_element_scripted.h
                                        physics_joint_scripted.h
                                        physics_shell_scripted.h
                                        physics_world_scripted.h
                                        physics_element_scripted.cpp
                                        physics_joint_scripted.cpp
                                        physics_shell_scripted.cpp
                                        physics_world_scripted.cpp)

set(AI_ACOMPONENTS_OBJECTHANDLER_PLANNER_ACTIONS object_actions.h
                                                 object_actions_inline.h
                                                 object_actions.cpp)

set(CORE_CLIENT_OBJECTS_PHYSICS_CHARACTERSUPPORT_HIT_ANIMS character_hit_animations.h
                                                           character_hit_animations_params.h
                                                           character_hit_animations.cpp)

set(CORE_COMMON_OBJECTFACTORY_OBJECT_ITEM_SCRIPT ../xrServerEntities/object_item_script.h
                                                 ../xrServerEntities/object_item_script.cpp)

set(AI_AGROUP_AGENT_MANAGER_AGENT_EXPLOSIVE_MANAGER agent_explosive_manager.h
                                                    agent_explosive_manager_inline.h
                                                    agent_explosive_manager.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_FADED_BALL FadedBall.h
                                                                 FadedBall.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_ABILITIES_SCAN ai/Monsters/scanning_ability.h
                                                  ai/Monsters/scanning_ability_inline.h)

set(AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONPLANNER action_planner.h
                                                                     action_planner_inline.h
                                                                     action_planner_script.cpp)

set(AI_ANAVIGATION_PATHFINDING_DATASTORAGES_CONSTRUCTORS data_storage_constructor.h)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_SCRIPTWND ui/UIScriptWnd.h
                                                    ui/uiscriptwnd_script.h
                                                    ui/UIScriptWnd.cpp
                                                    ui/UIScriptWnd_script.cpp
                                                    ui/uiscriptwnd_script2.cpp)

set(AI_ALIFE_SIMULATOR_BASE_REGISTRIES_GRAPH_REGISTRY alife_graph_registry.h
                                                      alife_graph_registry_inline.h
                                                      alife_graph_registry.cpp)

set(AI_AMONSTERS_COMMON_SCRIPT_SCRIPT_ENTITY script_entity.h
                                             script_entity_inline.h
                                             script_entity_space.h
                                             script_entity.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER ai/Monsters/control_com_defs.h
                                                   ai/Monsters/control_combase.h
                                                   ai/Monsters/control_manager.h
                                                   ai/Monsters/control_manager_custom.h
                                                   ai/Monsters/control_manager.cpp
                                                   ai/Monsters/control_manager_custom.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_HOME ai/Monsters/monster_home.h
                                        ai/Monsters/monster_home.cpp)

set(AI_ALIFE_SERVER_ENTITIES_DYNAMIC_OBJECT alife_dynamic_object.cpp)

set(CORE_SERVER_SERVERPERFORM xrServer_perform_GameExport.cpp
                              xrServer_perform_migration.cpp
                              xrServer_perform_RPgen.cpp
                              xrServer_perform_sls_default.cpp
                              xrServer_perform_sls_load.cpp
                              xrServer_perform_sls_save.cpp
                              xrServer_perform_transfer.cpp
                              xrServer_secure_messaging.cpp
                              xrServer_sls_clear.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTHIT script_hit.h
                                       script_hit_inline.h
                                       script_hit.cpp
                                       script_hit_script.cpp)

set(AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_WORLDPROPERTYEVALUATOR_SCRIPTPROPERTYEVALUATORWRAPPER script_property_evaluator_wrapper.h
                                                                                                             script_property_evaluator_wrapper_inline.h
                                                                                                             script_property_evaluator_wrapper.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_OBSTACLES_OBSTACLE_AVOIDERS_STATIC static_obstacles_avoider.h
                                                                                   static_obstacles_avoider_inline.h
                                                                                   static_obstacles_avoider.cpp)

set(AI_AMONSTERS_MONSTERS_BLOODSUCKER_PREDATOR_STATE ai/Monsters/Bloodsucker/bloodsucker_predator.h
                                                     ai/Monsters/Bloodsucker/bloodsucker_predator_inline.h
                                                     ai/Monsters/Bloodsucker/bloodsucker_predator_lite.h
                                                     ai/Monsters/Bloodsucker/bloodsucker_predator_lite_inline.h)

set(AI_AMONSTERS_MONSTERS_DOGPSY ai/Monsters/Pseudodog/psy_dog.h
                                 ai/Monsters/Pseudodog/psy_dog_aura.h
                                 ai/Monsters/Pseudodog/psy_dog_state_manager.h
                                 ai/Monsters/Pseudodog/psy_dog.cpp
                                 ai/Monsters/Pseudodog/psy_dog_aura.cpp
                                 ai/Monsters/Pseudodog/psy_dog_state_manager.cpp)

set(AI_ACOMPONENTS_SOUNDPLAYER_SOUND_COLLECTION_STORAGE sound_collection_storage.h
                                                        sound_collection_storage_inline.h
                                                        sound_collection_storage.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER stalker_animation_manager.h
                                                 stalker_animation_manager_impl.h
                                                 stalker_animation_manager_inline.h
                                                 stalker_animation_callbacks.cpp
                                                 stalker_animation_global.cpp
                                                 stalker_animation_head.cpp
                                                 stalker_animation_legs.cpp
                                                 stalker_animation_manager.cpp
                                                 stalker_animation_manager_debug.cpp
                                                 stalker_animation_manager_update.cpp
                                                 stalker_animation_script.cpp
                                                 stalker_animation_torso.cpp)

set(CORE_COMMON_NET_SHARED NET_Queue.h
                           ../xrServerEntities/xrMessages.h)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DOCUMENTS InfoDocument.h
                                                      InfoDocument.cpp)

set(AI_AEVAL_FUNCTIONS_PRIMARY ef_primary.h
                               ef_primary.cpp)

set(AI_AMONSTERS_MONSTERS_TUSHKANO_SCRIPT ai/Monsters/Tushkano/tushkano_script.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_VINTOREZ WeaponVintorez.h
                                                                                    WeaponVintorez.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DEVICES_DETECTORS_ELITEDETECTOR EliteDetector.h
                                                                            EliteDetector.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_ALIFE_TASK_ACTIONS stalker_alife_task_actions.h
                                                                         stalker_alife_task_actions.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA ui/UIPdaWnd.h
                                           ui/UIPdaWnd.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DEVICES_DETECTORS_ADVANCEDDETECTOR AdvancedDetector.h
                                                                               AdvancedDetector.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_PURE_COMS_ANIMATION ai/Monsters/control_animation.h
                                                                       ai/Monsters/control_animation.cpp)

set(AI_ALIFE_SIMULATOR_BASE_TIME_MANAGER alife_time_manager.h
                                         alife_time_manager_inline.h
                                         alife_time_manager.cpp)

set(AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTION space_restriction.h
                                                            space_restriction_inline.h
                                                            space_restriction.cpp)

set(AI_AMONSTERS_MONSTERS_CHIMERA_SCRIPT ai/Monsters/Chimera/chimera_script.cpp)

set(AI_ACOVER_SMART_COVER_DETAIL smart_cover_detail.h
                                 smart_cover_detail.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_MAININGAME ui/UICarPanel.h
                                                  ui/UIHudStatesWnd.h
                                                  ui/UIMainIngameWnd.h
                                                  ui/UIMessagesWindow.h
                                                  ui/UIMoneyIndicator.h
                                                  ui/UIMotionIcon.h
                                                  ui/UIPdaMsgListItem.h
                                                  UIZoneMap.h
                                                  ui/UIGameLog.h
                                                  ui/UICarPanel.cpp
                                                  ui/UIHudStatesWnd.cpp
                                                  ui/UIMainIngameWnd.cpp
                                                  ui/UIMessagesWindow.cpp
                                                  ui/UIMoneyIndicator.cpp
                                                  ui/UIMotionIcon.cpp
                                                  ui/UIPdaMsgListItem.cpp
                                                  UIZoneMap.cpp
                                                  ui/UIGameLog.cpp)

set(AI_AGROUP_AGENT_MANAGER agent_manager.h
                            agent_manager_inline.h
                            agent_manager_space.h
                            agent_manager.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_BLACKDROPS BlackDrops.h
                                                                 BlackDrops.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTCALLBACKEX script_callback_ex.h
                                              script_callback_ex_generators.h
                                              script_callback_ex_inline.h
                                              script_callback_ex_nonvoid.h
                                              script_callback_ex_void.h)

set(AI_AMONSTERS_MONSTERS_SNORK_SCRIPT ai/Monsters/Snork/snork_script.cpp)

set(AI_ANAVIGATION_PATHFINDING_DATASTORAGES_PRIORITY_QUEUES_BUCKET_LIST data_storage_bucket_list.h
                                                                        data_storage_bucket_list_inline.h)

set(AI_ALIFE_SIMULATOR_BASE_REGISTRY_CONTAINER alife_registry_container.h
                                               alife_registry_container_composition.h
                                               alife_registry_container_inline.h
                                               alife_registry_container_space.h
                                               alife_registry_wrappers.h
                                               alife_registry_container.cpp)

set(CORE_CLIENT_OBJECTS_ZONES_FRYUPZONE FryupZone.h
                                        FryupZone.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTSOUNDTYPE ../xrServerEntities/script_sound_type.h
                                             ../xrServerEntities/script_sound_type_script.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_UI_ITEM_INFOS ui/ui_af_params.h
                                                     ui/UIBoosterInfo.h
                                                     ui/UIItemInfo.h
                                                     ui/UIOutfitInfo.h
                                                     ui/UIWpnParams.h
                                                     ui/ui_af_params.cpp
                                                     ui/UIBoosterInfo.cpp
                                                     ui/UIItemInfo.cpp
                                                     ui/UIOutfitInfo.cpp
                                                     ui/UIWpnParams.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_GRENADES__AND__MISSILES Grenade.h
                                                                                          Missile.h
                                                                                          Grenade.cpp
                                                                                          Missile.cpp)

set(AI_ALIFE_INVENTORY_UPGRADE_UPGRADE_GROUP inventory_upgrade_group.h
                                             inventory_upgrade_group_inline.h
                                             inventory_upgrade_group.cpp)

set(CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_TRADE_PARAMETERS_TRADE_BOOL_PARAMETERS trade_bool_parameters.h
                                                                                        trade_bool_parameters_inline.h)

set(AI_AGROUP_AGENT_MANAGER_AGENT_MEMBER_MANAGER agent_member_manager.h
                                                 agent_member_manager_inline.h
                                                 agent_member_manager.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR_ANIMATION_PLANNER_TARGET_SELECTOR_TARGET_PROVIDER smart_cover_planner_target_provider.h
                                                                                                                                  smart_cover_planner_target_provider.cpp)

set(AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_PARAMS path_manager_params.h
                                                                path_manager_params_flooder.h
                                                                path_manager_params_game_level.h
                                                                path_manager_params_game_vertex.h
                                                                path_manager_params_nearest_vertex.h
                                                                path_manager_params_straight_line.h)

set(AI_ACOMPONENTS_OBJECTHANDLER object_handler.h
                                 object_handler_inline.h
                                 object_handler_space.h
                                 object_handler.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_BY_SOUND_ACTIONS stalker_danger_by_sound_actions.h
                                                                                      stalker_danger_by_sound_actions.cpp)

set(CORE_CLIENT_OBJECTS_ZONES_CAMPFIRE ZoneCampfire.h
                                       ZoneCampfire.cpp)

set(AI_ACOVER_COVER_POINT cover_point.h
                          cover_point_inline.h
                          cover_point_script.cpp)

set(CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_HOLDER_PARTICLESPLAYER ParticlesPlayer.h
                                                               ParticlesPlayer.cpp)

set(CORE_CLIENT_LEVEL_SENIORITYHIERARCHYHOLDER_TEAMHIERARCHYHOLDER team_hierarchy_holder.h
                                                                   team_hierarchy_holder_inline.h
                                                                   team_hierarchy_holder.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_PROGRESSBAR ui/UIDoubleProgressBar.h
                                                      ui/UIProgressBar.h
                                                      ui/UIProgressShape.h
                                                      ui/UIDoubleProgressBar.cpp
                                                      ui/UIProgressBar.cpp
                                                      ui/UIProgressBar_script.cpp
                                                      ui/UIProgressShape.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_THORNARTIFACT ThornArtifact.h
                                                                    ThornArtifact.cpp)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_ALIFE ai/Monsters/States/monster_state_smart_terrain_task.h
                                             ai/Monsters/States/monster_state_smart_terrain_task_graph_walk.h
                                             ai/Monsters/States/monster_state_smart_terrain_task_graph_walk_inline.h
                                             ai/Monsters/States/monster_state_smart_terrain_task_inline.h)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_PROPERTIES stalker_danger_property_evaluators.h
                                                                        stalker_danger_property_evaluators.cpp)

set(CORE_SERVER_EDITOR ../xrServerEntities/ItemListTypes.h
                       ../xrServerEntities/WaveForm.h
                       ../xrServerEntities/xrEProps.h)

set(AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_PROPERTYSTORAGE property_storage.h
                                                                       property_storage_inline.h
                                                                       property_storage_script.cpp)

set(CORE_CLIENT_OBJECTS_INVENTORY_ATTACHABLEITEM attachable_item.h
                                                 attachable_item_inline.h
                                                 attachable_item.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTRENDERDEVICE script_render_device.h
                                                script_render_device_script.cpp)

set(CORE_CLIENT_OBJECTS_VEHICLES_CAR Car.h
                                     CarDamageParticles.h
                                     CarLights.h
                                     Car.cpp
                                     CarCameras.cpp
                                     CarDamageParticles.cpp
                                     CarDoors.cpp
                                     CarExhaust.cpp
                                     CarInput.cpp
                                     CarLights.cpp
                                     CarScript.cpp
                                     CarSound.cpp
                                     CarWheels.cpp
                                     DBG_Car.cpp)

set(CORE_CLIENT_OBJECTS_PHYSICS ../xrServerEntities/PHNetState.h
                                PHShellCreator.h
                                physics_game.h
                                PhysicsGamePars.h
                                ../xrServerEntities/PHNetState.cpp
                                PHShellCreator.cpp
                                physics_game.cpp
                                PhysicsGamePars.cpp)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_INTERESTING_SOUND ai/Monsters/States/monster_state_hear_int_sound.h
                                                         ai/Monsters/States/monster_state_hear_int_sound_inline.h)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_ROCKETLAUNCHER CustomRocket.h
                                                                                 ExplosiveRocket.h
                                                                                 RocketLauncher.h
                                                                                 CustomRocket.cpp
                                                                                 ExplosiveRocket.cpp
                                                                                 RocketLauncher.cpp)

set(AI_ACOMPONENTS_MEMORYMANAGER_RAW_DATA_MANAGERS_VISUALMEMORYMANAGER visual_memory_manager.h
                                                                       visual_memory_manager_inline.h
                                                                       visual_memory_manager.cpp)

set(CORE_CLIENT_GAME_PERSISTENT GamePersistent.h
                                GamePersistent.cpp)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_CONTROLLED ai/Monsters/States/monster_state_controlled.h
                                                  ai/Monsters/States/monster_state_controlled_attack.h
                                                  ai/Monsters/States/monster_state_controlled_attack_inline.h
                                                  ai/Monsters/States/monster_state_controlled_follow.h
                                                  ai/Monsters/States/monster_state_controlled_follow_inline.h
                                                  ai/Monsters/States/monster_state_controlled_inline.h)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_SHOTGUN WeaponShotgun.h
                                                                                   WeaponShotgun.cpp
                                                                                   weaponshotgun_script.cpp)

set(AI_ACOMPONENTS_MEMORYMANAGER_RAW_DATA_MANAGERS_VISUALMEMORYMANAGER_VISION_CLIENT vision_client.h
                                                                                     vision_client_inline.h
                                                                                     vision_client.cpp)

set(CORE_CLIENT_OBJECTS_ZONES_ZONEVISUAL ZoneVisual.h
                                         ZoneVisual.cpp)

set(CORE_CLIENT_OBJECTS_ZONES_SPACERESTRICTOR space_restrictor.h
                                              space_restrictor_inline.h
                                              space_restrictor.cpp
                                              space_restrictor_script.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_XML ui/UITextureMaster.h
                                              ui/UIXmlInit.h
                                              ui/xrUIXmlParser.h
                                              ui/UITextureMaster.cpp
                                              ui/UIXmlInit.cpp
                                              ui/xrUIXmlParser.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_KILL_WOUNDED stalker_kill_wounded_planner.h
                                                                          stalker_kill_wounded_planner.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_HUD HitMarker.h
                                    HUDManager.h
                                    HitMarker.cpp
                                    HUDManager.cpp)

set(CORE_CLIENT_OBJECTS_PHYSICS_COLLISIONDAMAGERECEIVER PHCollisionDamageReceiver.h
                                                        PHCollisionDamageReceiver.cpp)

set(AI_AMONSTERS_HUMANS_STALKER Ai/Stalker/ai_stalker.h
                                ai/stalker/ai_stalker_impl.h
                                ai/stalker/ai_stalker_inline.h
                                Ai/Stalker/ai_stalker_space.h
                                Ai/Stalker/ai_stalker.cpp
                                Ai/Stalker/ai_stalker_script.cpp)

set(AI_ALIFE_UPDATE_MANAGER_SURGE_MANAGER alife_surge_manager.h
                                          alife_surge_manager_inline.h
                                          alife_surge_manager.cpp)

set(AI_ACOMPONENTS_MEMORYMANAGER_CLSUTERIZED_DATA_MANAGERS_ENEMYMANAGER enemy_manager.h
                                                                        enemy_manager_inline.h
                                                                        enemy_manager.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_SVD WeaponSVD.h
                                                                        WeaponSVD.cpp)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_REST ai/Monsters/States/monster_state_rest.h
                                            ai/Monsters/States/monster_state_rest_fun.h
                                            ai/Monsters/States/monster_state_rest_fun_inline.h
                                            ai/Monsters/States/monster_state_rest_idle.h
                                            ai/Monsters/States/monster_state_rest_idle_inline.h
                                            ai/Monsters/States/monster_state_rest_inline.h
                                            ai/Monsters/States/monster_state_rest_sleep.h
                                            ai/Monsters/States/monster_state_rest_sleep_inline.h
                                            ai/Monsters/States/monster_state_rest_walk_graph.h
                                            ai/Monsters/States/monster_state_rest_walk_graph_inline.h)

set(AI_ALIFE_SIMULATOR_BASE_REGISTRIES_GROUP_REGISTRY alife_group_registry.h
                                                      alife_group_registry_inline.h
                                                      alife_group_registry.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_AUTOMATICSHOTGUN WeaponAutomaticShotgun.h
                                                                                            WeaponAutomaticShotgun.cpp)

set(AI_AMONSTERS_COMMON_STEERING_BEHAVIOURS steering_behaviour.h
                                            steering_behaviour.cpp)

set(CORE_CLIENT_OBJECTS_PHYSICS_DAMAGABLEITEM DamagableItem.h
                                              DamagableItem.cpp)

set(CORE_CLIENT_SPECTATOR_CAMERAS spectator_camera_first_eye.h
                                  spectator_camera_first_eye.cpp)

set(CORE_CLIENT_OBJECTS_INVENTORY_EATABLEITEM eatable_item.h
                                              eatable_item.cpp)

set(AI_AGROUP_AGENT_MANAGER_AGENT_LOCATION_MANAGER_DANGER_COVER_LOCATION danger_cover_location.h
                                                                         danger_cover_location_inline.h
                                                                         danger_cover_location.cpp)

set(AI_ACOMPONENTS_MOVEMENTMANAGER_RESTRICTEDOBJECT restricted_object.h
                                                    restricted_object_inline.h
                                                    restricted_object.cpp)

set(AI_AMONSTERS_MONSTERS_ZOMBIE_SCRIPT ai/Monsters/Zombie/zombie_script.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_GRENADE_F1 F1.h
                                                                               F1.cpp)

set(AI_ACOMPONENTS_MOVEMENTMANAGER_PATHMANAGERS_PATROLPATHMANAGER patrol_path_manager.h
                                                                  patrol_path_manager_inline.h
                                                                  patrol_path_manager_space.h
                                                                  patrol_path_manager.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_ABILITIES_PSY_AURA ai/Monsters/psy_aura.h
                                                      ai/Monsters/psy_aura.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_FOOD__AND__DRUGS antirad.h
                                                             BottleItem.h
                                                             FoodItem.h
                                                             medkit.h
                                                             antirad.cpp
                                                             BottleItem.cpp
                                                             FoodItem.cpp
                                                             medkit.cpp)

set(CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_HOLDER holder_custom.h
                                               holder_custom.cpp
                                               holder_custom_script.cpp)

set(CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS_MAP map_location.h
                                               map_location_defs.h
                                               map_manager.h
                                               map_location.cpp
                                               map_manager.cpp)

set(CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT game_object_space.h
                                        GameObject.h
                                        GameObject.cpp)

set(AI_ACOMPONENTS_PROBLEMSOLVER_CONDITION_STATE_SCRIPTWORLDSTATE script_world_state.h
                                                                  script_world_state_script.cpp)

set(CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS_NEWS game_news.h
                                                game_news.cpp)

set(AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONBASE_SCRIPTACTIONWRAPPER script_action_wrapper.h
                                                                                      script_action_wrapper_inline.h
                                                                                      script_action_wrapper.cpp)

set(CORE_SERVER_SERVERENTITIES_OBJECTS_ALIFE_ITEMS ../xrServerEntities/xrServer_Objects_ALife_Items.h
                                                   ../xrServerEntities/xrServer_Objects_ALife_Items.cpp
                                                   ../xrServerEntities/xrServer_Objects_ALife_Items_script.cpp
                                                   ../xrServerEntities/xrServer_Objects_ALife_Items_script2.cpp
                                                   ../xrServerEntities/xrServer_Objects_ALife_Items_script3.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_ADDONS_SILENCER Silencer.h
                                                                                  Silencer.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_SQUAD_SQUAD_MANAGER ai/Monsters/ai_monster_squad_manager.h
                                                       ai/Monsters/ai_monster_squad_manager_inline.h
                                                       ai/Monsters/ai_monster_squad_manager.cpp)

set(CORE_SERVER_SERVERCONNECT xrServer_CL_connect.cpp
                              xrServer_CL_disconnect.cpp
                              xrServer_Connect.cpp
                              xrServer_Disconnect.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_LINES ui/UILine.h
                                                ui/UILines.h
                                                ui/uilinestd.h
                                                ui/UISubLine.h
                                                ui/UILine.cpp
                                                ui/UILines.cpp
                                                ui/UISubLine.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_UNKNOWN stalker_danger_unknown_planner.h
                                                                             stalker_danger_unknown_planner.cpp)

set(CORE_COMMON_SMARTCAST ../xrServerEntities/smart_cast.h
                          ../xrServerEntities/smart_cast_impl0.h
                          ../xrServerEntities/smart_cast_impl1.h
                          ../xrServerEntities/smart_cast_impl2.h
                          ../xrServerEntities/smart_cast.cpp
                          ../xrServerEntities/smart_cast_stats.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_OPTIONSITEM ui/UIOptionsItem.h
                                                   ui/UIOptionsManager.h
                                                   ui/UIOptionsManagerScript.h
                                                   ui/UIOptionsItem.cpp
                                                   ui/UIOptionsManager.cpp
                                                   ui/UIOptionsManagerScript.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_SEQUENCER ai/Monsters/control_sequencer.h
                                                                    ai/Monsters/control_sequencer.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_ELECTRIC_BALL ElectricBall.h
                                                                    ElectricBall.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTFLAGS ../xrServerEntities/script_flags.h
                                         ../xrServerEntities/script_flags_script.cpp)

set(CORE_CLIENT_LEVEL_CONTROLLER xr_level_controller.h
                                 xr_level_controller.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_ACTIONS stalker_combat_actions.h
                                                                     stalker_combat_actions.cpp)

set(CORE_CLIENT_EFFECTORS_MONSTERS_QQQ ai/Monsters/ai_monster_effector.h
                                       pp_effector_custom.h
                                       pp_effector_distance.h
                                       ai/Monsters/ai_monster_effector.cpp
                                       pp_effector_custom.cpp
                                       pp_effector_distance.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_BINOCULAR WeaponBinoculars.h
                                                                              WeaponBinocularsVision.h
                                                                              WeaponBinoculars.cpp
                                                                              WeaponBinoculars_script.cpp
                                                                              WeaponBinocularsVision.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_BUTTONS ui/UI3tButton.h
                                                  ui/UIBtnHint.h
                                                  ui/UIButton.h
                                                  ui/UICheckButton.h
                                                  ui/UIRadioButton.h
                                                  ui/UI3tButton.cpp
                                                  ui/UIBtnHint.cpp
                                                  ui/UIButton.cpp
                                                  ui/UIButton_script.cpp
                                                  ui/UICheckButton.cpp
                                                  ui/UIRadioButton.cpp)

set(AI_ASCRIPT_LUA_STUDIO ../xrServerEntities/lua_studio.h
                          ../xrServerEntities/lua_studio.cpp)

set(AI_ACOVER_SMART_COVER_STORAGE_DESCRIPTION_LOOPHOLE_ACTION smart_cover_action.h
                                                              smart_cover_action_inline.h
                                                              smart_cover_action.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR smart_cover_animation_selector.h
                                                                                smart_cover_animation_selector_inline.h
                                                                                smart_cover_animation_selector.cpp)

set(CORE_CLIENT_OBJECTS_PHYSICS_ANIMATION_MOVEMENT_CONTROLLER animation_movement_controller.h
                                                              poses_blending.h
                                                              animation_movement_controller.cpp
                                                              poses_blending.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_PROPERTIESBOX ui/UIPropertiesBox.h
                                                        ui/UIPropertiesBox.cpp
                                                        ui/UIPropertiesBox_script.cpp)

set(CORE_CLIENT_OBJECTS_BASE_ENTITYCONDITION EntityCondition.h
                                             hit_immunity.h
                                             hit_immunity_space.h
                                             Wound.h
                                             EntityCondition.cpp
                                             hit_immunity.cpp
                                             Wound.cpp)

set(CORE_CLIENT_EFFECTS_CORE DynamicHeightMap.h)

set(AI_ALIFE_SIMULATOR_BASE_REGISTRIES_SMART_TERRAIN_REGISTRY alife_smart_terrain_registry.h
                                                              alife_smart_terrain_registry_inline.h
                                                              alife_smart_terrain_registry.cpp)

set(CORE_CLIENT_OBJECTS_ZONES_SMARTZONE smart_zone.h)

set(AI_ACOMPONENTS_PROBLEMSOLVER_OPERATOR_CONDITION operator_condition.h
                                                    operator_condition_inline.h)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_SEARCH_PLANNER stalker_search_planner.h
                                                                            stalker_search_planner.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_FN2000 WeaponFN2000.h
                                                                           WeaponFN2000.cpp)

set(CORE_SERVER screenshot_server.h
                xrClientsPool.h
                xrServer.h
                xrServer_info.h
                ../xrServerEntities/xrServer_Space.h
                xrServer_updates_compressor.h
                xrServerMapSync.h
                screenshot_server.cpp
                xrClientsPool.cpp
                xrGame.cpp
                xrServer.cpp
                xrServer_balance.cpp
                xrServer_info.cpp
                xrServer_updates_compressor.cpp
                xrServerMapSync.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_ZUDAARTIFACT ZudaArtifact.h
                                                                   ZudaArtifact.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_HPSA WeaponHPSA.h
                                                                         WeaponHPSA.cpp
                                                                         WeaponHPSA_script.cpp)

set(AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_WORLDPROPERTYEVALUATOR property_evaluator.h
                                                                              property_evaluator_inline.h
                                                                              property_evaluator_script.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_IN_DIRECTION stalker_danger_in_direction_planner.h
                                                                                  stalker_danger_in_direction_planner.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_WEAPON_GENERIC CameraRecoil.h
                                                                                 first_bullet_controller.h
                                                                                 ShootingObject.h
                                                                                 Weapon.h
                                                                                 first_bullet_controller.cpp
                                                                                 ShootingObject.cpp
                                                                                 Weapon.cpp
                                                                                 WeaponDispersion.cpp
                                                                                 WeaponFire.cpp
                                                                                 WeaponUpgrade.cpp)

set(AI_ACOMPONENTS_MEMORYMANAGER_RAW_DATA_MANAGERS_SOUNDMEMORYMANAGER_SOUNDUSERDATAVISITOR sound_user_data_visitor.h)

set(AI_AMONSTERS_MONSTERS_ZOMBIE ai/Monsters/Zombie/zombie.h
                                 ai/Monsters/Zombie/zombie_state_manager.h
                                 ai/Monsters/Zombie/zombie.cpp
                                 ai/Monsters/Zombie/zombie_state_manager.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_PARTICLE_ACTION script_particle_action.h
                                                                  script_particle_action_inline.h
                                                                  script_particle_action.cpp
                                                                  script_particle_action_script.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_PROPERTIES stalker_property_evaluators.h
                                                         stalker_property_evaluators_inline.h
                                                         stalker_property_evaluators.cpp)

set(AI_ALIFE_SIMULATOR_BASE_SMART_TERRAIN_TASK alife_smart_terrain_task.h
                                               alife_smart_terrain_task_inline.h
                                               alife_smart_terrain_task.cpp
                                               alife_smart_terrain_task_script.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_HINT ui/UIHint.h
                                               ui/UIHint.cpp)

set(CORE_CLIENT_SPECTATOR Spectator.h
                          Spectator.cpp)

set(AI_AMONSTERS_MONSTERS_FRACTURE_SCRIPT ai/Monsters/Fracture/fracture_script.cpp)

set(CORE_CLIENT_PARTICLES ParticlesObject.h
                          ParticlesObject.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_ADDONS_GRENADELAUNCHER GrenadeLauncher.h
                                                                                         GrenadeLauncher.cpp)

set(AI_ACOMPONENTS_SIGHTMANAGER_SIGHT_ACTION sight_action.h
                                             sight_action_inline.h
                                             sight_action.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_SOUND_ACTION script_sound_action.h
                                                               script_sound_action_inline.h
                                                               script_sound_action.cpp
                                                               script_sound_action_script.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_STATIC ui/UIAnimatedStatic.h
                                                 ui/UILanimController.h
                                                 ui/UIStatic.h
                                                 UIStaticItem.h
                                                 ui/UIAnimatedStatic.cpp
                                                 ui/UILanimController.cpp
                                                 ui/UIStatic.cpp
                                                 ui/UIStatic_script.cpp
                                                 UIStaticItem.cpp)

set(AI_ACOMPONENTS_PROBLEMSOLVER_OPERATOR_CONDITION_SCRIPTWORLDPROPERTY script_world_property.h
                                                                        script_world_property_inline.h
                                                                        script_world_property_script.cpp)

set(CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_TRADE_PARAMETERS_PURCHASE_LIST purchase_list.h
                                                                                purchase_list_inline.h
                                                                                purchase_list.cpp)

set(AI_AGROUP_AGENT_MANAGER_AGENT_ENEMY_MANAGER agent_enemy_manager.h
                                                agent_enemy_manager_inline.h
                                                agent_enemy_manager.cpp)

set(AI_ACOMPONENTS_MOVEMENTMANAGER_PATHMANAGERS_DETAILPATHMANAGER detail_path_builder.h
                                                                  detail_path_manager.h
                                                                  detail_path_manager_inline.h
                                                                  detail_path_manager_space.h
                                                                  detail_path_manager.cpp
                                                                  detail_path_manager_smooth.cpp)

set(CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS_ENCYCLOPEDIA encyclopedia_article.h
                                                        encyclopedia_article_defs.h
                                                        encyclopedia_article.cpp)

set(AI_ALIFE_SIMULATOR_BASE alife_simulator_base.h
                            alife_simulator_base_inline.h
                            alife_simulator_base.cpp
                            alife_simulator_base2.cpp)

set(AI_AMONSTERS_MONSTERS_PHANTOM ai/phantom/phantom.h
                                  ai/phantom/phantom.cpp)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_DANGEROUS_SOUND ai/Monsters/States/monster_state_hear_danger_sound.h
                                                       ai/Monsters/States/monster_state_hear_danger_sound_inline.h)

set(CORE_SERVER_SERVERPROCESS xrServer_svclient_validation.h
                              xrServer_process_event.cpp
                              xrServer_process_event_activate.cpp
                              xrServer_process_event_destroy.cpp
                              xrServer_process_event_ownership.cpp
                              xrServer_process_event_reject.cpp
                              xrServer_process_spawn.cpp
                              xrServer_process_update.cpp
                              xrServer_svclient_validation.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_IN_DIRECTION_ACTIONS stalker_danger_in_direction_actions.h
                                                                                          stalker_danger_in_direction_actions.cpp)

set(AI_ALIFE_SIMULATOR_BASE_REGISTRIES_SPAWN_REGISTRY_SERVER_ENTITY_WRAPPER server_entity_wrapper.h
                                                                            server_entity_wrapper_inline.h
                                                                            server_entity_wrapper.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_KEYBINDINGS key_binding_registrator.h
                                         key_binding_registrator_script.cpp)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_GROUP_MONSTERS_HOME ai/monsters/group_states/group_state_attack.h
                                                           ai/monsters/group_states/group_state_attack_inline.h
                                                           ai/monsters/group_states/group_state_attack_run.h
                                                           ai/monsters/group_states/group_state_attack_run_inline.h
                                                           ai/monsters/group_states/group_state_custom.h
                                                           ai/monsters/group_states/group_state_custom_inline.h
                                                           ai/monsters/group_states/group_state_eat.h
                                                           ai/monsters/group_states/group_state_eat_drag.h
                                                           ai/monsters/group_states/group_state_eat_drag_inline.h
                                                           ai/monsters/group_states/group_state_eat_eat.h
                                                           ai/monsters/group_states/group_state_eat_eat_inline.h
                                                           ai/monsters/group_states/group_state_eat_inline.h
                                                           ai/monsters/group_states/group_state_hear_danger_sound.h
                                                           ai/monsters/group_states/group_state_hear_danger_sound_inline.h
                                                           ai/monsters/group_states/group_state_home_point_attack.h
                                                           ai/monsters/group_states/group_state_home_point_attack_inline.h
                                                           ai/monsters/group_states/group_state_panic.h
                                                           ai/monsters/group_states/group_state_panic_inline.h
                                                           ai/monsters/group_states/group_state_panic_run.h
                                                           ai/monsters/group_states/group_state_panic_run_inline.h
                                                           ai/monsters/group_states/group_state_rest.h
                                                           ai/monsters/group_states/group_state_rest_idle.h
                                                           ai/monsters/group_states/group_state_rest_idle_inline.h
                                                           ai/monsters/group_states/group_state_rest_inline.h
                                                           ai/monsters/group_states/group_state_squad_move_to_radius.h
                                                           ai/monsters/group_states/group_state_squad_move_to_radius_inline.h
                                                           ai/monsters/group_states/state_adapter.h)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_BLACKGRAVIARTIFACT BlackGraviArtifact.h
                                                                         BlackGraviArtifact.cpp)

set(AI_ANAVIGATION_GAMELEVELCROSSTABLE game_level_cross_table.h
                                       game_level_cross_table_inline.h)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_HITTED ai/Monsters/States/monster_state_hitted.h
                                              ai/Monsters/States/monster_state_hitted_hide.h
                                              ai/Monsters/States/monster_state_hitted_hide_inline.h
                                              ai/Monsters/States/monster_state_hitted_inline.h
                                              ai/Monsters/States/monster_state_hitted_moveout.h
                                              ai/Monsters/States/monster_state_hitted_moveout_inline.h)

set(AI_ALIFE_SERVER_ENTITIES_HUMAN_OBJECT_HANDLER alife_human_object_handler.h
                                                  alife_human_object_handler_inline.h
                                                  alife_human_object_handler_save.h
                                                  alife_human_object_handler.cpp)

set(AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTIONHOLDER_SPACERESTRICTIONSHAPE space_restriction_shape.h
                                                                                        space_restriction_shape_inline.h
                                                                                        space_restriction_shape.cpp)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_HELP_SOUND ai/Monsters/States/monster_state_help_sound.h
                                                  ai/Monsters/States/monster_state_help_sound_inline.h)

set(CORE_CLIENT_OBJECTS_PHYSICS_DESTROYABLEPHYSICSOBJECT DestroyablePhysicsObject.h
                                                         DestroyablePhysicsObject.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS callback_info.h
                                          ui/uiabstract.h
                                          ui/UIMessages.h
                                          ui/UIWndCallback.h
                                          ui/UIWndCallback.cpp)

set(CORE_COMMON_ASSOCIATIVE_VECTOR_VECTOR ../xrServerEntities/associative_vector.h
                                          ../xrServerEntities/associative_vector_inline.h)

set(CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_TRADE_PARAMETERS_TRADE_PARAMETERS trade_parameters.h
                                                                                   trade_parameters_inline.h
                                                                                   trade_parameters.cpp)

set(CORE_CLIENT_EFFECTORS_WEAPON EffectorShot.h
                                 EffectorShotX.h
                                 EffectorZoomInertion.h
                                 EffectorShot.cpp
                                 EffectorShotX.cpp
                                 EffectorZoomInertion.cpp)

set(AI_AGROUP_AGENT_MANAGER_AGENT_LOCATION_MANAGER_DANGER_OBJECT_LOCATION danger_object_location.h
                                                                          danger_object_location_inline.h
                                                                          danger_object_location.cpp)

set(AI_ALIFE_SERVER_ENTITIES_ONLINE_OFFLINE_GROUP_BRAIN alife_online_offline_group_brain.h
                                                        alife_online_offline_group_brain_inline.h
                                                        alife_online_offline_group_brain.cpp)

set(AI_ALIFE_INVENTORY_UPGRADE_UPGRADE inventory_upgrade.h
                                       inventory_upgrade_inline.h
                                       inventory_upgrade.cpp)

set(AI_AMONSTERS_MONSTERS_PSEUDODOG ai/Monsters/Pseudodog/pseudodog.h
                                    ai/Monsters/Pseudodog/pseudodog_psi_effector.h
                                    ai/Monsters/Pseudodog/pseudodog_state_manager.h
                                    ai/Monsters/Pseudodog/pseudodog.cpp
                                    ai/Monsters/Pseudodog/pseudodog_psi_effector.cpp
                                    ai/Monsters/Pseudodog/pseudodog_state_manager.cpp)

set(CORE_CLIENT_OBJECTS_ZONES_HAIRSZONE HairsZone.h
                                        HairsZone.cpp
                                        HairsZone_script.cpp)

set(CORE_SERVER_SERVERENTITIES ../xrServerEntities/gametype_chooser.h
                               ../xrServerEntities/PropertiesListTypes.h
                               ../xrServerEntities/ShapeData.h
                               ../xrServerEntities/xrServer_Objects_Abstract.h
                               ../xrServerEntities/xrServer_Objects_ALife_All.h
                               ../xrServerEntities/xrServer_script_macroses.h
                               ../xrServerEntities/gametype_chooser.cpp
                               ../xrServerEntities/xrServer_Factory.cpp
                               ../xrServerEntities/xrServer_Objects_Abstract.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_WATCH_ACTION script_watch_action.h
                                                               script_watch_action_inline.h
                                                               script_watch_action.cpp
                                                               script_watch_action_script.cpp)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_EAT_DRAG ai/Monsters/States/monster_state_eat_drag.h
                                                ai/Monsters/States/monster_state_eat_drag_inline.h)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_EAT_EATING ai/Monsters/States/monster_state_eat_eat.h
                                                  ai/Monsters/States/monster_state_eat_eat_inline.h)

set(AI_ALIFE_SERVER_ENTITIES_HUMAN_BRAIN ../xrServerEntities/alife_human_brain.h
                                         ../xrServerEntities/alife_human_brain_inline.h
                                         alife_human_brain_save.h
                                         ../xrServerEntities/alife_human_brain.cpp
                                         alife_human_brain_script.cpp)

set(AI_ACOMPONENTS_OBJECTHANDLER_PLANNER object_handler_planner.h
                                         object_handler_planner_impl.h
                                         object_handler_planner_inline.h
                                         object_handler_planner.cpp
                                         object_handler_planner_missile.cpp
                                         object_handler_planner_weapon.cpp)

set(AI_AMONSTERS_MONSTERS_BOAR_SCRIPT ai/Monsters/Boar/boar_script.cpp)

set(CORE_CLIENT_OBJECTS_PHYSICS_DEBUG PHDebug.h
                                      PHDebug.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_GAMETYPES_GAMECUSTOM UIGameCustom.h
                                                     UIGameCustom.cpp
                                                     UIGameCustom_script.cpp)

set(AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_GAME_VERTEX path_manager_game_vertex.h
                                                                     path_manager_game_vertex_inline.h)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_INVENTORY ui/UIActorMenu.h
                                                 ui/UIActorStateInfo.h
                                                 ui/UIActorMenu.cpp
                                                 ui/UIActorMenu_action.cpp
                                                 ui/UIActorMenu_script.cpp
                                                 ui/UIActorMenuDeadBodySearch.cpp
                                                 ui/UIActorMenuInitialize.cpp
                                                 ui/UIActorMenuInventory.cpp
                                                 ui/UIActorMenuTrade.cpp
                                                 ui/UIActorMenuUpgrade.cpp
                                                 ui/UIActorStateInfo.cpp)

set(AI_ALIFE_SIMULATOR_BASE_REGISTRIES_ABSTRACT_REGISTRY alife_abstract_registry.h
                                                         alife_abstract_registry_inline.h
                                                         alife_registry_wrapper.h)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_GRENADE stalker_danger_grenade_planner.h
                                                                             stalker_danger_grenade_planner.cpp)

set(AI_AMONSTERS_MONSTERS_FLESH ai/Monsters/Flesh/flesh.h
                                ai/Monsters/Flesh/flesh_state_manager.h
                                ai/Monsters/Flesh/flesh.cpp
                                ai/Monsters/Flesh/flesh_state_manager.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT stalker_combat_planner.h
                                                             stalker_combat_planner.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_GET_DISTANCE stalker_get_distance_planner.h
                                                                          stalker_get_distance_planner.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_AMMO WeaponAmmo.h
                                                                       WeaponAmmo.cpp)

set(AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT action_management_config.h)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_ANOMALY_ACTIONS stalker_anomaly_actions.h
                                                                      stalker_anomaly_actions.cpp)

set(CORE_CLIENT_LEVEL_LEVELMAPSYNC Level_network_map_sync.h
                                   Level_network_map_sync.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA_LOGS ui/UILogsWnd.h
                                                ui/UILogsWnd.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_SQUAD ai/Monsters/ai_monster_squad.h
                                         ai/Monsters/ai_monster_squad.cpp
                                         ai/Monsters/ai_monster_squad_attack.cpp
                                         ai/Monsters/ai_monster_squad_rest.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_STATE ai/Monsters/monster_state_manager.h
                                         ai/Monsters/monster_state_manager_inline.h
                                         ai/Monsters/state.h
                                         ai/Monsters/state_defs.h
                                         ai/Monsters/state_inline.h
                                         ai/Monsters/state_manager.h)

set(AI_ANAVIGATION_PATHFINDING_DATASTORAGES_PATH_BUILDERS_EDGE_PATH edge_path.h
                                                                    edge_path_inline.h)

set(AI_AGROUP_AGENT_MANAGER_AGENT_LOCATION_MANAGER_DANGER_LOCATION danger_location.h
                                                                   danger_location_inline.h
                                                                   danger_location.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_ALIFE_ACTIONS stalker_alife_actions.h
                                                                    stalker_alife_actions.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTFMATRIX ../xrServerEntities/script_fmatrix.h
                                           ../xrServerEntities/script_fmatrix_script.cpp)

set(AI_ANAVIGATION_PATROLPATHS_PATROLPOINT patrol_point.h
                                           patrol_point_inline.h
                                           patrol_point.cpp)

set(AI_AMONSTERS_MONSTERS_CONTROLLER_STATE_ATTACK ai/Monsters/Controller/controller_state_attack.h
                                                  ai/Monsters/Controller/controller_state_attack_fast_move.h
                                                  ai/Monsters/Controller/controller_state_attack_fast_move_inline.h
                                                  ai/Monsters/Controller/controller_state_attack_inline.h
                                                  ai/Monsters/Controller/controller_state_control_hit.h
                                                  ai/Monsters/Controller/controller_state_control_hit_inline.h
                                                  ai/Monsters/Controller/controller_tube.h
                                                  ai/Monsters/Controller/controller_tube_inline.h)

set(AI_ACOMPONENTS_MEMORYMANAGER memory_manager.h
                                 memory_manager_inline.h
                                 memory_space.h
                                 memory_space_impl.h
                                 memory_manager.cpp
                                 memory_space_script.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_CURSOR HUDCrosshair.h
                                       HUDTarget.h
                                       UICursor.h
                                       HUDCrosshair.cpp
                                       HUDTarget.cpp
                                       UICursor.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_UI_ITEM_INFOS_CHARACTERINFO ui/UICharacterInfo.h
                                                                   ui/UICharacterInfo.cpp)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_GENERAL_MOVEMENT ai/Monsters/States/state_hide_from_point.h
                                                        ai/Monsters/States/state_hide_from_point_inline.h
                                                        ai/Monsters/States/state_move_around_point.h
                                                        ai/Monsters/States/state_move_around_point_inline.h
                                                        ai/Monsters/States/state_move_to_point.h
                                                        ai/Monsters/States/state_move_to_point_inline.h
                                                        ai/Monsters/States/state_move_to_restrictor.h
                                                        ai/Monsters/States/state_move_to_restrictor_inline.h)

set(AI_ANAVIGATION_PATROLPATHS_PATROLPATH patrol_path.h
                                          patrol_path_inline.h
                                          patrol_path.cpp)

set(CORE_SERVER_SERVERENTITIES_SCRIPT_VALUE_CONTAINER ../xrServerEntities/script_value_container.h
                                                      ../xrServerEntities/script_value_container_impl.h)

set(AI_AMONSTERS_COMMON_COMPONENTS_ACTOR_CONTROLLER ai/Monsters/controlled_actor.h
                                                    ai/Monsters/controlled_actor.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON__DEBUG_FONTS ui/UIDebugFonts.h
                                                    ui/UIDebugFonts.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_OUTFIT ActorHelmet.h
                                                   BoneProtections.h
                                                   CustomOutfit.h
                                                   ExoOutfit.h
                                                   MilitaryOutfit.h
                                                   ScientificOutfit.h
                                                   StalkerOutfit.h
                                                   ActorHelmet.cpp
                                                   BoneProtections.cpp
                                                   CustomOutfit.cpp
                                                   ExoOutfit.cpp
                                                   MilitaryOutfit.cpp
                                                   ScientificOutfit.cpp
                                                   StalkerOutfit.cpp)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_PANIC ai/Monsters/States/monster_state_panic.h
                                             ai/Monsters/States/monster_state_panic_inline.h
                                             ai/Monsters/States/monster_state_panic_run.h
                                             ai/Monsters/States/monster_state_panic_run_inline.h)

set(AI_ACOMPONENTS_SIGHTMANAGER sight_manager.h
                                sight_manager_inline.h
                                sight_manager_space.h
                                sight_manager.cpp
                                sight_manager_target.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DEATH stalker_death_planner.h
                                                            stalker_death_planner.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_OBJECT_ACTION script_object_action.h
                                                                script_object_action_inline.h
                                                                script_object_action.cpp
                                                                script_object_action_script.cpp)

set(AI_AGROUP_AGENT_MANAGER_AGENT_CORPSE_MANAGER_MEMBER_CORPSE member_corpse.h
                                                               member_corpse_inline.h)

set(CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_AI_OBSTACLE_MIN_OBB_MINIMIZE_1D magic_minimize_1d.h
                                                                        magic_minimize_1d_inline.h
                                                                        magic_minimize_1d.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTINIFILE ../xrServerEntities/script_ini_file.h
                                           ../xrServerEntities/script_ini_file_inline.h
                                           ../xrServerEntities/script_ini_file.cpp
                                           ../xrServerEntities/script_ini_file_script.cpp)

set(CORE_CLIENT_OBJECTS_VEHICLES_CAR_CARWEAPON CarWeapon.h
                                               CarWeapon.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS ai/Monsters/ai_monster_defs.h
                                   ai/Monsters/ai_monster_shared_data.h
                                   ai/Monsters/ai_monster_utils.h
                                   ai/monsters/anti_aim_ability.h
                                   ai/monsters/monster_aura.h
                                   ai/Monsters/monster_corpse_manager.h
                                   ai/Monsters/monster_enemy_manager.h
                                   ai/Monsters/monster_sound_defs.h
                                   ai/Monsters/monster_velocity_space.h
                                   ai/Monsters/ai_monster_utils.cpp
                                   ai/monsters/anti_aim_ability.cpp
                                   ai/monsters/monster_aura.cpp
                                   ai/Monsters/monster_corpse_manager.cpp
                                   ai/Monsters/monster_enemy_manager.cpp)

set(AI_AMONSTERS_COMMON_STEERING_BEHAVIOURS_MANAGER steering_behaviour_manager.h)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_SCROLLBAR ui/UIFixedScrollBar.h
                                                    ui/UIScrollBar.h
                                                    ui/UIScrollBox.h
                                                    ui/UIFixedScrollBar.cpp
                                                    ui/UIScrollBar.cpp
                                                    ui/UIScrollBox.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_BASE_CONTROLLERS_ANIMATION ai/Monsters/control_animation_base.h
                                                                              ai/Monsters/control_animation_base.cpp
                                                                              ai/Monsters/control_animation_base_accel.cpp
                                                                              ai/Monsters/control_animation_base_load.cpp
                                                                              ai/Monsters/control_animation_base_update.cpp)

set(CORE_CLIENT_LEVEL_BULLET_MANAGER Level_Bullet_Manager.h
                                     Tracer.h
                                     Level_Bullet_Manager.cpp
                                     Level_bullet_manager_firetrace.cpp
                                     Tracer.cpp)

set(AI_AMONSTERS_MONSTERS_CONTROLLER_STATE_PANIC ai/Monsters/Controller/controller_state_panic.h
                                                 controller_state_panic_inline.h)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTEFFECTOR script_effector.h
                                            script_effector_inline.h
                                            script_effector.cpp
                                            script_effector_script.cpp)

set(CORE_CLIENT_LEVEL_CLIENTSPAWNMANAGER client_spawn_manager.h
                                         client_spawn_manager_inline.h
                                         client_spawn_manager.cpp
                                         client_spawn_manager_script.cpp)

set(AI_AMONSTERS_MONSTERS_BLOODSUCKER ai/Monsters/Bloodsucker/bloodsucker.h
                                      ai/Monsters/Bloodsucker/bloodsucker_state_manager.h
                                      ai/Monsters/Bloodsucker/bloodsucker_vampire_effector.h
                                      ai/Monsters/Bloodsucker/bloodsucker.cpp
                                      ai/Monsters/Bloodsucker/bloodsucker_state_manager.cpp
                                      ai/Monsters/Bloodsucker/bloodsucker_vampire_effector.cpp)

set(AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_GENERIC path_manager_generic.h
                                                                 path_manager_generic_inline.h)

set(AI_ALIFE_SIMULATOR_BASE_HEADER alife_simulator_header.h
                                   alife_simulator_header_inline.h
                                   alife_simulator_header.cpp)

set(CORE_SERVER_GAMES_SERVER_SINGLE game_sv_single.h
                                    game_sv_single.cpp)

set(CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS_DIALOGS AI_PhraseDialogManager.h
                                                   Phrase.h
                                                   PhraseDialog.h
                                                   PhraseDialog_script.h
                                                   PhraseDialogDefs.h
                                                   PhraseDialogManager.h
                                                   PhraseScript.h
                                                   AI_PhraseDialogManager.cpp
                                                   Phrase.cpp
                                                   PhraseDialog.cpp
                                                   PhraseDialog_script.cpp
                                                   PhraseDialogManager.cpp
                                                   PhraseScript.cpp)

set(AI_AMONSTERS_MONSTERS_CHIMERA_STATE_HUNTING ai/Monsters/Chimera/chimera_state_hunting.h
                                                ai/Monsters/Chimera/chimera_state_hunting_come_out.h
                                                ai/Monsters/Chimera/chimera_state_hunting_come_out_inline.h
                                                ai/Monsters/Chimera/chimera_state_hunting_inline.h
                                                ai/Monsters/Chimera/chimera_state_hunting_move_to_cover.h
                                                ai/Monsters/Chimera/chimera_state_hunting_move_to_cover_inline.h)

set(AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_BASE_PARAMS stalker_movement_params.h
                                                            stalker_movement_params_inline.h
                                                            stalker_movement_params.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_SVU WeaponSVU.h
                                                                        WeaponSVU.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTINIFILE_SCRIPTRTOKENLIST ../xrServerEntities/script_rtoken_list.h
                                                            ../xrServerEntities/script_rtoken_list_inline.h
                                                            ../xrServerEntities/script_rtoken_list_script.cpp)

set(AI_ACOMPONENTS_MOVEMENTMANAGER_PATHMANAGERS_LEVELPATHMANAGER level_path_builder.h
                                                                 level_path_manager.h
                                                                 level_path_manager_inline.h)

set(AI_ALIFE_SIMULATOR_BASE_REGISTRIES_GRAPH_REGISTRY_LEVEL_REGISTRY alife_level_registry.h
                                                                     alife_level_registry_inline.h)

set(AI_AMONSTERS_MONSTERS_BLOODSUCKER_ATTACK ai/Monsters/Bloodsucker/bloodsucker_attack_state.h
                                             ai/Monsters/Bloodsucker/bloodsucker_attack_state_hide.h
                                             ai/Monsters/Bloodsucker/bloodsucker_attack_state_hide_inline.h
                                             ai/Monsters/Bloodsucker/bloodsucker_attack_state_inline.h)

set(AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_GAME_LEVEL path_manager_game_level.h
                                                                    path_manager_game_level_inline.h)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_MAINMENU MainMenu.h
                                                ui/MMSound.h
                                                ui/UIMMShniaga.h
                                                MainMenu.cpp
                                                ui/MMSound.cpp
                                                ui/UIMMShniaga.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DEVICES_DETECTORS_SIMPLE_DETECTOR SimpleDetector.h
                                                                              SimpleDetector.cpp)

set(AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONBASE action_base.h
                                                                  action_base_inline.h
                                                                  action_base_script.cpp)

set(AI_ASCRIPT ../xrServerEntities/script_export_macroses.h
               ../xrServerEntities/script_export_space.h
               ../xrServerEntities/script_space_forward.h)

set(AI_ALIFE_UPDATE_MANAGER_STORAGE_MANAGER alife_storage_manager.h
                                            alife_storage_manager_inline.h
                                            alife_storage_manager.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_ACTIONS_BASE stalker_combat_action_base.h
                                                                          stalker_combat_action_base.cpp)

set(AI_AMONSTERS_MONSTERS_BURER_SCRIPT ai/Monsters/Burer/burer_script.cpp)

set(AI_ACOMPONENTS_DOORS_MANAGER doors.h)

set(AI_ANAVIGATION_PATHFINDING_DATASTORAGES_VERTEX_MANAGERS_HASH_FIXED vertex_manager_hash_fixed.h
                                                                       vertex_manager_hash_fixed_inline.h)

set(AI_AMONSTERS_COMMON_COMPONENTS_MORALE ai/Monsters/monster_morale.h
                                          ai/Monsters/monster_morale_inline.h
                                          ai/Monsters/monster_morale.cpp)

set(CORE_CLIENT_LEVEL_CLIENTDIGESTCOMPUTER Level_network_digest_computer.cpp)

set(AI_AMONSTERS_MONSTERS_BLOODSUCKER_ALIEN_FEATURE ai/Monsters/Bloodsucker/bloodsucker_alien.h
                                                    ai/Monsters/Bloodsucker/bloodsucker_alien.cpp)

set(CORE_COMMON_OBJECTBROKER ../xrServerEntities/object_broker.h
                             ../xrServerEntities/object_cloner.h
                             ../xrServerEntities/object_comparer.h
                             ../xrServerEntities/object_destroyer.h
                             ../xrServerEntities/object_interfaces.h
                             ../xrServerEntities/object_loader.h
                             ../xrServerEntities/object_saver.h
                             ../xrServerEntities/object_type_traits.h)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_RUSTYHAIRARTIFACT RustyHairArtifact.h
                                                                        RustyHairArtifact.cpp)

set(AI_ACOMPONENTS_MEMORYMANAGER_CLSUTERIZED_DATA_MANAGERS_OBJECTMANAGER object_manager.h
                                                                         object_manager_inline.h)

set(AI_ALIFE_SERVER_ENTITIES_MONSTER_ABSTRACT_MOVEMENT_MANAGER alife_monster_movement_manager.h
                                                               alife_monster_movement_manager_inline.h
                                                               alife_monster_movement_manager.cpp
                                                               alife_monster_movement_manager_script.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_UNKNOWN_ACTIONS stalker_danger_unknown_actions.h
                                                                                     stalker_danger_unknown_actions.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA_MAP ui/map_hint.h
                                               map_spot.h
                                               ui/UIMap.h
                                               ui/UIMapWnd.h
                                               ui/UIMapWndActions.h
                                               ui/UIMapWndActionsSpace.h
                                               ui/map_hint.cpp
                                               map_spot.cpp
                                               ui/UIMap.cpp
                                               ui/UIMapWnd.cpp
                                               ui/UIMapWnd2.cpp
                                               ui/UIMapWndActions.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_SOUNDUSERDATA stalker_sound_data.h
                                              stalker_sound_data_inline.h
                                              stalker_sound_data.cpp)

set(CORE_CLIENT_OBJECTS_DELAYEDACTIONFUSE DelayedActionFuse.h
                                          DelayedActionFuse.cpp)

set(CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS_STATISTICS actor_statistic_defs.h
                                                      actor_statistic_mgr.h
                                                      actor_statistic_mgr.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_BM_16 weaponBM16.h
                                                                          weaponBM16.cpp
                                                                          weaponBM16_script.cpp)

set(AI_ACOMPONENTS_MOVEMENTMANAGER_LOCATIONMANAGER location_manager.h
                                                   location_manager_inline.h
                                                   location_manager.cpp)

set(CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYITEMOBJECT inventory_item_object.h
                                                      inventory_item_object_inline.h
                                                      inventory_item_object.cpp)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_STEAL ai/Monsters/States/monster_state_steal.h
                                             ai/Monsters/States/monster_state_steal_inline.h)

set(CORE_CLIENT_OBJECTS_BASE_USABLESCRIPTOBJECT UsableScriptObject.h
                                                UsableScriptObject.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_EVALUATORS smart_cover_evaluators.h
                                                                        smart_cover_evaluators.cpp)

set(AI_ANAVIGATION_PATROLPATHS_PATROLPATHSTORAGE patrol_path_storage.h
                                                 patrol_path_storage_inline.h
                                                 patrol_path_storage.cpp)

set(AI_AGROUP_AGENT_MANAGER_AGENT_PLANNER_PROPERTIES agent_manager_properties.h
                                                     agent_manager_properties_inline.h
                                                     agent_manager_properties.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_INTERACTIVEBACKGROUND ui/UI_IB_Static.h
                                                                ui/UIInteractiveBackground.h
                                                                ui/UI_IB_Static.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER_PAIR stalker_animation_pair.h
                                                      stalker_animation_pair_inline.h
                                                      stalker_animation_pair.cpp)

set(CORE_SERVER_ID_GENERATOR id_generator.h)

set(CORE_CLIENT_LEVEL_DEBUG_RENDERER debug_renderer.h
                                     debug_renderer_inline.h
                                     debug_renderer.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_NEEDLES Needles.h
                                                              Needles.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER_DATA_STORAGE_DATA stalker_animation_data.h
                                                                   stalker_animation_data.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_MISCELLANEOUS ai_stalker_alife.cpp
                                              ai/stalker/ai_stalker_cover.cpp
                                              ai/stalker/ai_stalker_debug.cpp
                                              Ai/Stalker/ai_stalker_events.cpp
                                              Ai/Stalker/ai_stalker_feel.cpp
                                              Ai/Stalker/ai_stalker_fire.cpp
                                              Ai/Stalker/ai_stalker_misc.cpp
                                              ai/stalker/ai_stalker_script_entity.cpp)

set(CORE_CLIENT_OBJECTS_ZONES_MOSQUITOBALD MosquitoBald.h
                                           MosquitoBald.cpp
                                           MosquitoBald_script.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_ROTATION_JUMP ai/Monsters/control_melee_jump.h
                                                                        ai/Monsters/control_rotation_jump.h
                                                                        ai/Monsters/control_melee_jump.cpp
                                                                        ai/Monsters/control_rotation_jump.cpp)

set(CORE_CLIENT_OBJECTS_ZONES_MINCER Mincer.h
                                     Mincer.cpp
                                     mincer_script.cpp)

set(AI_AMONSTERS_MONSTERS_CHIMERA_STATE_THREATEN ai/Monsters/Chimera/chimera_state_threaten.h
                                                 ai/Monsters/Chimera/chimera_state_threaten_inline.h
                                                 ai/Monsters/Chimera/chimera_state_threaten_roar.h
                                                 ai/Monsters/Chimera/chimera_state_threaten_roar_inline.h
                                                 ai/Monsters/Chimera/chimera_state_threaten_steal.h
                                                 ai/Monsters/Chimera/chimera_state_threaten_steal_inline.h
                                                 ai/Monsters/Chimera/chimera_state_threaten_walk.h
                                                 ai/Monsters/Chimera/chimera_state_threaten_walk_inline.h)

set(CORE_CLIENT_OBJECTS_INVENTORY_BOX InventoryBox.h
                                      InventoryBox.cpp)

set(AI_ANAVIGATION_PATHFINDING_ALGORITHMS_ASTAR a_star.h
                                                a_star_inline.h)

set(AI_ASCRIPT_SCRIPTCLASSES_UI script_ui_registrator.h
                                ScriptXMLInit.h
                                ui_base.h
                                ui_defs.h
                                UIDialogHolder.h
                                ScriptXMLInit.cpp
                                ui_export_script.cpp
                                ui_base.cpp
                                UIDialogHolder.cpp)

set(AI_ACOMPONENTS_OBJECTHANDLER_PLANNER_PROPERTIES object_property_evaluators.h
                                                    object_property_evaluators_inline.h
                                                    object_property_evaluators.cpp)

set(AI_AMONSTERS_MONSTERS_CONTROLLER_BASE_CONTROLLERS_DIRECTION ai/Monsters/Controller/controller_direction.h
                                                                ai/Monsters/Controller/controller_direction.cpp)

set(AI_ACOMPONENTS_MEMORYMANAGER_CLSUTERIZED_DATA_MANAGERS_DANGERMANAGER_DANGER_OBJECT danger_object.h
                                                                                       danger_object_inline.h
                                                                                       danger_object.cpp)

set(AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTIONHOLDER_SPACERESTRICTIONBASE space_restriction_base.h
                                                                                       space_restriction_base_inline.h
                                                                                       space_restriction_base.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS stalker_movement_manager_smart_cover.h
                                                             stalker_movement_manager_smart_cover_inline.h
                                                             stalker_movement_manager_smart_cover.cpp
                                                             stalker_movement_manager_smart_cover_fov_range.cpp
                                                             stalker_movement_manager_smart_cover_loopholes.cpp)

set(CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_TRADE_PARAMETERS_TRADE_FACTOR_PARAMETERS trade_factor_parameters.h
                                                                                          trade_factor_parameters_inline.h)

set(AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER stalker_movement_manager_space.h)

set(CORE_CLIENT_OBJECTS_PHYSICS_CHARACTERSUPPORT_INTERACTIVE_MOTION imotion_position.h
                                                                    imotion_velocity.h
                                                                    interactive_motion.h
                                                                    imotion_position.cpp
                                                                    imotion_velocity.cpp
                                                                    interactive_motion.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_EDITBOX_CUSTOMEB ui/UICustomEdit.h
                                                           ui/UICustomEdit.cpp
                                                           ui/UIEditBox_script.cpp)

set(CORE_CLIENT_OBJECTS_PHYSICS_PHDESTROYABLE PHDestroyable.h
                                              PHDestroyable.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DEVICES_FLARE flare.h
                                                          flare.cpp)

set(AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONPLANNERACTION_ACTIONPLANNERACTIONSCRIPT action_planner_action_script.h
                                                                                                     action_planner_action_script_inline.h)

set(AI_ANAVIGATION_PATHFINDING_DATASTORAGES_PATH_BUILDERS_VERTEX_PATH vertex_path.h
                                                                      vertex_path_inline.h)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTNETPACKET ../xrServerEntities/script_net_packet.h
                                             ../xrServerEntities/script_net_packet_script.cpp)

set(AI_ACOMPONENTS_MEMORYMANAGER_RAW_DATA_MANAGERS_HITMEMORYMANAGER hit_memory_manager.h
                                                                    hit_memory_manager_inline.h
                                                                    hit_memory_manager.cpp)

set(CORE_CLIENT_OBJECTS_ZONES_SCRIPTZONE script_zone.h
                                         script_zone.cpp
                                         script_zone_script.cpp)

set(CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_CHARACTER_INFO character_community.h
                                                                ../xrServerEntities/character_info.h
                                                                ../xrServerEntities/character_info_defs.h
                                                                character_rank.h
                                                                character_reputation.h
                                                                ini_id_loader.h
                                                                ini_table_loader.h
                                                                monster_community.h
                                                                ../xrServerEntities/specific_character.h
                                                                character_community.cpp
                                                                ../xrServerEntities/character_info.cpp
                                                                character_rank.cpp
                                                                character_reputation.cpp
                                                                monster_community.cpp
                                                                ../xrServerEntities/specific_character.cpp)

set(AI_ALIFE_SERVER_ENTITIES_MONSTER_ABSTRACT_MOVEMENT_MANAGER_MOVEMENT_MANAGER_HOLDER ../xrServerEntities/alife_movement_manager_holder.h)

set(AI_ACOMPONENTS_MOVEMENTMANAGER_LOCATIONSELECTORS_GAMELOCATIONSELECTOR game_location_selector.h
                                                                          game_location_selector_inline.h)

set(AI_ANAVIGATION_PATHFINDING_DATASTORAGES_VERTEX_ALLOCATORS_FIXED vertex_allocator_fixed.h
                                                                    vertex_allocator_fixed_inline.h)

set(CORE_CLIENT_OBJECTS_PHYSICS_PHYSICSSHELLHOLDER PhysicsShellHolder.h
                                                   PhysicsShellHolder.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_SEARCH_PLANNER_ACTIONS stalker_search_actions.h
                                                                                    stalker_search_actions.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_ALIFE stalker_alife_planner.h
                                                            stalker_alife_planner.cpp)

set(AI_AMONSTERS_MONSTERS_RATS ai/monsters/rats/ai_rat.h
                               ai/monsters/rats/ai_rat_impl.h
                               ai/monsters/rats/ai_rat_inline.h
                               ai/monsters/rats/ai_rat_space.h
                               ai/monsters/rats/ai_rat.cpp
                               ai/monsters/rats/ai_rat_animations.cpp
                               ai/monsters/rats/ai_rat_behaviour.cpp
                               ai/monsters/rats/ai_rat_feel.cpp
                               ai/monsters/rats/ai_rat_fire.cpp
                               ai/monsters/rats/ai_rat_templates.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_GROZA WeaponGroza.h
                                                                                 WeaponGroza.cpp)

set(AI_AMONSTERS_MONSTERS_POLTERGEIST_SCRIPT ai/Monsters/Poltergeist/poltergeist_script.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_BASECLIENTCLASSES base_client_classes.h
                                               base_client_classes_wrappers.h
                                               base_client_classes_script.cpp)

set(AI_AGROUP_AGENT_MANAGER_AGENT_ENEMY_MANAGER_MEMBER_ENEMY member_enemy.h
                                                             member_enemy_inline.h)

set(AI_ANAVIGATION_PATHFINDING_ALGORITHMS_DIJKSTRA dijkstra.h
                                                   dijkstra_inline.h)

set(AI_ACOMPONENTS_MEMORYMANAGER_RAW_DATA_MANAGERS_VISUALMEMORYMANAGER_VISUAL_MEMORY_PARAMS visual_memory_params.h
                                                                                            visual_memory_params.cpp)

set(AI_ALIFE_SIMULATOR_BASE_REGISTRIES_SPAWN_REGISTRY_HEADER alife_spawn_registry_header.h
                                                             alife_spawn_registry_header_inline.h
                                                             alife_spawn_registry_header.cpp)

set(AI_ACOMPONENTS_MEMORYMANAGER_CLSUTERIZED_DATA_MANAGERS_DANGERMANAGER danger_manager.h
                                                                         danger_manager_inline.h
                                                                         danger_manager.cpp)

set(CORE_COMMON_OBJECTFACTORY_OBJECT_ITEM_ABSTRACT ../xrServerEntities/object_item_abstract.h
                                                   ../xrServerEntities/object_item_abstract_inline.h)

set(AI_ACOVER_SMART_COVER_OBJECT smart_cover_object.h
                                 smart_cover_object_inline.h
                                 smart_cover_object.cpp
                                 smart_cover_object_script.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR_ANIMATION_PLANNER_LOOPHOLE_ACTIONS smart_cover_loophole_planner_actions.h
                                                                                                                   smart_cover_loophole_planner_actions_inline.h
                                                                                                                   smart_cover_loophole_planner_actions.cpp)

set(AI_AMONSTERS_MONSTERS_TUSHKANO ai/Monsters/Tushkano/tushkano.h
                                   ai/Monsters/Tushkano/tushkano_state_manager.h
                                   ai/Monsters/Tushkano/tushkano.cpp
                                   ai/Monsters/Tushkano/tushkano_state_manager.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_OBSTACLES stalker_movement_manager_obstacles.h
                                                          stalker_movement_manager_obstacles_inline.h
                                                          stalker_movement_manager_obstacles.cpp
                                                          stalker_movement_manager_obstacles_path.cpp)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_GENERAL ai/Monsters/States/state_data.h)

set(AI_ALIFE alife_simulator.h
             alife_simulator_inline.h
             ../xrServerEntities/alife_space.h
             alife_simulator.cpp
             alife_simulator_script.cpp
             ../xrServerEntities/alife_space.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER_NAMES stalker_animation_names.h
                                                       stalker_animation_names.cpp)

set(CORE_CLIENT_OBJECTS_VEHICLES_CAR_CAR_MEMORY car_memory.h
                                                car_memory.cpp)

set(CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS InfoPortion.h
                                           ../xrServerEntities/InfoPortionDefs.h
                                           ../xrServerEntities/xml_str_id_loader.h
                                           InfoPortion.cpp)

set(AI_ACOMPONENTS_MEMORYMANAGER_CLSUTERIZED_DATA_MANAGERS_ITEMMANAGER item_manager.h
                                                                       item_manager.cpp)

set(AI_AMONSTERS_COMMON_STEERING_BEHAVIOURS_COMPONENTS_ALIGNMENT steering_behaviour_alignment.h)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTLANIM script_lanim.h
                                         script_lanim.cpp)

set(AI_ACOMPONENTS_PROBLEMSOLVER_OPERATOR_ABSTRACT operator_abstract.h
                                                   operator_abstract_inline.h)

set(AI_AMONSTERS_MONSTERS_POLTERGEIST_ABILITIES ai/Monsters/Poltergeist/poltergeist_ability.cpp
                                                ai/Monsters/Poltergeist/poltergeist_flame_thrower.cpp
                                                ai/Monsters/Poltergeist/poltergeist_telekinesis.cpp)

set(AI_ACOVER_SMART_COVER_STORAGE_DESCRIPTION_TRANSITIONS_ANIMATION smart_cover_transition_animation.hpp
                                                                    smart_cover_transition_animation_inline.hpp
                                                                    smart_cover_transition_animation.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_LOW_COVER_PLANNER_ACTIONS stalker_low_cover_actions.h
                                                                                       stalker_low_cover_actions.cpp)

set(AI_AMONSTERS_MONSTERS_RATS_STATE_MANAGER rat_state_manager.h
                                             rat_state_manager_inline.h
                                             rat_state_manager.cpp)

set(AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_LEVEL_STRAIGHT_LINE path_manager_level_straight_line.h
                                                                             path_manager_level_straight_line_inline.h)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_PISTOL WeaponCustomPistol.h
                                                                         WeaponPistol.h
                                                                         WeaponCustomPistol.cpp
                                                                         WeaponPistol.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_PDA__AND__INFORMATION PDA.h
                                                                  pda_space.h
                                                                  PdaMsg.h
                                                                  PDA.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_COVER_MANAGER ai/Monsters/monster_cover_manager.h
                                                 ai/Monsters/monster_cover_manager.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_ABSTRACT_ACTION script_abstract_action.h
                                                                  script_abstract_action_inline.h
                                                                  script_abstract_action.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTFCOLOR ../xrServerEntities/script_fcolor.h
                                          ../xrServerEntities/script_fcolor_script.cpp)

set(AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_WORLDPROPERTYEVALUATOR_CONST property_evaluator_const.h
                                                                                    property_evaluator_const_inline.h)

set(CORE_CLIENT_OBJECTS_BASE_ENTITYALIVE entity_alive.h
                                         entity_alive_inline.h
                                         entity_alive.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER_STATE stalker_animation_state.h
                                                       stalker_animation_state_inline.h
                                                       stalker_animation_state.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_MOVEMENT_ACTION_PATROL_PATH_PARAMS patrol_path_params.h
                                                                                     patrol_path_params_inline.h
                                                                                     patrol_path_params.cpp
                                                                                     patrol_path_params_script.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_SCROLLVIEW ui/UIScrollView.h
                                                     ui/UIScrollView.cpp)

set(AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONBASE_ACTIONSCRIPTBASE action_script_base.h
                                                                                   action_script_base_inline.h)

set(AI_ANAVIGATION_PATHFINDING_DATASTORAGES_PRIORITY_QUEUES_BINARY_HEAP data_storage_binary_heap.h
                                                                        data_storage_binary_heap_inline.h)

set(AI_ALIFE_SIMULATOR_BASE_REGISTRIES_SAFE_MAP_ITERATOR safe_map_iterator.h
                                                         safe_map_iterator_inline.h)

set(AI_ASCRIPT_SCRIPTCLASSES_CONSOLE console_registrator.h
                                     console_registrator_script.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_MOTION_STATS ai/Monsters/ai_monster_motion_stats.h
                                                ai/Monsters/ai_monster_motion_stats.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_COVER ai/Monsters/corpse_cover.h
                                         ai/Monsters/corpse_cover.cpp)

set(CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_AI_OBSTACLE_MIN_OBB_MAGIC_MINIMIZE_ND magic_minimize_nd.h
                                                                              magic_minimize_nd_inline.h)

set(CORE_COMMON_STRINGTABLE string_table.h
                            string_table_defs.h
                            string_table.cpp)

set(AI_AMONSTERS_MONSTERS_SNORK_SPECIAL_JUMP ai/Monsters/Snork/snork_jump.h
                                             ai/Monsters/Snork/snork_jump.cpp)

set(AI_ALIFE_SAVED_GAME_WRAPPER saved_game_wrapper.h
                                saved_game_wrapper_inline.h
                                saved_game_wrapper.cpp
                                saved_game_wrapper_script.cpp)

set(AI_ACOMPONENTS_SIGHTMANAGER_CONTROL_ACTION control_action.h
                                               control_action_inline.h)

set(AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_PURE_COMS_DIRECTION ai/Monsters/control_direction.h
                                                                       ai/Monsters/control_direction.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_OBSTACLES_RESTRICTED_OBJECT_OBSTACLE restricted_object_obstacle.h
                                                                                     restricted_object_obstacle.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER stalker_decision_space.h
                                              stalker_planner.h
                                              stalker_planner_inline.h
                                              stalker_planner.cpp)

set(CORE_COMMON_DATETIME date_time.h
                         date_time.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_MELEE_CHECKER ai/Monsters/melee_checker.h
                                                 ai/Monsters/melee_checker_inline.h
                                                 ai/Monsters/melee_checker.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_EDITBOX ui/UIEditBox.h
                                                  ui/UIEditBoxEx.h
                                                  ui/UIEditBox.cpp
                                                  ui/UIEditBoxEx.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_LOW_COVER_PLANNER stalker_low_cover_planner.h
                                                                               stalker_low_cover_planner.cpp)

set(AI_ALIFE_SIMULATOR_BASE_REGISTRIES_STORY_REGISTRY alife_story_registry.h
                                                      alife_story_registry_inline.h
                                                      alife_story_registry.cpp)

set(AI_AMONSTERS_MONSTERS_CONTROLLER ai/Monsters/Controller/controller.h
                                     ai/Monsters/Controller/controller_state_manager.h
                                     ai/Monsters/Controller/controller.cpp
                                     ai/Monsters/Controller/controller_state_manager.cpp)

set(CORE_COMMON_RANDOM_WEIGHTED ai/weighted_random.h
                                ai/weighted_random.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_TUTORIAL ui/UIGameTutorial.h
                                         ui/UIGameTutorial.cpp
                                         ui/UIGameTutorialSimpleItem.cpp
                                         ui/UIGameTutorialVideoItem.cpp)

set(CORE_CLIENT_OBJECTS_PHYSICS_PHCOMMANDER PHCommander.h
                                            PHReqComparer.h
                                            PHScriptCall.h
                                            PHSimpleCalls.h
                                            PHCommander.cpp
                                            PHScriptCall.cpp
                                            PHSimpleCalls.cpp
                                            PHSimpleCallsScript.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_BASE stalker_movement_manager_base.h
                                                     stalker_movement_manager_base_inline.h
                                                     stalker_movement_manager_base.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_GRAVIARTIFACT GraviArtifact.h
                                                                    GraviArtifact.cpp)

set(AI_ALIFE_SERVER_ENTITIES_MONSTER_ABSTRACT_MOVEMENT_MANAGER_PATROL_PATH_MANAGER alife_monster_patrol_path_manager.h
                                                                                   alife_monster_patrol_path_manager_inline.h
                                                                                   alife_monster_patrol_path_manager.cpp
                                                                                   alife_monster_patrol_path_manager_script.cpp)

set(AI_ALIFE_SERVER_ENTITIES_MONSTER_ABSTRACT_MOVEMENT_MANAGER_DETAIL_PATH_MANAGER alife_monster_detail_path_manager.h
                                                                                   alife_monster_detail_path_manager_inline.h
                                                                                   alife_monster_detail_path_manager.cpp
                                                                                   alife_monster_detail_path_manager_script.cpp)

set(AI_ACOMPONENTS_MEMORYMANAGER_RAW_DATA_MANAGERS_SOUNDMEMORYMANAGER sound_memory_manager.h
                                                                      sound_memory_manager_inline.h
                                                                      sound_memory_manager.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_AK74 WeaponAK74.h
                                                                                WeaponAK74.cpp)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_CAMP ai/Monsters/States/monster_state_attack_camp.h
                                            ai/Monsters/States/monster_state_attack_camp_inline.h
                                            ai/Monsters/States/monster_state_attack_camp_stealout.h
                                            ai/Monsters/States/monster_state_attack_camp_stealout_inline.h)

set(AI_ACOMPONENTS_PROBLEMSOLVER_CONDITION_STATE condition_state.h
                                                 condition_state_inline.h)

set(CORE_CLIENT_LEVEL_DEBUG level_debug.h
                            level_debug.cpp)

set(AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_SOLVER path_manager_solver.h
                                                                path_manager_solver_inline.h)

set(CORE_CLIENT_OBJECTS_SEARCHLIGHT searchlight.h
                                    searchlight.cpp)

set(AI_ACOMPONENTS_MOVING_OBJECTS_MOVING_OBJECT moving_object.h
                                                moving_object_inline.h
                                                moving_object.cpp)

set(CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER inventory_owner_inline.h
                                                 InventoryOwner.h
                                                 inventory_owner_info.cpp
                                                 InventoryOwner.cpp)

set(AI_ANAVIGATION_PATHFINDING_PATHMANAGERS path_manager.h)

set(AI mt_config.h)

set(CORE_CLIENT_OBJECTS_PHYSICS_PHYSICSSKELETONOBJECT PHDestroyableNotificate.h
                                                      PhysicsSkeletonObject.h
                                                      PHDestroyableNotificate.cpp
                                                      PhysicsSkeletonObject.cpp)

set(AI_ACOMPONENTS_MOVING_OBJECTS_OBSTACLES_QUERY obstacles_query.h
                                                  obstacles_query_inline.h
                                                  obstacles_query.cpp)

set(AI_ACOMPONENTS_SPACERESTRICTIONMANAGER ../xrServerEntities/restriction_space.h
                                           space_restriction_manager.h
                                           space_restriction_manager_inline.h
                                           space_restriction_manager.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_COMBOBOX ui/UIComboBox.h
                                                   ui/UIComboBox.cpp
                                                   ui/UIComboBox_script.cpp)

set(AI_AMONSTERS_MONSTERS_BLOODSUCKER_VAMPIRE_STATE ai/Monsters/Bloodsucker/bloodsucker_vampire.h
                                                    ai/Monsters/Bloodsucker/bloodsucker_vampire_approach.h
                                                    ai/Monsters/Bloodsucker/bloodsucker_vampire_approach_inline.h
                                                    ai/Monsters/Bloodsucker/bloodsucker_vampire_execute.h
                                                    ai/Monsters/Bloodsucker/bloodsucker_vampire_execute_inline.h
                                                    ai/Monsters/Bloodsucker/bloodsucker_vampire_hide.h
                                                    ai/Monsters/Bloodsucker/bloodsucker_vampire_hide_inline.h
                                                    ai/Monsters/Bloodsucker/bloodsucker_vampire_inline.h)

set(CORE_CLIENT_OBJECTS_SEARCHLIGHT_TRADE trade.h
                                          trade.cpp
                                          trade2.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_PARTICLE_ACTION_PARTICLE_PARAMS particle_params.h
                                                                                  particle_params_inline.h
                                                                                  particle_params.cpp
                                                                                  particle_params_script.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_ABILITIES_ENERGY_HOLDER ai/Monsters/energy_holder.h
                                                           ai/Monsters/energy_holder.cpp)

set(CORE_CLIENT_OBJECTS_PHYSICS_MOVEMENTCONTROL CaptureBoneCallback.h
                                                PHMovementControl.h
                                                PHMovementControl.cpp
                                                PHMovementDynamicActivate.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_PURE_COMS_MOVEMENT ai/Monsters/control_movement.h
                                                                      ai/Monsters/control_movement.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_MEMORY ai/Monsters/monster_corpse_memory.h
                                          ai/Monsters/monster_enemy_memory.h
                                          ai/Monsters/monster_hit_memory.h
                                          ai/Monsters/monster_sound_memory.h
                                          ai/Monsters/monster_corpse_memory.cpp
                                          ai/Monsters/monster_enemy_memory.cpp
                                          ai/Monsters/monster_hit_memory.cpp
                                          ai/Monsters/monster_sound_memory.cpp)

set(AI_ANAVIGATION_PATHFINDING_DATASTORAGES_VERTEX_MANAGERS_FIXED vertex_manager_fixed.h
                                                                  vertex_manager_fixed_inline.h)

set(AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_LEVEL path_manager_level.h
                                                               path_manager_level_inline.h)

set(AI_ACOMPONENTS_SIGHTMANAGER_SIGHT_CONTROL_ACTION sight_control_action.h
                                                     sight_control_action_inline.h)

set(AI_ACOMPONENTS_PROBLEMSOLVER problem_solver.h
                                 problem_solver_inline.h)

set(CORE_SERVER_SERVERENTITIES_OBJECTS ../xrServerEntities/xrServer_Object_Base.h
                                       ../xrServerEntities/xrServer_Objects.h
                                       ../xrServerEntities/xrServer_Object_Base.cpp
                                       ../xrServerEntities/xrServer_Objects.cpp
                                       ../xrServerEntities/xrServer_Objects_script.cpp
                                       ../xrServerEntities/xrServer_Objects_script2.cpp)

set(CORE_CLIENT_OBJECTS_BASE_ENTITY Entity.h
                                    Entity.cpp)

set(AI_ANAVIGATION_PATHFINDING_DATASTORAGES_CONSTRUCTORS_BUILDER_ALLOCATOR builder_allocator_constructor.h
                                                                           builder_allocator_constructor_inline.h)

set(CORE_CLIENT_LEVEL_AUTOSAVEMANAGER autosave_manager.h
                                      autosave_manager_inline.h
                                      autosave_manager.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_BASE_VELOCITY_COLLECTION stalker_velocity_collection.h
                                                                         stalker_velocity_collection_inline.h
                                                                         stalker_velocity_collection.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_GET_DISTANCE_ACTIONS stalker_get_distance_actions.h
                                                                                  stalker_get_distance_actions.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_SOUNDDATAVISITOR stalker_sound_data_visitor.h
                                                 stalker_sound_data_visitor_inline.h
                                                 stalker_sound_data_visitor.cpp)

set(AI_ASCRIPT_SCRIPTPROCESS ../xrServerEntities/script_process.h
                             ../xrServerEntities/script_process_inline.h
                             ../xrServerEntities/script_process.cpp)

set(AI_ACOMPONENTS_MOVING_OBJECTS moving_objects.h
                                  moving_objects_impl.h
                                  moving_objects_inline.h
                                  moving_objects.cpp
                                  moving_objects_dynamic.cpp
                                  moving_objects_dynamic_collision.cpp
                                  moving_objects_static.cpp)

set(AI_ACOMPONENTS_STEP_MANAGER step_manager.h
                                step_manager_defs.h
                                step_manager.cpp)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_EAT ai/Monsters/States/monster_state_eat.h
                                           ai/Monsters/States/monster_state_eat_inline.h)

set(CORE_CLIENT_OBJECTS_PHYSICS_PHSKELETON PHSkeleton.h
                                           PHSkeleton.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_DUMMYARTIFACT DummyArtifact.h
                                                                    DummyArtifact.cpp)

set(AI_ALIFE_INTERACTION_MANAGER_COMMUNICATION_MANAGER alife_communication_manager.h
                                                       alife_communication_manager_inline.h
                                                       alife_communication_space.h
                                                       alife_communication_manager.cpp)

set(CORE_CLIENT_OBJECTS_ACTOR_BASE_MEMORY actor_memory.h
                                          actor_memory.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_KNIFE WeaponKnife.h
                                                                          WeaponKnife.cpp
                                                                          WeaponKnife_script.cpp)

set(AI_AMONSTERS_COMMON_STEERING_BEHAVIOURS_BASE steering_behaviour_base.h
                                                 steering_behaviour_base_inline.h)

set(AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_TRIPLE_ANIMATION ai/Monsters/anim_triple.h
                                                                           ai/Monsters/anim_triple.cpp)

set(CORE_SERVER_FILETRANSFER file_transfer.h
                             filereceiver_node.h
                             filetransfer_common.h
                             filetransfer_node.h
                             file_transfer.cpp
                             filereceiver_node.cpp
                             filetransfer_node.cpp)

set(AI_ALIFE_INVENTORY_UPGRADE_UPGRADE_ROOT inventory_upgrade_root.h
                                            inventory_upgrade_root_inline.h
                                            inventory_upgrade_root.cpp)

set(AI_AMONSTERS_MONSTERS_DOGPSY_PSY_ATTACK_HIDE ai/Monsters/Pseudodog/psy_dog_state_psy_attack.h
                                                 ai/Monsters/Pseudodog/psy_dog_state_psy_attack_hide.h
                                                 ai/Monsters/Pseudodog/psy_dog_state_psy_attack_hide_inline.h
                                                 ai/Monsters/Pseudodog/psy_dog_state_psy_attack_inline.h)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA_LOGS_NEWS ui/UINewsItemWnd.h
                                                     ui/UINewsItemWnd.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_TALK ui/UITalkDialogWnd.h
                                            ui/UITalkWnd.h
                                            ui/UITalkDialogWnd.cpp
                                            ui/UITalkWnd.cpp)

set(CORE_CLIENT_LEVEL_LEVEL_SOUNDS level_sounds.h
                                   level_sounds.cpp)

set(CORE_CLIENT_LEVEL_GLOBALFEELTOUCH GlobalFeelTouch.hpp
                                      GlobalFeelTouch.cpp)

set(AI_AMONSTERS_MONSTERS_CONTROLLER_PSY_HIT ai/Monsters/Controller/controller_psy_hit.h
                                             ai/Monsters/Controller/controller_psy_hit_effector.h
                                             ai/Monsters/Controller/controller_psy_hit.cpp
                                             ai/Monsters/Controller/controller_psy_hit_effector.cpp)

set(CORE_CLIENT_EFFECTORS_POSTPROCESS PostprocessAnimator.h
                                      zone_effector.h
                                      PostprocessAnimator.cpp
                                      zone_effector.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_EVENT_HANDLER ai/Monsters/monster_event_manager.h
                                                 ai/Monsters/monster_event_manager_defs.h
                                                 ai/Monsters/monster_event_manager.cpp)

set(AI_ANAVIGATION_GRAPHABSTRACT_GRAPHVERTEX graph_vertex.h
                                             graph_vertex_inline.h)

set(AI_AMONSTERS_MONSTERS_FLESH_SCRIPT ai/Monsters/Flesh/flesh_script.cpp)

set(CORE_SERVER_GAMES_PLAYERACCOUNTS mixed_delegate.h
                                     mixed_delegate_unique_tags.h
                                     queued_async_method.h)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_MESSAGEBOX ui/UIMessageBox.h
                                                     ui/UIMessageBoxEx.h
                                                     ui/UIMessageBox.cpp
                                                     ui/UIMessageBox_script.cpp
                                                     ui/UIMessageBoxEx.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_PURE_COMS_PATH_BUILDER ai/Monsters/control_path_builder.h
                                                                          ai/Monsters/control_path_builder.cpp)

set(CORE_CLIENT_OBJECTS_INVENTORY_EATABLEITEMOBJECT eatable_item_object.h
                                                    eatable_item_object.cpp)

set(CORE_CLIENT_OBJECTS_PHYSICS_IK Ik/aint.h
                                   Ik/Dof7control.h
                                   Ik/eqn.h
                                   Ik/eulersolver.h
                                   ik_anim_state.h
                                   ik_calculate_data.h
                                   ik_calculate_state.h
                                   ik_collide_data.h
                                   ik_dbg_matrix.h
                                   ik_foot_collider.h
                                   ik_limb_state.h
                                   ik_limb_state_predict.h
                                   ik_object_shift.h
                                   IKFoot.h
                                   IKFoot_inl.h
                                   Ik/IKLimb.h
                                   IKLimbsController.h
                                   Ik/jtlimits.h
                                   Ik/limb.h
                                   Ik/math3d.h
                                   Ik/mathTrig.h
                                   pose_extrapolation.h
                                   Ik/aint.cxx
                                   Ik/Dof7control.cpp
                                   Ik/eqn.cxx
                                   Ik/eulersolver.cxx
                                   ik_anim_state.cpp
                                   ik_calculate_data.cpp
                                   ik_dbg_matrix.cpp
                                   ik_foot_collider.cpp
                                   ik_limb_state.cpp
                                   ik_object_shift.cpp
                                   IKFoot.cpp
                                   Ik/IKLimb.cpp
                                   IKLimbsController.cpp
                                   Ik/jtlimits.cxx
                                   Ik/limb.cxx
                                   Ik/math3d.cpp
                                   Ik/mathTrig.cpp
                                   pose_extrapolation.cpp)

set(AI_AMONSTERS_COMMON_STEERING_BEHAVIOURS_COMPONENTS_SEPARATION steering_behaviour_separation.h)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_FADED_BALL_MERCURY_BALL MercuryBall.h
                                                                              MercuryBall.cpp)

set(AI_ACOMPONENTS_SETUPMANAGER setup_manager.h
                                setup_manager_inline.h)

set(CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS_GAME_TASKS GameTask.h
                                                      GameTaskDefs.h
                                                      GametaskManager.h
                                                      GameTask.cpp
                                                      GameTask_script.cpp
                                                      GametaskManager.cpp)

set(AI_ALIFE_SIMULATOR_BASE_REGISTRIES_OBJECT_REGISTRY alife_object_registry.h
                                                       alife_object_registry_inline.h
                                                       alife_object_registry.cpp)

set(AI_AMONSTERS_COMMON_SCRIPT_SCRIPT_BINDER script_binder.h
                                             script_binder_inline.h
                                             script_binder.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_BONES ai/Monsters/ai_monster_bones.h
                                         ai/Monsters/ai_monster_bones.cpp)

set(AI_ACOMPONENTS_SIGHTMANAGER_AIMERS_WEAPON aimers_weapon.h
                                              aimers_weapon_inline.h
                                              aimers_weapon.cpp)

set(AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_LEVEL_FLOODER path_manager_level_flooder.h
                                                                       path_manager_level_flooder_inline.h)

set(AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR_ANIMATION_PLANNER_TARGET_SELECTOR_DEFAULT_BEHAVIOUR smart_cover_default_behaviour_planner.hpp
                                                                                                                                    smart_cover_default_behaviour_planner_inline.hpp
                                                                                                                                    smart_cover_default_behaviour_planner.cpp)

set(AI_AMONSTERS_MONSTERS_PSEUDOGIGANT_SCRIPT ai/Monsters/PseudoGigant/pseudogigant_script.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_KILL_WOUNDED_ACTIONS stalker_kill_wounded_actions.h
                                                                                  stalker_kill_wounded_actions.cpp)

set(AI_ACOVER_SMART_COVER_COVER smart_cover.h
                                smart_cover_inline.h
                                smart_cover.cpp)

set(AI_AMONSTERS_MONSTERS_PSEUDODOG_SCRIPT ai/Monsters/Pseudodog/pseudodog_script.cpp)

set(AI_ACOMPONENTS_DOORS_MANAGER_ACTOR doors_actor.h
                                       doors_actor.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_SPINBOX ui/UICustomSpin.h
                                                  ui/UISpinNum.h
                                                  ui/UISpinText.h
                                                  ui/UICustomSpin.cpp
                                                  ui/UISpinNum.cpp
                                                  ui/UISpinText.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA_STATISTICS__AND__RANKINGS ui/UIAchievements.h
                                                                     ui/UIRankingWnd.h
                                                                     ui/UIAchievements.cpp
                                                                     ui/UIRankingWnd.cpp)

set(CORE_CLIENT_OBJECTS_PHYSICS_PHYSICOBJECT animation_script_callback.h
                                             PhysicObject.h
                                             animation_script_callback.cpp
                                             PhysicObject.cpp
                                             PhysicObject_script.cpp)

set(AI_AEVAL_FUNCTIONS_PATTERNS ef_pattern.h
                                ef_pattern.cpp)

set(AI_AMONSTERS_MONSTERS_BURER_FAST_GRAVI ai/Monsters/Burer/burer_fast_gravi.h
                                           ai/Monsters/Burer/burer_fast_gravi.cpp)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_HOME_POINT ai/Monsters/States/monster_state_home_point_attack.h
                                                  ai/Monsters/States/monster_state_home_point_attack_inline.h
                                                  ai/Monsters/States/monster_state_home_point_danger.h
                                                  ai/Monsters/States/monster_state_home_point_danger_inline.h
                                                  ai/Monsters/States/monster_state_home_point_rest.h
                                                  ai/Monsters/States/monster_state_home_point_rest_inline.h)

set(AI_ALIFE_UPDATE_MANAGER alife_update_manager.h
                            alife_update_manager_inline.h
                            alife_update_manager.cpp)

set(AI_AMONSTERS_MONSTERS_CHIMERA ai/Monsters/Chimera/chimera.h
                                  ai/Monsters/Chimera/chimera_state_manager.h
                                  ai/Monsters/Chimera/chimera.cpp
                                  ai/Monsters/Chimera/chimera_state_manager.cpp)

set(AI_AMONSTERS_MONSTERS_DOG_SCRIPT ai/Monsters/Dog/dog_script.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTREADER ../xrServerEntities/script_reader.h
                                          ../xrServerEntities/script_reader_script.cpp)

set(CORE_SERVER_SERVERENTITIES_OBJECTS_ALIFE_MONSTERS ../xrServerEntities/xrServer_Objects_ALife_Monsters.h
                                                      ../xrServerEntities/xrServer_Objects_ALife_Monsters.cpp
                                                      ../xrServerEntities/xrServer_Objects_ALife_Monsters_script.cpp
                                                      ../xrServerEntities/xrServer_Objects_ALife_Monsters_script2.cpp
                                                      ../xrServerEntities/xrserver_objects_alife_monsters_script3.cpp
                                                      ../xrServerEntities/xrServer_Objects_ALife_Monsters_script4.cpp)

set(AI_ADEBUG ai_debug.h
              ai_debug_variables.h
              debug_text_tree.h
              debug_text_tree_inline.h
              ai_debug_variables.cpp
              dbg_draw_frustum.cpp
              debug_text_tree.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_MAINMENU_KEYBINDING ui/UIEditKeyBind.h
                                                           ui/UIKeyBinding.h
                                                           ui/UIEditKeyBind.cpp
                                                           ui/UIKeyBinding.cpp)

set(AI_ANAVIGATION_LEVELGRAPH level_graph.h
                              level_graph_inline.h
                              level_graph_space.h
                              level_graph_vertex_inline.h
                              level_graph.cpp
                              level_graph_debug.cpp
                              level_graph_debug2.cpp
                              level_graph_vertex.cpp)

set(AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONPLANNER_ACTIONPLANNERSCRIPT action_planner_script.h
                                                                                         action_planner_script_inline.h)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_GENERAL_TEST ai/Monsters/States/state_hit_object.h
                                                    ai/Monsters/States/state_hit_object_inline.h
                                                    ai/Monsters/States/state_test_look_actor.h
                                                    ai/Monsters/States/state_test_look_actor_inline.h
                                                    ai/Monsters/States/state_test_state.h
                                                    ai/Monsters/States/state_test_state_inline.h)

set(AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_BASE_CONTROLLERS_MOVEMENT ai/Monsters/control_movement_base.h
                                                                             ai/Monsters/control_movement_base.cpp)

set(AI_AMONSTERS_MONSTERS_RATS_STATES_BASE rat_state_base.h
                                           rat_state_base_inline.h
                                           rat_state_base.cpp)

set(AI_ALIFE_SERVER_ENTITIES_ANOMALOUS_ZONE alife_anomalous_zone.cpp)

set(CORE_CLIENT_OBJECTS_PHYSICS_BREAKABLE BreakableObject.h
                                          BreakableObject.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_BOLT Bolt.h
                                                                         Bolt.cpp)

set(CORE_COMMON_DEBUG_STATIC_CAST_CHECKED static_cast_checked.hpp)

set(AI_ALIFE_SERVER_ENTITIES_HUMAN alife_human_abstract.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_FORT WeaponFORT.h
                                                                         WeaponFORT.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_EVENT_HANDLER_CUSTOM_EVENTS ai/Monsters/custom_events.h)

set(AI_AMONSTERS_MONSTERS_BLOODSUCKER_SCRIPT ai/Monsters/Bloodsucker/bloodsucker_script.cpp)

set(CORE ../xrServerEntities/pch_script.h
         StdAfx.h
         ../xrServerEntities/pch_script.cpp
         StdAfx.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTGAMEOBJECT script_game_object.h
                                              script_game_object_impl.h
                                              script_game_object.cpp
                                              script_game_object2.cpp
                                              script_game_object3.cpp
                                              script_game_object4.cpp
                                              script_game_object_inventory_owner.cpp
                                              script_game_object_script.cpp
                                              script_game_object_script2.cpp
                                              script_game_object_script3.cpp
                                              script_game_object_script_trader.cpp
                                              script_game_object_smart_covers.cpp
                                              script_game_object_trader.cpp
                                              script_game_object_use.cpp
                                              script_game_object_use2.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_GAMETYPES_SINGLE UIGameSP.h
                                                 UIGameSP.cpp)

set(CORE_CLIENT_OBJECTS_ZONES_RADIOACTIVEZONE RadioactiveZone.h
                                              RadioactiveZone.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTSOUND script_sound.h
                                         script_sound_inline.h
                                         script_sound.cpp
                                         script_sound_script.cpp)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_ATTACK ai/Monsters/States/monster_state_attack.h
                                              ai/Monsters/States/monster_state_attack_inline.h
                                              ai/Monsters/States/monster_state_attack_melee.h
                                              ai/Monsters/States/monster_state_attack_melee_inline.h
                                              ai/monsters/states/monster_state_attack_on_run.h
                                              ai/monsters/states/monster_state_attack_on_run_inline.h
                                              ai/Monsters/States/monster_state_attack_run.h
                                              ai/monsters/states/monster_state_attack_run_attack.h
                                              ai/monsters/states/monster_state_attack_run_attack_inline.h
                                              ai/Monsters/States/monster_state_attack_run_inline.h)

set(CORE_CLIENT_OBJECTS_PHYSICS_CHARACTERSUPPORT_DEATH_ANIMS death_anims.h
                                                             death_anims.cpp
                                                             death_anims_predicates.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_USP45 WeaponUSP45.h
                                                                                 WeaponUSP45.cpp)

set(AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONPLANNERACTION action_planner_action.h
                                                                           action_planner_action_inline.h
                                                                           action_planner_action_script.cpp)

set(AI_AGROUP_AGENT_MANAGER_AGENT_PLANNER agent_manager_planner.h
                                          agent_manager_planner.cpp)

set(AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTIONHOLDER_SPACERESTRICTIONABSTRACT space_restriction_abstract.h
                                                                                           space_restriction_abstract_inline.h)

set(AI_ALIFE_SERVER_ENTITIES_TRADER alife_trader.cpp)

set(CORE_SERVER_GAMES game_base.h
                      game_base_kill_type.h
                      game_base_menu_events.h
                      ../xrServerEntities/game_base_space.h
                      game_base.cpp)

set(AI_AEVAL_STORAGE ef_storage.h
                     ef_storage_inline.h
                     ef_storage.cpp
                     ef_storage_script.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_INVENTORYWND_INVENTORYUPGRADE ui/UIInventoryUpgradeWnd.h
                                                                     ui/UIInvUpgrade.h
                                                                     ui/UIInvUpgradeInfo.h
                                                                     ui/UIInvUpgradeProperty.h
                                                                     ui/UIInventoryUpgradeWnd.cpp
                                                                     ui/UIInventoryUpgradeWnd_add.cpp
                                                                     ui/UIInvUpgrade.cpp
                                                                     ui/UIInvUpgradeInfo.cpp
                                                                     ui/UIInvUpgradeProperty.cpp)

set(AI_AMONSTERS_COMMON_MISCELLANEOUS ai_monster_space.h
                                      AI/ai_monsters_anims.h
                                      AI/ai_monsters_misc.h
                                      ai/position_prediction.h
                                      AI/ai_monsters_misc.cpp)

set(CORE_CLIENT_OBJECTS_PHYSICS_HIT Hit.h
                                    Hit.cpp)

set(AI_ALIFE_SERVER_ENTITIES_ONLINE_OFFLINE_GROUP alife_online_offline_group.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_GRENADE_ACTIONS stalker_danger_grenade_actions.h
                                                                                     stalker_danger_grenade_actions.cpp)

set(CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_RELATION_REGISTRY relation_registry.h
                                                                   relation_registry_defs.h
                                                                   relation_registry_inline.h
                                                                   relation_registry.cpp
                                                                   relation_registry_actions.cpp
                                                                   relation_registry_fights.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_ANOMALY_DETECTOR ai/Monsters/anomaly_detector.h
                                                    ai/Monsters/anomaly_detector.cpp)

set(AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTIONHOLDER_SPACERESTRICTIONBRIDGE space_restriction_bridge.h
                                                                                         space_restriction_bridge_inline.h
                                                                                         space_restriction_bridge.cpp)

set(AI_AMONSTERS_MONSTERS_FRACTURE ai/Monsters/Fracture/fracture.h
                                   ai/Monsters/Fracture/fracture_state_manager.h
                                   ai/Monsters/Fracture/fracture.cpp
                                   ai/Monsters/Fracture/fracture_state_manager.cpp)

set(AI_AMONSTERS_MONSTERS_POLTERGEIST_HIDDEN_ATTACK ai/Monsters/Poltergeist/poltergeist_state_attack_hidden.h
                                                    ai/Monsters/Poltergeist/poltergeist_state_attack_hidden_inline.h)

set(CORE_CLIENT_LEVEL_SENIORITYHIERARCHYHOLDER ../xrServerEntities/LevelGameDef.h
                                               seniority_hierarchy_holder.h
                                               seniority_hierarchy_holder_inline.h
                                               seniority_hierarchy_space.h
                                               ../xrServerEntities/LevelGameDef.cpp
                                               seniority_hierarchy_holder.cpp)

set(AI_ALIFE_SERVER_ENTITIES_MONSTER_ABSTRACT_BRAIN ../xrServerEntities/alife_monster_brain.h
                                                    ../xrServerEntities/alife_monster_brain_inline.h
                                                    ../xrServerEntities/alife_monster_brain.cpp
                                                    alife_monster_brain_script.cpp)

set(AI_ACOVER_SMART_COVER_STORAGE_DESCRIPTION_TRANSITIONS_TRANSITION smart_cover_transition.hpp
                                                                     smart_cover_transition.cpp)

set(CORE_CLIENT_OBJECTS_ZONES_TORRIDZONE TorridZone.h
                                         TorridZone.cpp)

set(AI_ACOMPONENTS_SIGHTMANAGER_AIMERS_BASE aimers_base.h
                                            aimers_base_inline.h
                                            aimers_base.cpp)

set(CORE_COMMON_QUADTREE quadtree.h
                         quadtree_inline.h)

set(AI_ASCRIPT_SCRIPTTHREAD ../xrServerEntities/script_thread.h
                            ../xrServerEntities/script_thread_inline.h
                            ../xrServerEntities/script_thread.cpp)

set(AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_GAME path_manager_game.h
                                                              path_manager_game_inline.h)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_DRAGDROP ui/UICellCustomItems.h
                                                   ui/UICellItem.h
                                                   ui/UICellItemFactory.h
                                                   ui/UIDragDropListEx.h
                                                   ui/UIDragDropReferenceList.h
                                                   ui/UICellCustomItems.cpp
                                                   ui/UICellItem.cpp
                                                   ui/UICellItemFactory.cpp
                                                   ui/UIDragDropListEx.cpp
                                                   ui/UIDragDropReferenceList.cpp)

set(CORE_CLIENT_LEVEL Level.h
                      Level.cpp
                      Level_input.cpp
                      Level_load.cpp
                      level_map_locations.cpp
                      Level_network.cpp
                      Level_network_compressed_updates.cpp
                      Level_network_messages.cpp
                      Level_network_spawn.cpp
                      Level_network_start_client.cpp
                      level_script.cpp
                      Level_secure_messaging.cpp
                      Level_SLS_Default.cpp
                      Level_SLS_Load.cpp
                      Level_SLS_Save.cpp
                      Level_start.cpp)

set(AI_AMONSTERS_MONSTERS_SNORK ai/Monsters/Snork/snork.h
                                ai/Monsters/Snork/snork_state_manager.h
                                ai/Monsters/Snork/snork.cpp
                                ai/Monsters/Snork/snork_state_manager.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_BASE_VELOCITY_HOLDER stalker_velocity_holder.h
                                                                     stalker_velocity_holder_inline.h
                                                                     stalker_velocity_holder.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_RGD5 RGD5.h
                                                                         RGD5.cpp)

set(AI_ALIFE_INTERACTION_MANAGER_COMBAT_MANAGER alife_combat_manager.h
                                                alife_combat_manager_inline.h
                                                alife_combat_manager.cpp)

set(CORE_CLIENT_LEVEL_SENIORITYHIERARCHYHOLDER_SQUADHIERARCHYHOLDER squad_hierarchy_holder.h
                                                                    squad_hierarchy_holder_inline.h
                                                                    squad_hierarchy_holder.cpp)

set(CORE_CLIENT_EFFECTORS_ACTOR ActorEffector.h
                                CameraEffector.h
                                EffectorBobbing.h
                                EffectorFall.h
                                ActorEffector.cpp
                                ActorEffector_script.cpp
                                CameraEffector.cpp
                                EffectorBobbing.cpp
                                EffectorFall.cpp)

set(AI_ASCRIPT_SCRIPTDEBUGGER ../xrServerEntities/mslotutils.h
                              ../xrServerEntities/script_callStack.h
                              ../xrServerEntities/script_debugger.h
                              ../xrServerEntities/script_debugger_messages.h
                              ../xrServerEntities/script_debugger_threads.h
                              ../xrServerEntities/script_lua_helper.h
                              ../xrServerEntities/script_callStack.cpp
                              ../xrServerEntities/script_debugger.cpp
                              ../xrServerEntities/script_debugger_threads.cpp
                              ../xrServerEntities/script_lua_helper.cpp)

set(AI_ACOMPONENTS_SIGHTMANAGER_AIMERS_BONE aimers_bone.h
                                            aimers_bone_inline.h)

set(AI_AMONSTERS_COMMON_TRAJECTORIES trajectories.h
                                     trajectories.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR_ANIMATION_PLANNER_TARGET_SELECTOR smart_cover_planner_target_selector.h
                                                                                                                  smart_cover_planner_target_selector_inline.h
                                                                                                                  smart_cover_planner_target_selector.cpp)

set(CORE_COMMON_OBJECTFACTORY_OBJECT_ITEM_SINGLE ../xrServerEntities/object_item_single.h
                                                 ../xrServerEntities/object_item_single_inline.h)

set(AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_BASE_CONTROLLERS_PATH_BUILDER ai/Monsters/control_path_builder_base.h
                                                                                 ai/Monsters/control_path_builder_base_inline.h
                                                                                 ai/Monsters/control_path_builder_base.cpp
                                                                                 ai/Monsters/control_path_builder_base_path.cpp
                                                                                 ai/Monsters/control_path_builder_base_set.cpp
                                                                                 ai/Monsters/control_path_builder_base_update.cpp)

set(AI_ACOMPONENTS_MOVEMENTMANAGER_PATHMANAGERS_ABSTRACTPATHMANAGER abstract_path_manager.h
                                                                    abstract_path_manager_inline.h)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTFVECTOR ../xrServerEntities/script_fvector.h
                                           ../xrServerEntities/script_fvector_script.cpp)

set(AI_ACOMPONENTS_MOVEMENTMANAGER_PATHMANAGERS_GAMEPATHMANAGER game_path_manager.h
                                                                game_path_manager_inline.h)

set(CORE_CLIENT_OBJECTS_INVENTORY Inventory.h
                                  ../xrServerEntities/inventory_space.h
                                  Inventory.cpp
                                  inventory_quickswitch.cpp)

set(AI_ALIFE_INVENTORY_UPGRADE inventory_upgrade_manager.h
                               inventory_upgrade_manager_inline.h
                               inventory_upgrade_manager.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_ARROW ui/ui_arrow.h
                                                ui/ui_arrow.cpp)

set(AI_ASOUND ../xrServerEntities/ai_sounds.h
              ai_sounds.cpp)

set(AI_ALIFE_SERVER_ENTITIES_SMART_ZONE alife_smart_zone.cpp)

set(CORE_CLIENT_OBJECTS_ACTOR_BASE Actor.h
                                   actor_anim_defs.h
                                   actor_defs.h
                                   Actor_Flags.h
                                   actor_input_handler.h
                                   ActorAnimation.h
                                   ActorCondition.h
                                   fire_disp_controller.h
                                   Actor.cpp
                                   actor_communication.cpp
                                   Actor_Events.cpp
                                   Actor_Feel.cpp
                                   actor_input_handler.cpp
                                   Actor_Movement.cpp
                                   Actor_Network.cpp
                                   actor_script.cpp
                                   Actor_Sleep.cpp
                                   Actor_Weapon.cpp
                                   ActorAnimation.cpp
                                   ActorCameras.cpp
                                   ActorCondition.cpp
                                   ActorInput.cpp
                                   ActorMountedWeapon.cpp
                                   ActorVehicle.cpp
                                   fire_disp_controller.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_ABILITIES_TELEKINESIS ai/Monsters/telekinesis.h
                                                         ai/Monsters/telekinesis_inline.h
                                                         ai/Monsters/telekinetic_object.h
                                                         TeleWhirlwind.h
                                                         ai/Monsters/telekinesis.cpp
                                                         ai/Monsters/telekinetic_object.cpp
                                                         TeleWhirlwind.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_HUDITEM hud_item_object.h
                                                    HudItem.h
                                                    HudSound.h
                                                    player_hud.h
                                                    hud_item_object.cpp
                                                    HudItem.cpp
                                                    HudSound.cpp
                                                    player_hud.cpp
                                                    player_hud_tune.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_LR300 WeaponLR300.h
                                                                          WeaponLR300.cpp)

set(CORE_CLIENT_OBJECTS_HANGING_LAMP HangingLamp.h
                                     HangingLamp.cpp)

set(AI_ACOMPONENTS_MOVEMENTMANAGER movement_manager.h
                                   movement_manager_impl.h
                                   movement_manager_inline.h
                                   movement_manager_space.h
                                   movement_manager.cpp
                                   movement_manager_game.cpp
                                   movement_manager_level.cpp
                                   movement_manager_patrol.cpp
                                   movement_manager_physic.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_GALANTINEARTIFACT GalantineArtifact.h
                                                                        GalantineArtifact.cpp)

set(CORE_CLIENT_OBJECTS_INVENTORY_PHYSICITEM physic_item.h
                                             physic_item_inline.h
                                             physic_item.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTBINDEROBJECT script_binder_object.h
                                                script_binder_object.cpp
                                                script_binder_object_script.cpp)

set(AI_ACOMPONENTS_MOVEMENTMANAGER_LOCATIONSELECTORS_LEVELLOCATIONSELECTOR level_location_selector.h
                                                                           level_location_selector_inline.h)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER stalker_danger_planner.h
                                                             stalker_danger_planner_inline.h
                                                             stalker_danger_planner.cpp)

set(CORE_CLIENT_OBJECTS_ZONES_TEAMBASEZONE team_base_zone.h
                                           team_base_zone.cpp)

set(AI_ALIFE_SIMULATOR_BASE_REGISTRIES_SCHEDULE_REGISTRY alife_schedule_registry.h
                                                         alife_schedule_registry_inline.h
                                                         alife_schedule_registry.cpp)

set(AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTIONHOLDER_SPACERESTRICTIONCOMPOSITION space_restriction_composition.h
                                                                                              space_restriction_composition_inline.h
                                                                                              space_restriction_composition.cpp)

set(AI_ANAVIGATION_PATHFINDING_DATASTORAGES_CONSTRUCTORS_MANAGER_BUILDER_ALLOCATOR manager_builder_allocator_constructor.h
                                                                                   manager_builder_allocator_constructor_inline.h)

set(AI_AMONSTERS_MONSTERS_CROW AI/Crow/ai_crow.h
                               AI/Crow/ai_crow.cpp
                               ai_crow_script.cpp)

set(AI_ASCRIPT_SCRIPTENGINE ../xrServerEntities/script_engine.h
                            ../xrServerEntities/script_engine_inline.h
                            ../xrServerEntities/script_engine_space.h
                            ../xrServerEntities/script_engine.cpp
                            ../xrServerEntities/script_engine_export.cpp
                            script_engine_help.cpp
                            ../xrServerEntities/script_engine_script.cpp)

set(CORE_CLIENT_OBJECTS_PHYSICS_PHYSICSSOUNDPLAYER moving_bones_snd_player.h
                                                   PHSoundPlayer.h
                                                   moving_bones_snd_player.cpp
                                                   PHSoundPlayer.cpp)

set(CORE_CLIENT_OBJECTS_ZONES_NOGRAVITYZONE NoGravityZone.h
                                            NoGravityZone.cpp)

set(AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONPLANNER_SCRIPTACTIONPLANNERWRAPPER script_action_planner_wrapper.h
                                                                                                script_action_planner_wrapper_inline.h
                                                                                                script_action_planner_wrapper.cpp)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_GENERAL_CUSTOM_ACTION ai/Monsters/States/state_custom_action.h
                                                             ai/Monsters/States/state_custom_action_inline.h
                                                             ai/Monsters/States/state_custom_action_look.h
                                                             ai/Monsters/States/state_custom_action_look_inline.h)

set(AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTIONHOLDER space_restriction_holder.h
                                                                  space_restriction_holder_inline.h
                                                                  space_restriction_holder.cpp)

set(CORE_SERVER_SERVERENTITIES_OBJECTS_ALIFE_SMARTCOVER ../xrServerEntities/xrServer_Objects_Alife_Smartcovers.h
                                                        ../xrServerEntities/xrServer_Objects_Alife_Smartcovers.cpp
                                                        ../xrServerEntities/xrServer_Objects_Alife_Smartcovers_script.cpp)

set(CORE_COMMON_ASSOCIATIVE_VECTOR_COMPARE ../xrServerEntities/associative_vector_compare_predicate.h
                                           ../xrServerEntities/associative_vector_compare_predicate_inline.h)

set(CORE_CLIENT_LEVEL_SENIORITYHIERARCHYHOLDER_GROUPHIERARCHYHOLDER group_hierarchy_holder.h
                                                                    group_hierarchy_holder_inline.h
                                                                    group_hierarchy_holder.cpp)

set(AI_AGROUP_AGENT_MANAGER_AGENT_CORPSE_MANAGER agent_corpse_manager.h
                                                 agent_corpse_manager_inline.h
                                                 agent_corpse_manager.cpp)

set(CORE_CLIENT_OBJECTS_PHYSICS_CHARACTERSUPPORT_INTERACTIVE_ANIMS interactive_animation.h
                                                                   physics_shell_animated.h
                                                                   interactive_animation.cpp
                                                                   physics_shell_animated.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTSOUNDINFO script_sound_info.h
                                             script_sound_info_script.cpp)

set(AI_ALIFE_SERVER_ENTITIES_MONSTER_ABSTRACT alife_monster_abstract.cpp
                                              alife_monster_base.cpp)

set(AI_AGROUP_AGENT_MANAGER_AGENT_MEMORY_MANAGER agent_memory_manager.h
                                                 agent_memory_manager_inline.h
                                                 agent_memory_manager.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_COVEREVALUATORS cover_evaluators.h
                                                cover_evaluators_inline.h
                                                cover_evaluators.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DEATH_ACTIONS stalker_death_actions.h
                                                                    stalker_death_actions.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR_ANIMATION_PLANNER smart_cover_animation_planner.h
                                                                                                  smart_cover_animation_planner_inline.h
                                                                                                  smart_cover_animation_planner.cpp)

set(AI_ANAVIGATION_OBJECTLOCATION ai_object_location.h
                                  ai_object_location_impl.h
                                  ai_object_location_inline.h)

set(AI_ACOMPONENTS_MATERIALMANAGER material_manager.h
                                   material_manager_inline.h
                                   material_manager.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_MOVEMENT_ACTION script_movement_action.h
                                                                  script_movement_action_inline.h
                                                                  script_movement_action.cpp
                                                                  script_movement_action_script.cpp)

set(AI_ACOMPONENTS_DOORS_MANAGER_DOOR doors_door.h
                                      doors_door.cpp)

set(AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_RUN_ATTACK ai/Monsters/control_run_attack.h
                                                                     ai/Monsters/control_run_attack.cpp)

set(CORE_COMMON_DLL_PROCESS_DETACH xrgame_dll_detach.cpp)

set(AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_LEVEL_NEAREST_VERTEX path_manager_level_nearest_vertex.h
                                                                              path_manager_level_nearest_vertex_inline.h)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_ENTITY_ACTION script_entity_action.h
                                                                script_entity_action_inline.h
                                                                script_entity_action.cpp
                                                                script_entity_action_script.cpp)

set(AI_ACOVER cover_manager.h
              cover_manager_inline.h
              cover_manager.cpp)

set(AI_AGROUP_AGENT_MANAGER_AGENT_EXPLOSIVE_MANAGER_DANGER_EXPLOSIVE danger_explosive.h
                                                                     danger_explosive_inline.h
                                                                     danger_explosive.cpp)

set(AI_ASPACE ai_space.h
              ai_space_inline.h
              ai_space.cpp)

set(AI_AMONSTERS_MONSTERS_ZOMBIE_STATES ai/Monsters/Zombie/zombie_state_attack_run.h
                                        ai/Monsters/Zombie/zombie_state_attack_run_inline.h)

set(AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_ACTION_CONDITION script_action_condition.h
                                                                   script_action_condition_inline.h
                                                                   script_action_condition.cpp
                                                                   script_action_condition_script.cpp)

set(AI_ACOMPONENTS_DOORS_MANAGER_MANAGER doors_manager.h
                                         doors_manager.cpp)

set(AI_AMONSTERS_COMMON_STEERING_BEHAVIOURS_COMPONENTS_COHESION steering_behaviour_cohesion.h)

set(AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_BASE_CONTROLLERS_DIRECTION ai/Monsters/control_direction_base.h
                                                                              ai/Monsters/control_direction_base.cpp)

set(CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_TRADE_PARAMETERS_TRADE_ACTION_PARAMETERS trade_action_parameters.h
                                                                                          trade_action_parameters_inline.h)

set(AI_ASCRIPT_SCRIPTSTORAGE ../xrServerEntities/script_storage.h
                             ../xrServerEntities/script_storage_inline.h
                             ../xrServerEntities/script_storage_space.h
                             ../xrServerEntities/script_storage.cpp)

set(CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_BASTARTIFACT BastArtifact.h
                                                                   BastArtifact.cpp)

set(AI_ALIFE_UPDATE_MANAGER_SWITCH_MANAGER alife_switch_manager.h
                                           alife_switch_manager_inline.h
                                           alife_switch_manager.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER_DATA_STORAGE stalker_animation_data_storage.h
                                                              stalker_animation_data_storage_inline.h
                                                              stalker_animation_data_storage.cpp)

set(AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONPLANNERACTION_SCRIPTACTIONPLANNERACTIONWRAPPER script_action_planner_action_wrapper.h
                                                                                                            script_action_planner_action_wrapper_inline.h
                                                                                                            script_action_planner_action_wrapper.cpp)

set(AI_ANAVIGATION_PATHFINDING_GRAPHENGINE graph_engine.h
                                           graph_engine_inline.h
                                           graph_engine_space.h)

set(AI_ACOVER_SMART_COVER_STORAGE_DESCRIPTION_LOOPHOLE smart_cover_loophole.h
                                                       smart_cover_loophole_inline.h
                                                       smart_cover_loophole.cpp)

set(CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_TRADE_PARAMETERS_TRADE_FACTORS trade_factors.h
                                                                                trade_factors_inline.h)

set(AI_AMONSTERS_MONSTERS_CAT_SCRIPT ai/Monsters/Cat/cat_script.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA_TASKS ui/UIMapLegend.h
                                                 ui/UISecondTaskWnd.h
                                                 ui/UITaskWnd.h
                                                 ui/UIMapLegend.cpp
                                                 ui/UISecondTaskWnd.cpp
                                                 ui/UITaskWnd.cpp)

set(CORE_COMMON_DEBUG_MAKE_FINAL debug_make_final.hpp
                                 debug_make_final_test.cpp)

set(AI_AMONSTERS_COMMON_MONSTER_STATES_FIND_ENEMY ai/Monsters/States/monster_state_find_enemy.h
                                                  ai/Monsters/States/monster_state_find_enemy_angry.h
                                                  ai/Monsters/States/monster_state_find_enemy_angry_inline.h
                                                  ai/Monsters/States/monster_state_find_enemy_inline.h
                                                  ai/Monsters/States/monster_state_find_enemy_look.h
                                                  ai/Monsters/States/monster_state_find_enemy_look_inline.h
                                                  ai/Monsters/States/monster_state_find_enemy_run.h
                                                  ai/Monsters/States/monster_state_find_enemy_run_inline.h
                                                  ai/Monsters/States/monster_state_find_enemy_walk.h
                                                  ai/Monsters/States/monster_state_find_enemy_walk_inline.h)

set(CORE_CLIENT_OBJECTS_PHYSICS_CHARACTERSUPPORT ActivatingCharCollisionDelay.h
                                                 animation_utils.h
                                                 character_shell_control.h
                                                 CharacterPhysicsSupport.h
                                                 ActivatingCharCollisionDelay.cpp
                                                 animation_utils.cpp
                                                 character_shell_control.cpp
                                                 CharacterPhysicsSupport.cpp)

set(AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_OBSTACLES_REFRESHABLE_OBSTACLES_QUERY refreshable_obstacles_query.h
                                                                                      refreshable_obstacles_query_inline.h)

set(CORE_CLIENT_OBJECTS_ZONES_LEVELCHANGER level_changer.h
                                           level_changer.cpp)

set(CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_AI_OBSTACLE_MIN_OBB_MAGIC_BOX magic_box3.h
                                                                      magic_box3_inline.h
                                                                      magic_box3.cpp)

set(AI_ASCRIPT_SCRIPTCLASSES script_bind_macroses.h)

set(CORE_COMMON_NET_SHARED_SECUREMESSAGES secure_messaging.h
                                          secure_messaging.cpp)

set(AI_AMONSTERS_MONSTERS_RATS_STATES rat_states.h
                                      ai/monsters/rats/rat_state_activation.cpp
                                      ai/monsters/rats/rat_state_initialize.cpp
                                      ai/monsters/rats/rat_state_switch.cpp
                                      rat_states.cpp)

source_group("Core\\Client\\Objects\\zones\\CustomZone" FILES ${CORE_CLIENT_OBJECTS_ZONES_CUSTOMZONE})
source_group("Core\\Client\\Level\\LevelNetworkDemo" FILES ${CORE_CLIENT_LEVEL_LEVELNETWORKDEMO})
source_group("AI\\ALife\\interaction_manager" FILES ${AI_ALIFE_INTERACTION_MANAGER})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\RPG7" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_RPG7})
source_group("AI\\ALife\\server_entities\\creature_abstract" FILES ${AI_ALIFE_SERVER_ENTITIES_CREATURE_ABSTRACT})
source_group("Core\\Server\\ServerEntities\\objects_alife" FILES ${CORE_SERVER_SERVERENTITIES_OBJECTS_ALIFE})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Devices\\Torch" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DEVICES_TORCH})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\TabControl" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_TABCONTROL})
source_group("AI\\AComponents\\DamageManager" FILES ${AI_ACOMPONENTS_DAMAGEMANAGER})
source_group("AI\\AGroup\\agent_manager\\agent_member_manager\\member_order" FILES ${AI_AGROUP_AGENT_MANAGER_AGENT_MEMBER_MANAGER_MEMBER_ORDER})
source_group("AI\\ACover\\smart_cover\\storage" FILES ${AI_ACOVER_SMART_COVER_STORAGE})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\Weapon Walther 99" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_WALTHER_99})
source_group("AI\\AMonsters\\monsters\\Controller\\Base Controllers\\Animation" FILES ${AI_AMONSTERS_MONSTERS_CONTROLLER_BASE_CONTROLLERS_ANIMATION})
source_group("AI\\AMonsters\\humans\\stalker\\MovementManager\\smart_covers\\animation_selector\\animation_planner\\cover_actions" FILES ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR_ANIMATION_PLANNER_COVER_ACTIONS})
source_group("AI\\AMonsters\\common\\monster states\\Steal\\Squad\\Rest" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_STEAL_SQUAD_REST})
source_group("Core\\Server\\Games\\server" FILES ${CORE_SERVER_GAMES_SERVER})
source_group("AI\\ANavigation\\Pathfinding\\DataStorages\\priority_queues" FILES ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_PRIORITY_QUEUES})
source_group("AI\\AMonsters\\common\\components\\Control Manager\\Custom\\Jump" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_JUMP})
source_group("AI\\AScript\\ScriptClasses\\ScriptActions\\script_monster_action" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_MONSTER_ACTION})
source_group("AI\\AMonsters\\monsters\\Cat" FILES ${AI_AMONSTERS_MONSTERS_CAT})
source_group("AI\\AGroup\\agent_manager\\agent_planner\\actions" FILES ${AI_AGROUP_AGENT_MANAGER_AGENT_PLANNER_ACTIONS})
source_group("AI\\AScript\\ScriptClasses\\ScriptEffector\\ScriptEffectorWrapper" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTEFFECTOR_SCRIPTEFFECTORWRAPPER})
source_group("AI\\ALife\\server_entities\\trader_abstract" FILES ${AI_ALIFE_SERVER_ENTITIES_TRADER_ABSTRACT})
source_group("AI\\AComponents\\DecisionManagement\\ActionManagement\\WorldPropertyEvaluator\\member" FILES ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_WORLDPROPERTYEVALUATOR_MEMBER})
source_group("AI\\AEval\\functions\\base" FILES ${AI_AEVAL_FUNCTIONS_BASE})
source_group("AI\\AComponents\\MovementManager\\LocationSelectors\\AbstractLocationSelector" FILES ${AI_ACOMPONENTS_MOVEMENTMANAGER_LOCATIONSELECTORS_ABSTRACTLOCATIONSELECTOR})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\Weapon RG6" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_RG6})
source_group("AI\\AMonsters\\monsters\\Dog" FILES ${AI_AMONSTERS_MONSTERS_DOG})
source_group("AI\\AComponents\\DecisionManagement" FILES ${AI_ACOMPONENTS_DECISIONMANAGEMENT})
source_group("AI\\AComponents\\SoundPlayer" FILES ${AI_ACOMPONENTS_SOUNDPLAYER})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\danger\\actions\\by_sound" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_BY_SOUND})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Devices\\Detectors" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DEVICES_DETECTORS})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Custom Weapon\\Automatic" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_AUTOMATIC})
source_group("Core\\Client\\Objects\\physics\\Climable" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_CLIMABLE})
source_group("AI\\ALife\\server_entities\\object" FILES ${AI_ALIFE_SERVER_ENTITIES_OBJECT})
source_group("AI\\AScript\\ScriptClasses\\UI\\Common\\PDA\\FactionWar" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA_FACTIONWAR})
source_group("AI\\AMonsters\\humans\\stalker\\MovementManager\\base\\restriction" FILES ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_BASE_RESTRICTION})
source_group("Core\\Client\\Objects\\base\\GameObject\\ai_obstacle\\min_obb" FILES ${CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_AI_OBSTACLE_MIN_OBB})
source_group("AI\\ALife\\inventory_upgrade\\property" FILES ${AI_ALIFE_INVENTORY_UPGRADE_PROPERTY})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\PM" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_PM})
source_group("AI\\AScript\\ScriptClasses\\ScriptFS" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTFS})
source_group("AI\\AMonsters\\monsters\\Burer" FILES ${AI_AMONSTERS_MONSTERS_BURER})
source_group("Core\\Client\\Cameras" FILES ${CORE_CLIENT_CAMERAS})
source_group("AI\\AMonsters\\monsters\\Controller\\Script" FILES ${AI_AMONSTERS_MONSTERS_CONTROLLER_SCRIPT})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\StationaryMgun" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_STATIONARYMGUN})
source_group("Core\\Common\\Profiler" FILES ${CORE_COMMON_PROFILER})
source_group("AI\\AMonsters\\humans\\trader" FILES ${AI_AMONSTERS_HUMANS_TRADER})
source_group("Core\\Client\\Objects\\inventory\\AttachmentOwner" FILES ${CORE_CLIENT_OBJECTS_INVENTORY_ATTACHMENTOWNER})
source_group("AI\\ALife\\server_entities\\group_abstract" FILES ${AI_ALIFE_SERVER_ENTITIES_GROUP_ABSTRACT})
source_group("AI\\AGroup\\agent_manager\\agent_location_manager" FILES ${AI_AGROUP_AGENT_MANAGER_AGENT_LOCATION_MANAGER})
source_group("Core\\Common\\Shared" FILES ${CORE_COMMON_SHARED})
source_group("AI\\AMonsters\\common\\base monster" FILES ${AI_AMONSTERS_COMMON_BASE_MONSTER})
source_group("AI\\AMonsters\\common\\components\\Control Manager\\Custom\\Threaten" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_THREATEN})
source_group("AI\\AScript\\ScriptThread\\ScriptStackTracker" FILES ${AI_ASCRIPT_SCRIPTTHREAD_SCRIPTSTACKTRACKER})
source_group("AI\\AMonsters\\common\\components\\Abilities\\Invisibility" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_ABILITIES_INVISIBILITY})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Explosives" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_EXPLOSIVES})
source_group("Core\\Common\\Random\\32bit" FILES ${CORE_COMMON_RANDOM_32BIT})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Custom Weapon\\Addons\\Scope" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_ADDONS_SCOPE})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\TrackBar" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_TRACKBAR})
source_group("AI\\AScript\\ScriptClasses\\ScriptMonsterHitInfo" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTMONSTERHITINFO})
source_group("AI\\AMonsters\\common\\components\\Abilities\\Controlled" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_ABILITIES_CONTROLLED})
source_group("AI\\AScript\\ScriptClasses\\ScriptBinderObject\\ScriptBinderObjectWrapper" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTBINDEROBJECT_SCRIPTBINDEROBJECTWRAPPER})
source_group("AI\\AMonsters\\humans\\stalker\\AnimationManager\\script" FILES ${AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER_SCRIPT})
source_group("Core\\Server\\Games\\client\\single" FILES ${CORE_SERVER_GAMES_CLIENT_SINGLE})
source_group("AI\\AMonsters\\monsters\\Poltergeist" FILES ${AI_AMONSTERS_MONSTERS_POLTERGEIST})
source_group("AI\\ANavigation\\GameGraph" FILES ${AI_ANAVIGATION_GAMEGRAPH})
source_group("AI\\AMonsters\\humans\\stalker\\MovementManager\\obstacles\\obstacle_avoiders\\dynamic" FILES ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_OBSTACLES_OBSTACLE_AVOIDERS_DYNAMIC})
source_group("AI\\AMonsters\\monsters\\Burer\\Attack" FILES ${AI_AMONSTERS_MONSTERS_BURER_ATTACK})
source_group("AI\\AScript\\ScriptClasses\\ScriptParticles" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTPARTICLES})
source_group("AI\\AMonsters\\common\\custom" FILES ${AI_AMONSTERS_COMMON_CUSTOM})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\Weapon Val" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_VAL})
source_group("Core\\Common\\Console Commands" FILES ${CORE_COMMON_CONSOLE_COMMANDS})
source_group("AI\\AMonsters\\common\\script\\script_object" FILES ${AI_AMONSTERS_COMMON_SCRIPT_SCRIPT_OBJECT})
source_group("AI\\AScript\\ScriptClasses\\ScriptActions\\acript_animation_action" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_ACRIPT_ANIMATION_ACTION})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\ListBox" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_LISTBOX})
source_group("AI\\AMonsters\\common\\components\\Control Manager\\Custom\\CriticalWound" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_CRITICALWOUND})
source_group("AI\\AMonsters\\monsters\\Bloodsucker\\Capture Jump" FILES ${AI_AMONSTERS_MONSTERS_BLOODSUCKER_CAPTURE_JUMP})
source_group("Core\\Common\\ObjectFactory" FILES ${CORE_COMMON_OBJECTFACTORY})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\anomaly" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_ANOMALY})
source_group("AI\\AScript\\ScriptClasses\\ScriptIniFile\\ScriptTokenList" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTINIFILE_SCRIPTTOKENLIST})
source_group("Core\\Server\\Games\\client\\base" FILES ${CORE_SERVER_GAMES_CLIENT_BASE})
source_group("Core\\Client\\Objects\\base\\GameObject\\ai_obstacle" FILES ${CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_AI_OBSTACLE})
source_group("AI\\AMonsters\\monsters\\PseudoGigant" FILES ${AI_AMONSTERS_MONSTERS_PSEUDOGIGANT})
source_group("Core\\Common\\ObjectFactory\\object_item_client_server" FILES ${CORE_COMMON_OBJECTFACTORY_OBJECT_ITEM_CLIENT_SERVER})
source_group("Core\\Client\\Objects\\inventory\\InventoryItem" FILES ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYITEM})
source_group("AI\\ANavigation\\GraphAbstract\\GraphEdge" FILES ${AI_ANAVIGATION_GRAPHABSTRACT_GRAPHEDGE})
source_group("AI\\AMonsters\\common\\monster states\\General\\Look" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_GENERAL_LOOK})
source_group("AI\\ALife\\inventory_upgrade\\upgrade_base" FILES ${AI_ALIFE_INVENTORY_UPGRADE_UPGRADE_BASE})
source_group("Core\\Client\\Objects\\vehicles\\heli" FILES ${CORE_CLIENT_OBJECTS_VEHICLES_HELI})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Artifacts" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS})
source_group("AI\\AMonsters\\monsters\\Boar" FILES ${AI_AMONSTERS_MONSTERS_BOAR})
source_group("Core\\Client\\Objects\\zones\\GraviZone" FILES ${CORE_CLIENT_OBJECTS_ZONES_GRAVIZONE})
source_group("AI\\ALife\\simulator_base\\registries\\spawn_registry" FILES ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_SPAWN_REGISTRY})
source_group("AI\\ACover\\smart_cover\\storage\\description" FILES ${AI_ACOVER_SMART_COVER_STORAGE_DESCRIPTION})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\Windows" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_WINDOWS})
source_group("AI\\AScript\\ScriptClasses\\UI\\Common\\InventoryUtilities" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_INVENTORYUTILITIES})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS})
source_group("AI\\AMonsters\\monsters\\Controller\\State Attack\\Cover" FILES ${AI_AMONSTERS_MONSTERS_CONTROLLER_STATE_ATTACK_COVER})
source_group("Core\\Client\\Objects\\physics\\scripts" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_SCRIPTS})
source_group("AI\\AComponents\\ObjectHandler\\planner\\actions" FILES ${AI_ACOMPONENTS_OBJECTHANDLER_PLANNER_ACTIONS})
source_group("Core\\Client\\Objects\\physics\\CharacterSupport\\hit_anims" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_CHARACTERSUPPORT_HIT_ANIMS})
source_group("Core\\Common\\ObjectFactory\\object_item_script" FILES ${CORE_COMMON_OBJECTFACTORY_OBJECT_ITEM_SCRIPT})
source_group("AI\\AGroup\\agent_manager\\agent_explosive_manager" FILES ${AI_AGROUP_AGENT_MANAGER_AGENT_EXPLOSIVE_MANAGER})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Artifacts\\Faded Ball" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_FADED_BALL})
source_group("AI\\AMonsters\\common\\components\\Abilities\\Scan" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_ABILITIES_SCAN})
source_group("AI\\AComponents\\DecisionManagement\\ActionManagement\\ActionPlanner" FILES ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONPLANNER})
source_group("AI\\ANavigation\\Pathfinding\\DataStorages\\constructors" FILES ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_CONSTRUCTORS})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\ScriptWnd" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_SCRIPTWND})
source_group("AI\\ALife\\simulator_base\\registries\\graph_registry" FILES ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_GRAPH_REGISTRY})
source_group("AI\\AMonsters\\common\\script\\script_entity" FILES ${AI_AMONSTERS_COMMON_SCRIPT_SCRIPT_ENTITY})
source_group("AI\\AMonsters\\common\\components\\Control Manager" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER})
source_group("AI\\AMonsters\\common\\components\\Home" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_HOME})
source_group("AI\\ALife\\server_entities\\dynamic_object" FILES ${AI_ALIFE_SERVER_ENTITIES_DYNAMIC_OBJECT})
source_group("Core\\Server\\ServerPerform" FILES ${CORE_SERVER_SERVERPERFORM})
source_group("AI\\AScript\\ScriptClasses\\ScriptHit" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTHIT})
source_group("AI\\AComponents\\DecisionManagement\\ActionManagement\\WorldPropertyEvaluator\\ScriptPropertyEvaluatorWrapper" FILES ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_WORLDPROPERTYEVALUATOR_SCRIPTPROPERTYEVALUATORWRAPPER})
source_group("AI\\AMonsters\\humans\\stalker\\MovementManager\\obstacles\\obstacle_avoiders\\static" FILES ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_OBSTACLES_OBSTACLE_AVOIDERS_STATIC})
source_group("AI\\AMonsters\\monsters\\Bloodsucker\\Predator State" FILES ${AI_AMONSTERS_MONSTERS_BLOODSUCKER_PREDATOR_STATE})
source_group("AI\\AMonsters\\monsters\\DogPsy" FILES ${AI_AMONSTERS_MONSTERS_DOGPSY})
source_group("AI\\AComponents\\SoundPlayer\\sound_collection_storage" FILES ${AI_ACOMPONENTS_SOUNDPLAYER_SOUND_COLLECTION_STORAGE})
source_group("AI\\AMonsters\\humans\\stalker\\AnimationManager" FILES ${AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER})
source_group("Core\\Common\\NET Shared" FILES ${CORE_COMMON_NET_SHARED})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Documents" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DOCUMENTS})
source_group("AI\\AEval\\functions\\primary" FILES ${AI_AEVAL_FUNCTIONS_PRIMARY})
source_group("AI\\AMonsters\\monsters\\Tushkano\\Script" FILES ${AI_AMONSTERS_MONSTERS_TUSHKANO_SCRIPT})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\Weapon Vintorez" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_VINTOREZ})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Devices\\Detectors\\EliteDetector" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DEVICES_DETECTORS_ELITEDETECTOR})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\alife\\task_actions" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_ALIFE_TASK_ACTIONS})
source_group("AI\\AScript\\ScriptClasses\\UI\\Common\\PDA" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Devices\\Detectors\\AdvancedDetector" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DEVICES_DETECTORS_ADVANCEDDETECTOR})
source_group("AI\\AMonsters\\common\\components\\Control Manager\\Pure Coms\\Animation" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_PURE_COMS_ANIMATION})
source_group("AI\\ALife\\simulator_base\\time_manager" FILES ${AI_ALIFE_SIMULATOR_BASE_TIME_MANAGER})
source_group("AI\\AComponents\\SpaceRestrictionManager\\SpaceRestriction" FILES ${AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTION})
source_group("AI\\AMonsters\\monsters\\Chimera\\Script" FILES ${AI_AMONSTERS_MONSTERS_CHIMERA_SCRIPT})
source_group("AI\\ACover\\smart_cover\\detail" FILES ${AI_ACOVER_SMART_COVER_DETAIL})
source_group("AI\\AScript\\ScriptClasses\\UI\\Common\\MainIngame" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_MAININGAME})
source_group("AI\\AGroup\\agent_manager" FILES ${AI_AGROUP_AGENT_MANAGER})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Artifacts\\BlackDrops" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_BLACKDROPS})
source_group("AI\\AScript\\ScriptClasses\\ScriptCallbackEx" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTCALLBACKEX})
source_group("AI\\AMonsters\\monsters\\Snork\\Script" FILES ${AI_AMONSTERS_MONSTERS_SNORK_SCRIPT})
source_group("AI\\ANavigation\\Pathfinding\\DataStorages\\priority_queues\\bucket_list" FILES ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_PRIORITY_QUEUES_BUCKET_LIST})
source_group("AI\\ALife\\simulator_base\\registry_container" FILES ${AI_ALIFE_SIMULATOR_BASE_REGISTRY_CONTAINER})
source_group("Core\\Client\\Objects\\zones\\FryUpZone" FILES ${CORE_CLIENT_OBJECTS_ZONES_FRYUPZONE})
source_group("AI\\AScript\\ScriptClasses\\ScriptSoundType" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTSOUNDTYPE})
source_group("AI\\AScript\\ScriptClasses\\UI\\Common\\ui-item-infos" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_UI_ITEM_INFOS})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Custom Weapon\\Grenades &amp; Missiles" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_GRENADES__AND__MISSILES})
source_group("AI\\ALife\\inventory_upgrade\\upgrade_group" FILES ${AI_ALIFE_INVENTORY_UPGRADE_UPGRADE_GROUP})
source_group("Core\\Client\\Objects\\inventory\\InventoryOwner\\trade_parameters\\trade_bool_parameters" FILES ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_TRADE_PARAMETERS_TRADE_BOOL_PARAMETERS})
source_group("AI\\AGroup\\agent_manager\\agent_member_manager" FILES ${AI_AGROUP_AGENT_MANAGER_AGENT_MEMBER_MANAGER})
source_group("AI\\AMonsters\\humans\\stalker\\MovementManager\\smart_covers\\animation_selector\\animation_planner\\target_selector\\target_provider" FILES ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR_ANIMATION_PLANNER_TARGET_SELECTOR_TARGET_PROVIDER})
source_group("AI\\ANavigation\\Pathfinding\\PathManagers\\path_manager_params" FILES ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_PARAMS})
source_group("AI\\AComponents\\ObjectHandler" FILES ${AI_ACOMPONENTS_OBJECTHANDLER})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\danger\\actions\\by_sound\\actions" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_BY_SOUND_ACTIONS})
source_group("Core\\Client\\Objects\\zones\\campfire" FILES ${CORE_CLIENT_OBJECTS_ZONES_CAMPFIRE})
source_group("AI\\ACover\\cover_point" FILES ${AI_ACOVER_COVER_POINT})
source_group("Core\\Client\\Objects\\base\\GameObject\\Holder\\ParticlesPlayer" FILES ${CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_HOLDER_PARTICLESPLAYER})
source_group("Core\\Client\\Level\\SeniorityHierarchyHolder\\TeamHierarchyHolder" FILES ${CORE_CLIENT_LEVEL_SENIORITYHIERARCHYHOLDER_TEAMHIERARCHYHOLDER})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\ProgressBar" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_PROGRESSBAR})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Artifacts\\ThornArtifact" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_THORNARTIFACT})
source_group("AI\\AMonsters\\common\\monster states\\ALife" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_ALIFE})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\danger\\properties" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_PROPERTIES})
source_group("Core\\Server\\Editor" FILES ${CORE_SERVER_EDITOR})
source_group("AI\\AComponents\\DecisionManagement\\ActionManagement\\PropertyStorage" FILES ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_PROPERTYSTORAGE})
source_group("Core\\Client\\Objects\\inventory\\AttachableItem" FILES ${CORE_CLIENT_OBJECTS_INVENTORY_ATTACHABLEITEM})
source_group("AI\\AScript\\ScriptClasses\\ScriptRenderDevice" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTRENDERDEVICE})
source_group("Core\\Client\\Objects\\vehicles\\Car" FILES ${CORE_CLIENT_OBJECTS_VEHICLES_CAR})
source_group("Core\\Client\\Objects\\physics" FILES ${CORE_CLIENT_OBJECTS_PHYSICS})
source_group("AI\\AMonsters\\common\\monster states\\Interesting Sound" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_INTERESTING_SOUND})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Custom Weapon\\RocketLauncher" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_ROCKETLAUNCHER})
source_group("AI\\AComponents\\MemoryManager\\raw_data_managers\\VisualMemoryManager" FILES ${AI_ACOMPONENTS_MEMORYMANAGER_RAW_DATA_MANAGERS_VISUALMEMORYMANAGER})
source_group("Core\\Client\\Game Persistent" FILES ${CORE_CLIENT_GAME_PERSISTENT})
source_group("AI\\AMonsters\\common\\monster states\\Controlled" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_CONTROLLED})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\Weapon Shotgun" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_SHOTGUN})
source_group("AI\\AComponents\\MemoryManager\\raw_data_managers\\VisualMemoryManager\\vision_client" FILES ${AI_ACOMPONENTS_MEMORYMANAGER_RAW_DATA_MANAGERS_VISUALMEMORYMANAGER_VISION_CLIENT})
source_group("Core\\Client\\Objects\\zones\\ZoneVisual" FILES ${CORE_CLIENT_OBJECTS_ZONES_ZONEVISUAL})
source_group("Core\\Client\\Objects\\zones\\SpaceRestrictor" FILES ${CORE_CLIENT_OBJECTS_ZONES_SPACERESTRICTOR})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\XML" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_XML})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\combat\\kill_wounded" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_KILL_WOUNDED})
source_group("AI\\AScript\\ScriptClasses\\UI\\HUD" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_HUD})
source_group("Core\\Client\\Objects\\physics\\CollisionDamageReceiver" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_COLLISIONDAMAGERECEIVER})
source_group("AI\\AMonsters\\humans\\stalker" FILES ${AI_AMONSTERS_HUMANS_STALKER})
source_group("AI\\ALife\\update_manager\\surge_manager" FILES ${AI_ALIFE_UPDATE_MANAGER_SURGE_MANAGER})
source_group("AI\\AComponents\\MemoryManager\\clsuterized_data_managers\\EnemyManager" FILES ${AI_ACOMPONENTS_MEMORYMANAGER_CLSUTERIZED_DATA_MANAGERS_ENEMYMANAGER})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\SVD" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_SVD})
source_group("AI\\AMonsters\\common\\monster states\\Rest" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_REST})
source_group("AI\\ALife\\simulator_base\\registries\\group_registry" FILES ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_GROUP_REGISTRY})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\Weapon AutomaticShotgun" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_AUTOMATICSHOTGUN})
source_group("AI\\AMonsters\\common\\steering behaviours" FILES ${AI_AMONSTERS_COMMON_STEERING_BEHAVIOURS})
source_group("Core\\Client\\Objects\\physics\\DamagableItem" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_DAMAGABLEITEM})
source_group("Core\\Client\\Spectator\\Cameras" FILES ${CORE_CLIENT_SPECTATOR_CAMERAS})
source_group("Core\\Client\\Objects\\inventory\\EatableItem" FILES ${CORE_CLIENT_OBJECTS_INVENTORY_EATABLEITEM})
source_group("AI\\AGroup\\agent_manager\\agent_location_manager\\danger_cover_location" FILES ${AI_AGROUP_AGENT_MANAGER_AGENT_LOCATION_MANAGER_DANGER_COVER_LOCATION})
source_group("AI\\AComponents\\MovementManager\\RestrictedObject" FILES ${AI_ACOMPONENTS_MOVEMENTMANAGER_RESTRICTEDOBJECT})
source_group("AI\\AMonsters\\monsters\\Zombie\\Script" FILES ${AI_AMONSTERS_MONSTERS_ZOMBIE_SCRIPT})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\Grenade F1" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_GRENADE_F1})
source_group("AI\\AComponents\\MovementManager\\PathManagers\\PatrolPathManager" FILES ${AI_ACOMPONENTS_MOVEMENTMANAGER_PATHMANAGERS_PATROLPATHMANAGER})
source_group("AI\\AMonsters\\common\\components\\Abilities\\Psy Aura" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_ABILITIES_PSY_AURA})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Food &amp; Drugs" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_FOOD__AND__DRUGS})
source_group("Core\\Client\\Objects\\base\\GameObject\\Holder" FILES ${CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_HOLDER})
source_group("Core\\Client\\Objects\\tasks_info_dialogs\\map" FILES ${CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS_MAP})
source_group("Core\\Client\\Objects\\base\\GameObject" FILES ${CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT})
source_group("AI\\AComponents\\ProblemSolver\\condition_state\\ScriptWorldState" FILES ${AI_ACOMPONENTS_PROBLEMSOLVER_CONDITION_STATE_SCRIPTWORLDSTATE})
source_group("Core\\Client\\Objects\\tasks_info_dialogs\\news" FILES ${CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS_NEWS})
source_group("AI\\AComponents\\DecisionManagement\\ActionManagement\\ActionBase\\ScriptActionWrapper" FILES ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONBASE_SCRIPTACTIONWRAPPER})
source_group("Core\\Server\\ServerEntities\\objects_alife_items" FILES ${CORE_SERVER_SERVERENTITIES_OBJECTS_ALIFE_ITEMS})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Custom Weapon\\Addons\\Silencer" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_ADDONS_SILENCER})
source_group("AI\\AMonsters\\common\\components\\Squad\\Squad Manager" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_SQUAD_SQUAD_MANAGER})
source_group("Core\\Server\\ServerConnect" FILES ${CORE_SERVER_SERVERCONNECT})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\Lines" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_LINES})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\danger\\actions\\unknown" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_UNKNOWN})
source_group("Core\\Common\\SmartCast" FILES ${CORE_COMMON_SMARTCAST})
source_group("AI\\AScript\\ScriptClasses\\UI\\Common\\OptionsItem" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_OPTIONSITEM})
source_group("AI\\AMonsters\\common\\components\\Control Manager\\Custom\\Sequencer" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_SEQUENCER})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Artifacts\\Electric Ball" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_ELECTRIC_BALL})
source_group("AI\\AScript\\ScriptClasses\\ScriptFlags" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTFLAGS})
source_group("Core\\Client\\Level Controller" FILES ${CORE_CLIENT_LEVEL_CONTROLLER})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\combat\\actions" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_ACTIONS})
source_group("Core\\Client\\Effectors\\monsters_qqq" FILES ${CORE_CLIENT_EFFECTORS_MONSTERS_QQQ})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\Binocular" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_BINOCULAR})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\Buttons" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_BUTTONS})
source_group("AI\\AScript\\lua_studio" FILES ${AI_ASCRIPT_LUA_STUDIO})
source_group("AI\\ACover\\smart_cover\\storage\\description\\loophole\\action" FILES ${AI_ACOVER_SMART_COVER_STORAGE_DESCRIPTION_LOOPHOLE_ACTION})
source_group("AI\\AMonsters\\humans\\stalker\\MovementManager\\smart_covers\\animation_selector" FILES ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR})
source_group("Core\\Client\\Objects\\physics\\animation_movement_controller" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_ANIMATION_MOVEMENT_CONTROLLER})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\PropertiesBox" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_PROPERTIESBOX})
source_group("Core\\Client\\Objects\\base\\EntityCondition" FILES ${CORE_CLIENT_OBJECTS_BASE_ENTITYCONDITION})
source_group("Core\\Client\\Effects\\Core" FILES ${CORE_CLIENT_EFFECTS_CORE})
source_group("AI\\ALife\\simulator_base\\registries\\smart_terrain_registry" FILES ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_SMART_TERRAIN_REGISTRY})
source_group("Core\\Client\\Objects\\zones\\SmartZone" FILES ${CORE_CLIENT_OBJECTS_ZONES_SMARTZONE})
source_group("AI\\AComponents\\ProblemSolver\\operator_condition" FILES ${AI_ACOMPONENTS_PROBLEMSOLVER_OPERATOR_CONDITION})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\combat\\search_planner" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_SEARCH_PLANNER})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\FN2000" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_FN2000})
source_group("Core\\Server" FILES ${CORE_SERVER})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Artifacts\\ZudaArtifact" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_ZUDAARTIFACT})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\HPSA" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_HPSA})
source_group("AI\\AComponents\\DecisionManagement\\ActionManagement\\WorldPropertyEvaluator" FILES ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_WORLDPROPERTYEVALUATOR})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\danger\\actions\\in_direction" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_IN_DIRECTION})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Custom Weapon\\Weapon Generic" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_WEAPON_GENERIC})
source_group("AI\\AComponents\\MemoryManager\\raw_data_managers\\SoundMemoryManager\\SoundUserDataVisitor" FILES ${AI_ACOMPONENTS_MEMORYMANAGER_RAW_DATA_MANAGERS_SOUNDMEMORYMANAGER_SOUNDUSERDATAVISITOR})
source_group("AI\\AMonsters\\monsters\\Zombie" FILES ${AI_AMONSTERS_MONSTERS_ZOMBIE})
source_group("AI\\AScript\\ScriptClasses\\ScriptActions\\script_particle_action" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_PARTICLE_ACTION})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\properties" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_PROPERTIES})
source_group("AI\\ALife\\simulator_base\\smart_terrain_task" FILES ${AI_ALIFE_SIMULATOR_BASE_SMART_TERRAIN_TASK})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\Hint" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_HINT})
source_group("Core\\Client\\Spectator" FILES ${CORE_CLIENT_SPECTATOR})
source_group("AI\\AMonsters\\monsters\\Fracture\\Script" FILES ${AI_AMONSTERS_MONSTERS_FRACTURE_SCRIPT})
source_group("Core\\Client\\Particles" FILES ${CORE_CLIENT_PARTICLES})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Custom Weapon\\Addons\\GrenadeLauncher" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_ADDONS_GRENADELAUNCHER})
source_group("AI\\AComponents\\SightManager\\sight_action" FILES ${AI_ACOMPONENTS_SIGHTMANAGER_SIGHT_ACTION})
source_group("AI\\AScript\\ScriptClasses\\ScriptActions\\script_sound_action" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_SOUND_ACTION})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\Static" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_STATIC})
source_group("AI\\AComponents\\ProblemSolver\\operator_condition\\ScriptWorldProperty" FILES ${AI_ACOMPONENTS_PROBLEMSOLVER_OPERATOR_CONDITION_SCRIPTWORLDPROPERTY})
source_group("Core\\Client\\Objects\\inventory\\InventoryOwner\\trade_parameters\\purchase_list" FILES ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_TRADE_PARAMETERS_PURCHASE_LIST})
source_group("AI\\AGroup\\agent_manager\\agent_enemy_manager" FILES ${AI_AGROUP_AGENT_MANAGER_AGENT_ENEMY_MANAGER})
source_group("AI\\AComponents\\MovementManager\\PathManagers\\DetailPathManager" FILES ${AI_ACOMPONENTS_MOVEMENTMANAGER_PATHMANAGERS_DETAILPATHMANAGER})
source_group("Core\\Client\\Objects\\tasks_info_dialogs\\encyclopedia" FILES ${CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS_ENCYCLOPEDIA})
source_group("AI\\ALife\\simulator_base" FILES ${AI_ALIFE_SIMULATOR_BASE})
source_group("AI\\AMonsters\\monsters\\Phantom" FILES ${AI_AMONSTERS_MONSTERS_PHANTOM})
source_group("AI\\AMonsters\\common\\monster states\\Dangerous Sound" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_DANGEROUS_SOUND})
source_group("Core\\Server\\ServerProcess" FILES ${CORE_SERVER_SERVERPROCESS})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\danger\\actions\\in_direction\\actions" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_IN_DIRECTION_ACTIONS})
source_group("AI\\ALife\\simulator_base\\registries\\spawn_registry\\server_entity_wrapper" FILES ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_SPAWN_REGISTRY_SERVER_ENTITY_WRAPPER})
source_group("AI\\AScript\\ScriptClasses\\KeyBindings" FILES ${AI_ASCRIPT_SCRIPTCLASSES_KEYBINDINGS})
source_group("AI\\AMonsters\\common\\monster states\\Group Monsters Home" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_GROUP_MONSTERS_HOME})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Artifacts\\BlackGraviArtifact" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_BLACKGRAVIARTIFACT})
source_group("AI\\ANavigation\\GameLevelCrossTable" FILES ${AI_ANAVIGATION_GAMELEVELCROSSTABLE})
source_group("AI\\AMonsters\\common\\monster states\\Hitted" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_HITTED})
source_group("AI\\ALife\\server_entities\\human\\object_handler" FILES ${AI_ALIFE_SERVER_ENTITIES_HUMAN_OBJECT_HANDLER})
source_group("AI\\AComponents\\SpaceRestrictionManager\\SpaceRestrictionHolder\\SpaceRestrictionShape" FILES ${AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTIONHOLDER_SPACERESTRICTIONSHAPE})
source_group("AI\\AMonsters\\common\\monster states\\Help Sound" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_HELP_SOUND})
source_group("Core\\Client\\Objects\\physics\\DestroyablePhysicsObject" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_DESTROYABLEPHYSICSOBJECT})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS})
source_group("Core\\Common\\associative_vector\\vector" FILES ${CORE_COMMON_ASSOCIATIVE_VECTOR_VECTOR})
source_group("Core\\Client\\Objects\\inventory\\InventoryOwner\\trade_parameters\\trade_parameters" FILES ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_TRADE_PARAMETERS_TRADE_PARAMETERS})
source_group("Core\\Client\\Effectors\\Weapon" FILES ${CORE_CLIENT_EFFECTORS_WEAPON})
source_group("AI\\AGroup\\agent_manager\\agent_location_manager\\danger_object_location" FILES ${AI_AGROUP_AGENT_MANAGER_AGENT_LOCATION_MANAGER_DANGER_OBJECT_LOCATION})
source_group("AI\\ALife\\server_entities\\online_offline_group\\brain" FILES ${AI_ALIFE_SERVER_ENTITIES_ONLINE_OFFLINE_GROUP_BRAIN})
source_group("AI\\ALife\\inventory_upgrade\\upgrade" FILES ${AI_ALIFE_INVENTORY_UPGRADE_UPGRADE})
source_group("AI\\AMonsters\\monsters\\PseudoDog" FILES ${AI_AMONSTERS_MONSTERS_PSEUDODOG})
source_group("Core\\Client\\Objects\\zones\\HairsZone" FILES ${CORE_CLIENT_OBJECTS_ZONES_HAIRSZONE})
source_group("Core\\Server\\ServerEntities" FILES ${CORE_SERVER_SERVERENTITIES})
source_group("AI\\AScript\\ScriptClasses\\ScriptActions\\script_watch_action" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_WATCH_ACTION})
source_group("AI\\AMonsters\\common\\monster states\\Eat\\Drag" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_EAT_DRAG})
source_group("AI\\AMonsters\\common\\monster states\\Eat\\Eating" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_EAT_EATING})
source_group("AI\\ALife\\server_entities\\human\\brain" FILES ${AI_ALIFE_SERVER_ENTITIES_HUMAN_BRAIN})
source_group("AI\\AComponents\\ObjectHandler\\planner" FILES ${AI_ACOMPONENTS_OBJECTHANDLER_PLANNER})
source_group("AI\\AMonsters\\monsters\\Boar\\Script" FILES ${AI_AMONSTERS_MONSTERS_BOAR_SCRIPT})
source_group("Core\\Client\\Objects\\physics\\Debug" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_DEBUG})
source_group("AI\\AScript\\ScriptClasses\\UI\\GameTypes\\GameCustom" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_GAMETYPES_GAMECUSTOM})
source_group("AI\\ANavigation\\Pathfinding\\PathManagers\\path_manager_game\\vertex" FILES ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_GAME_VERTEX})
source_group("AI\\AScript\\ScriptClasses\\UI\\Common\\Inventory" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_INVENTORY})
source_group("AI\\ALife\\simulator_base\\registries\\abstract_registry" FILES ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_ABSTRACT_REGISTRY})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\danger\\actions\\grenade" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_GRENADE})
source_group("AI\\AMonsters\\monsters\\Flesh" FILES ${AI_AMONSTERS_MONSTERS_FLESH})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\combat" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\combat\\get_distance" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_GET_DISTANCE})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Custom Weapon\\Ammo" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_AMMO})
source_group("AI\\AComponents\\DecisionManagement\\ActionManagement" FILES ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\anomaly\\actions" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_ANOMALY_ACTIONS})
source_group("Core\\Client\\Level\\LevelMapSync" FILES ${CORE_CLIENT_LEVEL_LEVELMAPSYNC})
source_group("AI\\AScript\\ScriptClasses\\UI\\Common\\PDA\\logs" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA_LOGS})
source_group("AI\\AMonsters\\common\\components\\Squad" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_SQUAD})
source_group("AI\\AMonsters\\common\\components\\State" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_STATE})
source_group("AI\\ANavigation\\Pathfinding\\DataStorages\\path_builders\\edge_path" FILES ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_PATH_BUILDERS_EDGE_PATH})
source_group("AI\\AGroup\\agent_manager\\agent_location_manager\\danger_location" FILES ${AI_AGROUP_AGENT_MANAGER_AGENT_LOCATION_MANAGER_DANGER_LOCATION})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\alife\\actions" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_ALIFE_ACTIONS})
source_group("AI\\AScript\\ScriptClasses\\ScriptFmatrix" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTFMATRIX})
source_group("AI\\ANavigation\\PatrolPaths\\PatrolPoint" FILES ${AI_ANAVIGATION_PATROLPATHS_PATROLPOINT})
source_group("AI\\AMonsters\\monsters\\Controller\\State Attack" FILES ${AI_AMONSTERS_MONSTERS_CONTROLLER_STATE_ATTACK})
source_group("AI\\AComponents\\MemoryManager" FILES ${AI_ACOMPONENTS_MEMORYMANAGER})
source_group("AI\\AScript\\ScriptClasses\\UI\\Cursor" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_CURSOR})
source_group("AI\\AScript\\ScriptClasses\\UI\\Common\\ui-item-infos\\CharacterInfo" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_UI_ITEM_INFOS_CHARACTERINFO})
source_group("AI\\AMonsters\\common\\monster states\\General\\Movement" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_GENERAL_MOVEMENT})
source_group("AI\\ANavigation\\PatrolPaths\\PatrolPath" FILES ${AI_ANAVIGATION_PATROLPATHS_PATROLPATH})
source_group("Core\\Server\\ServerEntities\\script_value_container" FILES ${CORE_SERVER_SERVERENTITIES_SCRIPT_VALUE_CONTAINER})
source_group("AI\\AMonsters\\common\\components\\Actor Controller" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_ACTOR_CONTROLLER})
source_group("AI\\AScript\\ScriptClasses\\UI\\Common\\_Debug Fonts" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON__DEBUG_FONTS})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Outfit" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_OUTFIT})
source_group("AI\\AMonsters\\common\\monster states\\Panic" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_PANIC})
source_group("AI\\AComponents\\SightManager" FILES ${AI_ACOMPONENTS_SIGHTMANAGER})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\death" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DEATH})
source_group("AI\\AScript\\ScriptClasses\\ScriptActions\\script_object_action" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_OBJECT_ACTION})
source_group("AI\\AGroup\\agent_manager\\agent_corpse_manager\\member_corpse" FILES ${AI_AGROUP_AGENT_MANAGER_AGENT_CORPSE_MANAGER_MEMBER_CORPSE})
source_group("Core\\Client\\Objects\\base\\GameObject\\ai_obstacle\\min_obb\\minimize_1d" FILES ${CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_AI_OBSTACLE_MIN_OBB_MINIMIZE_1D})
source_group("AI\\AScript\\ScriptClasses\\ScriptIniFile" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTINIFILE})
source_group("Core\\Client\\Objects\\vehicles\\Car\\CarWeapon" FILES ${CORE_CLIENT_OBJECTS_VEHICLES_CAR_CARWEAPON})
source_group("AI\\AMonsters\\common\\components" FILES ${AI_AMONSTERS_COMMON_COMPONENTS})
source_group("AI\\AMonsters\\common\\steering behaviours\\manager" FILES ${AI_AMONSTERS_COMMON_STEERING_BEHAVIOURS_MANAGER})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\ScrollBar" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_SCROLLBAR})
source_group("AI\\AMonsters\\common\\components\\Control Manager\\Base Controllers\\Animation" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_BASE_CONTROLLERS_ANIMATION})
source_group("Core\\Client\\Level\\Bullet Manager" FILES ${CORE_CLIENT_LEVEL_BULLET_MANAGER})
source_group("AI\\AMonsters\\monsters\\Controller\\State Panic" FILES ${AI_AMONSTERS_MONSTERS_CONTROLLER_STATE_PANIC})
source_group("AI\\AScript\\ScriptClasses\\ScriptEffector" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTEFFECTOR})
source_group("Core\\Client\\Level\\ClientSpawnManager" FILES ${CORE_CLIENT_LEVEL_CLIENTSPAWNMANAGER})
source_group("AI\\AMonsters\\monsters\\Bloodsucker" FILES ${AI_AMONSTERS_MONSTERS_BLOODSUCKER})
source_group("AI\\ANavigation\\Pathfinding\\PathManagers\\path_manager_generic" FILES ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_GENERIC})
source_group("AI\\ALife\\simulator_base\\header" FILES ${AI_ALIFE_SIMULATOR_BASE_HEADER})
source_group("Core\\Server\\Games\\server\\single" FILES ${CORE_SERVER_GAMES_SERVER_SINGLE})
source_group("Core\\Client\\Objects\\tasks_info_dialogs\\dialogs" FILES ${CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS_DIALOGS})
source_group("AI\\AMonsters\\monsters\\Chimera\\state hunting" FILES ${AI_AMONSTERS_MONSTERS_CHIMERA_STATE_HUNTING})
source_group("AI\\AMonsters\\humans\\stalker\\MovementManager\\base\\params" FILES ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_BASE_PARAMS})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\SVU" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_SVU})
source_group("AI\\AScript\\ScriptClasses\\ScriptIniFile\\ScriptRTokenList" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTINIFILE_SCRIPTRTOKENLIST})
source_group("AI\\AComponents\\MovementManager\\PathManagers\\LevelPathManager" FILES ${AI_ACOMPONENTS_MOVEMENTMANAGER_PATHMANAGERS_LEVELPATHMANAGER})
source_group("AI\\ALife\\simulator_base\\registries\\graph_registry\\level_registry" FILES ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_GRAPH_REGISTRY_LEVEL_REGISTRY})
source_group("AI\\AMonsters\\monsters\\Bloodsucker\\Attack" FILES ${AI_AMONSTERS_MONSTERS_BLOODSUCKER_ATTACK})
source_group("AI\\ANavigation\\Pathfinding\\PathManagers\\path_manager_game\\level" FILES ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_GAME_LEVEL})
source_group("AI\\AScript\\ScriptClasses\\UI\\Common\\MainMenu" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_MAINMENU})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Devices\\Detectors\\Simple Detector" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DEVICES_DETECTORS_SIMPLE_DETECTOR})
source_group("AI\\AComponents\\DecisionManagement\\ActionManagement\\ActionBase" FILES ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONBASE})
source_group("AI\\AScript" FILES ${AI_ASCRIPT})
source_group("AI\\ALife\\update_manager\\storage_manager" FILES ${AI_ALIFE_UPDATE_MANAGER_STORAGE_MANAGER})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\combat\\actions\\base" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_ACTIONS_BASE})
source_group("AI\\AMonsters\\monsters\\Burer\\Script" FILES ${AI_AMONSTERS_MONSTERS_BURER_SCRIPT})
source_group("AI\\AComponents\\doors_manager" FILES ${AI_ACOMPONENTS_DOORS_MANAGER})
source_group("AI\\ANavigation\\Pathfinding\\DataStorages\\vertex_managers\\hash_fixed" FILES ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_VERTEX_MANAGERS_HASH_FIXED})
source_group("AI\\AMonsters\\common\\components\\Morale" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_MORALE})
source_group("Core\\Client\\Level\\ClientDigestComputer" FILES ${CORE_CLIENT_LEVEL_CLIENTDIGESTCOMPUTER})
source_group("AI\\AMonsters\\monsters\\Bloodsucker\\Alien Feature" FILES ${AI_AMONSTERS_MONSTERS_BLOODSUCKER_ALIEN_FEATURE})
source_group("Core\\Common\\ObjectBroker" FILES ${CORE_COMMON_OBJECTBROKER})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Artifacts\\RustyHairArtifact" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_RUSTYHAIRARTIFACT})
source_group("AI\\AComponents\\MemoryManager\\clsuterized_data_managers\\ObjectManager" FILES ${AI_ACOMPONENTS_MEMORYMANAGER_CLSUTERIZED_DATA_MANAGERS_OBJECTMANAGER})
source_group("AI\\ALife\\server_entities\\monster_abstract\\movement_manager" FILES ${AI_ALIFE_SERVER_ENTITIES_MONSTER_ABSTRACT_MOVEMENT_MANAGER})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\danger\\actions\\unknown\\actions" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_UNKNOWN_ACTIONS})
source_group("AI\\AScript\\ScriptClasses\\UI\\Common\\PDA\\MAP" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA_MAP})
source_group("AI\\AMonsters\\humans\\stalker\\SoundUserData" FILES ${AI_AMONSTERS_HUMANS_STALKER_SOUNDUSERDATA})
source_group("Core\\Client\\Objects\\DelayedActionFuse" FILES ${CORE_CLIENT_OBJECTS_DELAYEDACTIONFUSE})
source_group("Core\\Client\\Objects\\tasks_info_dialogs\\statistics" FILES ${CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS_STATISTICS})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\BM-16" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_BM_16})
source_group("AI\\AComponents\\MovementManager\\LocationManager" FILES ${AI_ACOMPONENTS_MOVEMENTMANAGER_LOCATIONMANAGER})
source_group("Core\\Client\\Objects\\inventory\\InventoryItemObject" FILES ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYITEMOBJECT})
source_group("AI\\AMonsters\\common\\monster states\\Steal" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_STEAL})
source_group("Core\\Client\\Objects\\base\\UsableScriptObject" FILES ${CORE_CLIENT_OBJECTS_BASE_USABLESCRIPTOBJECT})
source_group("AI\\AMonsters\\humans\\stalker\\MovementManager\\smart_covers\\evaluators" FILES ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_EVALUATORS})
source_group("AI\\ANavigation\\PatrolPaths\\PatrolPathStorage" FILES ${AI_ANAVIGATION_PATROLPATHS_PATROLPATHSTORAGE})
source_group("AI\\AGroup\\agent_manager\\agent_planner\\properties" FILES ${AI_AGROUP_AGENT_MANAGER_AGENT_PLANNER_PROPERTIES})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\InteractiveBackground" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_INTERACTIVEBACKGROUND})
source_group("AI\\AMonsters\\humans\\stalker\\AnimationManager\\pair" FILES ${AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER_PAIR})
source_group("Core\\Server\\ID_Generator" FILES ${CORE_SERVER_ID_GENERATOR})
source_group("Core\\Client\\Level\\Debug Renderer" FILES ${CORE_CLIENT_LEVEL_DEBUG_RENDERER})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Artifacts\\Needles" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_NEEDLES})
source_group("AI\\AMonsters\\humans\\stalker\\AnimationManager\\data_storage\\data" FILES ${AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER_DATA_STORAGE_DATA})
source_group("AI\\AMonsters\\humans\\stalker\\Miscellaneous" FILES ${AI_AMONSTERS_HUMANS_STALKER_MISCELLANEOUS})
source_group("Core\\Client\\Objects\\zones\\MosquitoBald" FILES ${CORE_CLIENT_OBJECTS_ZONES_MOSQUITOBALD})
source_group("AI\\AMonsters\\common\\components\\Control Manager\\Custom\\Rotation Jump" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_ROTATION_JUMP})
source_group("Core\\Client\\Objects\\zones\\Mincer" FILES ${CORE_CLIENT_OBJECTS_ZONES_MINCER})
source_group("AI\\AMonsters\\monsters\\Chimera\\state threaten" FILES ${AI_AMONSTERS_MONSTERS_CHIMERA_STATE_THREATEN})
source_group("Core\\Client\\Objects\\inventory_box" FILES ${CORE_CLIENT_OBJECTS_INVENTORY_BOX})
source_group("AI\\ANavigation\\Pathfinding\\Algorithms\\Astar" FILES ${AI_ANAVIGATION_PATHFINDING_ALGORITHMS_ASTAR})
source_group("AI\\AScript\\ScriptClasses\\UI" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI})
source_group("AI\\AComponents\\ObjectHandler\\planner\\properties" FILES ${AI_ACOMPONENTS_OBJECTHANDLER_PLANNER_PROPERTIES})
source_group("AI\\AMonsters\\monsters\\Controller\\Base Controllers\\Direction" FILES ${AI_AMONSTERS_MONSTERS_CONTROLLER_BASE_CONTROLLERS_DIRECTION})
source_group("AI\\AComponents\\MemoryManager\\clsuterized_data_managers\\DangerManager\\danger_object" FILES ${AI_ACOMPONENTS_MEMORYMANAGER_CLSUTERIZED_DATA_MANAGERS_DANGERMANAGER_DANGER_OBJECT})
source_group("AI\\AComponents\\SpaceRestrictionManager\\SpaceRestrictionHolder\\SpaceRestrictionBase" FILES ${AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTIONHOLDER_SPACERESTRICTIONBASE})
source_group("AI\\AMonsters\\humans\\stalker\\MovementManager\\smart_covers" FILES ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS})
source_group("Core\\Client\\Objects\\inventory\\InventoryOwner\\trade_parameters\\trade_factor_parameters" FILES ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_TRADE_PARAMETERS_TRADE_FACTOR_PARAMETERS})
source_group("AI\\AMonsters\\humans\\stalker\\MovementManager" FILES ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER})
source_group("Core\\Client\\Objects\\physics\\CharacterSupport\\interactive_motion" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_CHARACTERSUPPORT_INTERACTIVE_MOTION})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\EditBox\\customEB" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_EDITBOX_CUSTOMEB})
source_group("Core\\Client\\Objects\\physics\\PHDestroyable" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_PHDESTROYABLE})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Devices\\flare" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DEVICES_FLARE})
source_group("AI\\AComponents\\DecisionManagement\\ActionManagement\\ActionPlannerAction\\ActionPlannerActionScript" FILES ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONPLANNERACTION_ACTIONPLANNERACTIONSCRIPT})
source_group("AI\\ANavigation\\Pathfinding\\DataStorages\\path_builders\\vertex_path" FILES ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_PATH_BUILDERS_VERTEX_PATH})
source_group("AI\\AScript\\ScriptClasses\\ScriptNetPacket" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTNETPACKET})
source_group("AI\\AComponents\\MemoryManager\\raw_data_managers\\HitMemoryManager" FILES ${AI_ACOMPONENTS_MEMORYMANAGER_RAW_DATA_MANAGERS_HITMEMORYMANAGER})
source_group("Core\\Client\\Objects\\zones\\ScriptZone" FILES ${CORE_CLIENT_OBJECTS_ZONES_SCRIPTZONE})
source_group("Core\\Client\\Objects\\inventory\\InventoryOwner\\character_info" FILES ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_CHARACTER_INFO})
source_group("AI\\ALife\\server_entities\\monster_abstract\\movement_manager\\movement_manager_holder" FILES ${AI_ALIFE_SERVER_ENTITIES_MONSTER_ABSTRACT_MOVEMENT_MANAGER_MOVEMENT_MANAGER_HOLDER})
source_group("AI\\AComponents\\MovementManager\\LocationSelectors\\GameLocationSelector" FILES ${AI_ACOMPONENTS_MOVEMENTMANAGER_LOCATIONSELECTORS_GAMELOCATIONSELECTOR})
source_group("AI\\ANavigation\\Pathfinding\\DataStorages\\vertex_allocators\\fixed" FILES ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_VERTEX_ALLOCATORS_FIXED})
source_group("Core\\Client\\Objects\\physics\\PhysicsShellHolder" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_PHYSICSSHELLHOLDER})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\combat\\search_planner\\actions" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_SEARCH_PLANNER_ACTIONS})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\alife" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_ALIFE})
source_group("AI\\AMonsters\\monsters\\Rats" FILES ${AI_AMONSTERS_MONSTERS_RATS})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\Weapon Groza" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_GROZA})
source_group("AI\\AMonsters\\monsters\\Poltergeist\\Script" FILES ${AI_AMONSTERS_MONSTERS_POLTERGEIST_SCRIPT})
source_group("AI\\AScript\\ScriptClasses\\BaseClientClasses" FILES ${AI_ASCRIPT_SCRIPTCLASSES_BASECLIENTCLASSES})
source_group("AI\\AGroup\\agent_manager\\agent_enemy_manager\\member_enemy" FILES ${AI_AGROUP_AGENT_MANAGER_AGENT_ENEMY_MANAGER_MEMBER_ENEMY})
source_group("AI\\ANavigation\\Pathfinding\\Algorithms\\Dijkstra" FILES ${AI_ANAVIGATION_PATHFINDING_ALGORITHMS_DIJKSTRA})
source_group("AI\\AComponents\\MemoryManager\\raw_data_managers\\VisualMemoryManager\\visual_memory_params" FILES ${AI_ACOMPONENTS_MEMORYMANAGER_RAW_DATA_MANAGERS_VISUALMEMORYMANAGER_VISUAL_MEMORY_PARAMS})
source_group("AI\\ALife\\simulator_base\\registries\\spawn_registry\\header" FILES ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_SPAWN_REGISTRY_HEADER})
source_group("AI\\AComponents\\MemoryManager\\clsuterized_data_managers\\DangerManager" FILES ${AI_ACOMPONENTS_MEMORYMANAGER_CLSUTERIZED_DATA_MANAGERS_DANGERMANAGER})
source_group("Core\\Common\\ObjectFactory\\object_item_abstract" FILES ${CORE_COMMON_OBJECTFACTORY_OBJECT_ITEM_ABSTRACT})
source_group("AI\\ACover\\smart_cover\\object" FILES ${AI_ACOVER_SMART_COVER_OBJECT})
source_group("AI\\AMonsters\\humans\\stalker\\MovementManager\\smart_covers\\animation_selector\\animation_planner\\loophole_actions" FILES ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR_ANIMATION_PLANNER_LOOPHOLE_ACTIONS})
source_group("AI\\AMonsters\\monsters\\Tushkano" FILES ${AI_AMONSTERS_MONSTERS_TUSHKANO})
source_group("AI\\AMonsters\\humans\\stalker\\MovementManager\\obstacles" FILES ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_OBSTACLES})
source_group("AI\\AMonsters\\common\\monster states\\General" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_GENERAL})
source_group("AI\\ALife" FILES ${AI_ALIFE})
source_group("AI\\AMonsters\\humans\\stalker\\AnimationManager\\names" FILES ${AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER_NAMES})
source_group("Core\\Client\\Objects\\vehicles\\Car\\car_memory" FILES ${CORE_CLIENT_OBJECTS_VEHICLES_CAR_CAR_MEMORY})
source_group("Core\\Client\\Objects\\tasks_info_dialogs" FILES ${CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS})
source_group("AI\\AComponents\\MemoryManager\\clsuterized_data_managers\\ItemManager" FILES ${AI_ACOMPONENTS_MEMORYMANAGER_CLSUTERIZED_DATA_MANAGERS_ITEMMANAGER})
source_group("AI\\AMonsters\\common\\steering behaviours\\components\\alignment" FILES ${AI_AMONSTERS_COMMON_STEERING_BEHAVIOURS_COMPONENTS_ALIGNMENT})
source_group("AI\\AScript\\ScriptClasses\\ScriptLAnim" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTLANIM})
source_group("AI\\AComponents\\ProblemSolver\\operator_abstract" FILES ${AI_ACOMPONENTS_PROBLEMSOLVER_OPERATOR_ABSTRACT})
source_group("AI\\AMonsters\\monsters\\Poltergeist\\Abilities" FILES ${AI_AMONSTERS_MONSTERS_POLTERGEIST_ABILITIES})
source_group("AI\\ACover\\smart_cover\\storage\\description\\transitions\\animation" FILES ${AI_ACOVER_SMART_COVER_STORAGE_DESCRIPTION_TRANSITIONS_ANIMATION})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\combat\\low_cover_planner\\actions" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_LOW_COVER_PLANNER_ACTIONS})
source_group("AI\\AMonsters\\monsters\\Rats\\state_manager" FILES ${AI_AMONSTERS_MONSTERS_RATS_STATE_MANAGER})
source_group("AI\\ANavigation\\Pathfinding\\PathManagers\\path_manager_level\\straight_line" FILES ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_LEVEL_STRAIGHT_LINE})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Custom Weapon\\Pistol" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_PISTOL})
source_group("Core\\Client\\Objects\\items &amp; weapons\\PDA &amp; information" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_PDA__AND__INFORMATION})
source_group("AI\\AMonsters\\common\\components\\Cover Manager" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_COVER_MANAGER})
source_group("AI\\AScript\\ScriptClasses\\ScriptActions\\script_abstract_action" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_ABSTRACT_ACTION})
source_group("AI\\AScript\\ScriptClasses\\ScriptFcolor" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTFCOLOR})
source_group("AI\\AComponents\\DecisionManagement\\ActionManagement\\WorldPropertyEvaluator\\const" FILES ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_WORLDPROPERTYEVALUATOR_CONST})
source_group("Core\\Client\\Objects\\base\\EntityAlive" FILES ${CORE_CLIENT_OBJECTS_BASE_ENTITYALIVE})
source_group("AI\\AMonsters\\humans\\stalker\\AnimationManager\\state" FILES ${AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER_STATE})
source_group("AI\\AScript\\ScriptClasses\\ScriptActions\\script_movement_action\\patrol_path_params" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_MOVEMENT_ACTION_PATROL_PATH_PARAMS})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\ScrollView" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_SCROLLVIEW})
source_group("AI\\AComponents\\DecisionManagement\\ActionManagement\\ActionBase\\ActionScriptBase" FILES ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONBASE_ACTIONSCRIPTBASE})
source_group("AI\\ANavigation\\Pathfinding\\DataStorages\\priority_queues\\binary_heap" FILES ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_PRIORITY_QUEUES_BINARY_HEAP})
source_group("AI\\ALife\\simulator_base\\registries\\safe_map_iterator" FILES ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_SAFE_MAP_ITERATOR})
source_group("AI\\AScript\\ScriptClasses\\Console" FILES ${AI_ASCRIPT_SCRIPTCLASSES_CONSOLE})
source_group("AI\\AMonsters\\common\\components\\Motion Stats" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_MOTION_STATS})
source_group("AI\\AMonsters\\common\\components\\Cover" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_COVER})
source_group("Core\\Client\\Objects\\base\\GameObject\\ai_obstacle\\min_obb\\magic_minimize_nd" FILES ${CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_AI_OBSTACLE_MIN_OBB_MAGIC_MINIMIZE_ND})
source_group("Core\\Common\\StringTable" FILES ${CORE_COMMON_STRINGTABLE})
source_group("AI\\AMonsters\\monsters\\Snork\\Special Jump" FILES ${AI_AMONSTERS_MONSTERS_SNORK_SPECIAL_JUMP})
source_group("AI\\ALife\\saved_game_wrapper" FILES ${AI_ALIFE_SAVED_GAME_WRAPPER})
source_group("AI\\AComponents\\SightManager\\control_action" FILES ${AI_ACOMPONENTS_SIGHTMANAGER_CONTROL_ACTION})
source_group("AI\\AMonsters\\common\\components\\Control Manager\\Pure Coms\\Direction" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_PURE_COMS_DIRECTION})
source_group("AI\\AMonsters\\humans\\stalker\\MovementManager\\obstacles\\restricted_object_obstacle" FILES ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_OBSTACLES_RESTRICTED_OBJECT_OBSTACLE})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER})
source_group("Core\\Common\\DateTime" FILES ${CORE_COMMON_DATETIME})
source_group("AI\\AMonsters\\common\\components\\Melee Checker" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_MELEE_CHECKER})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\EditBox" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_EDITBOX})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\combat\\low_cover_planner" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_LOW_COVER_PLANNER})
source_group("AI\\ALife\\simulator_base\\registries\\story_registry" FILES ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_STORY_REGISTRY})
source_group("AI\\AMonsters\\monsters\\Controller" FILES ${AI_AMONSTERS_MONSTERS_CONTROLLER})
source_group("Core\\Common\\Random\\weighted" FILES ${CORE_COMMON_RANDOM_WEIGHTED})
source_group("AI\\AScript\\ScriptClasses\\UI\\Tutorial" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_TUTORIAL})
source_group("Core\\Client\\Objects\\physics\\PHCommander" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_PHCOMMANDER})
source_group("AI\\AMonsters\\humans\\stalker\\MovementManager\\base" FILES ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_BASE})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Artifacts\\GraviArtifact" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_GRAVIARTIFACT})
source_group("AI\\ALife\\server_entities\\monster_abstract\\movement_manager\\patrol_path_manager" FILES ${AI_ALIFE_SERVER_ENTITIES_MONSTER_ABSTRACT_MOVEMENT_MANAGER_PATROL_PATH_MANAGER})
source_group("AI\\ALife\\server_entities\\monster_abstract\\movement_manager\\detail_path_manager" FILES ${AI_ALIFE_SERVER_ENTITIES_MONSTER_ABSTRACT_MOVEMENT_MANAGER_DETAIL_PATH_MANAGER})
source_group("AI\\AComponents\\MemoryManager\\raw_data_managers\\SoundMemoryManager" FILES ${AI_ACOMPONENTS_MEMORYMANAGER_RAW_DATA_MANAGERS_SOUNDMEMORYMANAGER})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\Weapon AK74" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_AK74})
source_group("AI\\AMonsters\\common\\monster states\\Camp" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_CAMP})
source_group("AI\\AComponents\\ProblemSolver\\condition_state" FILES ${AI_ACOMPONENTS_PROBLEMSOLVER_CONDITION_STATE})
source_group("Core\\Client\\Level Debug" FILES ${CORE_CLIENT_LEVEL_DEBUG})
source_group("AI\\ANavigation\\Pathfinding\\PathManagers\\path_manager_solver" FILES ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_SOLVER})
source_group("Core\\Client\\Objects\\searchlight" FILES ${CORE_CLIENT_OBJECTS_SEARCHLIGHT})
source_group("AI\\AComponents\\moving_objects\\moving_object" FILES ${AI_ACOMPONENTS_MOVING_OBJECTS_MOVING_OBJECT})
source_group("Core\\Client\\Objects\\inventory\\InventoryOwner" FILES ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER})
source_group("AI\\ANavigation\\Pathfinding\\PathManagers" FILES ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS})
source_group("AI" FILES ${AI})
source_group("Core\\Client\\Objects\\physics\\PhysicsSkeletonObject" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_PHYSICSSKELETONOBJECT})
source_group("AI\\AComponents\\moving_objects\\obstacles_query" FILES ${AI_ACOMPONENTS_MOVING_OBJECTS_OBSTACLES_QUERY})
source_group("AI\\AComponents\\SpaceRestrictionManager" FILES ${AI_ACOMPONENTS_SPACERESTRICTIONMANAGER})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\ComboBox" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_COMBOBOX})
source_group("AI\\AMonsters\\monsters\\Bloodsucker\\Vampire State" FILES ${AI_AMONSTERS_MONSTERS_BLOODSUCKER_VAMPIRE_STATE})
source_group("Core\\Client\\Objects\\searchlight\\Trade" FILES ${CORE_CLIENT_OBJECTS_SEARCHLIGHT_TRADE})
source_group("AI\\AScript\\ScriptClasses\\ScriptActions\\script_particle_action\\particle_params" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_PARTICLE_ACTION_PARTICLE_PARAMS})
source_group("AI\\AMonsters\\common\\components\\Abilities\\Energy Holder" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_ABILITIES_ENERGY_HOLDER})
source_group("Core\\Client\\Objects\\physics\\MovementControl" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_MOVEMENTCONTROL})
source_group("AI\\AMonsters\\common\\components\\Control Manager\\Pure Coms\\Movement" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_PURE_COMS_MOVEMENT})
source_group("AI\\AMonsters\\common\\components\\Memory" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_MEMORY})
source_group("AI\\ANavigation\\Pathfinding\\DataStorages\\vertex_managers\\fixed" FILES ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_VERTEX_MANAGERS_FIXED})
source_group("AI\\ANavigation\\Pathfinding\\PathManagers\\path_manager_level" FILES ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_LEVEL})
source_group("AI\\AComponents\\SightManager\\sight_control_action" FILES ${AI_ACOMPONENTS_SIGHTMANAGER_SIGHT_CONTROL_ACTION})
source_group("AI\\AComponents\\ProblemSolver" FILES ${AI_ACOMPONENTS_PROBLEMSOLVER})
source_group("Core\\Server\\ServerEntities\\objects" FILES ${CORE_SERVER_SERVERENTITIES_OBJECTS})
source_group("Core\\Client\\Objects\\base\\Entity" FILES ${CORE_CLIENT_OBJECTS_BASE_ENTITY})
source_group("AI\\ANavigation\\Pathfinding\\DataStorages\\constructors\\builder_allocator" FILES ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_CONSTRUCTORS_BUILDER_ALLOCATOR})
source_group("Core\\Client\\Level\\AutosaveManager" FILES ${CORE_CLIENT_LEVEL_AUTOSAVEMANAGER})
source_group("AI\\AMonsters\\humans\\stalker\\MovementManager\\base\\velocity_collection" FILES ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_BASE_VELOCITY_COLLECTION})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\combat\\get_distance\\actions" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_GET_DISTANCE_ACTIONS})
source_group("AI\\AMonsters\\humans\\stalker\\SoundDataVisitor" FILES ${AI_AMONSTERS_HUMANS_STALKER_SOUNDDATAVISITOR})
source_group("AI\\AScript\\ScriptProcess" FILES ${AI_ASCRIPT_SCRIPTPROCESS})
source_group("AI\\AComponents\\moving_objects" FILES ${AI_ACOMPONENTS_MOVING_OBJECTS})
source_group("AI\\AComponents\\Step Manager" FILES ${AI_ACOMPONENTS_STEP_MANAGER})
source_group("AI\\AMonsters\\common\\monster states\\Eat" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_EAT})
source_group("Core\\Client\\Objects\\physics\\PHSkeleton" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_PHSKELETON})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Artifacts\\DummyArtifact" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_DUMMYARTIFACT})
source_group("AI\\ALife\\interaction_manager\\communication_manager" FILES ${AI_ALIFE_INTERACTION_MANAGER_COMMUNICATION_MANAGER})
source_group("Core\\Client\\Objects\\actor\\base\\memory" FILES ${CORE_CLIENT_OBJECTS_ACTOR_BASE_MEMORY})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\Knife" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_KNIFE})
source_group("AI\\AMonsters\\common\\steering behaviours\\base" FILES ${AI_AMONSTERS_COMMON_STEERING_BEHAVIOURS_BASE})
source_group("AI\\AMonsters\\common\\components\\Control Manager\\Custom\\Triple Animation" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_TRIPLE_ANIMATION})
source_group("Core\\Server\\filetransfer" FILES ${CORE_SERVER_FILETRANSFER})
source_group("AI\\ALife\\inventory_upgrade\\upgrade_root" FILES ${AI_ALIFE_INVENTORY_UPGRADE_UPGRADE_ROOT})
source_group("AI\\AMonsters\\monsters\\DogPsy\\Psy Attack Hide" FILES ${AI_AMONSTERS_MONSTERS_DOGPSY_PSY_ATTACK_HIDE})
source_group("AI\\AScript\\ScriptClasses\\UI\\Common\\PDA\\logs\\News" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA_LOGS_NEWS})
source_group("AI\\AScript\\ScriptClasses\\UI\\Common\\TALK" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_TALK})
source_group("Core\\Client\\Level\\Level Sounds" FILES ${CORE_CLIENT_LEVEL_LEVEL_SOUNDS})
source_group("Core\\Client\\Level\\GlobalFeelTouch" FILES ${CORE_CLIENT_LEVEL_GLOBALFEELTOUCH})
source_group("AI\\AMonsters\\monsters\\Controller\\Psy hit" FILES ${AI_AMONSTERS_MONSTERS_CONTROLLER_PSY_HIT})
source_group("Core\\Client\\Effectors\\Postprocess" FILES ${CORE_CLIENT_EFFECTORS_POSTPROCESS})
source_group("AI\\AMonsters\\common\\components\\Event Handler" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_EVENT_HANDLER})
source_group("AI\\ANavigation\\GraphAbstract\\GraphVertex" FILES ${AI_ANAVIGATION_GRAPHABSTRACT_GRAPHVERTEX})
source_group("AI\\AMonsters\\monsters\\Flesh\\Script" FILES ${AI_AMONSTERS_MONSTERS_FLESH_SCRIPT})
source_group("Core\\Server\\Games\\PlayerAccounts" FILES ${CORE_SERVER_GAMES_PLAYERACCOUNTS})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\MessageBox" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_MESSAGEBOX})
source_group("AI\\AMonsters\\common\\components\\Control Manager\\Pure Coms\\Path Builder" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_PURE_COMS_PATH_BUILDER})
source_group("Core\\Client\\Objects\\inventory\\EatableItemObject" FILES ${CORE_CLIENT_OBJECTS_INVENTORY_EATABLEITEMOBJECT})
source_group("Core\\Client\\Objects\\physics\\IK" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_IK})
source_group("AI\\AMonsters\\common\\steering behaviours\\components\\separation" FILES ${AI_AMONSTERS_COMMON_STEERING_BEHAVIOURS_COMPONENTS_SEPARATION})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Artifacts\\Faded Ball\\Mercury Ball" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_FADED_BALL_MERCURY_BALL})
source_group("AI\\AComponents\\SetupManager" FILES ${AI_ACOMPONENTS_SETUPMANAGER})
source_group("Core\\Client\\Objects\\tasks_info_dialogs\\game tasks" FILES ${CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS_GAME_TASKS})
source_group("AI\\ALife\\simulator_base\\registries\\object_registry" FILES ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_OBJECT_REGISTRY})
source_group("AI\\AMonsters\\common\\script\\script_binder" FILES ${AI_AMONSTERS_COMMON_SCRIPT_SCRIPT_BINDER})
source_group("AI\\AMonsters\\common\\components\\Bones" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_BONES})
source_group("AI\\AComponents\\SightManager\\aimers\\weapon" FILES ${AI_ACOMPONENTS_SIGHTMANAGER_AIMERS_WEAPON})
source_group("AI\\ANavigation\\Pathfinding\\PathManagers\\path_manager_level\\flooder" FILES ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_LEVEL_FLOODER})
source_group("AI\\AMonsters\\humans\\stalker\\MovementManager\\smart_covers\\animation_selector\\animation_planner\\target_selector\\default_behaviour" FILES ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR_ANIMATION_PLANNER_TARGET_SELECTOR_DEFAULT_BEHAVIOUR})
source_group("AI\\AMonsters\\monsters\\PseudoGigant\\Script" FILES ${AI_AMONSTERS_MONSTERS_PSEUDOGIGANT_SCRIPT})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\combat\\kill_wounded\\actions" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_KILL_WOUNDED_ACTIONS})
source_group("AI\\ACover\\smart_cover\\cover" FILES ${AI_ACOVER_SMART_COVER_COVER})
source_group("AI\\AMonsters\\monsters\\PseudoDog\\Script" FILES ${AI_AMONSTERS_MONSTERS_PSEUDODOG_SCRIPT})
source_group("AI\\AComponents\\doors_manager\\actor" FILES ${AI_ACOMPONENTS_DOORS_MANAGER_ACTOR})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\SpinBox" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_SPINBOX})
source_group("AI\\AScript\\ScriptClasses\\UI\\Common\\PDA\\Statistics &amp; Rankings" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA_STATISTICS__AND__RANKINGS})
source_group("Core\\Client\\Objects\\physics\\PhysicObject" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_PHYSICOBJECT})
source_group("AI\\AEval\\functions\\patterns" FILES ${AI_AEVAL_FUNCTIONS_PATTERNS})
source_group("AI\\AMonsters\\monsters\\Burer\\Fast Gravi" FILES ${AI_AMONSTERS_MONSTERS_BURER_FAST_GRAVI})
source_group("AI\\AMonsters\\common\\monster states\\Home Point" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_HOME_POINT})
source_group("AI\\ALife\\update_manager" FILES ${AI_ALIFE_UPDATE_MANAGER})
source_group("AI\\AMonsters\\monsters\\Chimera" FILES ${AI_AMONSTERS_MONSTERS_CHIMERA})
source_group("AI\\AMonsters\\monsters\\Dog\\Script" FILES ${AI_AMONSTERS_MONSTERS_DOG_SCRIPT})
source_group("AI\\AScript\\ScriptClasses\\ScriptReader" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTREADER})
source_group("Core\\Server\\ServerEntities\\objects_alife_monsters" FILES ${CORE_SERVER_SERVERENTITIES_OBJECTS_ALIFE_MONSTERS})
source_group("AI\\ADebug" FILES ${AI_ADEBUG})
source_group("AI\\AScript\\ScriptClasses\\UI\\Common\\MainMenu\\KeyBinding" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_MAINMENU_KEYBINDING})
source_group("AI\\ANavigation\\LevelGraph" FILES ${AI_ANAVIGATION_LEVELGRAPH})
source_group("AI\\AComponents\\DecisionManagement\\ActionManagement\\ActionPlanner\\ActionPlannerScript" FILES ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONPLANNER_ACTIONPLANNERSCRIPT})
source_group("AI\\AMonsters\\common\\monster states\\General\\Test" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_GENERAL_TEST})
source_group("AI\\AMonsters\\common\\components\\Control Manager\\Base Controllers\\Movement" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_BASE_CONTROLLERS_MOVEMENT})
source_group("AI\\AMonsters\\monsters\\Rats\\states\\base" FILES ${AI_AMONSTERS_MONSTERS_RATS_STATES_BASE})
source_group("AI\\ALife\\server_entities\\anomalous_zone" FILES ${AI_ALIFE_SERVER_ENTITIES_ANOMALOUS_ZONE})
source_group("Core\\Client\\Objects\\physics\\Breakable" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_BREAKABLE})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\Bolt" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_BOLT})
source_group("Core\\Common\\debug\\static_cast_checked" FILES ${CORE_COMMON_DEBUG_STATIC_CAST_CHECKED})
source_group("AI\\ALife\\server_entities\\human" FILES ${AI_ALIFE_SERVER_ENTITIES_HUMAN})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\FORT" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_FORT})
source_group("AI\\AMonsters\\common\\components\\Event Handler\\Custom Events" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_EVENT_HANDLER_CUSTOM_EVENTS})
source_group("AI\\AMonsters\\monsters\\Bloodsucker\\Script" FILES ${AI_AMONSTERS_MONSTERS_BLOODSUCKER_SCRIPT})
source_group("Core" FILES ${CORE})
source_group("AI\\AScript\\ScriptClasses\\ScriptGameObject" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTGAMEOBJECT})
source_group("AI\\AScript\\ScriptClasses\\UI\\GameTypes\\Single" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_GAMETYPES_SINGLE})
source_group("Core\\Client\\Objects\\zones\\RadioactiveZone" FILES ${CORE_CLIENT_OBJECTS_ZONES_RADIOACTIVEZONE})
source_group("AI\\AScript\\ScriptClasses\\ScriptSound" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTSOUND})
source_group("AI\\AMonsters\\common\\monster states\\Attack" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_ATTACK})
source_group("Core\\Client\\Objects\\physics\\CharacterSupport\\death_anims" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_CHARACTERSUPPORT_DEATH_ANIMS})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\Weapon USP45" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_USP45})
source_group("AI\\AComponents\\DecisionManagement\\ActionManagement\\ActionPlannerAction" FILES ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONPLANNERACTION})
source_group("AI\\AGroup\\agent_manager\\agent_planner" FILES ${AI_AGROUP_AGENT_MANAGER_AGENT_PLANNER})
source_group("AI\\AComponents\\SpaceRestrictionManager\\SpaceRestrictionHolder\\SpaceRestrictionAbstract" FILES ${AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTIONHOLDER_SPACERESTRICTIONABSTRACT})
source_group("AI\\ALife\\server_entities\\trader" FILES ${AI_ALIFE_SERVER_ENTITIES_TRADER})
source_group("Core\\Server\\Games" FILES ${CORE_SERVER_GAMES})
source_group("AI\\AEval\\storage" FILES ${AI_AEVAL_STORAGE})
source_group("AI\\AScript\\ScriptClasses\\UI\\Common\\InventoryWnd\\InventoryUpgrade" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_INVENTORYWND_INVENTORYUPGRADE})
source_group("AI\\AMonsters\\common\\miscellaneous" FILES ${AI_AMONSTERS_COMMON_MISCELLANEOUS})
source_group("Core\\Client\\Objects\\physics\\Hit" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_HIT})
source_group("AI\\ALife\\server_entities\\online_offline_group" FILES ${AI_ALIFE_SERVER_ENTITIES_ONLINE_OFFLINE_GROUP})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\danger\\actions\\grenade\\actions" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_GRENADE_ACTIONS})
source_group("Core\\Client\\Objects\\inventory\\InventoryOwner\\relation registry" FILES ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_RELATION_REGISTRY})
source_group("AI\\AMonsters\\common\\components\\Anomaly Detector" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_ANOMALY_DETECTOR})
source_group("AI\\AComponents\\SpaceRestrictionManager\\SpaceRestrictionHolder\\SpaceRestrictionBridge" FILES ${AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTIONHOLDER_SPACERESTRICTIONBRIDGE})
source_group("AI\\AMonsters\\monsters\\Fracture" FILES ${AI_AMONSTERS_MONSTERS_FRACTURE})
source_group("AI\\AMonsters\\monsters\\Poltergeist\\Hidden Attack" FILES ${AI_AMONSTERS_MONSTERS_POLTERGEIST_HIDDEN_ATTACK})
source_group("Core\\Client\\Level\\SeniorityHierarchyHolder" FILES ${CORE_CLIENT_LEVEL_SENIORITYHIERARCHYHOLDER})
source_group("AI\\ALife\\server_entities\\monster_abstract\\brain" FILES ${AI_ALIFE_SERVER_ENTITIES_MONSTER_ABSTRACT_BRAIN})
source_group("AI\\ACover\\smart_cover\\storage\\description\\transitions\\transition" FILES ${AI_ACOVER_SMART_COVER_STORAGE_DESCRIPTION_TRANSITIONS_TRANSITION})
source_group("Core\\Client\\Objects\\zones\\TorridZone" FILES ${CORE_CLIENT_OBJECTS_ZONES_TORRIDZONE})
source_group("AI\\AComponents\\SightManager\\aimers\\base" FILES ${AI_ACOMPONENTS_SIGHTMANAGER_AIMERS_BASE})
source_group("Core\\Common\\QuadTree" FILES ${CORE_COMMON_QUADTREE})
source_group("AI\\AScript\\ScriptThread" FILES ${AI_ASCRIPT_SCRIPTTHREAD})
source_group("AI\\ANavigation\\Pathfinding\\PathManagers\\path_manager_game" FILES ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_GAME})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\DragDrop" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_DRAGDROP})
source_group("Core\\Client\\Level" FILES ${CORE_CLIENT_LEVEL})
source_group("AI\\AMonsters\\monsters\\Snork" FILES ${AI_AMONSTERS_MONSTERS_SNORK})
source_group("AI\\AMonsters\\humans\\stalker\\MovementManager\\base\\velocity_holder" FILES ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_BASE_VELOCITY_HOLDER})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\RGD5" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_RGD5})
source_group("AI\\ALife\\interaction_manager\\combat_manager" FILES ${AI_ALIFE_INTERACTION_MANAGER_COMBAT_MANAGER})
source_group("Core\\Client\\Level\\SeniorityHierarchyHolder\\SquadHierarchyHolder" FILES ${CORE_CLIENT_LEVEL_SENIORITYHIERARCHYHOLDER_SQUADHIERARCHYHOLDER})
source_group("Core\\Client\\Effectors\\Actor" FILES ${CORE_CLIENT_EFFECTORS_ACTOR})
source_group("AI\\AScript\\ScriptDebugger" FILES ${AI_ASCRIPT_SCRIPTDEBUGGER})
source_group("AI\\AComponents\\SightManager\\aimers\\bone" FILES ${AI_ACOMPONENTS_SIGHTMANAGER_AIMERS_BONE})
source_group("AI\\AMonsters\\common\\trajectories" FILES ${AI_AMONSTERS_COMMON_TRAJECTORIES})
source_group("AI\\AMonsters\\humans\\stalker\\MovementManager\\smart_covers\\animation_selector\\animation_planner\\target_selector" FILES ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR_ANIMATION_PLANNER_TARGET_SELECTOR})
source_group("Core\\Common\\ObjectFactory\\object_item_single" FILES ${CORE_COMMON_OBJECTFACTORY_OBJECT_ITEM_SINGLE})
source_group("AI\\AMonsters\\common\\components\\Control Manager\\Base Controllers\\Path Builder" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_BASE_CONTROLLERS_PATH_BUILDER})
source_group("AI\\AComponents\\MovementManager\\PathManagers\\AbstractPathManager" FILES ${AI_ACOMPONENTS_MOVEMENTMANAGER_PATHMANAGERS_ABSTRACTPATHMANAGER})
source_group("AI\\AScript\\ScriptClasses\\ScriptFvector" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTFVECTOR})
source_group("AI\\AComponents\\MovementManager\\PathManagers\\GamePathManager" FILES ${AI_ACOMPONENTS_MOVEMENTMANAGER_PATHMANAGERS_GAMEPATHMANAGER})
source_group("Core\\Client\\Objects\\inventory" FILES ${CORE_CLIENT_OBJECTS_INVENTORY})
source_group("AI\\ALife\\inventory_upgrade" FILES ${AI_ALIFE_INVENTORY_UPGRADE})
source_group("AI\\AScript\\ScriptClasses\\UI\\UIWindows\\arrow" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_ARROW})
source_group("AI\\ASound" FILES ${AI_ASOUND})
source_group("AI\\ALife\\server_entities\\smart_zone" FILES ${AI_ALIFE_SERVER_ENTITIES_SMART_ZONE})
source_group("Core\\Client\\Objects\\actor\\base" FILES ${CORE_CLIENT_OBJECTS_ACTOR_BASE})
source_group("AI\\AMonsters\\common\\components\\Abilities\\Telekinesis" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_ABILITIES_TELEKINESIS})
source_group("Core\\Client\\Objects\\items &amp; weapons\\HudItem" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_HUDITEM})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Weapons\\Various weapons\\LR300" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_LR300})
source_group("Core\\Client\\Objects\\hanging_lamp" FILES ${CORE_CLIENT_OBJECTS_HANGING_LAMP})
source_group("AI\\AComponents\\MovementManager" FILES ${AI_ACOMPONENTS_MOVEMENTMANAGER})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Artifacts\\GalantineArtifact" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_GALANTINEARTIFACT})
source_group("Core\\Client\\Objects\\inventory\\PhysicItem" FILES ${CORE_CLIENT_OBJECTS_INVENTORY_PHYSICITEM})
source_group("AI\\AScript\\ScriptClasses\\ScriptBinderObject" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTBINDEROBJECT})
source_group("AI\\AComponents\\MovementManager\\LocationSelectors\\LevelLocationSelector" FILES ${AI_ACOMPONENTS_MOVEMENTMANAGER_LOCATIONSELECTORS_LEVELLOCATIONSELECTOR})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\danger" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER})
source_group("Core\\Client\\Objects\\zones\\TeamBaseZone" FILES ${CORE_CLIENT_OBJECTS_ZONES_TEAMBASEZONE})
source_group("AI\\ALife\\simulator_base\\registries\\schedule_registry" FILES ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_SCHEDULE_REGISTRY})
source_group("AI\\AComponents\\SpaceRestrictionManager\\SpaceRestrictionHolder\\SpaceRestrictionComposition" FILES ${AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTIONHOLDER_SPACERESTRICTIONCOMPOSITION})
source_group("AI\\ANavigation\\Pathfinding\\DataStorages\\constructors\\manager_builder_allocator" FILES ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_CONSTRUCTORS_MANAGER_BUILDER_ALLOCATOR})
source_group("AI\\AMonsters\\monsters\\Crow" FILES ${AI_AMONSTERS_MONSTERS_CROW})
source_group("AI\\AScript\\ScriptEngine" FILES ${AI_ASCRIPT_SCRIPTENGINE})
source_group("Core\\Client\\Objects\\physics\\PhysicsSoundPlayer" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_PHYSICSSOUNDPLAYER})
source_group("Core\\Client\\Objects\\zones\\NoGravityZone" FILES ${CORE_CLIENT_OBJECTS_ZONES_NOGRAVITYZONE})
source_group("AI\\AComponents\\DecisionManagement\\ActionManagement\\ActionPlanner\\ScriptActionPlannerWrapper" FILES ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONPLANNER_SCRIPTACTIONPLANNERWRAPPER})
source_group("AI\\AMonsters\\common\\monster states\\General\\Custom Action" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_GENERAL_CUSTOM_ACTION})
source_group("AI\\AComponents\\SpaceRestrictionManager\\SpaceRestrictionHolder" FILES ${AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTIONHOLDER})
source_group("Core\\Server\\ServerEntities\\objects_alife_smartcover" FILES ${CORE_SERVER_SERVERENTITIES_OBJECTS_ALIFE_SMARTCOVER})
source_group("Core\\Common\\associative_vector\\compare" FILES ${CORE_COMMON_ASSOCIATIVE_VECTOR_COMPARE})
source_group("Core\\Client\\Level\\SeniorityHierarchyHolder\\GroupHierarchyHolder" FILES ${CORE_CLIENT_LEVEL_SENIORITYHIERARCHYHOLDER_GROUPHIERARCHYHOLDER})
source_group("AI\\AGroup\\agent_manager\\agent_corpse_manager" FILES ${AI_AGROUP_AGENT_MANAGER_AGENT_CORPSE_MANAGER})
source_group("Core\\Client\\Objects\\physics\\CharacterSupport\\interactive_anims" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_CHARACTERSUPPORT_INTERACTIVE_ANIMS})
source_group("AI\\AScript\\ScriptClasses\\ScriptSoundInfo" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTSOUNDINFO})
source_group("AI\\ALife\\server_entities\\monster_abstract" FILES ${AI_ALIFE_SERVER_ENTITIES_MONSTER_ABSTRACT})
source_group("AI\\AGroup\\agent_manager\\agent_memory_manager" FILES ${AI_AGROUP_AGENT_MANAGER_AGENT_MEMORY_MANAGER})
source_group("AI\\AMonsters\\humans\\stalker\\CoverEvaluators" FILES ${AI_AMONSTERS_HUMANS_STALKER_COVEREVALUATORS})
source_group("AI\\AMonsters\\humans\\stalker\\DecisionMaker\\actions\\death\\actions" FILES ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DEATH_ACTIONS})
source_group("AI\\AMonsters\\humans\\stalker\\MovementManager\\smart_covers\\animation_selector\\animation_planner" FILES ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR_ANIMATION_PLANNER})
source_group("AI\\ANavigation\\ObjectLocation" FILES ${AI_ANAVIGATION_OBJECTLOCATION})
source_group("AI\\AComponents\\MaterialManager" FILES ${AI_ACOMPONENTS_MATERIALMANAGER})
source_group("AI\\AScript\\ScriptClasses\\ScriptActions\\script_movement_action" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_MOVEMENT_ACTION})
source_group("AI\\AComponents\\doors_manager\\door" FILES ${AI_ACOMPONENTS_DOORS_MANAGER_DOOR})
source_group("AI\\AMonsters\\common\\components\\Control Manager\\Custom\\Run Attack" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_RUN_ATTACK})
source_group("Core\\Common\\Dll Process Detach" FILES ${CORE_COMMON_DLL_PROCESS_DETACH})
source_group("AI\\ANavigation\\Pathfinding\\PathManagers\\path_manager_level\\nearest_vertex" FILES ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_LEVEL_NEAREST_VERTEX})
source_group("AI\\AScript\\ScriptClasses\\ScriptActions\\script_entity_action" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_ENTITY_ACTION})
source_group("AI\\ACover" FILES ${AI_ACOVER})
source_group("AI\\AGroup\\agent_manager\\agent_explosive_manager\\danger_explosive" FILES ${AI_AGROUP_AGENT_MANAGER_AGENT_EXPLOSIVE_MANAGER_DANGER_EXPLOSIVE})
source_group("AI\\ASpace" FILES ${AI_ASPACE})
source_group("AI\\AMonsters\\monsters\\Zombie\\States" FILES ${AI_AMONSTERS_MONSTERS_ZOMBIE_STATES})
source_group("AI\\AScript\\ScriptClasses\\ScriptActions\\script_action_condition" FILES ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_ACTION_CONDITION})
source_group("AI\\AComponents\\doors_manager\\manager" FILES ${AI_ACOMPONENTS_DOORS_MANAGER_MANAGER})
source_group("AI\\AMonsters\\common\\steering behaviours\\components\\cohesion" FILES ${AI_AMONSTERS_COMMON_STEERING_BEHAVIOURS_COMPONENTS_COHESION})
source_group("AI\\AMonsters\\common\\components\\Control Manager\\Base Controllers\\Direction" FILES ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_BASE_CONTROLLERS_DIRECTION})
source_group("Core\\Client\\Objects\\inventory\\InventoryOwner\\trade_parameters\\trade_action_parameters" FILES ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_TRADE_PARAMETERS_TRADE_ACTION_PARAMETERS})
source_group("AI\\AScript\\ScriptStorage" FILES ${AI_ASCRIPT_SCRIPTSTORAGE})
source_group("Core\\Client\\Objects\\items &amp; weapons\\Artifacts\\BastArtifact" FILES ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_BASTARTIFACT})
source_group("AI\\ALife\\update_manager\\switch_manager" FILES ${AI_ALIFE_UPDATE_MANAGER_SWITCH_MANAGER})
source_group("AI\\AMonsters\\humans\\stalker\\AnimationManager\\data_storage" FILES ${AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER_DATA_STORAGE})
source_group("AI\\AComponents\\DecisionManagement\\ActionManagement\\ActionPlannerAction\\ScriptActionPlannerActionWrapper" FILES ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONPLANNERACTION_SCRIPTACTIONPLANNERACTIONWRAPPER})
source_group("AI\\ANavigation\\Pathfinding\\GraphEngine" FILES ${AI_ANAVIGATION_PATHFINDING_GRAPHENGINE})
source_group("AI\\ACover\\smart_cover\\storage\\description\\loophole" FILES ${AI_ACOVER_SMART_COVER_STORAGE_DESCRIPTION_LOOPHOLE})
source_group("Core\\Client\\Objects\\inventory\\InventoryOwner\\trade_parameters\\trade_factors" FILES ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_TRADE_PARAMETERS_TRADE_FACTORS})
source_group("AI\\AMonsters\\monsters\\Cat\\Script" FILES ${AI_AMONSTERS_MONSTERS_CAT_SCRIPT})
source_group("AI\\AScript\\ScriptClasses\\UI\\Common\\PDA\\Tasks" FILES ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA_TASKS})
source_group("Core\\Common\\debug\\make_final" FILES ${CORE_COMMON_DEBUG_MAKE_FINAL})
source_group("AI\\AMonsters\\common\\monster states\\Find Enemy" FILES ${AI_AMONSTERS_COMMON_MONSTER_STATES_FIND_ENEMY})
source_group("Core\\Client\\Objects\\physics\\CharacterSupport" FILES ${CORE_CLIENT_OBJECTS_PHYSICS_CHARACTERSUPPORT})
source_group("AI\\AMonsters\\humans\\stalker\\MovementManager\\obstacles\\refreshable_obstacles_query" FILES ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_OBSTACLES_REFRESHABLE_OBSTACLES_QUERY})
source_group("Core\\Client\\Objects\\zones\\LevelChanger" FILES ${CORE_CLIENT_OBJECTS_ZONES_LEVELCHANGER})
source_group("Core\\Client\\Objects\\base\\GameObject\\ai_obstacle\\min_obb\\magic_box" FILES ${CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_AI_OBSTACLE_MIN_OBB_MAGIC_BOX})
source_group("AI\\AScript\\ScriptClasses" FILES ${AI_ASCRIPT_SCRIPTCLASSES})
source_group("Core\\Common\\NET Shared\\SecureMessages" FILES ${CORE_COMMON_NET_SHARED_SECUREMESSAGES})
source_group("AI\\AMonsters\\monsters\\Rats\\states" FILES ${AI_AMONSTERS_MONSTERS_RATS_STATES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ../xrServerEntities ../../3rd-party/luajit/include)
link_directories(${DXSDK_LIB_DIR} ../../lib)
add_definitions(-DXRGAME_EXPORTS -DdSINGLE -DMSVC -D_SECURE_SCL=0)

add_compile_options(/fp:fast /GR "/Yustdafx.h" /wd4237)

set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS "/Ycstdafx.h")
set(SCRIPT_PCH_FILE ${CMAKE_CURRENT_BINARY_DIR}/$<$<CONFIG:Debug>:Debug>$<$<CONFIG:RelWithDebInfo>:RelWithDebInfo>/xrGame_script.pch)
set_source_files_properties(../xrServerEntities/pch_script.cpp PROPERTIES COMPILE_FLAGS "/Ycpch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(actor.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(animation_script_callback.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(action_base_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(action_planner_action_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(action_planner_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(actor_communication.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(Actor_Network.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(actor_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ActorCondition.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ActorEffector_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(agent_enemy_manager.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(agent_manager_properties.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/ai_monsters_misc.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/crow/ai_crow.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/basemonster/base_monster_debug.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/basemonster/base_monster_feel.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/basemonster/base_monster_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/bloodsucker/bloodsucker_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/boar/boar_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/burer/burer_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/cat/cat_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/chimera/chimera_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/controller/controller_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/dog/dog_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/flesh/flesh_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/fracture/fracture_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/monster_enemy_memory.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/poltergeist/poltergeist_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/pseudodog/pseudodog_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/pseudogigant/pseudogigant_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/rats/ai_rat_feel.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/rats/ai_rat_fire.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/rats/rat_state_activation.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/rats/rat_state_initialize.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/rats/rat_state_switch.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/snork/snork_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/tushkano/tushkano_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/monsters/zombie/zombie_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/stalker/ai_stalker.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/stalker/ai_stalker_cover.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/stalker/ai_stalker_debug.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/stalker/ai_stalker_fire.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/stalker/ai_stalker_misc.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/stalker/ai_stalker_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/trader/ai_trader.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/trader/ai_trader_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai/trader/trader_animation.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ai_crow_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(alife_human_brain_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(alife_monster_brain_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(alife_monster_detail_path_manager_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(alife_monster_movement_manager_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(alife_monster_patrol_path_manager_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(alife_simulator.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(alife_simulator_base.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(alife_simulator_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(alife_smart_terrain_task_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(artefact_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(base_client_classes_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(CarScript.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(client_spawn_manager.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(client_spawn_manager_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(console_commands.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(console_registrator_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(cover_point_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(CustomMonster.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(danger_manager.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(DestroyablePhysicsObject.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(doors_door.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ef_storage_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(enemy_manager.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(entity_alive.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ExplosiveScript.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(F1.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(fs_registrator_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(game_base.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(game_cl_base.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(game_cl_single.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(game_graph_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(GameObject.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(GamePersistent.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(GameTask.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(GameTask_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(GametaskManager.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(HairsZone.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(HairsZone_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(HangingLamp.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(Helicopter.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(helicopter_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(Helicopter2.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(HelicopterMovementManager.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(hit_memory_manager.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(holder_custom_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(InfoPortion.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(Inventory.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(inventory_item.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(inventory_item_object.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(inventory_item_upgrade.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(inventory_owner_info.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(inventory_upgrade.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(inventory_upgrade_base.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(inventory_upgrade_group.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(inventory_upgrade_manager.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(inventory_upgrade_property.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(inventory_upgrade_root.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(InventoryBox.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(InventoryOwner.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(key_binding_registrator_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(Level.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(level_graph_debug2.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(Level_network.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(Level_network_spawn.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(level_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(map_manager.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(memory_manager.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(memory_space_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(mincer_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(MosquitoBald_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(movement_manager.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(movement_manager_patrol.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(object_handler.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(particle_params_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(patrol_path_manager.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(patrol_path_params.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(patrol_path_params_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(PDA.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(PhraseDialog.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(PhraseDialog_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(PhraseScript.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(PHScriptCall.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(PHSimpleCallsScript.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(PhysicObject.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(PhysicObject_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(physics_element_scripted.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(physics_joint_scripted.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(physics_shell_scripted.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(physics_world_scripted.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(PhysicsShellHolder.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(PhysicsShellScript.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(property_evaluator_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(property_storage_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(relation_registry_actions.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(RGD5.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(saved_game_wrapper_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(Scope.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_action_condition_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_action_planner_action_wrapper.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_action_planner_wrapper.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_action_wrapper.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_animation_action_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_binder.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_binder_object_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_binder_object_wrapper.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_effector_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_effector_wrapper.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_engine_help.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_entity.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_entity_action_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_game_object.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_game_object_inventory_owner.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_game_object_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_game_object_script_trader.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_game_object_script2.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_game_object_script3.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_game_object_smart_covers.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_game_object_trader.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_game_object_use.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_game_object_use2.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_game_object2.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_game_object3.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_game_object4.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_hit_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_lanim.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_monster_action_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_monster_hit_info_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_movement_action_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_object_action_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_particle_action_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_particles_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_property_evaluator_wrapper.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_render_device_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_sound_action_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_sound_info_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_sound_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_watch_action_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_world_property_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_world_state_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_zone.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(script_zone_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ScriptXMLInit.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(smart_cover.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(smart_cover_action.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(smart_cover_animation_planner.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(smart_cover_animation_selector.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(smart_cover_default_behaviour_planner.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(smart_cover_description.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(smart_cover_detail.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(smart_cover_evaluators.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(smart_cover_loophole.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(smart_cover_loophole_planner_actions.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(smart_cover_manager.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(smart_cover_object.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(smart_cover_object_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(smart_cover_planner_actions.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(smart_cover_planner_target_provider.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(smart_cover_planner_target_selector.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(smart_cover_storage.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(smart_cover_transition.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(smart_cover_transition_animation.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(sound_memory_manager.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(space_restrictor.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(space_restrictor_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_alife_actions.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_animation_manager_update.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_animation_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_anomaly_actions.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_combat_action_base.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_combat_actions.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_combat_planner.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_danger_planner.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_danger_property_evaluators.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_get_distance_actions.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_get_distance_planner.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_kill_wounded_actions.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_kill_wounded_planner.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_low_cover_actions.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_low_cover_planner.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_movement_manager_smart_cover.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_movement_manager_smart_cover_fov_range.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_movement_manager_smart_cover_loopholes.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_property_evaluators.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_search_actions.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(stalker_sound_data_visitor.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(StalkerOutfit.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(torch_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(trade.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(trade2.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/FactionState.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/FractionState.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/IUWpnParams.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIAchievements.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIActorMenu_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIActorMenuTrade.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIActorMenuUpgrade.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIButton_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIComboBox_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIEditBox_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIFactionWarWnd.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIGameTutorial.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIGameTutorialSimpleItem.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIGameTutorialVideoItem.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIInventoryUpgradeWnd.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIInventoryUpgradeWnd_add.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIInventoryUtilities.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIInvUpgrade.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIInvUpgradeInfo.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIInvUpgradeProperty.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIItemInfo.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIListBox_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIMessageBox_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIOptionsManagerScript.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIProgressBar_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIPropertiesBox_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIRankFaction.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIRankingWnd.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIScriptWnd.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIScriptWnd_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/uiscriptwnd_script2.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIStatic_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UITabControl_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIWindow_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIWndCallback.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui/UIWpnParams.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(ui_export_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(UIGameCustom.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(UIGameCustom_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(UIGameSP.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(UsableScriptObject.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(visual_memory_manager.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(WeaponAK74.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(WeaponBinoculars_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(weaponBM16_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(WeaponFN2000.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(WeaponFORT.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(WeaponGroza.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(WeaponHPSA.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(WeaponHPSA_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(WeaponKnife_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(WeaponLR300.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(WeaponMagazined.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(WeaponPM.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(WeaponRG6_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(WeaponRPG7_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(weaponshotgun_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(WeaponSVD.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(WeaponSVU.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(WeaponUSP45.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(WeaponVal.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(WeaponVintorez.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(WeaponWalther.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(xrgame_dll_detach.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(xrServer.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")

set_source_files_properties(../xrServerEntities/lua_studio.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/object_factory_register.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/object_factory_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/object_item_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/script_engine.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/script_engine_export.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/script_engine_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/script_fcolor_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/script_flags_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/script_fmatrix_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/script_fvector_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/script_ini_file_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/script_lua_helper.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/script_net_packet_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/script_process.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/script_reader_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/script_rtoken_list_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/script_sound_type_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/script_stack_tracker.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/script_storage.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/script_thread.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/script_token_list_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/xrServer_Objects_ALife_Items_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/xrServer_Objects_ALife_Items_script2.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/xrServer_Objects_ALife_Items_script3.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/xrServer_Objects_ALife_Monsters_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/xrServer_Objects_ALife_Monsters_script2.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/xrserver_objects_alife_monsters_script3.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/xrServer_Objects_ALife_Monsters_script4.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/xrServer_Objects_ALife_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/xrServer_Objects_ALife_script2.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/xrServer_Objects_ALife_script3.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/xrServer_Objects_Alife_Smartcovers.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/xrServer_Objects_Alife_Smartcovers_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/xrServer_Objects_script.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")
set_source_files_properties(../xrServerEntities/xrServer_Objects_script2.cpp PROPERTIES COMPILE_FLAGS "/Yupch_script.h /Fp\"${SCRIPT_PCH_FILE}\"")

add_library(xrGame SHARED ${CORE_CLIENT_OBJECTS_BASE_ENTITYALIVE}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_PURE_COMS_PATH_BUILDER}
                          ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_LEVEL}
                          ${CORE_SERVER_GAMES_SERVER}
                          ${CORE_COMMON_NET_SHARED}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_LOW_COVER_PLANNER}
                          ${AI_AGROUP_AGENT_MANAGER_AGENT_EXPLOSIVE_MANAGER}
                          ${AI_AMONSTERS_MONSTERS_TUSHKANO}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_ABILITIES_INVISIBILITY}
                          ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_BASE_PARAMS}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_LR300}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_STEAL}
                          ${AI_AMONSTERS_MONSTERS_SNORK}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_HUD}
                          ${AI_AMONSTERS_MONSTERS_CONTROLLER_BASE_CONTROLLERS_DIRECTION}
                          ${CORE_COMMON_NET_SHARED_SECUREMESSAGES}
                          ${AI_ASCRIPT_SCRIPTSTORAGE}
                          ${AI_ANAVIGATION_PATROLPATHS_PATROLPOINT}
                          ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_WORLDPROPERTYEVALUATOR}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_AUTOMATIC}
                          ${AI_ALIFE_SERVER_ENTITIES_GROUP_ABSTRACT}
                          ${AI_ALIFE_SERVER_ENTITIES_HUMAN_OBJECT_HANDLER}
                          ${CORE_CLIENT_GAME_PERSISTENT}
                          ${AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER_SCRIPT}
                          ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_WORLDPROPERTYEVALUATOR_SCRIPTPROPERTYEVALUATORWRAPPER}
                          ${AI_ALIFE_INTERACTION_MANAGER}
                          ${CORE_CLIENT_LEVEL_BULLET_MANAGER}
                          ${AI_ANAVIGATION_PATROLPATHS_PATROLPATH}
                          ${AI_ALIFE_SERVER_ENTITIES_MONSTER_ABSTRACT}
                          ${AI_ACOMPONENTS_OBJECTHANDLER_PLANNER_ACTIONS}
                          ${AI_AMONSTERS_MONSTERS_BLOODSUCKER}
                          ${AI_AMONSTERS_MONSTERS_SNORK_SPECIAL_JUMP}
                          ${AI_AMONSTERS_HUMANS_STALKER_SOUNDDATAVISITOR}
                          ${AI_ASCRIPT_SCRIPTENGINE}
                          ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_LEVEL_FLOODER}
                          ${AI_ACOMPONENTS_MEMORYMANAGER_RAW_DATA_MANAGERS_VISUALMEMORYMANAGER_VISUAL_MEMORY_PARAMS}
                          ${CORE_CLIENT_OBJECTS_PHYSICS}
                          ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONPLANNERACTION}
                          ${AI_ANAVIGATION_OBJECTLOCATION}
                          ${AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTIONHOLDER}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_GRAVIARTIFACT}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_STATE}
                          ${AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTIONHOLDER_SPACERESTRICTIONSHAPE}
                          ${AI_AMONSTERS_MONSTERS_CONTROLLER_STATE_ATTACK_COVER}
                          ${AI_ACOMPONENTS_PROBLEMSOLVER_OPERATOR_ABSTRACT}
                          ${CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS_STATISTICS}
                          ${CORE_COMMON_OBJECTBROKER}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_DRAGDROP}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_EVENT_HANDLER}
                          ${AI_ACOMPONENTS_MOVEMENTMANAGER_LOCATIONSELECTORS_ABSTRACTLOCATIONSELECTOR}
                          ${AI_ACOMPONENTS_PROBLEMSOLVER_OPERATOR_CONDITION_SCRIPTWORLDPROPERTY}
                          ${CORE_CLIENT_OBJECTS_INVENTORY_EATABLEITEM}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_MESSAGEBOX}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_HINT}
                          ${AI_AMONSTERS_MONSTERS_CONTROLLER_STATE_PANIC}
                          ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_GENERIC}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTRENDERDEVICE}
                          ${CORE_COMMON_OBJECTFACTORY_OBJECT_ITEM_SCRIPT}
                          ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYITEMOBJECT}
                          ${AI_ASCRIPT_SCRIPTTHREAD_SCRIPTSTACKTRACKER}
                          ${AI_AMONSTERS_MONSTERS_DOGPSY}
                          ${CORE_CLIENT_OBJECTS_DELAYEDACTIONFUSE}
                          ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR_ANIMATION_PLANNER_TARGET_SELECTOR_TARGET_PROVIDER}
                          ${CORE_SERVER}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTFS}
                          ${CORE_CLIENT_SPECTATOR_CAMERAS}
                          ${AI_ACOMPONENTS_DECISIONMANAGEMENT}
                          ${CORE_SERVER_SERVERPERFORM}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTSOUND}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_RUSTYHAIRARTIFACT}
                          ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_BASE_VELOCITY_HOLDER}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_WATCH_ACTION}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_SCRIPTS}
                          ${AI_ALIFE_SERVER_ENTITIES_MONSTER_ABSTRACT_MOVEMENT_MANAGER}
                          ${CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_HOLDER_PARTICLESPLAYER}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_PROPERTIES}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_ABILITIES_TELEKINESIS}
                          ${AI_ALIFE_SERVER_ENTITIES_HUMAN_BRAIN}
                          ${CORE_SERVER_ID_GENERATOR}
                          ${CORE_CLIENT_OBJECTS_VEHICLES_CAR_CAR_MEMORY}
                          ${AI_AMONSTERS_MONSTERS_BLOODSUCKER_ATTACK}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_MAINMENU_KEYBINDING}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_PURE_COMS_MOVEMENT}
                          ${CORE_CLIENT_EFFECTS_CORE}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_PHSKELETON}
                          ${CORE_SERVER_GAMES_SERVER_SINGLE}
                          ${AI_AMONSTERS_MONSTERS_BOAR}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_INTERACTIVEBACKGROUND}
                          ${AI_AGROUP_AGENT_MANAGER_AGENT_CORPSE_MANAGER_MEMBER_CORPSE}
                          ${AI_ALIFE_INTERACTION_MANAGER_COMMUNICATION_MANAGER}
                          ${CORE_CLIENT_OBJECTS_INVENTORY_EATABLEITEMOBJECT}
                          ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_VERTEX_ALLOCATORS_FIXED}
                          ${AI_ANAVIGATION_PATHFINDING_ALGORITHMS_DIJKSTRA}
                          ${AI_AMONSTERS_MONSTERS_CHIMERA_STATE_THREATEN}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_LINES}
                          ${AI_ACOVER_SMART_COVER_STORAGE_DESCRIPTION}
                          ${AI_ALIFE_SERVER_ENTITIES_DYNAMIC_OBJECT}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_ABILITIES_PSY_AURA}
                          ${CORE_SERVER_GAMES_CLIENT_BASE}
                          ${CORE_CLIENT_OBJECTS_ZONES_MINCER}
                          ${AI_AMONSTERS_MONSTERS_RATS}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_HUDITEM}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_ALIFE_TASK_ACTIONS}
                          ${AI_ACOMPONENTS_MOVEMENTMANAGER_LOCATIONSELECTORS_LEVELLOCATIONSELECTOR}
                          ${AI_ALIFE_SERVER_ENTITIES_SMART_ZONE}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_STEAL_SQUAD_REST}
                          ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_OBJECT_REGISTRY}
                          ${AI_ALIFE_SIMULATOR_BASE_HEADER}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_PHDESTROYABLE}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_EDITBOX_CUSTOMEB}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_OBJECT_ACTION}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA_FACTIONWAR}
                          ${AI_ACOMPONENTS_MEMORYMANAGER}
                          ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_SPAWN_REGISTRY_SERVER_ENTITY_WRAPPER}
                          ${CORE_CLIENT_LEVEL_CLIENTSPAWNMANAGER}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTINIFILE}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_STATIC}
                          ${CORE_CLIENT_OBJECTS_ZONES_SPACERESTRICTOR}
                          ${AI_ACOMPONENTS_MOVING_OBJECTS_OBSTACLES_QUERY}
                          ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_WORLDPROPERTYEVALUATOR_CONST}
                          ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_SCHEDULE_REGISTRY}
                          ${AI_ACOMPONENTS_PROBLEMSOLVER_CONDITION_STATE_SCRIPTWORLDSTATE}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTREADER}
                          ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_IN_DIRECTION}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_GALANTINEARTIFACT}
                          ${AI_AMONSTERS_MONSTERS_TUSHKANO_SCRIPT}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_ACRIPT_ANIMATION_ACTION}
                          ${AI_AGROUP_AGENT_MANAGER_AGENT_PLANNER}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_WEAPON_GENERIC}
                          ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_LEVEL_STRAIGHT_LINE}
                          ${AI_AGROUP_AGENT_MANAGER_AGENT_LOCATION_MANAGER_DANGER_LOCATION}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_RG6}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_SCROLLVIEW}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_MELEE_CHECKER}
                          ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_OBSTACLES_OBSTACLE_AVOIDERS_DYNAMIC}
                          ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_GAME_VERTEX}
                          ${AI_AMONSTERS_COMMON_COMPONENTS}
                          ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_TRADE_PARAMETERS_TRADE_FACTOR_PARAMETERS}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_IN_DIRECTION_ACTIONS}
                          ${AI_ANAVIGATION_LEVELGRAPH}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_GENERAL_MOVEMENT}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTEFFECTOR_SCRIPTEFFECTORWRAPPER}
                          ${AI_ALIFE_UPDATE_MANAGER}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_SCRIPTWND}
                          ${AI_AGROUP_AGENT_MANAGER_AGENT_MEMBER_MANAGER_MEMBER_ORDER}
                          ${AI_AMONSTERS_MONSTERS_CHIMERA_STATE_HUNTING}
                          ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONPLANNER_ACTIONPLANNERSCRIPT}
                          ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_SMART_TERRAIN_REGISTRY}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS}
                          ${CORE_SERVER_SERVERPROCESS}
                          ${CORE_SERVER_SERVERENTITIES_SCRIPT_VALUE_CONTAINER}
                          ${CORE_CLIENT_LEVEL_DEBUG_RENDERER}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_PISTOL}
                          ${AI_AMONSTERS_MONSTERS_CAT}
                          ${CORE_CLIENT_OBJECTS_BASE_ENTITY}
                          ${AI_ASCRIPT_SCRIPTDEBUGGER}
                          ${AI_AMONSTERS_MONSTERS_CHIMERA_SCRIPT}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_VAL}
                          ${AI_ACOMPONENTS_SETUPMANAGER}
                          ${AI_AMONSTERS_MONSTERS_FRACTURE}
                          ${AI_AMONSTERS_MONSTERS_BLOODSUCKER_ALIEN_FEATURE}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_CHARACTERSUPPORT_INTERACTIVE_ANIMS}
                          ${AI_AEVAL_STORAGE}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_ACTION_CONDITION}
                          ${CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS_GAME_TASKS}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_GENERAL_LOOK}
                          ${CORE_CLIENT_LEVEL_LEVELNETWORKDEMO}
                          ${CORE_CLIENT_OBJECTS_ZONES_SCRIPTZONE}
                          ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_PATH_BUILDERS_VERTEX_PATH}
                          ${AI_ACOMPONENTS_DOORS_MANAGER_MANAGER}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_PURE_COMS_DIRECTION}
                          ${AI_AMONSTERS_MONSTERS_BLOODSUCKER_CAPTURE_JUMP}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTGAMEOBJECT}
                          ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_VERTEX_MANAGERS_FIXED}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_UNKNOWN_ACTIONS}
                          ${CORE_CLIENT_LEVEL_LEVEL_SOUNDS}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_MOVEMENT_ACTION_PATROL_PATH_PARAMS}
                          ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_BASE_RESTRICTION}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_AK74}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_EAT_DRAG}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTLANIM}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_BASTARTIFACT}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_DESTROYABLEPHYSICSOBJECT}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_SPINBOX}
                          ${AI_AMONSTERS_MONSTERS_CONTROLLER_PSY_HIT}
                          ${CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_SVU}
                          ${CORE_SERVER_SERVERENTITIES_OBJECTS_ALIFE_MONSTERS}
                          ${AI_AMONSTERS_MONSTERS_BURER_SCRIPT}
                          ${CORE_CLIENT_LEVEL_SENIORITYHIERARCHYHOLDER_SQUADHIERARCHYHOLDER}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_GRENADES__AND__MISSILES}
                          ${CORE_CLIENT_OBJECTS_ZONES_CUSTOMZONE}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_INTERESTING_SOUND}
                          ${AI_ALIFE_SERVER_ENTITIES_OBJECT}
                          ${CORE_CLIENT_OBJECTS_ZONES_MOSQUITOBALD}
                          ${AI_AMONSTERS_MONSTERS_ZOMBIE_SCRIPT}
                          ${AI_ACOMPONENTS_SOUNDPLAYER_SOUND_COLLECTION_STORAGE}
                          ${CORE_CLIENT_OBJECTS_ACTOR_BASE_MEMORY}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_GRENADE_F1}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_MONSTER_ACTION}
                          ${AI_ACOMPONENTS_PROBLEMSOLVER_OPERATOR_CONDITION}
                          ${AI_AMONSTERS_COMMON_CUSTOM}
                          ${AI_ACOMPONENTS_PROBLEMSOLVER_CONDITION_STATE}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_MEMORY}
                          ${AI_ACOMPONENTS_STEP_MANAGER}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DEATH}
                          ${CORE_SERVER_FILETRANSFER}
                          ${AI_ASCRIPT_SCRIPTCLASSES_BASECLIENTCLASSES}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_CHARACTERSUPPORT_DEATH_ANIMS}
                          ${CORE_CLIENT_OBJECTS_INVENTORY_ATTACHABLEITEM}
                          ${AI_AMONSTERS_MONSTERS_BLOODSUCKER_SCRIPT}
                          ${CORE_CLIENT_LEVEL_CLIENTDIGESTCOMPUTER}
                          ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_GAME}
                          ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONBASE}
                          ${CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_AI_OBSTACLE_MIN_OBB_MINIMIZE_1D}
                          ${AI_ANAVIGATION_PATHFINDING_GRAPHENGINE}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_BM_16}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_DAMAGABLEITEM}
                          ${AI_ALIFE_UPDATE_MANAGER_STORAGE_MANAGER}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_PHCOMMANDER}
                          ${AI_ACOMPONENTS_MEMORYMANAGER_RAW_DATA_MANAGERS_SOUNDMEMORYMANAGER_SOUNDUSERDATAVISITOR}
                          ${AI_ACOMPONENTS_MEMORYMANAGER_RAW_DATA_MANAGERS_HITMEMORYMANAGER}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTFLAGS}
                          ${CORE_CLIENT_OBJECTS_BASE_ENTITYCONDITION}
                          ${AI_ACOVER_SMART_COVER_DETAIL}
                          ${AI_AMONSTERS_COMMON_SCRIPT_SCRIPT_OBJECT}
                          ${CORE_CLIENT_OBJECTS_INVENTORY}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DEVICES_DETECTORS_ELITEDETECTOR}
                          ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER}
                          ${AI_ALIFE_SERVER_ENTITIES_HUMAN}
                          ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONBASE_SCRIPTACTIONWRAPPER}
                          ${CORE_SERVER_SERVERENTITIES_OBJECTS_ALIFE}
                          ${AI_ANAVIGATION_GRAPHABSTRACT_GRAPHEDGE}
                          ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_TRADE_PARAMETERS_TRADE_FACTORS}
                          ${AI_AEVAL_FUNCTIONS_PATTERNS}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_OUTFIT}
                          ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_RELATION_REGISTRY}
                          ${AI_ALIFE_UPDATE_MANAGER_SURGE_MANAGER}
                          ${AI_ALIFE_INVENTORY_UPGRADE_UPGRADE_BASE}
                          ${AI_AMONSTERS_COMMON_SCRIPT_SCRIPT_BINDER}
                          ${CORE_COMMON_DATETIME}
                          ${AI_ACOMPONENTS_MATERIALMANAGER}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_EVENT_HANDLER_CUSTOM_EVENTS}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_BASE_CONTROLLERS_MOVEMENT}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_BREAKABLE}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_CURSOR}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_HOME_POINT}
                          ${CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_AI_OBSTACLE_MIN_OBB_MAGIC_BOX}
                          ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_OBSTACLES_RESTRICTED_OBJECT_OBSTACLE}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_TRIPLE_ANIMATION}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_BASE_CONTROLLERS_PATH_BUILDER}
                          ${CORE_CLIENT_LEVEL_DEBUG}
                          ${CORE_CLIENT_CAMERAS}
                          ${AI_AMONSTERS_MONSTERS_CROW}
                          ${AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTIONHOLDER_SPACERESTRICTIONCOMPOSITION}
                          ${AI_ACOMPONENTS_MEMORYMANAGER_RAW_DATA_MANAGERS_VISUALMEMORYMANAGER}
                          ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONPLANNERACTION_SCRIPTACTIONPLANNERACTIONWRAPPER}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_BINOCULAR}
                          ${AI_AMONSTERS_COMMON_STEERING_BEHAVIOURS}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_EXPLOSIVES}
                          ${AI_ASCRIPT_SCRIPTPROCESS}
                          ${AI_AEVAL_FUNCTIONS_BASE}
                          ${CORE_CLIENT_OBJECTS_VEHICLES_CAR_CARWEAPON}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_MOTION_STATS}
                          ${CORE_COMMON_OBJECTFACTORY_OBJECT_ITEM_CLIENT_SERVER}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_TUTORIAL}
                          ${AI_AMONSTERS_MONSTERS_FLESH}
                          ${AI_ACOMPONENTS_SIGHTMANAGER_AIMERS_BASE}
                          ${AI_AMONSTERS_MONSTERS_PSEUDOGIGANT_SCRIPT}
                          ${AI_AEVAL_FUNCTIONS_PRIMARY}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_CHARACTERSUPPORT_INTERACTIVE_MOTION}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_INVENTORY}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_ALIFE}
                          ${AI_ACOMPONENTS_MOVEMENTMANAGER_PATHMANAGERS_PATROLPATHMANAGER}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_ADDONS_SCOPE}
                          ${CORE_COMMON_QUADTREE}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_LOW_COVER_PLANNER_ACTIONS}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_USP45}
                          ${CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS_ENCYCLOPEDIA}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_SCROLLBAR}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_BLACKDROPS}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DEVICES_FLARE}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_AMMO}
                          ${AI_ACOVER_COVER_POINT}
                          ${AI_ACOVER_SMART_COVER_STORAGE_DESCRIPTION_LOOPHOLE}
                          ${AI_AMONSTERS_MONSTERS_BURER_ATTACK}
                          ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_SPAWN_REGISTRY}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_KNIFE}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTCALLBACKEX}
                          ${AI_ACOVER_SMART_COVER_OBJECT}
                          ${CORE_CLIENT_OBJECTS_VEHICLES_CAR}
                          ${AI_AMONSTERS_COMMON_BASE_MONSTER}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTINIFILE_SCRIPTTOKENLIST}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_ABILITIES_ENERGY_HOLDER}
                          ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_GROUP_REGISTRY}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_ROCKETLAUNCHER}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_BUTTONS}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_UI_ITEM_INFOS}
                          ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_TRADE_PARAMETERS_PURCHASE_LIST}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_SEARCH_PLANNER_ACTIONS}
                          ${CORE_CLIENT_LEVEL_LEVELMAPSYNC}
                          ${AI_ALIFE_INVENTORY_UPGRADE}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_FIND_ENEMY}
                          ${AI_ACOMPONENTS_MOVING_OBJECTS}
                          ${AI_AGROUP_AGENT_MANAGER_AGENT_MEMORY_MANAGER}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_ALIFE}
                          ${CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS_DIALOGS}
                          ${AI_ACOMPONENTS_SIGHTMANAGER_AIMERS_WEAPON}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_MORALE}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_RGD5}
                          ${AI_AGROUP_AGENT_MANAGER_AGENT_MEMBER_MANAGER}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_DANGEROUS_SOUND}
                          ${CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_HOLDER}
                          ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_LEVEL_NEAREST_VERTEX}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_TRACKBAR}
                          ${CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS_MAP}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTBINDEROBJECT_SCRIPTBINDEROBJECTWRAPPER}
                          ${CORE_CLIENT_LEVEL_AUTOSAVEMANAGER}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_ATTACK}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DOCUMENTS}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_TALK}
                          ${CORE_CLIENT_EFFECTORS_WEAPON}
                          ${AI_ACOMPONENTS_MOVEMENTMANAGER_PATHMANAGERS_GAMEPATHMANAGER}
                          ${CORE_CLIENT_OBJECTS_ZONES_LEVELCHANGER}
                          ${CORE_CLIENT_OBJECTS_SEARCHLIGHT_TRADE}
                          ${AI_AMONSTERS_COMMON_STEERING_BEHAVIOURS_COMPONENTS_COHESION}
                          ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_SHOTGUN}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_RPG7}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_BY_SOUND}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_MAININGAME}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_FOOD__AND__DRUGS}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_EAT_EATING}
                          ${AI_ACOMPONENTS_DAMAGEMANAGER}
                          ${AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER_DATA_STORAGE}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_BASE_CONTROLLERS_ANIMATION}
                          ${AI_ALIFE_SERVER_ENTITIES_ONLINE_OFFLINE_GROUP}
                          ${AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER_STATE}
                          ${AI_ACOMPONENTS_MOVEMENTMANAGER_RESTRICTEDOBJECT}
                          ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_WORLDPROPERTYEVALUATOR_MEMBER}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_SOUND_ACTION}
                          ${AI_AGROUP_AGENT_MANAGER_AGENT_ENEMY_MANAGER_MEMBER_ENEMY}
                          ${AI_AMONSTERS_MONSTERS_CAT_SCRIPT}
                          ${AI_AMONSTERS_MONSTERS_BLOODSUCKER_PREDATOR_STATE}
                          ${AI_AMONSTERS_HUMANS_TRADER}
                          ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_OBSTACLES}
                          ${AI_AMONSTERS_MONSTERS_DOGPSY_PSY_ATTACK_HIDE}
                          ${AI_AGROUP_AGENT_MANAGER_AGENT_PLANNER_ACTIONS}
                          ${CORE_COMMON_STRINGTABLE}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_PM}
                          ${AI_AMONSTERS_COMMON_STEERING_BEHAVIOURS_COMPONENTS_ALIGNMENT}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_ARROW}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS}
                          ${AI_ASOUND}
                          ${AI_ALIFE_SERVER_ENTITIES_MONSTER_ABSTRACT_BRAIN}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DEVICES_DETECTORS}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_ACTOR_CONTROLLER}
                          ${CORE_CLIENT_LEVEL_SENIORITYHIERARCHYHOLDER_TEAMHIERARCHYHOLDER}
                          ${AI_AMONSTERS_MONSTERS_RATS_STATES_BASE}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_HIT}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_HITTED}
                          ${CORE_CLIENT_SPECTATOR}
                          ${CORE_COMMON_DLL_PROCESS_DETACH}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_HPSA}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_CHARACTERSUPPORT_HIT_ANIMS}
                          ${AI_AMONSTERS_MONSTERS_PSEUDODOG_SCRIPT}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_CLIMABLE}
                          ${CORE_CLIENT_OBJECTS_ZONES_TEAMBASEZONE}
                          ${AI_ALIFE_SERVER_ENTITIES_MONSTER_ABSTRACT_MOVEMENT_MANAGER_MOVEMENT_MANAGER_HOLDER}
                          ${AI_ACOMPONENTS_SIGHTMANAGER_SIGHT_CONTROL_ACTION}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_TABCONTROL}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DEVICES_DETECTORS_SIMPLE_DETECTOR}
                          ${CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_AI_OBSTACLE}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_EAT}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_ADDONS_GRENADELAUNCHER}
                          ${CORE_CLIENT_OBJECTS_ZONES_ZONEVISUAL}
                          ${CORE_CLIENT_OBJECTS_ZONES_FRYUPZONE}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTEFFECTOR}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_MOVEMENT_ACTION}
                          ${AI_ACOMPONENTS_DOORS_MANAGER_ACTOR}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_PDA__AND__INFORMATION}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_BOLT}
                          ${AI_ACOMPONENTS_DOORS_MANAGER_DOOR}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_GET_DISTANCE_ACTIONS}
                          ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONBASE_ACTIONSCRIPTBASE}
                          ${AI_AGROUP_AGENT_MANAGER_AGENT_CORPSE_MANAGER}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_INVENTORYWND_INVENTORYUPGRADE}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_ABSTRACT_ACTION}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_GENERAL}
                          ${AI_ACOMPONENTS_MOVEMENTMANAGER_PATHMANAGERS_ABSTRACTPATHMANAGER}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTFMATRIX}
                          ${AI_AGROUP_AGENT_MANAGER_AGENT_LOCATION_MANAGER_DANGER_COVER_LOCATION}
                          ${AI_ACOMPONENTS_MEMORYMANAGER_CLSUTERIZED_DATA_MANAGERS_OBJECTMANAGER}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_ANOMALY_DETECTOR}
                          ${AI_ALIFE_SERVER_ENTITIES_TRADER_ABSTRACT}
                          ${AI_ACOMPONENTS_PROBLEMSOLVER}
                          ${AI_ALIFE_INVENTORY_UPGRADE_UPGRADE_ROOT}
                          ${CORE_CLIENT_OBJECTS_BASE_USABLESCRIPTOBJECT}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_BY_SOUND_ACTIONS}
                          ${AI_ACOVER}
                          ${AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER_DATA_STORAGE_DATA}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_PANIC}
                          ${CORE_CLIENT_LEVEL_SENIORITYHIERARCHYHOLDER}
                          ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR_ANIMATION_PLANNER}
                          ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_CONSTRUCTORS}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_WALTHER_99}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_CUSTOM_WEAPON_ADDONS_SILENCER}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_ANOMALY}
                          ${CORE_COMMON_DEBUG_MAKE_FINAL}
                          ${AI_ALIFE}
                          ${AI_ACOMPONENTS_MEMORYMANAGER_CLSUTERIZED_DATA_MANAGERS_ITEMMANAGER}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_MAINMENU}
                          ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_EVALUATORS}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_PROGRESSBAR}
                          ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYITEM}
                          ${AI_ACOMPONENTS_MEMORYMANAGER_RAW_DATA_MANAGERS_SOUNDMEMORYMANAGER}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_COVER_MANAGER}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_CONTROLLED}
                          ${AI_ACOMPONENTS_OBJECTHANDLER_PLANNER}
                          ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_SPAWN_REGISTRY_HEADER}
                          ${CORE_COMMON_CONSOLE_COMMANDS}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_GROZA}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DEVICES_TORCH}
                          ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_OBSTACLES_OBSTACLE_AVOIDERS_STATIC}
                          ${AI_ANAVIGATION_GRAPHABSTRACT_GRAPHVERTEX}
                          ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_SOLVER}
                          ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR_ANIMATION_PLANNER_LOOPHOLE_ACTIONS}
                          ${AI_ALIFE_SIMULATOR_BASE}
                          ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR_ANIMATION_PLANNER_TARGET_SELECTOR_DEFAULT_BEHAVIOUR}
                          ${AI_AMONSTERS_HUMANS_STALKER}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_ZUDAARTIFACT}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_ROTATION_JUMP}
                          ${AI_ANAVIGATION_PATHFINDING_ALGORITHMS_ASTAR}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_BONES}
                          ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_CONSTRUCTORS_BUILDER_ALLOCATOR}
                          ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_CONSTRUCTORS_MANAGER_BUILDER_ALLOCATOR}
                          ${CORE_SERVER_EDITOR}
                          ${AI_AMONSTERS_COMMON_STEERING_BEHAVIOURS_MANAGER}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_FADED_BALL}
                          ${AI_ALIFE_SERVER_ENTITIES_ONLINE_OFFLINE_GROUP_BRAIN}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_FN2000}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_HELP_SOUND}
                          ${AI_ACOMPONENTS_MOVEMENTMANAGER}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON__DEBUG_FONTS}
                          ${AI_AGROUP_AGENT_MANAGER_AGENT_ENEMY_MANAGER}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_ACTIONS}
                          ${CORE_CLIENT_OBJECTS_HANGING_LAMP}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA_LOGS_NEWS}
                          ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_SAFE_MAP_ITERATOR}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_KILL_WOUNDED}
                          ${AI_AMONSTERS_HUMANS_STALKER_MISCELLANEOUS}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTSOUNDTYPE}
                          ${CORE_SERVER_SERVERCONNECT}
                          ${AI_AMONSTERS_HUMANS_STALKER_SOUNDUSERDATA}
                          ${CORE_CLIENT_OBJECTS_ZONES_TORRIDZONE}
                          ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_OBSTACLES_REFRESHABLE_OBSTACLES_QUERY}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_PURE_COMS_ANIMATION}
                          ${AI_ADEBUG}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_STATIONARYMGUN}
                          ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_PROPERTYSTORAGE}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_NEEDLES}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_REST}
                          ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONPLANNERACTION_ACTIONPLANNERACTIONSCRIPT}
                          ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR_ANIMATION_PLANNER_TARGET_SELECTOR}
                          ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS}
                          ${CORE_CLIENT_OBJECTS_ZONES_SMARTZONE}
                          ${CORE_CLIENT_OBJECTS_INVENTORY_PHYSICITEM}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_UNKNOWN}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_AUTOMATICSHOTGUN}
                          ${CORE_CLIENT_OBJECTS_ZONES_GRAVIZONE}
                          ${AI_AGROUP_AGENT_MANAGER_AGENT_LOCATION_MANAGER}
                          ${AI_ACOMPONENTS_SIGHTMANAGER}
                          ${AI_ACOMPONENTS_MEMORYMANAGER_CLSUTERIZED_DATA_MANAGERS_DANGERMANAGER}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_OPTIONSITEM}
                          ${AI_AMONSTERS_MONSTERS_SNORK_SCRIPT}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTFCOLOR}
                          ${AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER_PAIR}
                          ${AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER}
                          ${CORE_CLIENT_LEVEL}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_CAMP}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_PARTICLE_ACTION}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTMONSTERHITINFO}
                          ${AI_ALIFE_INVENTORY_UPGRADE_UPGRADE}
                          ${AI_AMONSTERS_MONSTERS_ZOMBIE_STATES}
                          ${CORE_COMMON_RANDOM_WEIGHTED}
                          ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_BASE}
                          ${AI_AMONSTERS_MONSTERS_RATS_STATES}
                          ${AI_AMONSTERS_MONSTERS_CONTROLLER}
                          ${CORE_CLIENT_OBJECTS_ZONES_NOGRAVITYZONE}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_XML}
                          ${CORE_SERVER_GAMES_CLIENT_SINGLE}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_INVENTORYUTILITIES}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTBINDEROBJECT}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_GRENADE_ACTIONS}
                          ${CORE_CLIENT_OBJECTS_SEARCHLIGHT}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_ALIFE_ACTIONS}
                          ${CORE_COMMON_DEBUG_STATIC_CAST_CHECKED}
                          ${AI_AMONSTERS_MONSTERS_PSEUDOGIGANT}
                          ${CORE_CLIENT_LEVEL_SENIORITYHIERARCHYHOLDER_GROUPHIERARCHYHOLDER}
                          ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS}
                          ${AI_AGROUP_AGENT_MANAGER_AGENT_EXPLOSIVE_MANAGER_DANGER_EXPLOSIVE}
                          ${AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTION}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_UI_ITEM_INFOS_CHARACTERINFO}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_WINDOWS}
                          ${AI_AMONSTERS_MONSTERS_DOG}
                          ${AI_ACOMPONENTS_OBJECTHANDLER}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_KILL_WOUNDED_ACTIONS}
                          ${AI_AMONSTERS_COMMON_TRAJECTORIES}
                          ${AI_ASCRIPT_LUA_STUDIO}
                          ${AI_AMONSTERS_MONSTERS_POLTERGEIST_HIDDEN_ATTACK}
                          ${CORE_CLIENT_LEVEL_GLOBALFEELTOUCH}
                          ${AI_ASCRIPT_SCRIPTCLASSES_CONSOLE}
                          ${AI_ACOMPONENTS_MEMORYMANAGER_CLSUTERIZED_DATA_MANAGERS_DANGERMANAGER_DANGER_OBJECT}
                          ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_STORY_REGISTRY}
                          ${AI_ACOVER_SMART_COVER_STORAGE_DESCRIPTION_TRANSITIONS_TRANSITION}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA_TASKS}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTPARTICLES}
                          ${AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTIONHOLDER_SPACERESTRICTIONBRIDGE}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTNETPACKET}
                          ${CORE_CLIENT_PARTICLES}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_BLACKGRAVIARTIFACT}
                          ${AI_ASCRIPT}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_SVD}
                          ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_TRADE_PARAMETERS_TRADE_ACTION_PARAMETERS}
                          ${CORE_COMMON_ASSOCIATIVE_VECTOR_COMPARE}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_CRITICALWOUND}
                          ${AI_AMONSTERS_MONSTERS_CONTROLLER_SCRIPT}
                          ${CORE_CLIENT_OBJECTS_VEHICLES_HELI}
                          ${AI}
                          ${AI_AMONSTERS_MONSTERS_CHIMERA}
                          ${CORE_CLIENT_OBJECTS_ZONES_RADIOACTIVEZONE}
                          ${AI_ALIFE_SIMULATOR_BASE_TIME_MANAGER}
                          ${AI_AMONSTERS_MONSTERS_FLESH_SCRIPT}
                          ${AI_ACOMPONENTS_MOVING_OBJECTS_MOVING_OBJECT}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_SEQUENCER}
                          ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONPLANNER_SCRIPTACTIONPLANNERWRAPPER}
                          ${AI_ALIFE_SERVER_ENTITIES_MONSTER_ABSTRACT_MOVEMENT_MANAGER_PATROL_PATH_MANAGER}
                          ${AI_ACOMPONENTS_DECISIONMANAGEMENT_ACTIONMANAGEMENT_ACTIONPLANNER}
                          ${AI_AMONSTERS_MONSTERS_BURER_FAST_GRAVI}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTINIFILE_SCRIPTRTOKENLIST}
                          ${AI_AMONSTERS_COMMON_MISCELLANEOUS}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_ELECTRIC_BALL}
                          ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER}
                          ${CORE_CLIENT_OBJECTS_ZONES_CAMPFIRE}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTFVECTOR}
                          ${AI_ACOMPONENTS_MOVEMENTMANAGER_PATHMANAGERS_DETAILPATHMANAGER}
                          ${AI_ACOVER_SMART_COVER_STORAGE_DESCRIPTION_LOOPHOLE_ACTION}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_EDITBOX}
                          ${AI_ANAVIGATION_GAMEGRAPH}
                          ${CORE_CLIENT_OBJECTS_INVENTORY_BOX}
                          ${AI_AMONSTERS_MONSTERS_FRACTURE_SCRIPT}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_BASE_CONTROLLERS_DIRECTION}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_THORNARTIFACT}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS}
                          ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_SMART_COVERS_ANIMATION_SELECTOR_ANIMATION_PLANNER_COVER_ACTIONS}
                          ${AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTIONHOLDER_SPACERESTRICTIONBASE}
                          ${AI_ALIFE_SERVER_ENTITIES_MONSTER_ABSTRACT_MOVEMENT_MANAGER_DETAIL_PATH_MANAGER}
                          ${CORE_CLIENT_OBJECTS_INVENTORY_ATTACHMENTOWNER}
                          ${CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_AI_OBSTACLE_MIN_OBB_MAGIC_MINIMIZE_ND}
                          ${CORE_CLIENT_EFFECTORS_ACTOR}
                          ${AI_ACOMPONENTS_SIGHTMANAGER_CONTROL_ACTION}
                          ${CORE_COMMON_OBJECTFACTORY_OBJECT_ITEM_ABSTRACT}
                          ${AI_AMONSTERS_MONSTERS_CONTROLLER_BASE_CONTROLLERS_ANIMATION}
                          ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_PARAMS}
                          ${CORE_SERVER_GAMES_PLAYERACCOUNTS}
                          ${CORE_COMMON_OBJECTFACTORY_OBJECT_ITEM_SINGLE}
                          ${CORE_SERVER_SERVERENTITIES_OBJECTS_ALIFE_ITEMS}
                          ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_TRADE_PARAMETERS_TRADE_BOOL_PARAMETERS}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DEATH_ACTIONS}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_COMBOBOX}
                          ${AI_AMONSTERS_COMMON_SCRIPT_SCRIPT_ENTITY}
                          ${AI_ASCRIPT_SCRIPTCLASSES_KEYBINDINGS}
                          ${CORE_COMMON_PROFILER}
                          ${AI_AMONSTERS_MONSTERS_DOG_SCRIPT}
                          ${AI_AMONSTERS_MONSTERS_CONTROLLER_STATE_ATTACK}
                          ${CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT_AI_OBSTACLE_MIN_OBB}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_PHYSICSSKELETONOBJECT}
                          ${AI_AMONSTERS_HUMANS_STALKER_MOVEMENTMANAGER_BASE_VELOCITY_COLLECTION}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_COVER}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_GAMETYPES_SINGLE}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_GET_DISTANCE}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_PARTICLE_ACTION_PARTICLE_PARAMS}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_PROPERTIESBOX}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_ACTIONS_BASE}
                          ${AI_ACOMPONENTS_MOVEMENTMANAGER_LOCATIONSELECTORS_GAMELOCATIONSELECTOR}
                          ${CORE_CLIENT_OBJECTS_TASKS_INFO_DIALOGS_NEWS}
                          ${AI_AMONSTERS_COMMON_STEERING_BEHAVIOURS_COMPONENTS_SEPARATION}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_DEVICES_DETECTORS_ADVANCEDDETECTOR}
                          ${AI_ACOMPONENTS_SIGHTMANAGER_AIMERS_BONE}
                          ${AI_AMONSTERS_HUMANS_STALKER_COVEREVALUATORS}
                          ${AI_ALIFE_INVENTORY_UPGRADE_PROPERTY}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_PHYSICSSHELLHOLDER}
                          ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_PRIORITY_QUEUES}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_GROUP_MONSTERS_HOME}
                          ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_TRADE_PARAMETERS_TRADE_PARAMETERS}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_WEAPON_VINTOREZ}
                          ${CORE_COMMON_ASSOCIATIVE_VECTOR_VECTOR}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI}
                          ${AI_ACOMPONENTS_SPACERESTRICTIONMANAGER_SPACERESTRICTIONHOLDER_SPACERESTRICTIONABSTRACT}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_CHARACTERSUPPORT}
                          ${AI_ANAVIGATION_GAMELEVELCROSSTABLE}
                          ${CORE_COMMON_SHARED}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA_LOGS}
                          ${AI_ACOMPONENTS_MOVEMENTMANAGER_PATHMANAGERS_LEVELPATHMANAGER}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_FADED_BALL_MERCURY_BALL}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_HOME}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_SQUAD}
                          ${AI_ACOMPONENTS_MOVEMENTMANAGER_LOCATIONMANAGER}
                          ${AI_AMONSTERS_MONSTERS_POLTERGEIST_SCRIPT}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_GENERAL_TEST}
                          ${AI_ASPACE}
                          ${AI_ALIFE_SERVER_ENTITIES_ANOMALOUS_ZONE}
                          ${AI_AMONSTERS_COMMON_MONSTER_STATES_GENERAL_CUSTOM_ACTION}
                          ${AI_ACOMPONENTS_SIGHTMANAGER_SIGHT_ACTION}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_GAMETYPES_GAMECUSTOM}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_WEAPONS_VARIOUS_WEAPONS_FORT}
                          ${AI_ACOMPONENTS_MEMORYMANAGER_RAW_DATA_MANAGERS_VISUALMEMORYMANAGER_VISION_CLIENT}
                          ${AI_ACOMPONENTS_DOORS_MANAGER}
                          ${AI_ACOMPONENTS_OBJECTHANDLER_PLANNER_PROPERTIES}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_SQUAD_SQUAD_MANAGER}
                          ${AI_ASCRIPT_SCRIPTCLASSES}
                          ${AI_AMONSTERS_MONSTERS_BLOODSUCKER_VAMPIRE_STATE}
                          ${AI_AGROUP_AGENT_MANAGER_AGENT_PLANNER_PROPERTIES}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_COMBAT_SEARCH_PLANNER}
                          ${AI_ALIFE_SAVED_GAME_WRAPPER}
                          ${AI_AMONSTERS_MONSTERS_POLTERGEIST_ABILITIES}
                          ${CORE_COMMON_OBJECTFACTORY}
                          ${AI_ACOMPONENTS_SOUNDPLAYER}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_THREATEN}
                          ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_GRAPH_REGISTRY_LEVEL_REGISTRY}
                          ${AI_ALIFE_SERVER_ENTITIES_CREATURE_ABSTRACT}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_DANGER_ACTIONS_GRENADE}
                          ${AI_ACOVER_SMART_COVER_STORAGE_DESCRIPTION_TRANSITIONS_ANIMATION}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA}
                          ${AI_ASCRIPT_SCRIPTTHREAD}
                          ${CORE_CLIENT_OBJECTS_ACTOR_BASE}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_DEBUG}
                          ${AI_ALIFE_INVENTORY_UPGRADE_UPGRADE_GROUP}
                          ${AI_ALIFE_SERVER_ENTITIES_TRADER}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_ABILITIES_CONTROLLED}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_PROPERTIES}
                          ${AI_AMONSTERS_MONSTERS_PSEUDODOG}
                          ${AI_AMONSTERS_MONSTERS_BOAR_SCRIPT}
                          ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_GRAPH_REGISTRY}
                          ${AI_ACOMPONENTS_SPACERESTRICTIONMANAGER}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_IK}
                          ${AI_AMONSTERS_MONSTERS_RATS_STATE_MANAGER}
                          ${AI_ALIFE_UPDATE_MANAGER_SWITCH_MANAGER}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_UIWINDOWS_LISTBOX}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_JUMP}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_ANIMATION_MOVEMENT_CONTROLLER}
                          ${CORE_CLIENT_EFFECTORS_POSTPROCESS}
                          ${AI_AMONSTERS_COMMON_STEERING_BEHAVIOURS_BASE}
                          ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_VERTEX_MANAGERS_HASH_FIXED}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTSOUNDINFO}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_MOVEMENTCONTROL}
                          ${CORE_CLIENT_EFFECTORS_MONSTERS_QQQ}
                          ${CORE_COMMON_SMARTCAST}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER}
                          ${AI_ACOMPONENTS_MEMORYMANAGER_CLSUTERIZED_DATA_MANAGERS_ENEMYMANAGER}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTACTIONS_SCRIPT_ENTITY_ACTION}
                          ${AI_ALIFE_SIMULATOR_BASE_REGISTRY_CONTAINER}
                          ${AI_AMONSTERS_MONSTERS_BURER}
                          ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_PATH_BUILDERS_EDGE_PATH}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_COLLISIONDAMAGERECEIVER}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_ABILITIES_SCAN}
                          ${AI_ALIFE_SIMULATOR_BASE_REGISTRIES_ABSTRACT_REGISTRY}
                          ${AI_ACOVER_SMART_COVER_STORAGE}
                          ${AI_AMONSTERS_MONSTERS_POLTERGEIST}
                          ${CORE_SERVER_SERVERENTITIES}
                          ${CORE_COMMON_RANDOM_32BIT}
                          ${AI_ALIFE_INTERACTION_MANAGER_COMBAT_MANAGER}
                          ${CORE}
                          ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_PRIORITY_QUEUES_BINARY_HEAP}
                          ${CORE_CLIENT_OBJECTS_BASE_GAMEOBJECT}
                          ${AI_AMONSTERS_MONSTERS_ZOMBIE}
                          ${AI_AMONSTERS_COMMON_COMPONENTS_CONTROL_MANAGER_CUSTOM_RUN_ATTACK}
                          ${AI_ANAVIGATION_PATHFINDING_PATHMANAGERS_PATH_MANAGER_GAME_LEVEL}
                          ${AI_AGROUP_AGENT_MANAGER_AGENT_LOCATION_MANAGER_DANGER_OBJECT_LOCATION}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_PHYSICSSOUNDPLAYER}
                          ${AI_AGROUP_AGENT_MANAGER}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA_MAP}
                          ${CORE_CLIENT_LEVEL_CONTROLLER}
                          ${CORE_SERVER_GAMES}
                          ${AI_ANAVIGATION_PATHFINDING_DATASTORAGES_PRIORITY_QUEUES_BUCKET_LIST}
                          ${AI_AMONSTERS_HUMANS_STALKER_ANIMATIONMANAGER_NAMES}
                          ${CORE_CLIENT_OBJECTS_ZONES_HAIRSZONE}
                          ${CORE_CLIENT_OBJECTS_INVENTORY_INVENTORYOWNER_CHARACTER_INFO}
                          ${AI_ALIFE_SIMULATOR_BASE_SMART_TERRAIN_TASK}
                          ${AI_ASCRIPT_SCRIPTCLASSES_UI_COMMON_PDA_STATISTICS__AND__RANKINGS}
                          ${AI_AMONSTERS_HUMANS_STALKER_DECISIONMAKER_ACTIONS_ANOMALY_ACTIONS}
                          ${CORE_CLIENT_OBJECTS_PHYSICS_PHYSICOBJECT}
                          ${AI_ACOVER_SMART_COVER_COVER}
                          ${AI_AMONSTERS_MONSTERS_PHANTOM}
                          ${AI_ANAVIGATION_PATROLPATHS_PATROLPATHSTORAGE}
                          ${AI_ASCRIPT_SCRIPTCLASSES_SCRIPTHIT}
                          ${CORE_CLIENT_OBJECTS_ITEMS__AND__WEAPONS_ARTIFACTS_DUMMYARTIFACT}
                          ${CORE_SERVER_SERVERENTITIES_OBJECTS}
                          ${CORE_SERVER_SERVERENTITIES_OBJECTS_ALIFE_SMARTCOVER})
target_link_libraries(xrGame shell32 Shlwapi xrEngine luabind cs xrXMLParser xrPhysics)