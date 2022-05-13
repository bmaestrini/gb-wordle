// common.c

#include <gbdk/platform.h>
#include <stdint.h>
#include <stdbool.h>

#include "stats.h"
#include "common.h"
#include "input.h"
#include "gfx_common.h"
#include "sfx_common.h"

#include "gameplay.h"
#include "settings.h"
#include "window.h"

#include "settings_menu.h"

#include <lang_text.h>

#define MENU_MOVE_UP   -1
#define MENU_MOVE_NONE  0
#define MENU_MOVE_DOWN  1


const uint8_t menu_cursor_y_ids[] = {
    MENU_Y_EXIT,
    MENU_Y_HARD_MODE,
    MENU_Y_AUTO_FILL,
    MENU_Y_SOUND_FX,
    MENU_Y_SHOW_STATS,
    MENU_Y_FORFEIT_ROUND,
    MENU_Y_RESET_STATS,
};

// Function pointer table to match each menu item entry
const void (*menu_funcs[])(void) = {
    NULL, // Exit menu, no function to call
    &hardmode_handle_change,
    &autofill_handle_change,
    &soundfx_handle_change,
    &stats_show,
    &ask_forfeit_round,
    &ask_stats_reset,
};

#define MENU_ROW_HEIGHT_PX         8u
#define MENU_CURSOR_X             (8u + DEVICE_SPRITE_PX_OFFSET_X)
#define MENU_CURSOR_Y_ADJUST       12u // compensate for
#define MENU_CURSOR_Y_BASELINE    ((1 * (MENU_ROW_HEIGHT_PX)) + MENU_CURSOR_Y_ADJUST)  // To factor in window border
#define MENU_CURSOR_Y_SPR2_OFFSET  7u   // y + 7 instead of +8 to make a pointy arrow since it's using y flipped sprite from top of cursor
#define MENU_CURSOR_Y_AT_ROW(row) (WY_REG + (menu_cursor_y_ids[row] * MENU_ROW_HEIGHT_PX) + MENU_CURSOR_Y_BASELINE) // + (MENU_CURSOR_Y_BASELINE - DEVICE_SPRITE_PX_OFFSET_Y))


static uint8_t menu_idx;

// Hide the menu cursor
inline void menu_hide_cursor(void) {

    hide_sprite(SP_ID_CURSOR_MENU_START);
    hide_sprite(SP_ID_CURSOR_MENU_START + 1u);
}


// Move the cursor to highlight the current row
// move_dir should only every be: -1, 0, +1
void menu_update_cursor(int8_t move_dir) {

    if (move_dir) {

        menu_idx += move_dir;

        // Handle wraparound
        // Top -> Bottom is via unsigned overflow
        // Bottom -> Top  is via max menu entry count
        if (menu_idx == 0xFFu)
            menu_idx = ARRAY_LEN(menu_cursor_y_ids) - 1;
        else if (menu_idx > (ARRAY_LEN(menu_cursor_y_ids) - 1))
            menu_idx = 0u;

        play_sfx(SFX_CURSOR_MOVE);
    }

    uint8_t y = MENU_CURSOR_Y_AT_ROW(menu_idx);
    move_sprite(SP_ID_CURSOR_MENU_START     , MENU_CURSOR_X, y);
    move_sprite(SP_ID_CURSOR_MENU_START + 1u, MENU_CURSOR_X, y + MENU_CURSOR_Y_SPR2_OFFSET);
}



const uint8_t menu_str_template[] = __OPTIONS_MENU_STR;
uint8_t menu_str[sizeof(menu_str_template)];

// Display menu in a popup window with a cursor
void settings_menu_show(void) {

    // Reset display template
    // memcpy(menu_str, menu_str_template, sizeof(menu_str_template));
    // About 1/2 the size of including memcpy()
    uint8_t * p_dest = menu_str;
    const uint8_t * p_src = menu_str_template;
    while (p_src != menu_str_template + sizeof(menu_str_template)) {
        *p_dest++ = *p_src++;
    }

    str_bool_checkbox_at_X(menu_str, game_settings.opt_hard_mode_enabled);
    str_bool_checkbox_at_X(menu_str, game_settings.opt_autofill_enabled);
    str_bool_checkbox_at_X(menu_str, game_settings.opt_sound_fx_enabled);
    // str_bool_checkbox_at_X(menu_str, game_settings.opt_tile_flip_enabled);
    // str_bool_checkbox_at_X(menu_str, game_settings.opt_lock_matched);

    WIN_DIALOG_SET_FUNC_RUN(&menu_run);
    win_dialog_show_message(OPTIONS_MENU_DIALOG_WIN_Y, menu_str, NULL);


    // SDCC BUG?
    // Function pointer var needs to be static local or global
    // Otherwise SDCC generates "jp NZ, (hl)"
    // And gets the error: ?ASlink-Warning-Undefined Global 'hl' referenced by module 'settings_menu'
    //
    // if (*(menu_funcs[menu_idx]))
    //     (*(menu_funcs[menu_idx]))();
    //
    // void (*p_func)(void) = menu_funcs[menu_idx];
    //
    // Call selected menu item handler
    static void (*p_func)(void) = NULL;
    p_func = menu_funcs[menu_idx];

    if (*p_func)
        (*p_func)();
}



// Small loop that runs from within the popup menu
// which moves the cursor around and accepts selections
void menu_run(void) {

    // Default starting cursor pos / doubles as menu global return value
    menu_idx = MENU_DEFAULT_EXIT;

    // Show the cursor
    menu_update_cursor(MENU_MOVE_NONE);

    while (1) {

        waitpadticked_lowcpu(J_ANY_KEY);
        switch (KEYS_GET_TICKED()) {

            case J_UP: menu_update_cursor(MENU_MOVE_UP);
                       break;

            case J_DOWN: menu_update_cursor(MENU_MOVE_DOWN);
                         break;

                      // TODO: B to exit is nice, but will people get confused?
                      // Use B to exit the menu regardless of where the cursor is
            case J_B: menu_idx = MENU_DEFAULT_EXIT;
                     // Fall through to exit below

            case J_START: // Fall through to exit below
            case J_A:   // Hide the cursor here so that it doesn't show
                        // while the popup window is retracting
                        menu_hide_cursor();
                        return;
                        break; // redundant
        }
    }
}



