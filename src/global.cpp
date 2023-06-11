#include "global.h"

int RESOLUTION[2] = {800,600};

const int FPS = 60;
const int WIDTH  = RESOLUTION[0];
const int HEIGHT = RESOLUTION[1];

const char *TITLE = "Echo Chamber";

const float FONT_SIZE = WIDTH / 50.0;
const float FONT_SPACING = WIDTH / 400.0;

const float DX_POS_X = WIDTH * 7.0 / 40.0;
const float DX_POS_Y = HEIGHT *3.0 / 4.0;
const float DX_SIZ_X = WIDTH * 1.0 / 2.0;
const float DX_SIZ_Y = HEIGHT * 1.0 / 6.0;

const float PX_POS_X = WIDTH * 1.0 / 40.0;
const float PX_POS_Y = HEIGHT * 3.0 / 4.0;
const float PX_SIZ_X = WIDTH * 1.0 / 8.0;
const float PX_SIZ_Y = HEIGHT * 1.0 / 6.0;

const float OT_POS_X = WIDTH * 1.0 / 80.0;
const float OT_POS_Y = HEIGHT * 11.0 / 15.0;
const float OT_SIZ_X = WIDTH * 27.0 / 40.0;
const float OT_SIZ_Y = HEIGHT * 1.0 / 5.0;

const float FONT_X = DX_POS_X + FONT_SIZE;
const float FONT_Y = DX_POS_Y + FONT_SPACING;

const float CONT_X = 19.0 * FONT_SIZE * FONT_SPACING;
const float CONT_Y = HEIGHT - FONT_SIZE;

bool nextLine = true;