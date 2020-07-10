#pragma once
#include <GLFW/glfw3.h>
#include <stdlib.h> //for the random function

struct thergb {
    GLbyte r;
    GLbyte g;
    GLbyte b;
};

thergb* noiseScreen();

void drawScreen(thergb* rgb);