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

int existeVertice2(Grafo g, int id)
{
	int a = 1;
	while (g != NULL)
	{
		if (g->id == id)
		{
			a = 2;
			return(a);
		}
		else
		{
			g = g->seguinte;
		}
	}
	return(a);
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
		printf("Vertice nao encontrado!\n");
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
						printf("Codigo meio: %d\n", aux->codigoMeio);
						aux = aux->seguinte;
					}
				}
			}
			g = g->seguinte;
		}
}

void gravarGrafo(Grafo g) 
{
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
		printf("Ficheiro corrompido!\n");
	}
}
Grafo* lerdadosGrafo(Grafo g)
{
	FILE* fp;
	fp = fopen("Grafo.txt", "r");
	int idI = 0, idF = 0, peso = 0;
	char geocódigo[50];

	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%d;%d;\n", &idI, &idF, &peso);
			if (idF == 0 && peso == 0) 
			{
				if (existeVertice2(g, idI) == 1)
				{
					criarVertice(&g, idI, geocódigo);
				}
			}
			else
			{
				if (existeVertice2(g, idI) == 2)
				{
					if (existeVertice2(g, idF) == 2)
					{
						criarAresta(g, idI, idF, peso);
					}
					else
					{
						criarVertice(&g, idF, geocódigo);
						criarAresta(g, idI, idF, peso);
					}
				}
				else
				{
					criarVertice(&g, idI, geocódigo);
					criarVertice(&g, idF, geocódigo);
					criarAresta(g, idI, idF, peso);
				}
			}
		}
		fclose(fp);
		return(g);
	}
	else
	{
		printf("Ficheiro Corrompido!\n");
	}
}

char RuasG(char localização[], int r)
{
	printf("Escolha um destes locais: ");
	printf("1 - Rua Jacinto Vieira;2 - Rua 8 de Setembro;3 - Rua de Mazagão;4 - Rua do Miradouro;5 - Rua do Bairro;6 - Travessa das Glicinias");
	if (r == 1)
	{
		strcpy(localização, "batem.soma.babados");
		return(localização);
	}
	if (r == 2)
	{
		strcpy(localização, "duelo.geada.tear");
		return(localização);
	}
	if (r == 3)
	{
		strcpy(localização, "inicio.dívidas.festas");
		return(localização);
	}
	if (r == 4)
	{
		strcpy(localização, "bagre.enfim.noites");
		return(localização);
	}
	if (r == 5)
	{
		strcpy(localização, "copão.ganhar.troço");
		return(localização);
	}
	if (r == 6)
	{
		strcpy(localização, "farto.cheirosa.mentas");
		return(localização);
	}
}
int InserirMeio(Grafo g, Mobilidade* inicio, int id, int codigoMeio)
{
	Mobilidade* mobilidade = inicio;
	while (g != NULL)
	{
		if (g->id == id)
		{
		   Meios novo = malloc(sizeof(struct registo3));
		   novo->codigoMeio = codigoMeio;
		   novo->seguinte = g->meios;
	       g->meios = novo;
		   return(1);
		}
		else
		{
			g = g->seguinte;
		}
	}
}
int InserirCliente(Grafo g, Cliente* inicio, int id, int codigonif)
{
	Cliente* cliente = inicio;
	while (g != NULL)
	{
		if (g->id == id)
		{
			while (cliente != NULL)
			{
				Clientes novo = malloc(sizeof(struct registo4));
				novo->codigo = codigonif;
				novo->seguinte = g->Cliente;
				g->Cliente = novo;
				return(1);
			}
		}
		else
		{
			g = g->seguinte;
		}
	}
}

void ListarMeios(Grafo g, int id)
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
					printf("\nCodigo do meio atribuido: %d\n", aux->codigoMeio);
					aux = aux->seguinte;
				}
			}
		}
		g = g->seguinte;
	}
}
void ListarClientes(Grafo g, int id)
{
	while (g != NULL)
	{
		if (g->id == id)
		{
			Clientes aux = g->Cliente;
			if (aux == NULL)
			{
				printf("Sem clientes\n");
			}
			else
			{
				while (aux != NULL)
				{
					printf("NIF do Cliente: %d\n", aux->codigo);
					aux = aux->seguinte;
				}
			}
		}
		g = g->seguinte;
	}
}
void gravarGrafoVertice(Grafo g)
{
	Meios meios;
	Clientes clientes;
	FILE* fp;

	int diff = 0;
	fp = fopen("GrafoVertice.txt", "w");


	if (fp != NULL)
	{
		while (g != NULL)
		{
			meios = g->meios;
			while (meios != NULL)
			{
				diff = 111;
				fprintf(fp, "%d;%d;%d\n", g->id, meios->codigoMeio, diff);
				meios = meios->seguinte;
			}
			clientes = g->Cliente;
			while (clientes != NULL)
			{
				diff = 112;
				fprintf(fp, "%d;%d;%d\n", g->id, clientes->codigo, diff);
				clientes = clientes->seguinte;
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

Grafo lerdadosGrafoVertice(Grafo g, Mobilidade* inicio, Cliente* c)
{
	FILE* fp;
	Mobilidade* meio = inicio;
	Cliente* cliente = c;
	fp = fopen("GrafoVertice.txt", "r");

	int id1 = 0, id2 = 0, diff = 0;
	char geo[50];
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%d;%d\n", &id1, &id2, &diff);
			if (diff == 111)
			{
				InserirMeio(g, meio, id1, id2);
			}
			else if (diff == 112)
			{
				InserirCliente(g, cliente, id1, id2);
			}
		}
		fclose(fp);
		return(g);
	}
	else
	{
		printf("O ficheiro esta corrompido!");
	}
}
