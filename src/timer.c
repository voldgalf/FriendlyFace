//
// Created by brick on 11/26/2025.
//

#include "../include/timer.h"

FFACE_Timer* FFACE_CreateTimer(int goalFrames) {
    FFACE_Timer* newTimer = malloc(sizeof (FFACE_Timer));
    newTimer->currentFrame = 0;
    newTimer->goalFrames = goalFrames;
    return newTimer;
}

bool FFACE_DestroyTimer(FFACE_Timer* timer) {

    free(timer);

    return true;
}

bool FFACE_TickTimer(FFACE_Timer* timer) {
    timer->currentFrame +=1;
    return true;
}

bool FFACE_CheckTimer(FFACE_Timer* timer) {
    if(timer->currentFrame >= timer->goalFrames) {
        return true;
    }
    return false;
}

bool FFACE_ResetTimer(FFACE_Timer* timer) {
    timer->currentFrame = 0;
    return true;
}