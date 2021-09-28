#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cartones.h"
#include "jugador.h"
#define RENGLONES 3
#define COLUMNAS 5


struct estructuraJugador{
    char nombre[20];
    char apellido[20];
    int dni;
    int puntaje;
    Cartones C[3];
};

//constructor
Jugador iniciarsesion(){
    Jugador J = malloc(sizeof(struct estructuraJugador));
    char aux[50] = " ";

    printf("\nIngrese su nombre!\n\n");
    fflush(stdin);
    gets(aux);
    strcpy(J->nombre, aux);

    printf("\nIngrese su Apellido:\n\n");
    fflush(stdin);
    gets(aux);
    strcpy(J->apellido, aux);

    printf("\nIngrese su DNI\n\n");
    scanf("%d", &J->dni);

    return J;
};

//gets
char* getNombre(Jugador J){
    return J->nombre;
}
char* getApellido(Jugador J){
    return J->apellido;
}
int getDNI(Jugador J){
    return J->dni;
}
int getPuntaje(Jugador J){
    return J->puntaje;
}


//sets
void setNombre(Jugador J, char nuevoNombre[20]){
    strcpy(J->nombre, nuevoNombre);
}
void setApellido(Jugador J, char nuevoApellido[20]){
    strcpy(J->apellido, nuevoApellido);
}
void setDNI(Jugador J, int nuevoDNI){
    J->dni = nuevoDNI;
}
void setPuntaje(Jugador J, int nuevoPuntaje){
    J->puntaje = nuevoPuntaje;
}


//destructor
void destruirJugador(Jugador J){
    free(J);
}

//////////////////FUNCIONES/////////////////


void MostrarInicio(Jugador J){
printf("\n\n -- Usted esta registrado como --\n\n");
printf("--------- Nombre:      %s ---------\n", J->nombre);
printf("--------- Apellido:    %s ---------\n", J->apellido);
printf("--------- DNI:         %d ---------", J->dni);

};

void opcionmenu1(Jugador J){
    srand(time(0));
    int maximocartones=3;
    //Cartones jugador[maximocartones];
    Jugador computadora = malloc(sizeof(struct estructuraJugador));

    setPuntaje(computadora, 0); //variable para acumular el puntaje de la computadora
    setPuntaje(J, 0); //variable para acumular el puntaje del jugador


    //CANTIDAD DE CARTONES:
    int cantcartones=0; //esta variable servira para limitar la cantidad de cartones
    while((cantcartones<1)||(cantcartones>3)){ //limito los cartones entre 1 y 3
        printf("\n-------------------------------------\n- Con cuantos cartones quiere jugar?- \n-------------------------------------\n\n\n"); //pregunto al usuario con cuantos cartones jugaria
        scanf("%d", &cantcartones); //el usuario ingresa la cantidad de cartones
        printf("\n\n");
        if((cantcartones<1)||(cantcartones>3)){ //me aseguro de que haya puesto una cantidad valida de cartones
            printf("Debe elegir entre 1 y 3 cartones.\n"); //indico que no se ingreso una cantidad validas de cartones
        }
    }
    //CARGA DE CARTONES
    for(int i=0; i<cantcartones; i++){ //for desde 0 a la cantidad de cartones que eligio el jugador
        printf("Carton numero %d :\n", i+1);
        printf("\n1) Ingresar carton por teclado. \n2) Cargar carton aleatoriamente.\n\n"); //muestro el menu para elegir como cargar los cartones
        int menucartones=0; //inicializo una variable para el menu en 0 ya que trabajaremos con 1 y 2
        scanf("%d", &menucartones); // Leo la opcion elegida por usuario
        printf("\n\n");

        while((menucartones<1)||(menucartones>2)){     //Condicional en caso de que usuario elija opcion incorrecta
        printf("\n\n ERROR! Elija una opcion correcta!\n\n");//Condicional en caso de que usuario elija opcion incorrecta
        scanf("%d", &menucartones);}  //Vuelvo a pedir opcion de usuario hasta que me tipee una correcta

        switch(menucartones){
            case 1: cargarmatrizporteclado(J->C[i]); break; //se ingresa el carton por teclado
            case 2: cargarmatrizaleatoria(J->C[i]); break; //se ingresa el carton aleatoriamente
        }

        cargarmatrizaleatoria(computadora->C[i]); //cargo aleatoriamente los cartones de la computadora

    }

    printf("\nSus cartones:\n\n"); //cartones del jugador
    for(int i=0; i<cantcartones; i++){ //for para mostrar todos los cartones
        printf("\n--J1---Carton %d---\n",i+1);
        mostrarmatriz(J->C[i]);
         printf("------------------\n");
    }

    printf("\nCartones del contrincante:\n"); //cartones de la computadora
        for(int i=0; i<cantcartones; i++){ //for para mostrar todos los cartones
             printf("\n--PC---Carton %d---\n",i+1);
            mostrarmatriz(computadora->C[i]);
             printf("------------------\n");
    }

    //GENERACION DE BOLILLAS
    int maxbolillas=90;
    int bolillas[maxbolillas];
    cargarvectoraleatorio(bolillas, maxbolillas);
    //(genero el vector de bolillas aleatoriamente y luego las uso de 0 a 90 ya desordenadas).

    //JUEGO
    int pulsador=0; //variable con el unico objetivo de accionar el juego cuando se pulsa 1
    int bonificacion=0; //variable para almacenar temporalmente los puntos ganados en las funciones y pasarlas a los acumuladores

    //Limitadores(para que se pueda cantar linea, columna o bingo solo 1 vez):
    int LimitarLinea=0;
    int LimitarColumna=0;
    int LimitarBingo=0;

    for(int i=0; i<maxbolillas; i++){ //for para trabajar con las bolillas 1 por 1
        printf("\n1) GENERAR BOLILLA.\n");
        scanf("%d", &pulsador);
        while(pulsador!=1){ //condicion para que se ingrese si o si 1
        //uso un while para que no se pase el turno
            printf("Usted ingreso una opcion no valida."); //de no ser asi lo indico
            printf("\n1) GENERAR BOLILLA.\n"); //pido que se ingrese 1 de nuevo
            scanf("%d", &pulsador);
        }
        if(pulsador==1){
            printf("\n---->  *( %d )*\n\n", bolillas[i]); //indico el numero de bolilla que salio
            printf("Sus cartones:\n"); //cartones del jugador

            //Marco y muestro los cartones:
            for(int k=0; k<cantcartones; k++){ //for para mostrar todos los cartones
            printf("\n--J1---Carton %d---\n",k+1);
                MarcarCarton(J->C[k], bolillas[i]);
                //mostrarmatriz(J->C[k]);

                printf("------------------\n");
            }

            //Proceso para que el jugador cante linea - columna - bingo:
            //IMPORTANTE: se suma el puntaje apenas se canta(linea, columna, bingo) y no abajo del for por que sino las funciones se pisan entre ellas al iniciarse en 0
            for(int k=0; k<cantcartones; k++){ //for para trabajar con todos los cartones
                if(LimitarLinea==0){ //si el limitador vale 0, se compara esperando que se cante Linea
                    bonificacion = CantarLinea(J->C[k]); //Si se canta linea la bonificacion pasa a valer 20
                    J->puntaje = J->puntaje + bonificacion; //Se le suma la bonificacion al puntaje
                    if(bonificacion==20){ //Si la bonificacion cambia (por haberse cantado Linea)
                        LimitarLinea=1; //El limitador pasa a valer 1 para que no se repita el proceso
                    }
                }
                if(LimitarColumna==0){ //si el limitador vale 0, se compara esperando que se cante Columna
                    bonificacion = CantarColumna(J->C[k]); //Si se canta columna la bonificacion pasa a valer 10
                    J->puntaje = J->puntaje + bonificacion; //Se le suma la bonificacion al puntaje
                    if(bonificacion==10){ //Si la bonificacion cambia (por haberse cantado Columna)
                        LimitarColumna=1; //El limitador pasa a valer 1 para que no se repita el proceso
                    }
                }
                if(LimitarBingo==0){ //si el limitador vale 0, se compara esperando que se cante Bingo
                    bonificacion = CantarBingo(J->C[k]); //Si se canta bingo la bonificacion pasa a valer 70
                    J->puntaje = J->puntaje + bonificacion; //Se le suma la bonificacion al puntaje
                    if(bonificacion==70){ //Si la bonificacion cambia (por haberse cantado Bingo)
                        LimitarBingo=1; //El limitador pasa a valer 1 para que no se repita el proceso
                   int ContadorFlag = i;
                   printf("\nawdawda--%d\n",ContadorFlag);
                    J->puntaje = MultiplicarPuntaje(J->puntaje,ContadorFlag);
                   i=maxbolillas;



                    }
                }
            }

            //Proceso para que la computadora cante linea - columna - bingo:
            //IMPORTANTE: se suma el puntaje apenas se canta(linea, columna, bingo) y no abajo del for por que sino las funciones se pisan entre ellas al iniciarse en 0
            printf("Cartones del contrincante:\n"); //cartones de la computadora
            for(int k=0; k<cantcartones; k++){ //for para mostrar todos los cartones
                printf("\n--PC---Carton %d---\n",k+1);
                MarcarCarton(computadora->C[k], bolillas[i]);
                mostrarmatriz(computadora->C[k]);
                printf("------------------\n");
            }

            for(int k=0; k<cantcartones; k++){ //for para trabajar con todos los cartones
                if(LimitarLinea==0){ //si el limitador vale 0, se compara esperando que se cante Linea
                    bonificacion = CantarLinea(computadora->C[k]); //Si se canta linea la bonificacion pasa a valer 20
                    computadora->puntaje = computadora->puntaje + bonificacion; //Se le suma la bonificacion al puntaje
                    if(bonificacion==20){ //Si la bonificacion cambia (por haberse cantado Linea)
                        LimitarLinea=1; //El limitador pasa a valer 1 para que no se repita el proceso
                    }
                }
                if(LimitarColumna==0){ //si el limitador vale 0, se compara esperando que se cante Columna
                    bonificacion = CantarColumna(computadora->C[k]); //Si se canta columna la bonificacion pasa a valer 10
                    computadora->puntaje = computadora->puntaje + bonificacion; //Se le suma la bonificacion al puntaje
                    if(bonificacion==10){ //Si la bonificacion cambia (por haberse cantado Columna)
                        LimitarColumna=1; //El limitador pasa a valer 1 para que no se repita el proceso
                    }
                }
                if(LimitarBingo==0){ //si el limitador vale 0, se compara esperando que se cante Bingo
                    bonificacion = CantarBingo(computadora->C[k]); //Si se canta bingo la bonificacion pasa a valer 70
                    computadora->puntaje = computadora->puntaje + bonificacion; //Se le suma la bonificacion al puntaje
                    if(bonificacion==70){ //Si la bonificacion cambia (por haberse cantado Bingo)
                        LimitarBingo=1; //El limitador pasa a valer 1 para que no se repita el proceso
                        int ContadorFlag = i;
                   printf("\nSe sacaron ---->%d Bolillas!\n",ContadorFlag);
                     computadora->puntaje = MultiplicarPuntaje(computadora->puntaje,ContadorFlag);
                     i=maxbolillas;
                    }
                }
            }

        //Muestro los puntajes ronda por ronda:
        printf("\nSu puntaje: %d\n", J->puntaje); //Jugador
        printf("\nPuntaje del contrincante: %d\n", computadora->puntaje); //Computadora
        }
        pulsador=0;//Cuando se termina el turno el pulsador vuelve a ser 0 para tener que volver a presionar 1
    }
    printf("\n\n*************\n\n\n");
}

