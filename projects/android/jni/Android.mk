LOCAL_PATH := $(call my-dir)
ENGINE_PATH := /../../../src/engine/

include $(CLEAR_VARS)

LOCAL_MODULE    := Game2jni
LOCAL_SRC_FILES := Game2.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)Renderer/Renderer.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)Renderer/Shader.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)Renderer/Matrix4f.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)Renderer/Camera.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)Renderer/BaseRenderable.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)Renderer/Grid.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)GameEngine.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)GlobalData.cpp
LOCAL_SRC_FILES += $(ENGINE_PATH)Player.cpp
LOCAL_LDLIBS    := -llog -lGLESv2

include $(BUILD_SHARED_LIBRARY)
