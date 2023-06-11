#pragma once
#include <bits/stdc++.h>

#include <raylib.h>
#include <vector>

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
void SplitDialogue(const std::string &input, std::string dialogue[]);