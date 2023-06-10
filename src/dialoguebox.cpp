#include "dialoguebox.h"
#include "colours.h"
#include "filepath.h"
#include "global.h"

#include <raylib.h>

PictureInfo picture;


const float MAX_CHARACTER_COUNT = (WIDTH / 2.0) / ((WIDTH / 50.0) + (WIDTH / 400.0));

Font alagard;

// Load main font
void loadALAGARD()
{
    alagard = LoadFontEx(
        PATH_ALAGARD,
        32,
        0,
        250
    );
}

// Draw Dialogue Box
void DrawDialogue()
{

    // Dialogue Outline
    DrawRectangle(
         OT_POS_X,
         OT_POS_Y,
         OT_SIZ_X,
         OT_SIZ_Y,
        PLEARTH_ONE
    );

    // Dialogue Container Rect
    DrawRectangle(
         DX_POS_X,
         DX_POS_Y,
         DX_SIZ_X,
         DX_SIZ_Y,
        PLEARTH_TWO
    );

    // Dialogue Picture
    DrawTexture(
        picture.character,
         PX_POS_X,
         PX_POS_Y,
        WHITE
    );
}

// Set Picture for Character
void SetDialoguePicture(const char *PATH)
{   
    Image character = LoadImage(PATH);
    picture.character = LoadTextureFromImage(character);
    UnloadImage(character);
}
