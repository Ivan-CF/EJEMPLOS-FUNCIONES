#include <stdio.h>
 
int main ()
{
   
    enum direccion { Arriba=50, Abajo=-1, Izquierda=88, Derecha=68 };
   
    enum direccion opcion;
   
    for ( int tmp = 0; tmp<5; tmp++){
   
        printf("Que direccion quieres tomar?\n%d = Arriba\n%d = Abajo\n%d = Izquierda\n",Arriba,Abajo,Izquierda);
        printf("%d = Derecha\n",Derecha);
       
        scanf("%d",&opcion);
        getchar();
       
        switch(opcion){
            case Arriba:
                printf("Vas Arriba\n");
                break;
            case Abajo:
                printf("Vas Abajo\n");
                break;
            case Izquierda:
                printf("Vas Izquierda\n");
                break;
            case Derecha:
                printf("Vas Derecha\n");
                break;
        }
   
    }
 
    getchar();
    return 0;
}