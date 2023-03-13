#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct cliente
{
	char username[50];
	char password[50];
	char nome[100];
	int contacto;
	int NIF;
	int codigo;
	char morada[50];
	struct registo* seguinte;
}Cliente;

Cliente* removercliente(Cliente* inicio, int codigo);
Cliente* adicionarcliente(Cliente* inicio, char nome[], char username[], char password[], int contacto, int codigo, int NIF, char morada[]);
void listarclientes(Cliente* inicio);
Cliente* editarcliente(Cliente* inicio, char nome[], char username[], char password[], int contacto, int codigo, int NIF, char morada[]);
int salvardadoscliente(Cliente* inicio);
int logincliente(Cliente* inicio, char user[], char pass[]);
Cliente* lerdados();