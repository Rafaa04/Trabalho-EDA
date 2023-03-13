#pragma once
#include <stdio.h>

typedef struct mobilidade {
	int codigo;
	float bateria;
	char tipomeio[50];
	float custo;
	struct mobilidade* seguinte;
}Mobilidade;

Mobilidade* adicionarMobilidade(Mobilidade* inicio, int codigo, float bateria[], char tipomeio[], float custo[]);
Mobilidade* salvardadosMobilidade(Mobilidade* inicio, int codigo, float bateria[], char tipomeio[], float custo[]);
Mobilidade* removerMobilidade(Mobilidade* inicio, int codigo);
Mobilidade* editarMobilidade(Mobilidade* inicio, int codigo, float bateria[], char tipomeio[], float custo[]);
void listarMobilidades(Mobilidade* inicio);