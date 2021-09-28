#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

///////////////TDA///////////////
struct estructuraJugador;

typedef struct estructuraJugador * Jugador;

//constructor
Jugador iniciarsesion();

//gets
char* getNombre(Jugador J);
char* getApellido(Jugador J);
int getDNI(Jugador J);
int getPuntaje(Jugador J);


//sets
void setNombre(Jugador J, char nuevoNombre[20]);
void setApellido(Jugador J, char nuevoApellido[20]);
void setDNI(Jugador J, int nuevoDNI);
void setPuntaje(Jugador J, int nuevoPuntaje);


//destructor
void destruirJugador(Jugador J);

///////////FUNCIONES//////////////
void MostrarInicio(Jugador J);

void opcionmenu1(Jugador J);

#endif // JUGADOR_H_INCLUDED
