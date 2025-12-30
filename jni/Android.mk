LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := main
LOCAL_SRC_FILES := ../src/main.c
LOCAL_LDLIBS := -llog -lGLESv2 -lSDL2
LOCAL_SHARED_LIBRARIES := SDL2

include $(BUILD_SHARED_LIBRARY)
$(call import-module,SDL2)
