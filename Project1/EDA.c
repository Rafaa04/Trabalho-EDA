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
	Cliente* cliente = NULL;
	cliente = lerdados();
	int opção, NIF2 = 0, NIF3 = 0;
	float saldo1 = 0;
	printf("|----------------MENU-----------------|\n");
	printf("|1 - Carregar Saldo                   |\n");
	printf("|2 - Mostrar Meios Disponiveis        |\n");
	printf("|3 - Alugar Meios Disponiveis         |\n");
	printf("|4 - Ver Historico De Aluguer Pessoal |\n");
	printf("|5 - Editar Dados Da Conta            |\n");
	printf("|0 - Sair                             |\n");
	printf("|-------------------------------------|\n");
	printf("Digite a opcao desejada:\n");
	scanf("%d", &opção);
	clear();
	switch (opção)
	{
	case 1:
		printf("Digite o NIF da conta: \n");
		scanf("%d", &NIF3);
		printf("Qual o montante que deseja adicionar na conta: \n");
		scanf("%f", &saldo1);
		saldo(cliente, saldo1, NIF3);
		salvardadoscliente(cliente);
		clear();
		menu_c();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		printf("Digite o NIF da conta a editar:\n");
		scanf("%d", &NIF2);
		editarcliente(cliente, NIF2);
		salvardadoscliente(cliente);
		menu_c();
		break;
	case 0:
		exit(0);
		break;
	default:
		printf("Opcao invalida.\n");
		break;
	}
	salvardadoscliente(cliente);
	return(opção);
}
int menu_g()
{
	Cliente* cliente = NULL;
	cliente = lerdados();
	int opção, contacto, codigo, NIF, NIF2;
	char username[50], password[50], nome[50], morada[50];
	float saldo = 0;
	printf("|----------------MENU-----------------|\n");
	printf("|1 - Inserir Novo Meio                |\n");
	printf("|2 - Inserir Cliente                  |\n");
	printf("|3 - Listar Meios Disponiveis         |\n");
	printf("|4 - Listar Clientes Registados       |\n");
	printf("|5 - Remover Meio Existente           |\n");
	printf("|6 - Remover Cliente Registado        |\n");
	printf("|0 - Sair                             |\n");
	printf("|-------------------------------------|\n");
	printf("\nDigite a opcao desejada:\n");
	scanf("%d", &opção);
	clear();
	switch (opção)
	{
	case 1:
		break;
	case 2:
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
		cliente = adicionarcliente(cliente, nome, username, password, contacto, codigo, NIF, morada, saldo);
		salvardadoscliente(cliente);
		break;
	case 3:
		break;
	case 4:
		listarclientes(cliente);
		printf("\n");
		menu_g();
		break;
	case 5:
		break;
	case 6:
		printf("Introduza o NIF do cliente a remover: ");
		scanf("%d", &NIF2);
		cliente = removercliente(cliente, NIF2);
		salvardadoscliente(cliente);
		break;
	case 0:
		exit(0);
		break;
	default:
		printf("Opcao invalida.\n");
		break;
	}
	return(opção);
}
int main() 
{
	Cliente* cliente = NULL;
	cliente = lerdados();
	char username[50], password[50], nome[50], morada[50], user = 'lesi', pass = 'lesi';
	int contacto, codigo, NIF;
	int opção, opção1;
	float saldo = 0;
	printf("|---------------MENU--------------|\n");
	printf("|1 - Entrar como cliente          |\n");
	printf("|2 - Entrar como gestor           |\n");
	printf("|0 - Sair                         |\n");
	printf("|---------------------------------|\n");
	printf("\nDigite a opcao desejada:\n");
	scanf("%d", &opção);
	clear();
	if (opção == 1) 
	{
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
			cliente = adicionarcliente(cliente, nome, username, password, contacto, codigo, NIF, morada, saldo);
			salvardadoscliente(cliente);
			clear();
			menu_c();
			break;
		case 2:
			printf("Introduza o seu username: ");
			scanf("%s", &username);
			printf("Introduza a sua password: ");
			scanf("%s", &password);
			logincliente(cliente, username, password);
			clear();
			menu_c();
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("Opcao invalida.\n");
			break;
		}
		salvardadoscliente(cliente);
	}
	if (opção == 2)
	{
		printf("Introduza o seu username de gestor: ");
		scanf("%s", &username);
		printf("Introduza a sua password de gestor: ");
		scanf("%s", &password);
		if (strstr(username, "lesi") && strstr(password, "lesi"))
		{
			clear();
			menu_g();
		}
		else
		{
			printf("login sem sucesso! Username ou password incorretos!\n");
			exit(0);
		}
		salvardadoscliente(cliente);
	}
	if (opção == 0) 
	{
		exit(0);
	}
}