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
    InitWindow(RESOLUTION[0], RESOLUTION[1], TITLE);
    SetTargetFPS(FPS);

    // Set Properites of Dialogue Box
    SetDialoguePicture(HIGH_MAGE);

    // Load font
    loadALAGARD();

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

        if (waitForInput && IsKeyPressed(KEY_E)) waitForInput = false;
    }

    // Cleanup Program
    CloseWindow();

    return 0;
}