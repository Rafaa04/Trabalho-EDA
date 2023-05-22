#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include "Cliente.h"
#include "Gestor.h"
#include "Mobilidade.h"
#include "Struct Grafos.h"

void clear() 
{
	system("@cls || clear");
}
int menu_c() 
{
	Cliente* cliente = NULL;
	Mobilidade* mobilidade = NULL;
	Grafo* grafo = NULL;
	cliente = lerdados();
	int codigo = 0, opção, NIF = 0, NIF2 = 0, NIF3 = 0, rsv, codigo_reserva;
	float saldo1 = 0, bateria = 0;

	printf("|-------------MENU CLIENTES------------|\n");
	printf("|1 - Carregar Saldo                    |\n");
	printf("|2 - Mostrar Meios Disponiveis         |\n");
	printf("|3 - Alugar Meios Disponiveis          |\n");
	printf("|4 - Editar Dados Da Conta             |\n");
	printf("|0 - Sair                              |\n");
	printf("|--------------------------------------|\n");
	printf("Digite a opcao desejada:\n");
	scanf("%d", &opção);
	clear();
	switch (opção)
	{
	case 1:
		cliente = lerdados();
		printf("Digite o NIF da conta: ");
		scanf("%d", &NIF3);
		printf("Qual o montante que deseja adicionar na conta: ");
		scanf("%f", &saldo1);
		adicionarsaldo(cliente, saldo1, NIF3);
		salvardadoscliente(cliente);
		clear();
		menu_c();
		break;
	case 2:
		mobilidade = lerdadosMobilidadebin();
		ordenaçãoMobilidade(mobilidade, bateria);
		listarMobilidade0(mobilidade);
		printf("\n");
		menu_c();
		break;
	case 3:
		mobilidade = lerdadosMobilidadebin();
		ordenaçãoMobilidade(mobilidade, bateria);
		listarMobilidade0(mobilidade);
		printf("\n");
		printf("Introduza o seu NIF: ");
		scanf("%d", &NIF);
		printf("Introduza o codigo de mobilidade do veiculo que pretende alugar: ");
		scanf("%d", &codigo);
		mobilidade = alugarMobilidade(mobilidade, NIF, codigo);
		salvardadosMobilidadetxt(mobilidade);
		salvardadosMobilidadebin(mobilidade);
		clear();
		menu_c();
		break;
	case 4:
		cliente = lerdados();
		printf("Digite o NIF da conta a editar:\n");
		scanf("%d", &NIF2);
		editarcliente(cliente, NIF2);
		salvardadoscliente(cliente);
		clear();
		menu_c();
		break;
	case 0:
		exit(0);
		break;
	default:
		printf("Opcao invalida.\n");
		exit(0);
		break;
	}
	salvardadoscliente(cliente);
	return(opção);
}
int menu_g()
{
	Cliente* cliente = NULL;
	Mobilidade* mobilidade = NULL;
	Grafo* grafo = NULL;
	cliente = lerdados();
	mobilidade = lerdadosMobilidadebin();
	int opção, contacto, codigo, NIF, NIF2, NIF3, Vertice, VerticeI, VerticeF, Aresta, VerticeA;
	char username[50], password[50], nome[50], morada[50];
	float saldo = 0, saldo1;

	char tipo_meio[50], localização[50], autonomia[50];
	int codigo_mobilidade = 0, codigo_reserva = 0, rsv = 0, NIF_mobilidade = 0;
	float bateria, preço;

	printf("|-------------MENU GESTORES------------|\n");
	printf("|1 - Inserir Novo Meio                 |\n");
	printf("|2 - Inserir Cliente                   |\n");
	printf("|3 - Listar Todos Os Meios             |\n");
	printf("|4 - Listar Clientes Registados        |\n");
	printf("|5 - Editar Meio Existente             |\n");
	printf("|6 - Remover Meio Existente            |\n");
	printf("|7 - Remover Cliente Registado         |\n");
	printf("|8 - Adicionar Saldo A Cliente         |\n");
	printf("|9 - Criar Um Vertice A Um Grafo       |\n");
	printf("|10 - Criar Uma Aresta A Um Grafo      |\n");
	printf("|11 - Visualizar Vertices Adjacentes   |\n");
	printf("|12 - Atribuir Um Cliente A Um Vertice |\n");
	printf("|13 - Atribuir Um Meio A Um Grafo      |\n");
	printf("|14 - Mostrar Os Meios No Grafo        |\n");
	printf("|0 - Sair                              |\n");
	printf("|--------------------------------------|\n");
	printf("\nDigite a opcao desejada:\n");
	scanf("%d", &opção);
	clear();
	switch (opção)
	{
	case 1:
		mobilidade = lerdadosMobilidadebin();
		printf("Preencha atentamente as informacoes pedidas!\n\n");
		scanf("%*c");
		printf("Codigo de mobilidade: ");
		scanf("%d", &codigo_mobilidade);
		printf("Bateria: ");
		scanf("%f", &bateria);
		printf("Autonomia: ");
		scanf("%s", &autonomia);
		printf("Tipo De Meio: ");
		scanf("%s", &tipo_meio);
		Ruas(localização);
		printf("Preco Por Minuto: ");
		scanf("%f", &preço);
		mobilidade = adicionarMobilidade(mobilidade, codigo_mobilidade, NIF_mobilidade, rsv, bateria, autonomia, tipo_meio, localização, preço);
		salvardadosMobilidadetxt(mobilidade);
		salvardadosMobilidadebin(mobilidade);
		clear();
		menu_g();
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
		clear();
		menu_g();
		break;
	case 3:
		mobilidade = lerdadosMobilidadebin();
		ordenaçãoMobilidade(mobilidade);
		listarMobilidade(mobilidade);
		printf("\n");
		menu_g();
		clear();
		break;
	case 4:
		cliente = lerdados();
		listarclientes(cliente);
		printf("\n");
		menu_g();
		break;
	case 5:
		printf("Introduza o codigo de mobilidade: ");
		scanf("%d", &codigo_mobilidade);
		clear();
		editarMobilidade(mobilidade, codigo_mobilidade);
		salvardadosMobilidadetxt(mobilidade);
		salvardadosMobilidadebin(mobilidade);
		clear();
		menu_g();
		break;
	case 6:
		printf("Introduza o codigo de mobilidade: ");
		scanf("%d", &codigo_mobilidade);
		mobilidade = removerMobilidade(mobilidade, codigo_mobilidade);
		salvardadosMobilidadetxt(mobilidade);
		salvardadosMobilidadebin(mobilidade);
		clear();
		menu_g();
		break;
	case 7:
		cliente = lerdados();
		printf("Introduza o NIF do cliente a remover: ");
		scanf("%d", &NIF2);
		cliente = removercliente(cliente, NIF2);
		salvardadoscliente(cliente);
		clear();
		menu_g();
		break;
	case 8:
		cliente = lerdados();
		printf("Digite o NIF da conta: ");
		scanf("%d", &NIF3);
		printf("Qual o montante que deseja adicionar na conta: ");
		scanf("%f", &saldo1);
		adicionarsaldo(cliente, saldo1, NIF3);
		salvardadoscliente(cliente);
		clear();
		menu_g();
		break;
	case 9:
		grafo = lerdadosGrafo();
		printf("Digite o numero do vertice que pretende criar: ");
		scanf("%d", &Vertice);
		criarVertice(&grafo, Vertice);
		clear();
		gravarGrafo(grafo);
		menu_g();
	case 10:
		grafo = lerdadosGrafo();
		printf("Digite o numero do vertice inicial: ");
		scanf("%d", &VerticeI);
		printf("Digite o numero do vertice final: ");
		scanf("%d", &VerticeF);
		printf("Digite o peso da aresta que pretende criar: ");
		scanf("%d", &Aresta);
		criarAresta(grafo, VerticeI, VerticeF, Aresta);
		clear();
		gravarGrafo(grafo);
		menu_g();
	case 11:
		grafo = lerdadosGrafo();
		printf("Digite o numeroo do vertice que pretende para ver os seus adjacentes: ");
		scanf("%d", &VerticeA);
		listarAdjacentes(grafo, VerticeA);
	case 0:
		exit(0);
		break;
	default:
		printf("Opcao invalida.\n");
		exit(0);
		break;
	}
	return(opção);
}
int main() 
{
	Cliente* cliente = NULL;
	cliente = lerdados();
	char username[50], password[50], nome[50], morada[50], user = 'lesi', pass = 'lesi';
	char localização[50];
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
			exit(0);
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