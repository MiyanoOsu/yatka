#ifndef _H_SKIN
#define _H_SKIN

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#define FONT_NUM			(8)
#define ORIENTATION_NUM		(15)

enum FigureId
{
	FIGID_I,
	FIGID_O,
	FIGID_T,
	FIGID_S,
	FIGID_Z,
	FIGID_J,
	FIGID_L,
	FIGID_GRAY,
	FIGID_END
};

enum BrickStyle
{
	BS_SIMPLE,
	BS_ORIENTATION_BASED,
	BS_FIGUREWISE,
	BS_END
};

enum BgAnimationMode
{
	BAM_REPLACE,
	BAM_BLEND,
	BAM_END
};

enum HoldMode
{
	HM_OFF,
	HM_EXCHANGE,
	HM_PRESERVE
};

struct Skin
{
	SDL_Surface *screen;
	enum BgAnimationMode bgmode;
	enum HoldMode holdmode;
	SDL_Surface *bgsheet;
	SDL_Surface *bg;
	SDL_Rect bgrect;
	SDL_Surface *fg;
	SDL_Surface *bricksprite[FIGID_END];
	Uint32 colors[FIGID_GRAY];
	Uint32 color_alphas[FIGID_GRAY];
	enum BrickStyle brickstyle;
	enum FigureId debriscolor;
	char *script;
	char *path;
	int boardx;
	int boardy;
	int bricksize;
	int brickyoffset;
	int ghost;
	SDL_Surface *brick_shadow;
	int shadowx;
	int shadowy;
	TTF_Font *fonts[FONT_NUM];
};

void skin_initSkin(struct Skin *skin);
void skin_destroySkin(struct Skin *skin);
void skin_loadSkin(struct Skin *skin, const char *path);
void skin_updateScreen(struct Skin *skin, SDL_Surface *screen);
void skin_updateBackground(struct Skin *skin);

#endif
