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

#define PS2_CLOCK_PIN   LINE_PIN22  // Was 32
#define PS2_DATA_PIN    LINE_PIN23  // Was 31

#define PS2_MOUSE_INVERT_X
#define PS2_MOUSE_INVERT_Y

#define LED_CAPS_LOCK_PIN         LINE_PIN30
//#define LED_CAPS_LOCK_PIN       TBD
//#define LED_SCROLL_LOCK_PIN     TBD