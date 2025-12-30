#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include "SDL.h"

typedef enum {
    DISPOSITIVO_DESKTOP,
    DISPOSITIVO_MOBILE
} Dispositivo;

typedef struct {
    const char *operacional;
    const char *arquitetura;
    Dispositivo tipo;
} infoSistema;

infoSistema detectar() {
    infoSistema info;
    info.operacional = SDL_GetPlatform();

    // Dispositivo
    #if defined(__ANDROID__) || defined(__IPHONES__)
       info.tipo = DISPOSITIVO_MOBILE;
    #else
       info.tipo = DISPOSITIVO_DESKTOP;
    #endif

    // Arquitetura
    #if defined(__aarch64__) || defined(_M_ARM64)
       info.arquitetura = "ARM 64-bits (v8)";
    #elif defined(__arm__) || defined(_M_ARM)
       info.arquitetura = "ARM 32-bits (v7)";
    #elif defined(__x86_64__) || defined(_M_X64)
       info.arquitetura = "x86_64 (Intel/AMD 64-bits)";
    #elif defined(__i386__) || defined(_M_IX86)
       info.arquitetura = "x86 (Intel 32-bits)";
    #else
       info.arquitetura = "Unknown";
    #endif

    return info;
}
#endif
