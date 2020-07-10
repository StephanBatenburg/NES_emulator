#include "rendering.h"

thergb* noiseScreen()
{
    thergb* rgb = new thergb[256 * 240];

    //set some random pixels to display...
    for (int i = 0; i < (256 * 240); i++) {
        rgb[i].r = rand();
        rgb[i].g = rand();
        rgb[i].b = rand();
    }

    return rgb;
}

void drawScreen(thergb* rgb)
{
    int j = 0;
    bool firstTrue = false;
    for (int i = 0; i < (256 * 240); i++) {
        if ((i % 256) == 0)
        {
            if (firstTrue)
            {
                j++;
            }
            firstTrue = true;
        }
        glBegin(GL_TRIANGLES);
        glColor3b(rgb[i].r, rgb[i].g, rgb[i].b);
        //calculate next location
        float firstx = -1.0 + ((i % 256) / 128.0);
        float firsty = 1.0 - ((j % 240) / 120.0);
        float secondx = firstx + (1.0 / 128.0);
        float secondy = firsty - (1.0 / 120);
        glVertex2f(firstx, firsty); //top left
        glVertex2f(firstx, secondy); //bottom left
        glVertex2f(secondx, firsty); //top right
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3b(rgb[i].r, rgb[i].g, rgb[i].b);
        //calculate next location
        glVertex2f(secondx, firsty); //top right
        glVertex2f(firstx, secondy); //bottom left
        glVertex2f(secondx, secondy); //bottom right
        glEnd();
    }

    delete(rgb);
}
