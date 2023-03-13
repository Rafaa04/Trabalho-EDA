#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include "Cliente.h"
void clear() 
{

	system("@cls || clear");
}
int menu_c() 
{
	int opção;
	printf("|----------------MENU-----------------|");
	printf("|1 - Carregar Saldo                   |\n");
	printf("|2 - Mostrar Meios Disponiveis        |\n");
	printf("|3 - Alugar Meios Disponiveis         |\n");
	printf("|4 - Ver Historico De Aluguer Pessoal |\n");
	printf("|5 - Editar Dados Da Conta            |\n");
	printf("|0 - Sair                             |\n");
	printf("|-------------------------------------|\n");
	printf("Opcao:\n");
	scanf("%d", &opção);
	return(opção);
}
int menu_g()
{
	int opção;
	printf("|----------------MENU-----------------|");
	printf("|1 - Adicionar Meio                   |\n");
	printf("|2 - Mostrar Meios Disponiveis        |\n");
	printf("|3 - Remover Meio Existente           |\n");
	printf("|4 - Guardar Novo Meio                |\n");
	printf("|5 - Ler Meios                        |\n");
	printf("|0 - Sair                             |\n");
	printf("|-------------------------------------|\n");
	printf("\nDigite a opcao desejada:\n");
	scanf("%d", &opção);
	return(opção);
}
int main() 
{
	Cliente* cliente = NULL;
	cliente = lerdados();
	char username[50], password[50], nome[50], morada[50];
	int contacto, codigo, NIF;
	int opção, opção1;
	printf("|---------------MENU--------------|\n");
	printf("|1 - Entrar como cliente          |\n");
	printf("|2 - Entrar como gestor           |\n");
	printf("|0 - Sair                         |\n");
	printf("|---------------------------------|\n");
	printf("\nDigite a opcao desejada:\n");
	scanf("%d", &opção);
	clear();
	if (opção == 1) {
		printf("|----------------MENU-----------------|\n");
		printf("|1 - Criar novo registo de utilizador |\n");
		printf("|2 - Login                            |\n");
		printf("|0 - Sair                             |\n");
		printf("|-------------------------------------|\n");
		printf("\nDigite a opcao desejada:\n");
		scanf("%d", &opção);
		clear();
		switch (opção) {
		case 1:
			printf("Preencha atentamente as informacoes pedidas!\n\n");
			scanf("%*c");
			printf("Nome: ");
			gets(nome);
			printf("Username: ");
			scanf("%s", username);
			printf("Password: ");
			scanf("%s", password);
			printf("Codigo: ");
			scanf("%d", &codigo);
			printf("Contacto: ");
			scanf("%d", &contacto);
			printf("NIF: ");
			scanf("%d", &NIF);
			scanf("%*c");
			printf("Morada: ");
			gets(morada);
			cliente = adicionarcliente(cliente, nome, username, password, contacto, codigo, NIF, morada);
			salvardadoscliente(cliente);
			break;
		case 2:
			printf("Introduza o seu username: ");
			scanf("%s", &username);
			printf("Introduza a sua password: ");
			scanf("%s", &password);
			logincliente(cliente, username, password);
			break;
		case 0:
			exit(0);
		default:
			printf("Opcao invalida.\n");
			break;
		}
	}
	if (opção == 2) {

	}
	switch (opção) {
	case 1:
		
		break;
	case 2:
	case 0:
		exit(0);
	default:
		printf("Opcao invalida.\n");
		break;
	}
}