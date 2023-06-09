#include "dialoguebox.h"
#include "colours.h"
#include "filepath.h"
#include "global.h"

#include <raylib.h>

#include <bits/stdc++.h>

bool show_dialogue_box = 0;

int main()
{
    // Set Window Properties
    InitWindow(RESOLUTION[0], RESOLUTION[1], TITLE);
    SetTargetFPS(FPS);

    // Set Properites of Dialogue Box
    SetDialoguePicture(PATH_HIGHMAGE);

    // Font
    Font alagard = LoadFontEx(
    PATH_ALAGARD, 
    32,
    0,
    250);

    // Game Loop
    while (!WindowShouldClose())
    {
        // Update
        if (IsKeyPressed(KEY_E)) show_dialogue_box = !show_dialogue_box;

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextEx(
           alagard,
           TITLE,
           (Vector2){5,5},
           FONT_SIZE,
           FONT_SPACING,
           BLACK);

        if (show_dialogue_box) DrawDialogue();
        else ClearBackground(RAYWHITE);

        EndDrawing();
    }

    // Cleanup Program
    CloseWindow();

    return 0;
}