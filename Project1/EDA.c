#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include "Cliente.h"

int main() {
	Cliente* cliente = NULL;
	cliente = lerdados();
	char username[50], password[50], nome[50], morada[50];
	int contacto, codigo, NIF;
	int op��o, op��o1;
	printf("---------------MENU--------------\n\n");
	printf("1 - Entrar como cliente;\n2 - Entrar como gestor.\n");
	printf("Digite a opcao desejada:\n\n");
	scanf("%d", &op��o);
	if (op��o == 1) {
		printf("\n---------------MENU--------------\n\n");
		printf("1 - Criar novo registo de usuario;\n2 - Login;\n0 - Sair;\n\n");
		printf("Digite a opcao desejada:\n\n");
		scanf("%d", &op��o);

		switch (op��o) {
		case 1:
			printf("Preencha atentamente as informacoes pedidas!\n");
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
			printf("Opcao inv�lida.\n");
			break;
		}
		op��o1 = menu_c();
		switch (op��o1)
		{
		case 0:
			exit(0);
		default:
			break;
		}
	}
	if (op��o == 2) {

	}
	switch (op��o) {
	case 1:
		
		break;
	case 2:
		menu1();
	case 0:
		exit(0);
	default:
		printf("Opcao inv�lida.\n");
		break;
	}
}
int menu1() {
	int op��o1;

	printf("\n---------------MENU--------------\n\n");
	printf("1 - Sou cliente;\n2 - Sou gestor;\n0 - Sair\n\n");
	printf("Digite a opcao desejada:\n\n");
	scanf("%d", &op��o1);

	switch (op��o1) {
	case 1:
		break;
	case 2:
		break;
	case 0:
		exit(0);
	default:
		printf("Opcao inv�lida.\n");
		break;
	}
}
int menu_c() {
	int op��o;
	printf("---------------MENU--------------\n");
	printf("1 - Carregar Saldo;\n");
	printf("2 - Mostrar Meios Disponiveis;\n");
	printf("3 - Alugar Meios Disponiveis;\n");
	printf("4 - Ver Historico De Aluguer Pessoal;\n");
	printf("5 - Editar Dados Da Conta;\n");
	printf("0 - Sair\n");
	printf("Opcao:\n");
	scanf("%d", &op��o);
	return(op��o);
}
int menu_g()
{
	int op��o;
	printf("---------------MENU--------------\n");
	printf("1 - Adicionar Meio\n");
	printf("2 - Mostrar Meios Disponiveis\n");
	printf("3 - Remover Meio Existente\n");
	printf("4 - Guardar Novo Meio\n");
	printf("5 - Ler Meios\n");
	printf("0 - Sair\n");
	printf("Opcao:\n");
	scanf("%d", &op��o);
	return(op��o);
}