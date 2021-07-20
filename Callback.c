#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user
{
  char username[100];
  int  id;
  int  register_year;
};

struct user temporal;
struct user server[]={
  "jesse",2312,2021,
  "annk",4331,2021,
  "oroboros",3952,2017,
  "dokuro",4316,2019,
  "kkjus",5332,2011,
  "marvest",9912,2010,
  "eillek",1092,2020,
  "tuomas",1292,2015,
  "marko",4131,2016,
  "tarja",1314,2014
};

void verLista(){
 
    int i;
    for (i = 0; i < 10; i++)
    {
    struct user personaActual = server[i];
    printf("Nombre: %s. ID: %i. Fecha de registro: %i\n", 		personaActual.username, personaActual.id, personaActual.register_year);
    }
}

//Metos que ordena por ID
void ordeId()
{

    int x;
    for (x = 0; x < 9; x++)
    {
        int indiceActual;
        for (indiceActual = 0; indiceActual < 9;
             indiceActual++)
        {
            int indiceSiguienteElemento = indiceActual + 1;

  // Ordenar por id, de manera descendente 
   if (server[indiceActual].id < server[indiceSiguienteElemento].id)
            {
    //Intercambiar la actual en la temporal
     memcpy(&temporal, &server[indiceActual], sizeof(struct user));
  // Movemos el actual al siguiente elemento
    memcpy(&server[indiceActual], &server[indiceSiguienteElemento], sizeof(struct user));
 //y en el sigueinte elemento lo que habia en el actual pero ahora esta en temporal
     memcpy(&server[indiceSiguienteElemento], &temporal, sizeof(struct user));
            }
        }
    }
}

// Metodo que ordena por fecha de registro
void ordenFechaRegistro()
{

    int x;
    for (x = 0; x < 9; x++)
    {
        int indiceActual;
        for (indiceActual = 0; indiceActual < 9;
             indiceActual++)
        {
        int indiceSiguienteElemento = indiceActual + 1;

  // Ordenar por fecha, de manera descendente 
   if (server[indiceActual].register_year < server[indiceSiguienteElemento].register_year)
            {
  // Intercambiar la actual en la temporal
  memcpy(&temporal, &server[indiceActual], sizeof(struct user));
  // Movemos el actual al siguiente elemento
  memcpy(&server[indiceActual], &server[indiceSiguienteElemento], sizeof(struct user));
  //y en el sigueinte elemento lo que habia en el actual pero ahora esta en temporal
  memcpy(&server[indiceSiguienteElemento], &temporal, sizeof(struct user));
            }
        }
    }
}
// Metodo que ordena alfabeicamente
void ordenPorNombre()
{

    int x;
   
    
    for (x = 0; x < 9; x++)
    {
            int indiceActual;
        for (indiceActual = 0; indiceActual < 9;
             indiceActual++)
        {
            int indiceSiguienteElemento = indiceActual + 1;

  //si la cadena es mayor  (alfabeticaente) intercambiamos
	if (strcmp(server[indiceActual].username,server[indiceSiguienteElemento].username)>0)
            {
  // Intercambiar la actual en la temporal
  memcpy(&temporal, &server[indiceActual], sizeof(struct user));
  // Movemos el actual al siguiente elemento
  memcpy(&server[indiceActual], &server[indiceSiguienteElemento], sizeof(struct user));
  //y en el sigueinte elemento lo que habia en el actual pero ahora esta en temporal
memcpy(&server[indiceSiguienteElemento], &temporal, sizeof(struct user));
            }
        }
    }
}

/// CABEZA DEL MAIN---------------------------
int main(void)
{
// Recorrer antes de ordenar
printf("Lista original\n");
    verLista();
    
  // llamamos al metodo ordenar por nombre
   ordenPorNombre();
  // Recorrer después deordenar por nombre
  printf("Despues de ordenar por nombre\n");
   verLista();
 
  // llamamos al metodo para ordenar por ID  
   ordeId();
// Recorrer después deordenar por ID
printf("Despues de ordenar por ID\n");
    verLista();
    
 // llamamos al metodo ordenFechaRegistro
   ordenFechaRegistro();
    // Recorrer después deordenar por frecha de registro
printf("Despues de ordenar por fecha de registro\n");
   verLista();
    
   
       
return 0;
}
//fin del main------------


