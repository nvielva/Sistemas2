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
        lista->cola = lista->cabeza;
    }
    else
    {
        Node* actual;
        
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

void recursion_destruir(ListaLigada* list, Node* nodo)
{   Node* temp;
    while(nodo != NULL){
        temp = nodo;
        nodo = nodo->next;
        free(temp);
    }
    list->cabeza = NULL;
    list->cola = NULL;
}

void listaligada_destroy(ListaLigada* list)
{
  recursion_destruir(list, list->cabeza);
  free(list);
  
  
}

void listaligada_union(ListaLigada* lista1, ListaLigada* lista2)
{
    
    
}




