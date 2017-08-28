cmake_minimum_required(VERSION 3.8)

project(xrPhysics)

set(PHYSICS_COLLIDERS_RAYMOTIONS dRayMotions.cpp
                                 dRayMotions.h)

set(PHYSICS_BASE_IMPACT PHImpact.h)

set(PHYSICS console_vars.cpp
            ShellHit.cpp
            console_vars.h)

set(PHYSICS_BASE_DEBUG debug_output.cpp
                       debug_output.h)

set(PHYSICS_BASE_OBJECTS_PHYMOVE_BASECHARACTER MovementBoxDynamicActivate.cpp
                                               PHCharacter.cpp
                                               IColisiondamageInfo.h
                                               MovementBoxDynamicActivate.h
                                               PHCharacter.h)

set(KERNEL stdafx.cpp
           xrPhysics.cpp
           stdafx.h
           xrPhysics.h)

set(PHYSICS_BASE_OBJECTS_MOVESTORAGE PHMoveStorage.cpp
                                     PHMoveStorage.h)

set(PHYSICS_BASE_OBJECTS_UTILS_STORAGE BlockAllocator.h
                                       CycleConstStorage.h)

set(PHYSICS_BASE_OBJECTS_UTILS phvalide.cpp
                               ph_valid_ode.h
                               phvalide.h
                               PHValideValues.h)

set(PHYSICS_BASE_OBJECTS_PHISLAND PHIsland.cpp
                                  PHIsland.h)

set(PHYSICS_BASE_OBJECTS_ELEMENT_GEOM ExtendedGeom.cpp
                                      Geometry.cpp
                                      PHGeometryOwner.cpp
                                      ExtendedGeom.h
                                      Geometry.h
                                      PHGeometryOwner.h)

set(PHYSICS_BASE_OBJECTS_PHOBJECT PHObject.cpp
                                  PHObject.h
                                  PHUpdateObject.h)

set(PHYSICS_BASE_OBJECTS_WORLD GeometryBits.cpp
                               params.cpp
                               PHWorld.cpp
                               Physics.cpp
                               GeometryBits.h
                               IPHWorld.h
                               params.h
                               PHItemList.h
                               PHWorld.h
                               Physics.h)

set(PHYSICS_BASE_OBJECTS_SPLITEDSHELL PHSplitedShell.cpp
                                      PHSplitedShell.h)

set(PHYSICS_BASE_OBJECTS_BASESHELL PhysicsShell.cpp
                                   IPhysicsShellHolder.h
                                   PhysicsShell.h)

set(PHYSICS_BASE_OBJECTS_SHELL PHShell.cpp
                               PHShellActivate.cpp
                               PHShellNetState.cpp
                               PHShell.h
                               PHShellBuildJoint.h)

set(PHYSICS_BASE_OBJECTS_DISABLING DisablingParams.cpp
                                   PHDisabling.cpp
                                   DisablingParams.h
                                   PHDisabling.h)

set(PHYSICS_BASE_OBJECTS_PHYMOVE_AICHARACTER PHAICharacter.cpp
                                             PHAICharacter.h)

set(PHYSICS_ACTIVATIONBOX IActivationShape.cpp
                          PHActivationShape.cpp
                          IActivationShape.h
                          PHActivationShape.h)

set(PHYSICS_COLLIDERS_TRI tri-colliderknoopc/dSortTriPrimitive.cpp
                          tri-colliderknoopc/dTriBox.cpp
                          tri-colliderknoopc/dTriCallideK.cpp
                          tri-colliderknoopc/dTriCylinder.cpp
                          tri-colliderknoopc/dTriList.cpp
                          tri-colliderknoopc/dTriSphere.cpp
                          tri-colliderknoopc/__aabb_tri.h
                          tri-colliderknoopc/dcTriangle.h
                          tri-colliderknoopc/dcTriListCollider.h
                          tri-colliderknoopc/dSortTriPrimitive.h
                          tri-colliderknoopc/dTriBox.h
                          tri-colliderknoopc/dTriCollideK.h
                          tri-colliderknoopc/dTriColliderCommon.h
                          tri-colliderknoopc/dTriColliderMath.h
                          tri-colliderknoopc/dTriCylinder.h
                          tri-colliderknoopc/dTriList.h
                          tri-colliderknoopc/dTriSphere.h
                          tri-colliderknoopc/dxTriList.h
                          tri-colliderknoopc/TriPrimitiveCollideClassDef.h)

set(PHYSICS_BASE_OBJECTS_PHNET ../xrServerEntities/PHNetState.cpp
                               ../xrServerEntities/PHNetState.h)

set(PHYSICS_BASE PhysicsExternalCommon.cpp
                 DamageSource.h
                 ode_include.h
                 ode_redefine.h
                 PhysicsCommon.h
                 PhysicsExternalCommon.h)

set(PHYSICS_BASE_OBJECTS_SCRIPT physics_scripted.cpp
                                iphysics_scripted.h
                                physics_scripted.h)

set(PHYSICS_BASE_OBJECTS_UTILS_MATH MathUtils.cpp
                                    PHDynamicData.cpp
                                    CalculateTriangle.h
                                    MathUtils.h
                                    MathUtilsOde.h
                                    matrix_utils.h
                                    PHDynamicData.h)

set(PHYSICS_BASE_OBJECTS_JOINT PHJoint.cpp
                               PHJoint.h)

set(PHYSICS_BASE_OBJECTS_BASESHELL_PHYSICSSHELLANIMATOR PhysicsShellAnimator.cpp
                                                        PhysicsShellAnimator.h
                                                        PhysicsShellAnimatorBoneData.h)

set(PHYSICS_DAMAGE_RECEIVER collisiondamagereceiver.cpp
                            icollisiondamagereceiver.h)

set(PHYSICS_BASE_OBJECTS_PHYMOVE_CAPTURE PHCapture.cpp
                                         PHCaptureInit.cpp
                                         IPHCapture.h
                                         PHCapture.h)

set(PHYSICS_BASE_OBJECTS_ELEMENT PHElement.cpp
                                 PHElementNetState.cpp
                                 PHElement.h
                                 PHElementInline.h)

set(PHYSICS_BASE_OBJECTS_STATICSHELL PHStaticGeomShell.cpp
                                     IPHStaticGeomShell.h
                                     PHStaticGeomShell.h)

set(PHYSICS_BASE_OBJECTS_BREAKABLE PHFracture.cpp
                                   PHJointDestroyInfo.cpp
                                   PHShellSplitter.cpp
                                   PHFracture.h
                                   PHJointDestroyInfo.h
                                   PHShellSplitter.h)

set(PHYSICS_BASE_OBJECTS_BODYEFFECTORS PHContactBodyEffector.cpp
                                       PHBaseBodyEffector.h
                                       PHContactBodyEffector.h)

set(PHYSICS_BASE_OBJECTS_PHYMOVE_SIPMPLECHARACTER ElevatorState.cpp
                                                  PHSimpleCharacter.cpp
                                                  ElevatorState.h
                                                  iclimableobject.h
                                                  IElevatorState.h
                                                  PHSimpleCharacter.h
                                                  PHSimpleCharacterInline.h)

set(PHYSICS_BASE_OBJECTS_UTILS_INTERPOLATION PHInterpolation.cpp
                                             PHInterpolation.h)

set(PHYSICS_COLLIDERS_CYL dcylinder/dCylinder.cpp
                          dcylinder/dCylinder.h)

set(PHYSICS_CAMERA_COLLISION ActorCameraCollision.cpp
                             ActorCameraCollision.h)

set(PHYSICS_BASE_OBJECTS PHDefs.h)

set(PHYSICS_BASE_OBJECTS_PHYMOVE_ACTORCARACTER PHActorCharacter.cpp
                                               PHActorCharacter.h
                                               PHActorCharacterInline.h)

set(PHYSICS_BASE_OBJECTS_COLLIDEVALIDATOR PHCollideValidator.cpp
                                          ICollideValidator.h
                                          PHCollideValidator.h)

source_group("physics\\colliders\\RayMotions" FILES ${PHYSICS_COLLIDERS_RAYMOTIONS})
source_group("physics\\Base\\Impact" FILES ${PHYSICS_BASE_IMPACT})
source_group("physics" FILES ${PHYSICS})
source_group("physics\\Base\\Debug" FILES ${PHYSICS_BASE_DEBUG})
source_group("physics\\Base\\Objects\\PhyMove\\BaseCharacter" FILES ${PHYSICS_BASE_OBJECTS_PHYMOVE_BASECHARACTER})
source_group("kernel" FILES ${KERNEL})
source_group("physics\\Base\\Objects\\MoveStorage" FILES ${PHYSICS_BASE_OBJECTS_MOVESTORAGE})
source_group("physics\\Base\\Objects\\Utils\\Storage" FILES ${PHYSICS_BASE_OBJECTS_UTILS_STORAGE})
source_group("physics\\Base\\Objects\\Utils" FILES ${PHYSICS_BASE_OBJECTS_UTILS})
source_group("physics\\Base\\Objects\\PHIsland" FILES ${PHYSICS_BASE_OBJECTS_PHISLAND})
source_group("physics\\Base\\Objects\\Element\\Geom" FILES ${PHYSICS_BASE_OBJECTS_ELEMENT_GEOM})
source_group("physics\\Base\\Objects\\PHObject" FILES ${PHYSICS_BASE_OBJECTS_PHOBJECT})
source_group("physics\\Base\\Objects\\World" FILES ${PHYSICS_BASE_OBJECTS_WORLD})
source_group("physics\\Base\\Objects\\SplitedShell" FILES ${PHYSICS_BASE_OBJECTS_SPLITEDSHELL})
source_group("physics\\Base\\Objects\\BaseShell" FILES ${PHYSICS_BASE_OBJECTS_BASESHELL})
source_group("physics\\Base\\Objects\\Shell" FILES ${PHYSICS_BASE_OBJECTS_SHELL})
source_group("physics\\Base\\Objects\\Disabling" FILES ${PHYSICS_BASE_OBJECTS_DISABLING})
source_group("physics\\Base\\Objects\\PhyMove\\AICharacter" FILES ${PHYSICS_BASE_OBJECTS_PHYMOVE_AICHARACTER})
source_group("physics\\ActivationBox" FILES ${PHYSICS_ACTIVATIONBOX})
source_group("physics\\colliders\\tri" FILES ${PHYSICS_COLLIDERS_TRI})
source_group("physics\\Base\\Objects\\PHNet" FILES ${PHYSICS_BASE_OBJECTS_PHNET})
source_group("physics\\Base" FILES ${PHYSICS_BASE})
source_group("physics\\Base\\Objects\\script" FILES ${PHYSICS_BASE_OBJECTS_SCRIPT})
source_group("physics\\Base\\Objects\\Utils\\Math" FILES ${PHYSICS_BASE_OBJECTS_UTILS_MATH})
source_group("physics\\Base\\Objects\\Joint" FILES ${PHYSICS_BASE_OBJECTS_JOINT})
source_group("physics\\Base\\Objects\\BaseShell\\PhysicsShellAnimator" FILES ${PHYSICS_BASE_OBJECTS_BASESHELL_PHYSICSSHELLANIMATOR})
source_group("physics\\damage_receiver" FILES ${PHYSICS_DAMAGE_RECEIVER})
source_group("physics\\Base\\Objects\\PhyMove\\Capture" FILES ${PHYSICS_BASE_OBJECTS_PHYMOVE_CAPTURE})
source_group("physics\\Base\\Objects\\Element" FILES ${PHYSICS_BASE_OBJECTS_ELEMENT})
source_group("physics\\Base\\Objects\\StaticShell" FILES ${PHYSICS_BASE_OBJECTS_STATICSHELL})
source_group("physics\\Base\\Objects\\Breakable" FILES ${PHYSICS_BASE_OBJECTS_BREAKABLE})
source_group("physics\\Base\\Objects\\BodyEffectors" FILES ${PHYSICS_BASE_OBJECTS_BODYEFFECTORS})
source_group("physics\\Base\\Objects\\PhyMove\\SipmpleCharacter" FILES ${PHYSICS_BASE_OBJECTS_PHYMOVE_SIPMPLECHARACTER})
source_group("physics\\Base\\Objects\\Utils\\Interpolation" FILES ${PHYSICS_BASE_OBJECTS_UTILS_INTERPOLATION})
source_group("physics\\colliders\\cyl" FILES ${PHYSICS_COLLIDERS_CYL})
source_group("physics\\camera_collision" FILES ${PHYSICS_CAMERA_COLLISION})
source_group("physics\\Base\\Objects" FILES ${PHYSICS_BASE_OBJECTS})
source_group("physics\\Base\\Objects\\PhyMove\\ActorCaracter" FILES ${PHYSICS_BASE_OBJECTS_PHYMOVE_ACTORCARACTER})
source_group("physics\\Base\\Objects\\CollideValidator" FILES ${PHYSICS_BASE_OBJECTS_COLLIDEVALIDATOR})

add_definitions(-DXRPHYSICS_EXPORTS -DMSVC -DdSINGLE -D_SECURE_SCL=0)

add_compile_options(/fp:fast /GR "/Yustdafx.h")
set_source_files_properties(stdafx.cpp PROPERTIES COMPILE_FLAGS /Yc)

add_library(xrPhysics SHARED ${PHYSICS_BASE_OBJECTS_BASESHELL_PHYSICSSHELLANIMATOR}
                             ${PHYSICS_BASE_OBJECTS_PHISLAND}
                             ${PHYSICS_COLLIDERS_TRI}
                             ${PHYSICS_BASE_OBJECTS_PHYMOVE_BASECHARACTER}
                             ${PHYSICS_BASE_OBJECTS_STATICSHELL}
                             ${PHYSICS_BASE_OBJECTS_PHYMOVE_SIPMPLECHARACTER}
                             ${PHYSICS_BASE}
                             ${PHYSICS_BASE_IMPACT}
                             ${PHYSICS_BASE_OBJECTS_SCRIPT}
                             ${PHYSICS_BASE_OBJECTS_BODYEFFECTORS}
                             ${PHYSICS_BASE_OBJECTS_PHYMOVE_AICHARACTER}
                             ${PHYSICS_BASE_OBJECTS_BREAKABLE}
                             ${PHYSICS_BASE_OBJECTS_COLLIDEVALIDATOR}
                             ${PHYSICS_DAMAGE_RECEIVER}
                             ${PHYSICS_ACTIVATIONBOX}
                             ${PHYSICS_BASE_OBJECTS_UTILS_MATH}
                             ${PHYSICS_BASE_DEBUG}
                             ${PHYSICS_BASE_OBJECTS_ELEMENT_GEOM}
                             ${PHYSICS_BASE_OBJECTS_UTILS_STORAGE}
                             ${PHYSICS_COLLIDERS_CYL}
                             ${PHYSICS_BASE_OBJECTS_WORLD}
                             ${PHYSICS_BASE_OBJECTS_PHYMOVE_CAPTURE}
                             ${PHYSICS_BASE_OBJECTS_MOVESTORAGE}
                             ${PHYSICS_BASE_OBJECTS_UTILS}
                             ${PHYSICS_COLLIDERS_RAYMOTIONS}
                             ${PHYSICS}
                             ${PHYSICS_BASE_OBJECTS_BASESHELL}
                             ${KERNEL}
                             ${PHYSICS_BASE_OBJECTS}
                             ${PHYSICS_BASE_OBJECTS_DISABLING}
                             ${PHYSICS_BASE_OBJECTS_PHYMOVE_ACTORCARACTER}
                             ${PHYSICS_BASE_OBJECTS_JOINT}
                             ${PHYSICS_CAMERA_COLLISION}
                             ${PHYSICS_BASE_OBJECTS_SHELL}
                             ${PHYSICS_BASE_OBJECTS_SPLITEDSHELL}
                             ${PHYSICS_BASE_OBJECTS_ELEMENT}
                             ${PHYSICS_BASE_OBJECTS_UTILS_INTERPOLATION}
                             ${PHYSICS_BASE_OBJECTS_PHOBJECT}
                             ${PHYSICS_BASE_OBJECTS_PHNET})
target_include_directories(xrPhysics PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(xrPhysics xrCore xrAPI xrSound xrCDB ode)