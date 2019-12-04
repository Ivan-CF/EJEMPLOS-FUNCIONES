#include <stdlib.h>
#include <stdio.h>
 
 
int Suma(int a, int b){
    int salida;
    salida = a + b;
   
    return salida;    
}
 
int Resta(int a, int b){
    return a-b;
}
 
void PintaResultado(int resultado){
    printf("El resultado es %d\n",resultado);
}
 
int main ()
{
    printf("Introduzca un valor 1\n");
     
    int valor1;
     
    scanf("%d",&valor1);
    getchar();
   
    printf("Introduzca un valor 2\n");
     
    int valor2;
     
    scanf("%d",&valor2);  
    getchar();
   
    printf("Que quieres hacer?\na=Suma; b= Resta\n");
     
    char opcion;
     
    scanf("%c",&opcion);
    getchar();
   
    int salida;
   
    switch(opcion){
        case 'a':
            salida = Suma(valor1,valor2);
            break;
        case 'b':
            salida = Resta(valor1,valor2);
            break;
    }
   
    PintaResultado(salida);
   
 
    getchar();
    return 0;
}