LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

# Busca os headers da SDL2
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../SDL2/include

LOCAL_SRC_FILES := ../src/main.c \
                   ../src/include/touch_screen.c

# Forma correta de linkar a SDL2 no Android
LOCAL_SHARED_LIBRARIES := SDL2

include $(BUILD_SHARED_LIBRARY)

# Importa o módulo da SDL2
$(call import-module,SDL2)

