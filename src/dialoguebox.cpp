#include "dialoguebox.h"
#include "colours.h"
#include "filepath.h"
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

const float MAX_CHARACTER_COUNT = (WIDTH / 2.0) / ((WIDTH / 50.0) + (WIDTH / 400.0));

Font alagard = LoadFontEx(
    PATH_ALAGARD,
    32,
    0,
    250
);

// Draw Dialogue Box
void DrawDialogue()
{

    // Dialogue Outline
    DrawRectangle(
        WIDTH * OT_POS_X,
        HEIGHT * OT_POS_Y,
        WIDTH * OT_SIZ_X,
        HEIGHT * OT_SIZ_Y,
        PLEARTH_ONE
    );

    // Dialogue Container Rect
    DrawRectangle(
        WIDTH * DX_POS_X,
        HEIGHT * DX_POS_Y,
        WIDTH * DX_SIZ_X,
        HEIGHT * DX_SIZ_Y,
        PLEARTH_TWO
    );

    // Dialogue Picture
    DrawTexture(
        picture.character,
        WIDTH * PX_POS_X,
        HEIGHT * PX_POS_Y,
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

// Draw Text for Dialogue
void DrawDialogueText(const char *text, Vector2 position)
{
    DrawTextEx(
        alagard,
        text,
        (Vector2){position.x,position.y},
        FONT_SIZE,
        FONT_SPACING,
        BLACK
    );
}