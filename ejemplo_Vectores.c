#include <stdio.h>
 
struct Vector2Jandu{
    int x;
    int y;
};
 
int main ()
{
    struct Vector2Jandu vector1;
    struct Vector2Jandu vector2;
   
    // vector1 = {3,2}
    vector1.x = 3;
    vector1.y = 2;
   
    //vector2 = {5,5}
    vector2.x = 5;
    vector2.y = 5;
   
    struct Vector2Jandu vector3;
    vector3.x = vector1.x + vector2.x;
    vector3.y = vector1.y + vector2.y;
 
    printf("El vector resultado es (%d,%d)\n",vector3.x,vector3.y);
 
    getchar();
    return 0;
}