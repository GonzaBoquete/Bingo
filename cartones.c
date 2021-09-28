#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cartones.h"
#define RENGLONES 3
#define COLUMNAS 5

////////////TDA////////////////
struct estructuraCartones{
    int matrizCarton[COLUMNAS][RENGLONES];
};

//constructor
Cartones crearCarton(){
    Cartones C = malloc(sizeof(struct estructuraCartones));
    iniciarmatrizencero(C->matrizCarton);
    int numero=0; //esta solo es una variable que va a tomar un valor por teclado
    int resultadobusqueda=0; //esta variable esta hecha solo para la funcion de busqueda
    for(int r=0; r<RENGLONES; r++){
        for(int c=0; c<COLUMNAS; c++){
            do{
            printf("Ingrese 15 numeros entre 1 y 90:\n"); //numero por teclado entre 1 y 90
            scanf("%d", &numero);
            while ((numero<1||numero>90)){
            printf("\n Elija numeros entre 1 y 90!!!\n");
              scanf("%d", &numero);
            }
            resultadobusqueda=busquedasecuencialmatriz(C->matrizCarton, numero); //busco el numero en el vector y toma un valor de la posicion en la matriz si esta o -1 si no esta
            if(resultadobusqueda!=-1){ //if para indicar que se ingreso un numero repetido
                printf("\nUsted ingreso un numero repetido.\n\n"); //muestro por pantalla que se ingreso un numero repetido
            }
            }while(resultadobusqueda!=-1); //abro un mientras diciendo que si se el numero no aparecio en el vector
                C->matrizCarton[c][r]=numero; //el vector en esa posicion toma el valor del numero aleatorio
        }
    }
    return C;
}

//gets
int getCarton(Cartones C){
    return C->matrizCarton;
}

//sets
void setCarton(Cartones C, int nuevoCarton[COLUMNAS][RENGLONES]){
    for(int r=0; r<RENGLONES; r++){
        for(int c=0; c<COLUMNAS; c++){
            C->matrizCarton[c][r] = nuevoCarton[c][r];
        }
    }
}

//destructor
void destruirCarton(Cartones C){
    free(C);
}




