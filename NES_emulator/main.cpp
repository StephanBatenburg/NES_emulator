#include <GLFW/glfw3.h>
#include <stdlib.h> //for the random function

struct thergb{
    GLbyte r;
    GLbyte g;
    GLbyte b;
};

int main(void)
{
    thergb* rgb= new thergb[256*240];
    //struct thergb rgb[256 * 240];

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1024, 960, "NES emulator", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    int windowWidth = 0;
    int windowHeight = 0;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);
    glViewport(0, 0, windowWidth, windowHeight);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        //set some random pixels to display...
        for (int i = 0; i < (256 * 240); i++) {
            rgb[i].r = rand();
            rgb[i].g = rand();
            rgb[i].b = rand();
        }

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

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        windowWidth = 0;
        windowHeight = 0;
        glfwGetWindowSize(window, &windowWidth, &windowHeight);
        glViewport(0, 0, windowWidth, windowHeight);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}