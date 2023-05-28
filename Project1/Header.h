#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adjacente {
    int id_vertice2;
    float peso;
    struct adjacente* proximo;
} Adjacente;

typedef struct grafo {
    int id_vertice;
    Adjacente* adjacentes;
    struct grafo* proximo;
} Grafo;

Grafo* getVerticePorId(Grafo* g, int id);
void listarAdjacentesPorRaio(Grafo* g, int id, float raio);

