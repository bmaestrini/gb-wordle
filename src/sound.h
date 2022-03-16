#ifndef _SOUND_H
#define _SOUND_H

#include <gbdk/platform.h>

#define CH1_SIZE 5 // 5 bytes for channel 1

typedef enum {
    CHANNEL_1,
    CHANNEL_2,
    CHANNEL_3,
    CHANNEL_4,
    CHANNEL_5
} SOUND_CHANNEL;

void init_sound(void);
void SoundFx(uint8_t sfx_idx);

#endif
