#pragma once
#include <stdio.h>

typedef struct mobilidade 
{
	int codigo;
	int codigo_reserva;
	int rsv;
	int NIF;
	float bateria;
	char autonomia[50];
	char tipomeio[50];
	char localiza��o[50];
	float pre�o;
	struct mobilidade* seguinte;
}Mobilidade;

Mobilidade* adicionarMobilidade(Mobilidade* inicio, int codigo, int codigo_reserva, int rsv, int NIF, float bateria, char autonomia[], char tipomeio[], char localiza��o[], float pre�o);
int salvardadosMobilidadetxt(Mobilidade* inicio);
void salvardadosMobilidadebin(Mobilidade* inicio);
Mobilidade* removerMobilidade(Mobilidade* inicio, int codigo);
void editarMobilidade(Mobilidade* inicio, int codigo);
void listarMobilidade(Mobilidade* inicio);
Mobilidade* lerdadosMobilidadebin();
Mobilidade* lerdadosMobilidadetxt();
Mobilidade* lerdadosMobilidade0();
Mobilidade* lerdadosMobilidade1();
void ordena��oMobilidade(Mobilidade* inicio, float bateria);
Mobilidade* alugarMobilidade(Mobilidade* inicio, int codigo_reserva, int NIF);