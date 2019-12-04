#include <stdio.h>
#include <string.h>
 
typedef int kk;
 
 
typedef struct SuperHeroes{
    char nombre[50];
    int fuerza;
}SuperHeroe;
 
 
int main ()
{
    SuperHeroe superman;
    SuperHeroe batman;
   
    strcpy(superman.nombre,"Superman");
    superman.fuerza=1000;
   
    strcpy(batman.nombre,"Batman");
    batman.fuerza = 10;
   
    kk variable1;
 
    variable1 = 5;
 
    printf("Ejemplo %d\n",variable1);
 
    getchar();
    return 0;
}