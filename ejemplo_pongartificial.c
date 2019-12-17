#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;
    const int velocidady = 8;
    const int ballSize = 25;
    const int maxVelocity = 8;
    const int minVelocity = 8;
   
    char *texto;
    Vector2 tamanoTexto;
   
    bool pause = false;
   
    int score1p = 0;
    int score2p = 0;
   
    Rectangle paladerecha;
   
    paladerecha.width = 20;
    paladerecha.height = 100;    
    paladerecha.x = screenWidth - 50 - paladerecha.width;
    paladerecha.y = screenHeight/2 - paladerecha.height/2;
   
   
    Rectangle palaizquierda;
   
    palaizquierda.width = 20;
    palaizquierda.height = 100;    
    palaizquierda.x = 50;
    palaizquierda.y = screenHeight/2 - palaizquierda.height/2;
   
   
    Vector2 ball;
    ball.x = screenWidth/2;
    ball.y = screenHeight/2;
   
    Vector2 ballVelocity;
    ballVelocity.x = minVelocity;
    ballVelocity.y = minVelocity;
   
   
    int iaLinex = screenWidth/2;
   
   
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
   
    Font fontTtf = LoadFontEx("Resources/Gameplay.ttf", 32, 0, 250);
   
    // Init Audio Device
    InitAudioDevice();      // Initialize audio device
 
    // Load sound
    Sound fxWav = LoadSound("Resources/bounce.wav");         // Load WAV audio file
    Sound fxGoal = LoadSound("Resources/goal.wav");         // Load WAV audio file
 
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
 
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // Gestiono pulsaciones botones
        if(!pause){
            /*
            if (IsKeyDown(KEY_Q)){
              palaizquierda.y -= velocidady;
            }
           
            if (IsKeyDown(KEY_A)){
              palaizquierda.y += velocidady;
            }
           
            if (IsKeyDown(KEY_UP)){
              paladerecha.y -= velocidady;
            }
           
            if (IsKeyDown(KEY_DOWN)){
              paladerecha.y += velocidady;
            }
            */
           
            if (IsKeyDown(KEY_RIGHT)){
                iaLinex+=velocidady;
            }
           
            if (IsKeyDown(KEY_LEFT)){
                iaLinex -=velocidady;
            }
        }
       
        // Ejecutamos LA IA
        if( ball.x > iaLinex){
            if(ball.y > paladerecha.y){
                paladerecha.y+=velocidady;
            }
           
            if(ball.y < paladerecha.y){
                paladerecha.y-=velocidady;
            }
        }
        
        if( ball.x < iaLinex){
            if(ball.y > palaizquierda.y){
                palaizquierda.y+=velocidady;
            }
           
            if(ball.y < palaizquierda.y){
                palaizquierda.y-=velocidady;
            }
        }
       
       
        if (IsKeyPressed(KEY_P)){
          pause = !pause;
        }
       
        //Consulto Limites
        if(palaizquierda.y<0){
            palaizquierda.y = 0;
        }
       
        if(palaizquierda.y > (screenHeight - palaizquierda.height)){
            palaizquierda.y = screenHeight - palaizquierda.height;
        }
       
        if(paladerecha.y<0){
            paladerecha.y = 0;
        }
       
        if(paladerecha.y > (screenHeight - paladerecha.height)){
            paladerecha.y = screenHeight - paladerecha.height;
        }
       
        //Gestionamos el movimiento de la Bola
        if(!pause){
            ball.x += ballVelocity.x;
            ball.y += ballVelocity.y;
        }
       
        //Aqui marcamos gol
        if(ball.x > screenWidth - ballSize){
            //Marca la pala izquierda
            //PlaySound(fxGoal);
            score1p++;
            ball.x = screenWidth/2;
            ball.y = screenHeight/2;
            ballVelocity.x = -minVelocity;
            ballVelocity.y = minVelocity;
           
        }else if(ball.x < ballSize){
            //Marca la pala derecha
            //PlaySound(fxGoal);
            score2p++;
            ball.x = screenWidth/2;
            ball.y = screenHeight/2;
            ballVelocity.x = minVelocity;
            ballVelocity.y = minVelocity;
        }
       
        if((ball.y > screenHeight - ballSize) || (ball.y < ballSize) ){
            ballVelocity.y *=-1;
            //PlaySound(fxWav);
        }
 
 
        if(CheckCollisionCircleRec(ball, ballSize, paladerecha)){
            if(ballVelocity.x>0){
                //PlaySound(fxWav);
                if(abs(ballVelocity.x)<maxVelocity){                    
                    ballVelocity.x *=-1.5;
                    ballVelocity.y *= 1.5;
                }else{
                    ballVelocity.x *=-1;
                }
            }
        }
       
        if(CheckCollisionCircleRec(ball, ballSize, palaizquierda)){
            if(ballVelocity.x<0){
                //PlaySound(fxWav);
                if(abs(ballVelocity.x)<maxVelocity){                    
                    ballVelocity.x *=-1.5;
                    ballVelocity.y *= 1.5;
                }else{
                    ballVelocity.x *=-1;
                }
            }
        }
       
        //----------------------------------------------------------------------------------
 
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
 
            ClearBackground(BLUE);
           
            // Pinto Pala Derecha
            DrawRectangleRec(paladerecha, GREEN);
           
            // Pinto Pala Izquierda
            DrawRectangleRec(palaizquierda, GREEN);
           
            // Pintamos la pelota
            DrawCircleV(ball, ballSize, GREEN);  
           
            // Pintar linea IA
            DrawLine(iaLinex, 0, iaLinex , screenHeight, RED);  
           
            // Texto ejemplo
           
            texto = FormatText("SCORE 1P: %d",score1p);
           
            DrawTextEx(fontTtf, texto, (Vector2){0,10}, 40, 0, RED);
 
            texto = FormatText("SCORE 2P: %d",score2p);
            tamanoTexto = MeasureTextEx(fontTtf, texto, 40, 0);
           
            DrawTextEx(fontTtf, texto, (Vector2){screenWidth - tamanoTexto.x,10}, 40, 0, RED);
            //DrawText(FormatText("SCORE 1P: %d",score1p), 10, 10, 40, RED);
            //DrawText(FormatText("SCORE 2P: %d",score2p), screenWidth - 300, 10, 40, RED);
           
            if(pause){
                DrawRectangle(0, 0, screenWidth, screenHeight, (Color){ 0, 255, 0, 255/2 });  
                DrawText("Press p to continue", screenWidth/2 - MeasureText("Press p to continue", 40)/2 , screenHeight/2, 40, RED);
            }
           
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
 
    UnloadFont(fontTtf);    // TTF Font unloading
   
    UnloadSound(fxWav);     // Unload sound data
 
    CloseAudioDevice();     // Close audio device
 
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
 
    return 0;
}