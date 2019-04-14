/* Módulo estándar de Input / Output */
#include <stdio.h>
/* Módulo estándar de C, para uso de memoria en el Heap*/
#include <stdlib.h>
/* Módulo estándar de números enteros */
#include <stdint.h>
#include <ctype.h>

#include "../lista_ligada/lista_ligada.h"


int main(int argument_count, char** arguments) {

	ListaLigada* lista;
	lista = listaligada_init();
	char* palabra = "hola";
	char* palabra1 = "hola";
	char* palabra2 = "hola";
	char* palabra3 = "chao";
	char* palabra4 = "hola";
	char* palabra5 = "chao";

	listaligada_append(lista, palabra);
	listaligada_append(lista, palabra1);
	listaligada_append(lista, palabra2);
	listaligada_append(lista, palabra3);
	listaligada_append(lista, palabra4);
	listaligada_append(lista, palabra5);

	Node* actual;
	actual = lista->cabeza;
	while (1)
	{	if(actual == lista->cola)
		{
			printf("Palabra: %s // Reps: %i\n", lista->cola->palabra, lista->cola->value);
			break;
		}
		printf("Palabra: %s // Reps: %i\n", actual->palabra, actual->value);
		actual = actual->next;
	}
	

	
	listaligada_destroy(lista);
	

	return 0;
}












