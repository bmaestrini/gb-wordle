// audio_common.h

#include "sound.h"

#define CH1_IDX(N) (N * CH1_SIZE)

#define SOUND_LEVEL_UP           CH1_IDX(0)
#define SOUND_GAME_OVER          CH1_IDX(1)
#define SOUND_SQUEEK             CH1_IDX(2)
#define SOUND_PIECE_ROTATE       CH1_IDX(3)
#define SOUND_PIECE_MOVE         CH1_IDX(4)
#define SOUND_TILE_CLEAR_NORMAL  CH1_IDX(5)


#define PLAY_SOUND_LEVEL_UP           (SoundFx(SOUND_LEVEL_UP))
#define PLAY_SOUND_GAME_OVER          (SoundFx(SOUND_GAME_OVER))
#define PLAY_SOUND_SQUEEK             (SoundFx(SOUND_SQUEEK))
#define PLAY_SOUND_PIECE_ROTATE       (SoundFx(SOUND_PIECE_ROTATE))
#define PLAY_SOUND_PIECE_MOVE         (SoundFx(SOUND_PIECE_MOVE))
#define PLAY_SOUND_TILE_CLEAR_NORMAL  (SoundFx(SOUND_TILE_CLEAR_NORMAL))

extern uint8_t ch1_sfx[];

