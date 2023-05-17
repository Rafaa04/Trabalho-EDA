#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Gestor.h"
#include "Mobilidade.h"
#include "Struct Grafos.h"

// Criar um novo vértice
// Devolve 1 em caso de sucesso ou 0 caso contrário
int criarVertice(Grafo* g, int novoid)
{
	Grafo novo = malloc(sizeof(struct registo1));
	if (novo != NULL)
	{
		novo->id = novoid;
		novo->meios = NULL;
		novo->Cliente = NULL;
		novo->adjacentes = NULL;
		novo->seguinte = *g;
		*g = novo;
	}
	else return(0);
}

// Devolve 1 se o vertice existe no grafo ou 0 caso contrário
int existeVertice(Grafo g, int id)
{
	while (g != NULL)
	{
		if (g->id == id) return(1);
		else g = g->seguinte;
	}
	return(0);
}

// Criar uma nova aresta
// Devolve 1 em caso de sucesso ou 0 caso contrário
int criarAresta(Grafo g, char vOrigem, char vDestino, int peso)
{
	Adjacente novo;
	if (existeVertice(g, vOrigem) && existeVertice(g, vDestino))
	{
		while (g != NULL) 
		{
			if (g->id == vOrigem) 
			{
				novo = malloc(sizeof(struct registo2));
				if (novo != NULL)
				{
					novo->id = vDestino;
					novo->peso = peso;
					novo->seguinte = g->adjacentes;
					g->adjacentes = novo;
					return(1);
				}
				else return(0);
			}
			else
			{
				g = g->seguinte;
			}
		}
	}
	else return(0);
}

// Listar os vértices adjacentes 
void listarAdjacentes(Grafo g, int id)
{
	Adjacente aux;
	if (existeVertice(g, id))
	{
		while (g->id == id) g = g->seguinte;
		aux = g->adjacentes;
		while (aux != NULL)
		{
			printf("Adjacente:%s;Peso:%.2f\n", aux->id, aux->peso);
			aux = aux->seguinte;
		}
	}
}

// Inserir meio de transporte na localização com geocódigo passado por parâmetro
// Devolve 1 em caso de sucesso ou 0 caso contrário
int inserirMeio(Grafo g, int id , int codigoMeio)
{
	while (g != NULL)
	{
		if (id == id)
		{
			Meios novo = malloc(sizeof(struct registo3));
			novo->codigo = codigoMeio;
			novo->seguinte = g->meios;
			g->meios = novo;
			return(1);
		}
		else {
			g = g->seguinte;
		}
	}
}

// Listar os códigos dos meios de transporte presente numa determinada localização passada por parâmetro
void listarMeios(Grafo g, int id)
{
		while (g != NULL)
		{
			if (g->id == id)
			{
				Meios aux = g->meios;
				if (aux == NULL)
				{
					printf("Sem meios de transporte!\n");
				}
				else
				{
					while (aux != NULL)
					{
						printf("Codigo meio: %d\n", aux->codigo);
						aux = aux->seguinte;
					}
				}
			}
			g = g->seguinte;
		}
}

void gravarGrafo(Grafo g) {
	int a = 0, b = 0;
	FILE* fp;
	fp = fopen("Grafo.txt", "w");
	if (fp != NULL)
	{
		while (g != NULL)
		{
			Adjacente adjacentes = g->adjacentes;
			if (adjacentes == NULL)
			{
				fprintf(fp, "%d;%d;%d", g->id, a, b);
			}
			else
			{
				while (adjacentes != NULL)
				{
					fprintf(fp, "%d;%d;%d", adjacentes->id, adjacentes->peso);
					adjacentes = adjacentes->seguinte;
				}
			}
			g = g->seguinte;
		}
	}
}