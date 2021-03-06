/* Copyright 2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "light.h"

const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |      G location
 *   |  |      |      B location
 *   |  |      |      | */
    {0, C1_3,  C2_3,  C3_3},
    {0, C1_4,  C2_4,  C3_4},
    {0, C1_5,  C2_5,  C3_5},
    {0, C1_11, C2_11, C3_11},
    {0, C1_12, C2_12, C3_12},
    {0, C1_13, C2_13, C3_13},
    {1, C1_3,  C2_3,  C3_3},
    {1, C1_4,  C2_4,  C3_4},
    {1, C1_5,  C2_5,  C3_5},
    {1, C1_11, C2_11, C3_11},
    {1, C1_12, C2_12, C3_12},
    {1, C1_13, C2_13, C3_13},

    {0, C1_6,  C2_6,  C3_6},
    {0, C1_7,  C2_7,  C3_7},
    {0, C1_8,  C2_8,  C3_8},
    {0, C1_14, C2_14, C3_14},
    {0, C1_15, C2_15, C3_15},
    {0, C1_16, C2_16, C3_16},
    {1, C1_6,  C2_6,  C3_6},
    {1, C1_7,  C2_7,  C3_7},
    {1, C1_8,  C2_8,  C3_8},
    {1, C1_14, C2_14, C3_14},
    {1, C1_15, C2_15, C3_15},
    {1, C1_16, C2_16, C3_16},

    {0, C9_1,  C8_1,  C7_1},
    {0, C9_2,  C8_2,  C7_2},
    {0, C9_3,  C8_3,  C7_3},
    {0, C9_9,  C8_9,  C7_9},
    {0, C9_10, C8_10, C7_10},
    {0, C9_11, C8_11, C7_11},
    {1, C9_1,  C8_1,  C7_1},
    {1, C9_2,  C8_2,  C7_2},
    {1, C9_3,  C8_3,  C7_3},
    {1, C9_9,  C8_9,  C7_9},
    {1, C9_10, C8_10, C7_10},
    {1, C9_11, C8_11, C7_11},

    {0, C9_4,  C8_4,  C7_4},
    {0, C9_5,  C8_5,  C7_5},
    {0, C9_6,  C8_6,  C7_6},
    {0, C9_12, C8_12, C7_12},
    {0, C9_13, C8_13, C7_13},
    {0, C9_14, C8_14, C7_14},
    {0, C9_15, C8_15, C6_14}, // middle 2u switch
    {1, C9_4,  C8_4,  C7_4},
    {1, C9_5,  C8_5,  C7_5},
    {1, C9_6,  C8_6,  C7_6},
    {1, C9_12, C8_12, C7_12},
    {1, C9_13, C8_13, C7_13},
    {1, C9_14, C8_14, C7_14}
};

const rgb_led g_rgb_leds[DRIVER_LED_TOTAL] = {

    /*{row | col << 4}
      |             {x=0..224, y=0..64}
      |              |                 modifier
      |              |                 | */
    {{0|(0<<4)},   {20.36*0, 21.33*0}, 1},
    {{0|(1<<4)},   {20.36*1, 21.33*0}, 0},
    {{0|(2<<4)},   {20.36*2, 21.33*0}, 0},
    {{0|(3<<4)},   {20.36*3, 21.33*0}, 0},
    {{0|(4<<4)},   {20.36*4, 21.33*0}, 0},
    {{0|(5<<4)},   {20.36*5, 21.33*0}, 0},
    {{0|(6<<4)},   {20.36*6, 21.33*0}, 0},
    {{0|(7<<4)},   {20.36*7, 21.33*0}, 0},
    {{0|(8<<4)},   {20.36*8, 21.33*0}, 0},
    {{0|(9<<4)},   {20.36*9, 21.33*0}, 0},
    {{0|(10<<4)},  {20.36*10,21.33*0}, 0},
    {{0|(11<<4)},  {20.36*11,21.33*0}, 1},

    {{1|(0<<4)},   {20.36*0, 21.33*1}, 1},
    {{1|(1<<4)},   {20.36*1, 21.33*1}, 0},
    {{1|(2<<4)},   {20.36*2, 21.33*1}, 0},
    {{1|(3<<4)},   {20.36*3, 21.33*1}, 0},
    {{1|(4<<4)},   {20.36*4, 21.33*1}, 0},
    {{1|(5<<4)},   {20.36*5, 21.33*1}, 0},
    {{1|(6<<4)},   {20.36*6, 21.33*1}, 0},
    {{1|(7<<4)},   {20.36*7, 21.33*1}, 0},
    {{1|(8<<4)},   {20.36*8, 21.33*1}, 0},
    {{1|(9<<4)},   {20.36*9, 21.33*1}, 0},
    {{1|(10<<4)},  {20.36*10,21.33*1}, 0},
    {{1|(11<<4)},  {20.36*11,21.33*1}, 1},

    {{2|(0<<4)},   {20.36*0, 21.33*2}, 1},
    {{2|(1<<4)},   {20.36*1, 21.33*2}, 0},
    {{2|(2<<4)},   {20.36*2, 21.33*2}, 0},
    {{2|(3<<4)},   {20.36*3, 21.33*2}, 0},
    {{2|(4<<4)},   {20.36*4, 21.33*2}, 0},
    {{2|(5<<4)},   {20.36*5, 21.33*2}, 0},
    {{2|(6<<4)},   {20.36*6, 21.33*2}, 0},
    {{2|(7<<4)},   {20.36*7, 21.33*2}, 0},
    {{2|(8<<4)},   {20.36*8, 21.33*2}, 0},
    {{2|(9<<4)},   {20.36*9, 21.33*2}, 0},
    {{2|(10<<4)},  {20.36*10,21.33*2}, 0},
    {{2|(11<<4)},  {20.36*11,21.33*2}, 1},

    {{3|(0<<4)},   {20.36*0, 21.33*3}, 1},
    {{3|(1<<4)},   {20.36*1, 21.33*3}, 1},
    {{3|(2<<4)},   {20.36*2, 21.33*3}, 1},
    {{3|(3<<4)},   {20.36*3, 21.33*3}, 1},
    {{3|(4<<4)},   {20.36*4, 21.33*3}, 1},
    {{3|(5<<4)},   {20.36*5, 21.33*3}, 0},
    {{3|(5<<4)},   {20.36*5.5,21.33*3}, 0},
    {{3|(6<<4)},   {20.36*6, 21.33*3}, 0},
    {{3|(7<<4)},   {20.36*7, 21.33*3}, 1},
    {{3|(8<<4)},   {20.36*8, 21.33*3}, 1},
    {{3|(9<<4)},   {20.36*9, 21.33*3}, 1},
    {{3|(10<<4)},  {20.36*10,21.33*3}, 1},
    {{3|(11<<4)},  {20.36*11,21.33*3}, 1}
};

void matrix_init_kb(void) {

    // Turn status LED on
    DDRD |= (1<<6);
    PORTD |= (1<<6);

    matrix_init_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record)
{
    return process_record_user(keycode, record);
}

void matrix_scan_kb(void)
{
    matrix_scan_user();
}

void suspend_power_down_kb(void)
{
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_kb(void)
{
    rgb_matrix_set_suspend_state(false);
}

