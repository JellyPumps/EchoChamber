#include "dialoguebox.h"
#include "colours.h"
#include "filepath.h"
#include "global.h"

#include <fstream>
#include <raylib.h>

#include <bits/stdc++.h>

bool show_dialogue_box = 0;

int main()
{
    // Set Window Properties
    InitWindow(g_RESOLUTION[0], g_RESOLUTION[1], g_TITLE);
    SetTargetFPS(g_FPS);

    // Load font
    loadALAGARD();

    // Load
    SetDialoguePicture(HIGH_MAGE);

    // Load Intro File
    std::ifstream introFile(PATH_INTRODUCTION_FILE);

    if (!introFile) {
        std::cout << "Failed to open dialogue file." << std::endl;
        return 1;
    }

    // Game Loop
    while (!WindowShouldClose())
    {
        // Update
        if (IsKeyPressed(KEY_R)) show_dialogue_box = !show_dialogue_box;
        
        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (show_dialogue_box) {
            DrawDialogue();
            ProcessDialogue(introFile);
        }
        else ClearBackground(RAYWHITE);

        EndDrawing();

        NextDialogue();
    }

    // Cleanup Program
    UnloadImage(high_mage);
    CloseWindow();

    return 0;
}