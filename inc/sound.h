#ifndef _H_SOUND
#define _H_SOUND

#define MUSIC_FADE_TIME		3000

enum SfxSpeech
{
	SS_B2B = 1,
	SS_TSPIN = 2,
	SS_MINITSPIN = 4,
	SS_SINGLE = 8,
	SS_DOUBLE = 16,
	SS_TRIPLE = 32,
	SS_TETRIS = 64
};

enum SfxEffect
{
	SE_HIT,
	SE_CLEAR,
	SE_CLICK
};

extern int initmusvol;
extern Mix_Music *music;
extern char music_name[];
extern Mix_Chunk *sfx_hit;
extern Mix_Chunk *sfx_clr;
extern Mix_Chunk *sfx_click;
extern Mix_Chunk *sfx_b2b;
extern Mix_Chunk *sfx_single;
extern Mix_Chunk *sfx_double;
extern Mix_Chunk *sfx_triple;
extern Mix_Chunk *sfx_tetris;
extern Mix_Chunk *sfx_tspin;
extern Mix_Chunk *sfx_minitspin;

void initSound(void);
void deinitSound(void);
void trackFinished(void);
void playMusic(void);
void stopMusic(void);
void letMusicFinish(void);
void playNextTrack(void);
void playPrevTrack(void);
void playSpeech(int ssflags);
void playEffect(enum SfxEffect se);
void playcombo(int combo);

#endif
