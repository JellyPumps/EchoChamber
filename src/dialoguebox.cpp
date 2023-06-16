#include "dialoguebox.h"
#include "colours.h"
#include "filepath.h"
#include "global.h"

#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

PictureInfo picture;


const int MAX_CHARACTER_COUNT = 32;
const int DIALOGUE_ARR_SIZE = 5;

std::string dialogue;
std::string character;
std::string dialogue_arr[DIALOGUE_ARR_SIZE];

Font alagard;

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
            FONT_SIZE,
            FONT_SPACING,
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
        DrawDialogueText(dialogue);
    }
}


void DrawDialogueText(const std::string &input)
{
    SplitDialogue(input, dialogue_arr);

    for (int i = 0; i < DIALOGUE_ARR_SIZE; i++) {

        int pos_i = i * (FONT_SIZE + FONT_SPACING);

        DrawTextEx(
            alagard,
            dialogue_arr[i].c_str(),
            (Vector2){FONT_X,FONT_Y + pos_i},
            FONT_SIZE,
            FONT_SPACING,
            BLACK
        );
    }
}