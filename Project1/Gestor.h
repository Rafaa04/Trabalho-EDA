#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct gestor {
	char nome[50];
	char username[50];
	char password[50];
	int codigo;
	char email[50];
	float saldo;
	struct gestor* seguinte;
}Gestor;

Gestor* adicionarGestor(Gestor* inicio, char nome[], char usarname[], char passowrd[], int codigo, char email[]);
Gestor* salvardadosGestor(Gestor* inicio, char nome[], char usarname[], char passowrd[], int codigo, char email[]);
Gestor* removerGestor(Gestor* inicio,int id[]);
Gestor* editarGestor(Gestor* inicio, char nome[], char usarname[], char passowrd[], int codigo, char email[]);