#include "dialoguebox.h"
#include "colours.h"
#include "filepath.h"
#include "global.h"

#include <cstddef>
#include <fstream>
#include <iostream>
#include <raylib.h>
#include <string>

PictureInfo picture;


const float DX_POS_X = g_WIDTH * 7.0 / 40.0;
const float DX_POS_Y = g_HEIGHT *3.0 / 4.0;
const float DX_SIZ_X = g_WIDTH * 1.0 / 2.0;
const float DX_SIZ_Y = g_HEIGHT * 1.0 / 6.0;
const float PX_POS_X = g_WIDTH * 1.0 / 40.0;
const float PX_POS_Y = g_HEIGHT * 3.0 / 4.0;
const float PX_SIZ_X = g_WIDTH * 1.0 / 8.0;
const float PX_SIZ_Y = g_HEIGHT * 1.0 / 6.0;
const float OT_POS_X = g_WIDTH * 1.0 / 80.0;
const float OT_POS_Y = g_HEIGHT * 11.0 / 15.0;
const float OT_SIZ_X = g_WIDTH * 27.0 / 40.0;
const float OT_SIZ_Y = g_HEIGHT * 1.0 / 5.0;

const float FONT_X = DX_POS_X + g_FONT_SIZE;
const float FONT_Y = DX_POS_Y + g_FONT_SPACING;
const float CONT_X = 19.0 * g_FONT_SIZE * g_FONT_SPACING;
const float CONT_Y = g_HEIGHT - g_FONT_SIZE;


const int MAX_CHARACTER_COUNT = 32;
const int DIALOGUE_ARR_SIZE = 5;

std::string dialogue;
std::string character;
std::string dialogue_arr[DIALOGUE_ARR_SIZE];

bool waitForInput;

Font alagard;
Image high_mage;

// Load Main Font
void loadALAGARD()
{
    alagard = LoadFontEx(
        PATH_ALAGARD,
        32,
        0,
        250
    );
}

// Draw Dialogue Box
void DrawDialogue()
{

    // Dialogue Outline
    DrawRectangle(
         OT_POS_X,
         OT_POS_Y,
         OT_SIZ_X,
         OT_SIZ_Y,
        PLEARTH_ONE
    );

    // Dialogue Container Rect
    DrawRectangle(
         DX_POS_X,
         DX_POS_Y,
         DX_SIZ_X,
         DX_SIZ_Y,
        PLEARTH_TWO
    );

    // Dialogue Picture
    DrawTexture(
        picture.character,
         PX_POS_X,
         PX_POS_Y,
        WHITE
    );
    
}

// Set Picture For Character
void SetDialoguePicture(const char *PATH)
{   
    Image character = LoadImage(PATH);
    picture.character = LoadTextureFromImage(character);
    UnloadImage(character);
}

// Dialogue Text Operations

void SplitDialogue(const std::string &input, std::string dialogue[])
{
    int currentIndex = 0;
    int dialogueIndex = 0;

    while (currentIndex < input.length() && dialogueIndex < DIALOGUE_ARR_SIZE)
    {
        std::string currentSentence;

        // Check If The Next Character Is A Whitespace
        if (currentIndex + MAX_CHARACTER_COUNT < input.length() - 1 &&
        input[currentIndex + MAX_CHARACTER_COUNT] != ' ') {
            
            // Find The Last Whitespace Before MAX_CHARACTER_COUNT
            int lastWhitespaceIndex = currentIndex + MAX_CHARACTER_COUNT;
            
            while (lastWhitespaceIndex >= currentIndex && input[lastWhitespaceIndex] != ' ') {
                lastWhitespaceIndex--;
            }

            // Divide At The Last Whitespace
            if (lastWhitespaceIndex >= currentIndex) {
                currentSentence = input.substr(
                    currentIndex,
                    lastWhitespaceIndex - currentIndex + 1
                );

                currentIndex = lastWhitespaceIndex + 1;
            }
        }

        // Divide At MAX_CHARACTER_COUNT If No Whitespace Found
        if (currentSentence.empty()) {
            currentSentence = input.substr(currentIndex, MAX_CHARACTER_COUNT);
            currentIndex += MAX_CHARACTER_COUNT;
        }

        // Remove Leading Whitespace From The Current Sentence
        size_t firstNonWhitespaceIndex = currentSentence.find_first_not_of(' ');
        if (firstNonWhitespaceIndex != std::string::npos) {
            currentSentence = currentSentence.substr(firstNonWhitespaceIndex);
        }

        dialogue[dialogueIndex] = currentSentence;
        dialogueIndex++;
    }
}

void ProcessDialogue(std::ifstream& file)
{
    std::string line;

    DrawDialogueText(dialogue);

    if (waitForInput) {
        // Press "KEY" To Continue Text
        DrawTextEx(
            alagard,
            "Press E To Continue",
            (Vector2){CONT_X,CONT_Y},
            g_FONT_SIZE,
            g_FONT_SPACING,
            GRAY
        );
    }
    else if (std::getline(file,line)) {

        for (int i = 0; i < DIALOGUE_ARR_SIZE; i++) {
            dialogue_arr[i] = "";
        }

        size_t colonPos = line.find(':');

        if (colonPos != std::string::npos) {
            character = line.substr(0, colonPos);
            dialogue = line.substr(colonPos + 1);
        }

        waitForInput = true;

        std::cout << character << "\n";

        if (character == "High Mage") {
            picture.character = LoadTextureFromImage(high_mage);
        }

        DrawDialogueText(dialogue);
    }
}


void DrawDialogueText(const std::string &input)
{
    SplitDialogue(input, dialogue_arr);

    for (int i = 0; i < DIALOGUE_ARR_SIZE; i++) {

        int pos_i = i * (g_FONT_SIZE + g_FONT_SPACING);

        DrawTextEx(
            alagard,
            dialogue_arr[i].c_str(),
            (Vector2){FONT_X,FONT_Y + pos_i},
            g_FONT_SIZE,
            g_FONT_SPACING,
            BLACK
        );
    }
}

void NextDialogue()
{
    if (waitForInput && IsKeyPressed(KEY_E)) waitForInput = false;
}