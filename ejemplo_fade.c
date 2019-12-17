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
   
    Rectangle rec = {0, 0, screenWidth, screenHeight};
    Color recColor = BLACK;
   
    bool fadeOut = true;
    float alpha = 0;
    float fadeSpeed = 0.01f;
    
    Vector2 v1;
    v1.x = screenWidth/2;
    v1.y = screenHeight/2-100;
    
    Vector2 v2;
    v2.x = screenWidth/2-100;
    v2.y = screenHeight/2+100;
    
    Vector2 v3;
    v3.x = screenWidth/2+100;
    v3.y = screenHeight/2+100;
   
   
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------
 
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        if(fadeOut)
        {
            alpha += fadeSpeed;
           
            if(alpha >= 1.0f)
            {
                alpha = 1.0f;
            }
        }
        else
        {
            alpha -= fadeSpeed;
            if(alpha <= 0.0f)
            {
                alpha = 0.0f;
            }
        }
       
        if(IsKeyPressed(KEY_SPACE))
        {
            fadeOut = !fadeOut;
        }
        //----------------------------------------------------------------------------------
 
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
 
            ClearBackground(RAYWHITE);
            
            DrawTriangle(v1, v2, v3, Fade(RED, alpha));
           
            //DrawRectangleRec(rec, Fade(recColor, alpha));
           
            DrawText(FormatText("%f", alpha), 10,10, 20, WHITE);
 
 
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
 
    // De-Initialization
    //--------------------------------------------------------------------------------------  
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
 
    return 0;
}