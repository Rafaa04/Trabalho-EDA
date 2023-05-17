#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mobilidade 
{
	int codigo;
	int codigo_reserva;
	int rsv;
	int NIF;
	float bateria;
	char autonomia[50];
	char tipomeio[50];
	char localização[50];
	float preço;
	struct mobilidade* seguinte;
}Mobilidade;

Mobilidade* adicionarMobilidade(Mobilidade* inicio, int codigo, int NIF, int rsv, float bateria, char autonomia[], char tipomeio[], char localização[], float preço);
int salvardadosMobilidadetxt(Mobilidade* inicio);
void salvardadosMobilidadebin(Mobilidade* inicio);
Mobilidade* removerMobilidade(Mobilidade* inicio, int codigo);
void editarMobilidade(Mobilidade* inicio, int codigo);
void listarMobilidade(Mobilidade* inicio);
Mobilidade* lerdadosMobilidadebin();
void ordenaçãoMobilidade(Mobilidade* inicio);
Mobilidade* alugarMobilidade(Mobilidade* inicio, int NIF, int rsv);