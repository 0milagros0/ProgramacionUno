//3 modos de recorrido:inorden,preorden y posorden
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
	int dato;
	struct Nodo *izq;
	struct Nodo *der;
};
struct Nodo* crearNodo(int valor) {
	struct Nodo* nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
	
	nuevo->dato = valor;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	
	return nuevo;
}
struct Nodo* insertar(struct Nodo* raiz, int valor) {
	
	if (raiz == NULL)
		return crearNodo(valor);
	
	if (valor < raiz->dato)
		raiz->izq = insertar(raiz->izq, valor);
	else
		raiz->der = insertar(raiz->der, valor);
	
	return raiz;
}
void inorden(struct Nodo* raiz) {
	
	if (raiz != NULL) {
		
		inorden(raiz->izq);
		
		printf("%d ", raiz->dato);
		
		inorden(raiz->der);
	}
}

void preOrden(struct Nodo* raiz) {
	if (raiz != NULL) {
		printf("%d ", raiz->dato);
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}

void postOrden(struct Nodo* raiz) {
	if (raiz != NULL) {
		
		postOrden(raiz->izq);
		postOrden(raiz->der);
		printf("%d ", raiz->dato);
	}
}
int main() {
	
	struct Nodo* raiz = NULL;
	
	int valor;
	int cantidad;

	printf("Ingresar cantidad de nodos: ");
	scanf("%d", &cantidad);
	
	for(int i = 0; i < cantidad; i++) {
		
		printf("Ingrese un valor: ");
		scanf("%d", &valor);
		
		raiz = insertar(raiz, valor);
	}

	printf("\nRecorrido Inorden: ");
	inorden(raiz);
	printf("\nReocrrido Preorden; ");
	preOrden(raiz);
	printf("\nRecorrido Posorden: ");
	postOrden(raiz);
	
	
	return 0;
}
