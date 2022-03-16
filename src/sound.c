// Some of this code is imported from ZGB

#include <stdarg.h>

#include "sound.h"


const uint8_t FX_REG_SIZES[] = {5, 4, 5, 4, 3};
const uint16_t FX_ADDRESS[] = {0xFF10, 0xFF16, 0xFF1A, 0xFF20, 0xFF24};


const uint8_t ch1_sfx[] = {
    0x76, 0x86, 0xF3, 0xE3, 0x86,  // PLAY_SOUND_LEVEL_UP
    0x7B, 0x80, 0xF5, 0xF2, 0x85,  // PLAY_SOUND_GAME_OVER
    0x15, 0x80, 0x57, 0x02, 0x86,  // PLAY_SOUND_SQUEEK
    0x24, 0x80, 0xF4, 0x94, 0x86,  // PLAY_SOUND_PIECE_ROTATE
    0x74, 0x80, 0xF2, 0xA6, 0x86,  // PLAY_SOUND_PIECE_MOVE
    0x76, 0xC3, 0xF3, 0x40, 0x87,  // PLAY_SOUND_TILE_CLEAR_NORMAL
};


void init_sound(void) {
    NR52_REG = 0x80; // Enables sound, always set this first
    NR51_REG = 0xFF; // Enables all channels (left and right)
    NR50_REG = 0x77; // Max volume
}

void SoundFx(uint8_t sfx_idx) {
    uint8_t i;
    uint8_t* reg = (uint8_t*)0xFF10;

    for(i = CH1_SIZE; i != 0; i--, reg++) {
        *reg = ch1_sfx[sfx_idx++];
    }
}
