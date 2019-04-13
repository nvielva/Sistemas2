
#pragma once

//primero creamos nodo

typedef struct Node
{   int value;
    char* palabra;
    struct Node *next;
} Node;

typedef struct lista_ligada
{
    Node* cabeza;
    int repeticiones;
    Node* cola;
    
} ListaLigada;

//crear lista, retorna lista (por eso es puntero)
ListaLigada* listaligada_init();

//agregar elemento, de no existir se agrega al final

void listaligada_append(ListaLigada* lista, char* palabra);

/** Libera todos los recursos asociados a la lista */
void listaligada_destroy(ListaLigada* lista);

/** Concatena la segunda lista a la primera lista */
void listaligada_union(ListaLigada* lista1, ListaLigada* lista2);

