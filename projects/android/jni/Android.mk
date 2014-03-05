LOCAL_PATH := $(call my-dir)
ENGINE_PATH := /../../../src/engine/

include $(CLEAR_VARS)

LOCAL_MODULE    := Game2jni
LOCAL_SRC_FILES += $(ENGINE_PATH)Common/Tests.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)Common/Matrix4f.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)Common/ThreadLock.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)Common/Vector2f.cpp

LOCAL_SRC_FILES += $(ENGINE_PATH)ECS/BaseSystem.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)ECS/Entity.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)ECS/GameLogic.cpp

LOCAL_SRC_FILES += $(ENGINE_PATH)GamePlay/EntityFabric.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)GamePlay/Game2Logic.cpp

LOCAL_SRC_FILES += $(ENGINE_PATH)GamePlay/Components/ConnectorComponent.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)GamePlay/Components/TargetComponent.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)GamePlay/Components/EnergyStorageComponent.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)GamePlay/Components/NodeComponent.cpp

LOCAL_SRC_FILES += $(ENGINE_PATH)GamePlay/Systems/CollisionSystem.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)GamePlay/Systems/MoveSystem.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)GamePlay/Systems/RenderSystem.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)GamePlay/Systems/TargetEnergySystem.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)GamePlay/Systems/EnergyBalanceSystem.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)GamePlay/Systems/EnergyCreatorSystem.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)GamePlay/Systems/AISystem.cpp

LOCAL_SRC_FILES += $(ENGINE_PATH)Renderer/BaseRenderable.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)Renderer/Camera.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)Renderer/Grid.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)Renderer/RectRenderable.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)Renderer/Renderer.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)Renderer/Shader.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)Renderer/LineRenderable.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)Renderer/TowerRenderable.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)Renderer/RingRenderable.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)Renderer/CircleRenderable.cpp

LOCAL_SRC_FILES += $(ENGINE_PATH)Timer.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)Cursor.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)InputProcessor.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)GameEngine.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)GlobalData.cpp

LOCAL_SRC_FILES := Game2.cpp
LOCAL_LDLIBS    := -llog -lGLESv2

include $(BUILD_SHARED_LIBRARY)
