#pragma once
#include <raylib.h>

// Picture Container Propertiers
typedef struct
{
    Texture2D character;
}PictureInfo;

extern PictureInfo picture;
extern Font alagard;

void loadALAGARD();
void DrawDialogue();
void SetDialoguePicture(const char *PATH);