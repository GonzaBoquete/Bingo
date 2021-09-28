#ifndef CARTONES_H_INCLUDED
#define CARTONES_H_INCLUDED

#define COLUMNAS 5
#define RENGLONES 3

/////////TDA//////////
struct estructuraCartones;

typedef struct estructuraCartones * Cartones;

//constructor
Cartones crearCarton();
//gets
int getCarton(Cartones C, int columna, int renglon);

//sets
void setCarton(Cartones C, int nuevoNumero, int columna, int renglon);

//destructor
void destruirCarton(Cartones C);


#endif // CARTONES_H_INCLUDED
