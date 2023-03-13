#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"

Cliente* adicionarcliente(Cliente* inicio, char nome[], char username[], char password[], int contacto, int codigo, int NIF, char morada[])
{
    Cliente* novo = malloc(sizeof(Cliente));
    if (novo != NULL)
    {
        strcpy(novo->nome, nome);
        strcpy(novo->username, username);
        strcpy(novo->password, password);
        novo->codigo = codigo;
        novo->contacto = contacto;
        novo->NIF = NIF;
        strcpy(novo->morada, morada);
        novo->seguinte = inicio;

        return novo;
    }
    else
    {
        return inicio;
    }
}
int salvardadoscliente(Cliente* inicio) {
    FILE* fp;
    fp = fopen("Clientes.txt", "w");
    if (fp != NULL) 
    {
        Cliente* cliente = inicio;
        while (cliente != NULL)
        {
            fprintf(fp, "%s;", cliente->nome);
            fprintf(fp, "%s;%s;", cliente->username, cliente->password);
            fprintf(fp, "%d;", cliente->codigo);
            fprintf(fp, "%d;", cliente->contacto);
            fprintf(fp, "%d;", cliente->NIF);
            fprintf(fp, "%s;\n", cliente->morada);
            cliente = cliente->seguinte;
        }
        fclose(fp);
        return(1);
    }
    else 
    {
        return(0);
    }
}
int logincliente(Cliente* inicio, char user[], char pass[])
{
    for (inicio; inicio != NULL; inicio = inicio->seguinte)
    {
        if (strstr(inicio->username, user) && strstr(inicio->password, pass))
        {
            printf("Login realizado com sucesso!\n");
            return(1);
        }
    }
    printf("login sem sucesso! Username ou password incorretos!\n");
    exit(0);
    return(0);
}
Cliente* lerdados()
{
    FILE* fp;
    Cliente* cliente = NULL;

    fp = fopen("Clientes.txt", "r");
    int NIF = 0, tlm = 0, cod = 0; //saldo = 0;
    char user[50], pass[50], nome[50], mo[50];

    if (fp != NULL)
    {
        while (!feof(fp))
        {
            fscanf(fp, "%[^;];%[^;];%[^;];%d;%d;%d;%[^\n]\n", &nome, &user, &pass, &cod, &tlm, &NIF, &mo); //&saldo);
            cliente = adicionarcliente(cliente, nome, user, pass, tlm, cod, NIF, mo); //sa);
        }
        fclose(fp);
    }
    return(cliente);
}