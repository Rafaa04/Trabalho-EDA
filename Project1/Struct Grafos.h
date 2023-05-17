#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Representar um grafo orientado e pesado através da definição de 
// uma lista ligada de listas ligadas


typedef struct registo4
{
	int codigo;
	struct registo4* seguinte;
} *Clientes;

typedef struct registo3
{
	int codigo;
	struct registo3* seguinte;
} *Meios;

// Representação de um grafo orientado e pesado
typedef struct registo2
{
	int id;
	int peso;
	struct registo2* seguinte;
} *Adjacente;

typedef struct registo1
{
	int id;
    Adjacente adjacentes;
	Meios meios;
	Clientes Cliente;
	struct registo1* seguinte;
} *Grafo;

int criarVertice(Grafo* g, int novoid);
int criarAresta(Grafo g, char vOrigem, char vDestino, int peso);
int existeVertice(Grafo g, int id);
void listarAdjacentes(Grafo g, int id);
int inserirMeio(Grafo g, int id, int codigoMeio);
void listarMeios(Grafo g, int id);
int inserirCliente(Grafo g, int id, int codigonif);
void gravarGrafo(Grafo g);




