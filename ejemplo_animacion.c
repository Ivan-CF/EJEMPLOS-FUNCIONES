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
 
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
   
   
    const int screenWidth = 800;
    const int screenHeight = 450;
   
    const int spriteWidth = 32;
    const int spriteHeight = 32;
 
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
   
    Texture2D characters = LoadTexture("resorces/characters.png");
   
    Rectangle sourceRec;
    sourceRec.x = 0;
    sourceRec.y = 35;
    sourceRec.width = spriteWidth;  // 32
    sourceRec.height = spriteHeight; //32
   
    Rectangle destinationRec;
    destinationRec.x = screenWidth/2 - spriteWidth/2;
    destinationRec.y = screenHeight/2 - spriteHeight/2;
    destinationRec.width = sourceRec.width*4;
    destinationRec.height = sourceRec.height*4;
   
    Vector2 origin;
    origin.x = 0;
    origin.y = 0;
   
    int framesCounter = 0;
 
 
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
 
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        framesCounter++;
       
        if (framesCounter >= 6)
        {
            if (sourceRec.x > spriteWidth*4)
            {
                sourceRec.x = 0;
            }
            framesCounter = 0;
            sourceRec.x += spriteWidth;          
 
        }
       
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
 
            ClearBackground(RAYWHITE);
           
            DrawTexturePro(characters, sourceRec, destinationRec, origin, 0, WHITE);
           
            DrawTexture(characters, 0, 0, WHITE);  
           
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
 
    // De-Initialization
    //--------------------------------------------------------------------------------------
   UnloadTexture(characters);
   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
 
    return 0;
}