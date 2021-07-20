#include <stdio.h>
#include <stdlib.h> 

#include "PriorityQueue.h"

// crea una cola vacia
void create(PriorityQueue * q){
  (*q) = NULL;
   
}// Livera espacio en memoria de la cola
void destroy(PriorityQueue * q){
	if((*q) == NULL) return;
	else{
	PriorityQueue aux = (*q);
	(*q) = (*q)->post;
	free(aux);
	destroy(q);
	}
}

//pone un elemento ordenado en la cola
void enqueue(PriorityQueue * q,int val){
	if((*q)==NULL){
		(*q) = (PriorityQueue)malloc(sizeof(struct TNode));
		(*q)->value = val;
		(*q)->post = NULL;
		
	}else{
		PriorityQueue fst =(*q);
		PriorityQueue prev = NULL;
		while((*q)!=NULL&&(*q)->value<val){
		prev = (*q);
		(*q)=(*q)->post;

		}if(*q==NULL){
		(*q) = (PriorityQueue)malloc(sizeof(struct TNode));
		(*q)->value=val;
		(*q)->post = NULL;
		prev->post=(*q);
		(*q) =fst;
		}else if ((*q)->value>=val){// el elemento dado al 			principio de la cola
		if(prev == NULL){// Comprovamos que el priemr elemento sea 			mayor que el dado
		prev= (PriorityQueue)malloc(sizeof(struct TNode));
		prev->value=val;
		prev->post =(*q);
		(*q) =prev;
		}else{
		PriorityQueue aux;//aux entre prev->value y (*q)->value
		aux = (PriorityQueue) malloc(sizeof(struct TNode));
		aux->value = val;
		prev->post = aux;
		aux->post = (*q);
		(*q) = fst;
		
		}
		}
	}

}

// saca el primer elemento de la cola
void dequeue(PriorityQueue * q){
	if((*q)==NULL)
	printf ("No se puede eliminar elementos; cola vacia");
	else{
	PriorityQueue aux= (*q);
	(*q) =(*q)->post;
	free(aux);
	}
}

//Devuelve el primer elemento de la cola
int first(PriorityQueue q){
	if(q == NULL)	
	printf ("LA cola esta vacia\n");
	else{ 
		return q->value;
		
	}
}

//devuleve el tamaño de la cola
int size(PriorityQueue q){
	if(q == NULL) return 0;
	else{ 
	return 1+size(q->post);
	
	}
}

//Devuelve 1 si esta vacia y 0 si tiene elementos
int isEmpty(PriorityQueue q){ 
	if(q==NULL)return 1;
	else{
	return 0;
	}
}

//muesta el contenido de la cola
void show(PriorityQueue q){
	if(q==NULL)
	printf("NULL\n");
	else {
	printf("%i->",q->value);
	show(q->post);
	}
	
}

