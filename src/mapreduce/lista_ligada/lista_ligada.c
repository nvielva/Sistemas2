// importo el archivo linkedlist.h
#include "lista_ligada.h"
// Libreria estandar de C
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


ListaLigada* listaligada_init()
{
    ListaLigada* lista = malloc(sizeof(ListaLigada));
    lista ->cabeza = NULL;
    lista ->cola = NULL;
    return lista;
}

void listaligada_append(ListaLigada* lista, char* palabra)
{   //CASO 1 ES LISTA ESTA VACIA
    int agregado = 0;
    if (lista->cabeza == NULL)
    {
        lista->cabeza = malloc(sizeof(Node));
        lista->cabeza->palabra = palabra;
        lista->cabeza->value = 1;
        lista->cabeza->next = NULL;
        //creamos la cola
        lista->cola = malloc(sizeof(Node));
        lista->cola->palabra = palabra;
        lista->cola->value = 1;
        lista->cola->next = NULL;
    }
    else
    {
        Node* actual;
        actual = malloc(sizeof(Node));
        actual = lista->cabeza;
        //VIAJAMOS POR LOS NODOS
        while (actual != NULL)
        {
            if (strcmp(actual->palabra, palabra) == 0)
            {   //AGREGAMOS UNIDAD EN PALABRA
                actual->value += 1;
                agregado = 1;
                break;
            }
            else
            {
                if (actual->next != NULL)
                {   
                    actual = actual->next;
                }
                else
                {
                    break;
                }
                
            }     
        }
        
        if (actual->next == NULL && agregado ==0)
        {   //AGREGAMOS PALABRA AL FINAL SI ESTA NO SE ENCONTRABA EN LA LISTA
            Node* nuevo = malloc(sizeof(Node));
            nuevo ->palabra = palabra;
            nuevo ->value = 1;
            nuevo->next = NULL;
            actual->next = nuevo;
            lista->cola = nuevo;
            lista->cola->next = NULL;
        }        
    }
    
    
}

void linkedlist_destroy(ListaLigada* list)
{Node* aux = NULL;
  aux= malloc(sizeof(Node));
  while (list->cabeza->next != NULL) {
    aux -> next = list->cabeza->next->next;
    free(list->cabeza->next);
    list->cabeza->next = aux->next;
  free(list->cabeza);
  free(list->cola);
  free(list);
  free(aux);
  }


