
#include <stdio.h>
#include <stdlib.h> 

typedef struct TNode * PriorityQueue;
struct TNode {
int value;
 PriorityQueue post;
};


void create(PriorityQueue * q);// crea una cola vacia
void destroy(PriorityQueue * q);// Livera espacio en memoria de la cola
void enqueue(PriorityQueue * q,int val);//pone un elemento ordenado en la cola
void dequeue(PriorityQueue * q);// saca el primer elemento de la cola
int first(PriorityQueue q);//Devuelve el primer elemento de la cola
int size(PriorityQueue q); //devuleve el tamaño de la cola
int isEmpty(PriorityQueue q);//Devuelve 1 si esta vacia y 0 si tiene elementos
void show(PriorityQueue q); //muesta el contenido de la cola

