/* Módulo estándar de Input / Output */
#include <stdio.h>
/* Módulo estándar de C, para uso de memoria en el Heap*/
#include <stdlib.h>
/* Módulo estándar de números enteros */
#include <stdint.h>
#include <ctype.h>
#include <pthread.h>
#include <string.h>

#include "../lista_ligada/lista_ligada.h"

typedef struct lista_palabras
{   int largo;
    char** palabras;
} ListaPalabras;

ListaPalabras* lista_palabras_init(char** lista, int largo)
{
	ListaPalabras* lista_w = malloc(sizeof(ListaPalabras));
	
	lista_w ->palabras = lista;
	lista_w ->largo = largo;
	printf("-------------------llegueueeueueue\n");
	for (int palabra = 0; palabra < 300; palabra++)
	{	printf("Palabra numero %i: ", palabra);
		printf("%s",lista_w->palabras[palabra]);
		
		printf("\n");
		
		
		
	}
	return lista_w;

}

void** map_thread(void** args){

	char** palabras = calloc(300, sizeof(char*));

	for(int row = 0; row < 300; row++)
	{
		palabras[row] = calloc(45, sizeof(char));


	}
	for(int row = 0; row < 300; row++)
	{	
		char* str = args[row];
		for(int i = 0; str[i]; i++){
		str[i] = tolower(str[i]);
		}
		strcpy(palabras[row], str);
	}
	
	ListaLigada* lista_map;
	lista_map = listaligada_init();
	int numero = 0 ;
	while (numero <300)
	{	
		listaligada_append(lista_map, palabras[numero]);
		numero+=1;
	}
	Node* actual;
	actual = lista_map->cabeza;
	int num = 0;
	while (1)
	{	if(actual == lista_map->cola)
		{
			printf("Palabra %i: %s // Reps: %i\n",num, lista_map->cola->palabra, lista_map->cola->value);
			break;
		}
		printf("Palabra %i: %s // Reps: %i\n",num, actual->palabra, actual->value);
		actual = actual->next;
		num+=1;
	}
	
	
	pthread_exit(lista_map);
	

	
	
}


int main(int argument_count, char** arguments) {

	char** lectura = calloc(300, sizeof(char*));

	for(int row = 0; row < 300; row++)
	{
		lectura[row] = calloc(45, sizeof(char));


	}

	char** asignado = calloc(300, sizeof(char*));

	for(int row = 0; row < 300; row++)
	{
		asignado[row] = calloc(45, sizeof(char));


	}

	char * filename = arguments[1];
	FILE * file = fopen(filename, "r");
	if (file == NULL) {
		return 1;
	}
	char* c[45];
	int thread_number = 0;
	int letra = 0;
	int wrd;
	pthread_t my_thread[200];
	while(fscanf(file, "%s", c) != EOF)
	{	
		if(wrd == 300){

			for (int i = 0; i < 300; i++)
			{	
				strcpy(asignado[i],lectura[i]);
				
			}
			
			//words = lista_palabras_init(lectura, 300);
			pthread_t my_thread[thread_number];
			pthread_create(&my_thread[thread_number], NULL, map_thread, asignado);
			thread_number+=1;
			wrd = 0;
			
			
			
			

		}
		
	
		
		strcpy(lectura[wrd], c);
		
		wrd+=1;
		
	}

	for (int i = 0; i < thread_number; i++)
	{
		ListaLigada* return_val;
		pthread_join(my_thread[i], &return_val);
		printf("padre: %s", return_val->cabeza->palabra);
	}
	
	
	
	
	fclose(file);
 




	/*char* lectura;
	lectura = malloc( 300 * sizeof(char))

	char* filename = arguments[1];
	char str[256];
	FILE* file = fopen(filename, "r");

	while (fgets(str, 256, file) != NULL){
        printf("%s\n", str);

	}
    fclose(file);*/























	/*ListaLigada* lista;
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
	

	
	listaligada_destroy(lista);*/

	

	return 0;
}












