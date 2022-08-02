// Copyright 2022 Karl Buchka (@basketofkittens)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define PS2_CLOCK_PIN TEENSY_PIN36
#define PS2_DATA_PIN  TEENSY_PIN35


//#define PS2_MOUSE_INVERT_X
//#define PS2_MOUSE_INVERT_Y