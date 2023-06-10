#pragma once
#include <raylib.h>

// Picture Container Propertiers
typedef struct
{
    Texture2D character;
}PictureInfo;

extern PictureInfo picture;

void DrawDialogue();
void SetDialoguePicture(const char *PATH);
void DrawDialogueText(const char *text, Vector2 position);