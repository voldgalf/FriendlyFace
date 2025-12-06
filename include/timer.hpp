//
// Created by brick on 11/26/2025.
//

#ifndef FFACE_TIMERS_H
#define FFACE_TIMERS_H

#include <SDL3/SDL.h>
#include <stdlib.h>

typedef struct {
    int goalFrames, currentFrame;
} FFACE_Timer;


/**
 * Function: FFACE_CreateTimer
 *
 * Create & returns FFACE_Timer struct.
 *
 * Parameters:
 * goalFrames - The amount of frames before the timer completes
 *
 * Returns:
 * A pointer to the created FFACE_Timer
 */
FFACE_Timer* FFACE_CreateTimer(int goalFrames);

/**
 * Function: FFACE_DestroyTimer
 *
 * Destroys FFACE_Timer
 *
 * Parameters:
 * timer - The timer wanted to destroy
 *
 * Returns:
 * true
 */
bool FFACE_DestroyTimer(FFACE_Timer* timer);

/**
 * Function: FFACE_TickTimer
 *
 * Increases
 * --- Code
 * FFACE_Timer->currentFrame
 * ---
 * by 1
 *
 * Parameters:
 * timer - The given timer to increase currentFrame by 1
 *
 * Returns:
 * true
 */
bool FFACE_TickTimer(FFACE_Timer* timer);

/**
 * Function: FFACE_CheckTimer
 *
 * Check if given timer's currentFrame is greater then goalFrames
 *
 * Parameters:
 * timer - The given timer to check if complete
 *
 * Returns:
 * true - Timer is complete
 * false - Timer is incomplete
 */
bool FFACE_CheckTimer(FFACE_Timer* timer);

/**
 * Function: FFACE_ResetTimer
 *
 * Resets given timer (set currentFrame to 0)
 *
 * Parameters:
 * timer - The given timer to reset
 *
 * Returns:
 * true
 */
bool FFACE_ResetTimer(FFACE_Timer* timer);

#endif //FFACE_TIMERS_H
