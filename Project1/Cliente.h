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
	float saldo;
	struct registo* seguinte;
}Cliente;

Cliente* removercliente(Cliente* inicio, int NIF);
Cliente* adicionarcliente(Cliente* inicio, char nome[], char username[], char password[], int contacto, int codigo, int NIF, char morada[], float saldo);
void listarclientes(Cliente* inicio);
void editarcliente(Cliente* inicio, int NIF);
int salvardadoscliente(Cliente* inicio);
int logincliente(Cliente* inicio, char user[], char pass[]);
Cliente* lerdados();
void saldo(Cliente* inicio,float saldo, int NIF);