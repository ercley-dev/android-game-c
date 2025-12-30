#include "touch_screen.h"
#include "SDL_log.h"


int touch() {
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_QUIT:
               break;
            case SDL_FINGERDOWN:
               touchX = e.tfinger.x;
               touchY = e.tfinger.y;
               SDL_Log("Finger down at normalized x: %f, y: %f", touchX, touchY);
               break;
            case SDL_FINGERMOTION:
               touchX = e.tfinger.x;
               touchY = e.tfinger.y;
               SDL_Log("Finger motion at normalized x: %f, y: %f", touchX, touchY);
               break;
            case SDL_FINGERUP:
               touchX = e.tfinger.x;
               touchY = e.tfinger.y;
               SDL_Log("Finger up at normalized x: %f, y: %f", touchX, touchY);
               break;
            default:
               break;
        }
    }
}
