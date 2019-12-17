/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
 
#include "raylib.h"
 
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;
 
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
   
    int framesCounter = 0;
    SetTargetFPS(60);
    bool blink = false;
    //--------------------------------------------------------------------------------------
 
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
       
        framesCounter++;
        if (framesCounter % 30 == 0)
        {
        framesCounter = 0;
        blink = !blink;
        }
        //----------------------------------------------------------------------------------
       
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
 
            ClearBackground(RAYWHITE);
 
            DrawText("GAME TITLE", screenWidth/2 - MeasureText("GAME TITLE", 60)/2, screenHeight/4, 60, LIME);
            if (blink) DrawText("Press Start", screenWidth/2 - MeasureText("Press Start", 30)/2, screenHeight - 100, 30, BLACK);
           
 
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
 
    // De-Initialization
    //--------------------------------------------------------------------------------------  
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
 
    return 0;
}