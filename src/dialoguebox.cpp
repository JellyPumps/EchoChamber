#include "dialoguebox.h"
#include "colours.h"
#include "global.h"

#include <raylib.h>

PictureInfo picture;

// Dialogue Properties
const float DX_POS_X = 7.0 / 40.0;
const float DX_POS_Y = 3.0 / 4.0;
const float DX_SIZ_X = 1.0 / 2.0;
const float DX_SIZ_Y = 1.0 / 6.0;

const float PX_POS_X = 1.0 / 40.0;
const float PX_POS_Y = 3.0 / 4.0;
const float PX_SIZ_X = 1.0 / 8.0;
const float PX_SIZ_Y = 1.0 / 6.0;

const float OT_POS_X = 1.0 / 80.0;
const float OT_POS_Y = 11.0 / 15.0;
const float OT_SIZ_X = 27.0 / 40.0;
const float OT_SIZ_Y = 1.0 / 5.0;

void DrawDialogue()
{

    // Dialogue Outline
    DrawRectangle(
        RESOLUTION[0] * OT_POS_X,
        RESOLUTION[1] * OT_POS_Y,
        RESOLUTION[0] * OT_SIZ_X,
        RESOLUTION[1] * OT_SIZ_Y,
        PLEARTH_ONE
    );

    // Dialogue Container Rect
    DrawRectangle(
        RESOLUTION[0] * DX_POS_X,
        RESOLUTION[1] * DX_POS_Y,
        RESOLUTION[0] * DX_SIZ_X,
        RESOLUTION[1] * DX_SIZ_Y,
        PLEARTH_TWO
    );

    // Dialogue Picture
    DrawTexture(
        picture.character,
        RESOLUTION[0] * PX_POS_X,
        RESOLUTION[1] * PX_POS_Y,
        WHITE
    );
}

// Set Dialogue Picture
void SetDialoguePicture(const char *PATH)
{   
    Image character = LoadImage(PATH);
    picture.character = LoadTextureFromImage(character);
    UnloadImage(character);
}