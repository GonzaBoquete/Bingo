#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cartones.h"
#include "jugador.h"
#define RENGLONES 3
#define COLUMNAS 5


int busquedasecuencialvector(int vector[], int tamanio, int busco);
//PRE: Tener un vector cargado y un numero a buscar
//POST: Devuelve como valor -1 si no se encuentra el numero en el vector y sino devuelve la posicion

void iniciarvectorencero(int vector[], int tamanio);
//PRE: tener definido un vector
//POST: el vector se cargara con valores nulos

void cargarvectoraleatorio(int vector[], int tamanio);
//PRE: Tener definido un vector
//POST: Tener un vector cargado aleatoriamente sin repetir

void mostrarvector(int vector[], int tamanio);
//PRE: Tener un vector cargado
//POST: Mostrar por pantalla los componentes del vector

int MultiplicarPuntaje(int puntaje,int contador);
//PRE: Haber cantado bingo teniendo guardado un puntaje y el contador con el turno en el que se canto bingo
//POST: Multiplicar el puntaje segun el turno en el que se haya cantado bingo

void opcionmenu4();


// ______////////// INICIO DEL MAIN ////////////////
int main()
{
srand(time(0));



 printf("\n****-----------------Bienvenido al BINGO!-----------------*****\n");

 printf("\n**Inicie sesion para continuar**\n");

 Jugador J = iniciarsesion();
 MostrarInicio(J);



 printf("\n\n\n_______________________________________________________________\n _-_-_-_-_-_-_-_-_-_-_-_-MENU PRINCIPAL_-_-_-_-_-_-_-_-_-_-_-_-\n_______________________________________________________________\n");
int opcion = 0;
while(opcion!=4){
printf("\n   *Elija su opcion para continuar!                         ---\n");
    printf("\n--- 1) Jugar!                                               ---\n");
    printf("\n--- 2) Mostrar resultados previos (No realizado)            ---\n");
    printf("\n--- 3)(No realizado)                                        ---\n");
    printf("\n--- 4) SALIR                                                ---\n\n");
    printf("---------------------------------------------------------------\n\n");

    scanf("%d", &opcion);
    switch(opcion){
        case 1: opcionmenu1(J); break; // COMENZAR JUEGO
        //case 2: opcionmenu2(); break; // MOSTRAR RESULTADOS PARTIDOS PREVIOS
        //case 3: opcionmenu3(); break; // PENDIENTE
        case 4: opcionmenu4(); break; // SALIR
        default: printf("\n ERROR!!!! Elija una opcion valida! \n"); break;
    }
}

return 0;
}
// ______////////// FIN DEL MAIN /////////////




int busquedasecuencialvector(int vector[], int tamanio, int busco){
    int pos=-1; //doy posicion inicial -1  a posicion para saber que si devuelve eso no se encontro el numero
    for(int i=0; i<tamanio; i++){
        if(vector[i]==busco){ //creo la condicion pra comparar el numero buscado con las componentes del vector
            pos=i; //si se cumple la condicion se guarda la posicion del numero encontrado
        }
    }
    return pos;
}

void iniciarvectorencero(int vector[], int tamanio){
    for(int i=0; i<tamanio; i++){
        vector[i]=0;
    }
}

void cargarvectoraleatorio(int vector[], int tamanio){
    iniciarvectorencero(vector, tamanio); //cargo el vector con valores nulos
    int numaleatorio=0; //esta solo es una variable que va a tomar un valor aleatorio
    int resultadobusqueda=0; //esta variable esta hecha solo para la funcion de busqueda
    for(int i=0; i<tamanio; i++){
        do{
        numaleatorio=1+(rand()%90); //numero aleatorio entre 1 y 90
        resultadobusqueda=busquedasecuencialvector(vector, tamanio, numaleatorio); //busco el numero en el vector y vale la posicion si esta o -1 si no esta
        }while(resultadobusqueda!=-1); //abro un mientras diciendo que si se el numero no aparecio en el vector
            vector[i]=numaleatorio; //el vector en esa posicion toma el valor del numero aleatorio
        }
}

void mostrarvector(int vector[], int tamanio){
    for(int i=0; i<tamanio; i++){
        printf("--> %d\n", vector[i]);
    }
}


void opcionmenu4(){

    printf("\n\n*----------Gracias por jugar--------*\n\n");

}


int MultiplicarPuntaje(int puntaje, int contador){

int resultado = 0;
if (contador<30){
    resultado = puntaje*2;
}
if (contador>=30&&contador<=50){
    resultado = puntaje*1.7;
}
if (contador>50&&contador<=70){
    resultado = puntaje*1.5;
}
if (contador>70){
    resultado = puntaje;
}

return resultado;

}
