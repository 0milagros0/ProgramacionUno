#include <stdio.h>
#include <stdlib.h>

//estructura del nodo
struct Nodo {
	int dato;
	struct Nodo *izq;
	struct Nodo *der;
};

//crea un nuevo nodo
struct Nodo* crearNodo(int valor) {
	struct Nodo* nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
	
	if (nuevo == NULL) {
		printf("error.\n");
		exit(1);
	}
	nuevo->dato = valor;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	
	return nuevo;
}

//Inserci�n recursiva en arbol binario
struct Nodo* insertar(struct Nodo* raiz, int valor) {
	
	if (raiz == NULL)
	return crearNodo(valor);
	if (valor < raiz->dato)
		raiz->izq = insertar(raiz->izq, valor);
	else
		raiz->der = insertar(raiz->der, valor);
	return raiz;
}
//Buscar un elemento en el �rbol
int BuscarArbol(struct Nodo* raiz, int valor) {
	
	if (raiz == NULL)
		return 0; // no encuentra
	if (raiz->dato == valor)
		return 1; //si encuentra
	if (valor < raiz->dato)
		return BuscarArbol(raiz->izq, valor);
	
	return BuscarArbol(raiz->der, valor);
}

int main() {
	
	struct Nodo* raiz = NULL;
	int valor;
	int cantidad;
	int buscado;
	
	printf("Cantidad de nodos: ");
	scanf("%d", &cantidad);
	
	for (int i = 0; i < cantidad; i++) {
		printf("Ingrese un valor: ");
		scanf("%d", &valor);
		
		raiz = insertar(raiz, valor);
	}
	
	printf("\nBusqueda de elemento\n");
	printf("ingrese el valor a buscar: ");
	scanf("%d", &buscado);
	
	if (BuscarArbol(raiz, buscado))
		printf(" %d se encuentra en el arbol.\n", buscado);
	else
		printf(" %d no se encuentra en el arbol.\n", buscado);

	return 0;
}
