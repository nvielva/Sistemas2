/* Módulo estándar de Input / Output */
#include <stdio.h>
/* Módulo estándar de C, para uso de memoria en el Heap*/
#include <stdlib.h>
/* Módulo estándar de números enteros */
#include <stdint.h>
#include <ctype.h>
#include <pthread.h>

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
	{	printf("Palabra: ");
		printf("%s",lista_w->palabras[palabra]);
		
		printf("\n");
		
		
		
	}
	return lista_w;

}

void* map_thread(void* args){
	ListaPalabras* palabras = (ListaPalabras*) args;
	
	
	ListaLigada* lista_map;
	lista_map = listaligada_init();
	for (int i = 0; i < palabras->largo; i++)
	{
		//printf("Palabra: %s", palabras->palabras[i]);
		
	}
	return lista_map;
	

	
	
}


int main(int argument_count, char** arguments) {

	char** lectura = calloc(300, sizeof(char*));

	for(int row = 0; row < 300; row++)
	{
		lectura[row] = calloc(45, sizeof(char));


	}
	char * filename = arguments[1];
	FILE * file = fopen(filename, "r");
	if (file == NULL) {
		return 1;
	}
	char c;
	int count = 0;
	int contador = 0;
	int thread_number = 0;
	int palabra;
	palabra = 0;
	int letra = 0;
	while((c = fgetc(file)) != EOF)
	{	char* word[45];
		if (palabra == 300)
		{  
			ListaPalabras* words;
			printf("TOOOOOOOOOOOoco");
			words = lista_palabras_init(lectura, palabra);
			/*CREAR THREAD */
			//pthread_t my_thread[thread_number];
			//pthread_create(&my_thread[thread_number], NULL, map_thread, (void*)&words);
			palabra = 0;
			thread_number+=1;
			for(int palab = 0; palab < 300; palab++)
			{
				
				lectura[palab] = "";


						
			}
			
		}
		
		if(c == ' ' || c == '\n')
		{
			printf("\n");
			++count;
			palabra+=1;
			letra = 0;
			
		}
		else
		{	
			lectura[palabra][letra] = c;
			printf("%c", c);
			letra+=1;
		}
	}
	if (contador > 0)
	{
		/* CREAR THREAD */
		//pthread_t my_thread;
		//pthread_create(&my_thread, NULL, map_thread(lectura, contador), NULL);
		contador = 0;
	}
	
	fclose(file);
 
	printf("Archivo tiene %i palabras \n.", count);



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












