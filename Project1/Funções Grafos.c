#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Gestor.h"
#include "Mobilidade.h"
#include "Struct Grafos.h"

// Criar um novo v�rtice
// Devolve 1 em caso de sucesso ou 0 caso contr�rio
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

// Devolve 1 se o vertice existe no grafo ou 0 caso contr�rio
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
// Devolve 1 em caso de sucesso ou 0 caso contr�rio
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

// Listar os v�rtices adjacentes 
void listarAdjacentes(Grafo g, int id)
{
	if (g == NULL)
	{
		printf("Grafo nao inicializado!\n");
		return;
	}
	while (g != NULL && g->id != id)
	{
		g = g->seguinte;
	}
	if (g == NULL)
	{
		printf("Verttice nao encontrado!\n");
		return;
	}
	if (g->adjacentes == NULL)
	{
		printf("Sem adjacentes!\n");
		return;
	}
	Adjacente aux = g->adjacentes;
	while (aux != NULL)
	{
		printf("Adjacente:%d;Peso:%d;\n", aux->id, aux->peso);
		aux = aux->seguinte;
	}
}

// Inserir meio de transporte na localiza��o com geoc�digo passado por par�metro
// Devolve 1 em caso de sucesso ou 0 caso contr�rio
int inserirMeio(Grafo g, int id, char geoc�digo[], int codigoMeio)
{
	Mobilidade* mobilidade;
	while (g != NULL)
	{
		if (g->id == id)
		{
			while (mobilidade != NULL)
			{
				if (strcmp(g->geoc�digo, mobilidade->localiza��o) == 0)
				{
					Meios novo = malloc(sizeof(struct registo3));
					novo->codigoMeio = codigoMeio;
					novo->seguinte = g->meios;
					g->meios = novo;
					return(1);
				}
				else
				{
					mobilidade = mobilidade->seguinte;
				}
			}
		}
		else 
		{
			g = g->seguinte;
		}
	}
	printf("O geocodigo do meio nao e o mesmo do vertice!");
}

// Listar os c�digos dos meios de transporte presente numa determinada localiza��o passada por par�metro
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
						printf("Codigo meio: %d\n", aux->codigoMeio);
						aux = aux->seguinte;
					}
				}
			}
			g = g->seguinte;
		}
}

void gravarGrafo(Grafo g) {
	Adjacente adjacentes;
	int a = 0, b = 0;
	FILE* fp;

	fp = fopen("Grafo.txt", "w");
	if (fp != NULL)
	{
		while (g != NULL)
		{
			adjacentes = g->adjacentes;
			if (adjacentes == NULL)
			{
				fprintf(fp, "%d;%d;%d;\n", g->id, a, b);
			}
			else
			{
				while (adjacentes != NULL)
				{
					fprintf(fp, "%d;%d;%d;\n", g->id, adjacentes->id, adjacentes->peso);
					adjacentes = adjacentes->seguinte;
				}
			}
			g = g->seguinte;
		}
		fclose(fp);
	}
	else
	{
		printf("O ficheiro esta corrompido!\n");
	}
}
Grafo* lerdadosGrafo()
{
	FILE* fp;
	Grafo* grafo = NULL;

	fp = fopen("Grafo.txt", "r");
	int idI = 0, idF = 0, peso = 0;

	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%d;%d\n", &idI, &idF, &peso);
			if (idF == 0 && peso == 0) 
			{
				criarVertice(&grafo, idI);
			}
			else
			{
				criarVertice(&grafo, idI);
				criarVertice(&grafo, idF);
				criarAresta(grafo, idI, idF, peso);
			}
		}
		fclose(fp);
	}
	return(grafo);
}

char RuasG(char localiza��o[], int r)
{
	printf("Escolha um destes locais: ");
	printf("1 - Rua Jacinto Vieira;2 - Rua 8 de Setembro;3 - Rua de Mazag�o;4 - Rua do Miradouro;5 - Rua do Bairro;6 - Travessa das Glicinias");
	if (r == 1)
	{
		strcpy(localiza��o, "batem.soma.babados");
		return(localiza��o);
	}
	if (r == 2)
	{
		strcpy(localiza��o, "duelo.geada.tear");
		return(localiza��o);
	}
	if (r == 3)
	{
		strcpy(localiza��o, "inicio.d�vidas.festas");
		return(localiza��o);
	}
	if (r == 4)
	{
		strcpy(localiza��o, "bagre.enfim.noites");
		return(localiza��o);
	}
	if (r == 5)
	{
		strcpy(localiza��o, "cop�o.ganhar.tro�o");
		return(localiza��o);
	}
	if (r == 6)
	{
		strcpy(localiza��o, "farto.cheirosa.mentas");
		return(localiza��o);
	}
}
