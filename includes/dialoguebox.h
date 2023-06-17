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
extern Image high_mage;

void loadALAGARD();
void DrawDialogue();
void DrawDialogueText(const std::string &input);
void SetDialoguePicture(const char *PATH);
void SplitDialogue(const std::string &input, std::string dialogue[]);
void ProcessDialogue(std::ifstream& file);