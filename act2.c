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

//Inserci�n recursiva en arbol binario de b�squeda
struct Nodo* insertar(struct Nodo* raiz, int valor) {
	
	if (raiz == NULL)
		return crearNodo(valor);
	
	if (valor < raiz->dato)
		raiz->izq = insertar(raiz->izq, valor);
	else
		raiz->der = insertar(raiz->der, valor);
	
	return raiz;
}

// Recorrido Inorden
void inorden(struct Nodo* raiz) {
	if (raiz != NULL) {
		inorden(raiz->izq);
		printf("%d ", raiz->dato);
		inorden(raiz->der);
	}
}

// Recorrido Preorden
void preOrden(struct Nodo* raiz) {
	if (raiz != NULL) {
		printf("%d ", raiz->dato);
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}

// Recorrido Posorden
void postOrden(struct Nodo* raiz) {
	if (raiz != NULL) {
		postOrden(raiz->izq);
		postOrden(raiz->der);
		printf("%d ", raiz->dato);
	}
}

// Buscar un elemento en el �rbol
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
	int opcion;
	int buscado;
	
	printf("MENU ARBOLES\n");
	printf("1-Recorrido Inorden\n");
	printf("2-Recorrido Posorden\n");
	printf("3-Recorrido Preorden\n");
	printf("4-Buscar un elemento en el arbol\n");
	printf("Seleccione una opcion: ");
	scanf("%d", &opcion);
	
	printf("Cantidad de nodos: ");
	scanf("%d", &cantidad);
	
	for (int i = 0; i < cantidad; i++) {
		printf("Ingrese un valor: ");
		scanf("%d", &valor);
		
		raiz = insertar(raiz, valor);
	}
	
	switch (opcion) {
		
	case 1:
		printf("\nRecorrido InOrden: ");
		inorden(raiz);
		printf("\n");
		break;
		
	case 2:
		printf("\nRecorrido PosOrden: ");
		postOrden(raiz);
		printf("\n");
		break;
		
	case 3:
		printf("\nRecorrido PreOrden: ");
		preOrden(raiz);
		printf("\n");
		break;
		
	case 4:
		printf("\nBusqueda de elemento\n");
		printf("ingrese el valor a buscar: ");
		scanf("%d", &buscado);
		
		if (BuscarArbol(raiz, buscado))
			printf(" %d se encuentra en el arbol.\n", buscado);
		else
			printf(" %d no se encuentra en el arbol.\n", buscado);
		
		break;
		
	default:
		printf("error \n");
	}
	
	return 0;
}
