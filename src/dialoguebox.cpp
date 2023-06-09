#include "dialoguebox.h"
#include "colours.h"
#include "global.h"

#include <raylib.h>

PictureInfo picture;

// Dialogue Properties
const float DX_POS_X = 7.0 / 40.0;
const float DX_POS_Y = 3.0 / 4.0;
const float DX_SIZ_X = 2.0;
const float DX_SIZ_Y = 6.0;

const float PX_POS_X = 40.0;
const float PX_POS_Y = 3.0 / 4.0;
const float PX_SIZ_X = 8.0;
const float PX_SIZ_Y = 6.0;

void DrawDialogue()
{
    // Dialogue Container Rect
    DrawRectangle(
        RESOLUTION[0] * DX_POS_X,
        RESOLUTION[1] * DX_POS_Y,
        RESOLUTION[0] / DX_SIZ_X,
        RESOLUTION[1] / DX_SIZ_Y,
        KEYSTONE
    );

    // Dialogue Picture Outline
    DrawRectangle(
        RESOLUTION[0] / PX_POS_X - 5,
        RESOLUTION[1] * PX_POS_Y - 5,
        RESOLUTION[0] / PX_SIZ_X + 10,
        RESOLUTION[1] / PX_SIZ_Y + 10,
        KEYSTONE
    );

    // Dialogue Picture
    DrawTexture(
        picture.character,
        RESOLUTION[0] / PX_POS_X,
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