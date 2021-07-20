#include <stdio.h>
#include <stdlib.h> 


#include "PriorityQueue.h"
int main(){
PriorityQueue q;
// creamos la cola
create(&q);
// Hacemos varias entradas de prueba
enqueue(&q,3);
enqueue(&q,2);
enqueue(&q,51);
enqueue(&q,8);
enqueue(&q,9);
// Mstramos la lista sin ordenar
printf("Lista:");
show(q);
printf("Primer elemento es: %i\n",first(q));
printf("Tamaño de la lista es: %i\n",size(q));
printf("Eliminamos el primer elemento de la lista: %i\n",first(q));
dequeue(&q);

///Mostramos la lista ordenada
printf("\nLista:");
show(q);
printf("Tamaño de la lista es: %i\n",size(q));
return 0;

}
