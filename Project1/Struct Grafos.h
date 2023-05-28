#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct registo4
{
	int codigo;
	struct registo4* seguinte;
} *Clientes;

typedef struct registo3
{
	int codigoMeio;
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
	char geocódigo[50];
    Adjacente adjacentes;
	Meios meios;
	Meios aux;
	Clientes Cliente;
	struct registo1* seguinte;
} *Grafo;


int criarVertice(Grafo* g, int novoid);
int criarAresta(Grafo g, char vOrigem, char vDestino, int peso);
int existeVertice(Grafo g, int id);
void listarAdjacentes(Grafo g, int id);
int InserirMeio(Grafo g, Mobilidade* inicio, int id, int codigoMeio);
void listarMeios(Grafo g, int id);
void ListarClientes(Grafo g, int id);
int InserirCliente(Grafo g, Cliente* inicio, int id, int codigonif);
void gravarGrafo(Grafo g);
Grafo* lerdadosGrafo(Grafo g);
char RuasG(char localização[], int r);
void gravarGrafoVertice(Grafo g);
Grafo lerdadosGrafoVertice(Grafo* g, Mobilidade* inicio, Cliente* c);
void ListarporDistancia(Grafo* g, int id);