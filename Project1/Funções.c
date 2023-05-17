#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Gestor.h"
#include "Mobilidade.h"
#include "Histórico.h"

Cliente* removercliente(Cliente* inicio, int NIF)
{
    Cliente *atual = inicio, *anterior = inicio, * aux;

    if (inicio == NULL)
    {
        return(NULL);
    }
    else if (atual->NIF == NIF)
    {
        aux = atual->seguinte;
        free(atual);
        printf("\nCliente removido!\n");
        return (aux);
    }
    else
    {
        while ((atual != NULL) && (atual->NIF != NIF))
        {
            anterior = atual;
            atual = atual->seguinte;
        }
        if (atual == NULL)return(inicio);
        else
        {
            anterior->seguinte = atual->seguinte;
            free(atual);
            printf("\nCliente removido!\n");
            return(inicio);
        }
    }

}
Cliente* adicionarcliente(Cliente* inicio, char nome[], char username[], char password[], int contacto, int codigo, int NIF, char morada[], float saldo)
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
        novo->saldo = saldo;
        novo->seguinte = inicio;
        return novo;
    }
    else
    {
        return inicio;
    }
}
void listarclientes(Cliente* inicio)
{
    while (inicio != NULL)
    {
        printf("Nome:%s;Username:%s;Password:%s;Contacto:%d;Codigo:%d;NIF:%d;Morada:%s;Saldo:%f;\n", inicio->nome, inicio->username, inicio->password, inicio->contacto, inicio->codigo, inicio->NIF, inicio->morada, inicio->saldo);
        inicio = inicio->seguinte;
    }
}
void editarcliente(Cliente* inicio, int NIF)
{
    Cliente* atual = inicio;
    char novo_nome[50], nova_morada[50], novo_user[50], nova_pass[50];
    int novo_codigo = 0, novo_contacto = 0, opção = 0;
    while (inicio != NULL)
    {
        if (inicio->NIF == NIF)
        {
            printf("O que pretende alterar?\n");
            printf("1 - Nome\n2 - Username\n3 - Password\n4 - Codigo\n5 - Contacto\n6 - Morada\n");
            scanf("%d", &opção);
            switch (opção)
            {
            case 1:
                printf("Digite o novo nome: \n");
                scanf("%s", novo_nome);
                strcpy(atual->nome, novo_nome);
                return(inicio);
                break;
            case 2:
                printf("Digite o novo username: \n");
                scanf("%s", novo_user);
                strcpy(inicio->username, novo_user);
                return(inicio);
                break;
            case 3:
                printf("Digite a nova password: \n");
                scanf("%s", nova_pass);
                strcpy(inicio->password, nova_pass);
                return(inicio);
                break;
            case 4:
                printf("Digite o novo contacto: \n");
                scanf("%d ", &novo_contacto);
                inicio->contacto = novo_contacto;
                return(inicio);
                break;
            case 5:
                printf("Digite o novo codigo: \n");
                scanf("%d", &novo_codigo);
                inicio->codigo = novo_codigo;
                return(inicio);
                break;
            case 6:
                printf("Digite a nova morada: \n");
                scanf("%s", nova_morada);
                strcpy(inicio->morada, nova_morada);
                return(inicio);
                break;
            }
            printf("Conta alterada com sucesso!");
        }
        else
        {
            inicio = inicio->seguinte;
        }


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
            fprintf(fp, "%s;", cliente->morada);
            fprintf(fp, "%f\n", cliente->saldo);
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
    int NIF = 0, tlm = 0, cod = 0;
    char user[50], pass[50], nome[50], mo[50];
    float saldo1 = 0;

    if (fp != NULL)
    {
        while (!feof(fp))
        {
            fscanf(fp, "%[^;];%[^;];%[^;];%d;%d;%d;%[^;];%f\n", &nome, &user, &pass, &cod, &tlm, &NIF, &mo, &saldo1);
            cliente = adicionarcliente(cliente, nome, user, pass, tlm, cod, NIF, mo, saldo1);
        }
        fclose(fp);
    }
    return(cliente);
}
void adicionarsaldo(Cliente* inicio, float saldo, int NIF) 
{
    while (inicio != NULL) 
    {
        if (inicio->NIF == NIF)
        {
            inicio->saldo += saldo;
            return(inicio);
        }
        else
        {
            inicio = inicio->seguinte;
        }
    }
}

//****************************************************************************************************************************************************//

Mobilidade* adicionarMobilidade(Mobilidade* inicio, int codigo, int NIF, int rsv, float bateria, char autonomia[], char tipomeio[], char localização[], float preço)
{
    Mobilidade* novo = malloc(sizeof(struct mobilidade));
    if (novo != NULL)
    {
        novo->codigo = codigo;
        novo->NIF = NIF;
        novo->rsv = rsv;
        novo->bateria = bateria;
        strcpy(novo->autonomia, autonomia);
        strcpy(novo->tipomeio, tipomeio);
        strcpy(novo->localização, localização);
        novo->preço = preço;
        novo->seguinte = inicio;
        return(novo);
    }
    else
    {
        return(inicio);
    }
}
Mobilidade* lerdadosMobilidadebin()
{
    FILE* fp;
    Mobilidade* mobilidade = NULL;
    fp = fopen("Mobilidade.bin", "rb");

    if (fp != NULL)
    {
        Mobilidade inicio;
        while (fread(&inicio, sizeof(Mobilidade), 1, fp) == 1)
        {
            mobilidade = adicionarMobilidade(mobilidade, inicio.codigo, inicio.NIF, inicio.rsv, inicio.bateria,inicio.autonomia, inicio.tipomeio, inicio.localização, inicio.preço);
        }
        fclose(fp);
    }
    return mobilidade;
    
}
int salvardadosMobilidadetxt(Mobilidade* inicio) {
    FILE* fp;
    fp = fopen("Mobilidade.txt", "w");
    if (fp != NULL)
    {
        Mobilidade* mobilidade = inicio;
        while (mobilidade != NULL)
        {
            fprintf(fp, "%d;", mobilidade->codigo);
            fprintf(fp, "%d;", mobilidade->NIF);
            fprintf(fp, "%d;", mobilidade->rsv);
            fprintf(fp, "%.2f;", mobilidade->bateria);
            fprintf(fp, "%skm;", mobilidade->autonomia);
            fprintf(fp, "%s;", mobilidade->tipomeio);
            fprintf(fp, "%s;", mobilidade->localização);
            fprintf(fp, "%.2f;\n", mobilidade->preço);
            mobilidade = mobilidade->seguinte;
        }
        fclose(fp);
        return(1);
    }
    else
    {
        return(0);
    }
}
void salvardadosMobilidadebin(Mobilidade* inicio) {
    FILE* fp;
    fp = fopen("Mobilidade.bin", "wb");
    if (fp != NULL)
    {
        Mobilidade* mobilidade = inicio;
        while (mobilidade != NULL)
        {
            fwrite(mobilidade, sizeof(Mobilidade), 1, fp);
            mobilidade = mobilidade->seguinte;
        }
        fclose(fp);
    }
}
void listarMobilidade(Mobilidade* inicio)
{
    while (inicio != NULL)
    {
        printf("Codigo:%d;Tipo de meio:%s;Bateria:%.2f;Autonomia:%skm;Localizacao:%s;Preco:%.2f por minuto;\n", inicio->codigo, inicio->tipomeio, inicio->bateria, inicio->autonomia, inicio->localização, inicio->preço);
        inicio = inicio->seguinte;
    }
}
void listarMobilidade0(Mobilidade* inicio)
{
    while (inicio != NULL)
    {
        if (inicio->rsv == 0) 
        {
            printf("Codigo:%d;NIF:%d;Reserva:%d;Tipo de meio:%s;Bateria:%.2f;Autonomia:%skm;Localizacao:%s;Preco:%.2f por minuto;\n", inicio->codigo, inicio->NIF, inicio->rsv, inicio->tipomeio, inicio->bateria, inicio->autonomia, inicio->localização, inicio->preço);
            inicio = inicio->seguinte;
        }
        else
        {
            inicio = inicio->seguinte;
        }
        
    }
    return(0);
}
void listarMobilidade1(Mobilidade* inicio)
{
    while (inicio != NULL)
    {
        if (inicio-> rsv == 1)
        {
            printf("Codigo:%d;NIF:%d;Reserva:%d;Tipo de meio:%s;Bateria:%.2f;Autonomia:%skm;Localizacao:%s;Preco:%.2f por minuto;\n", inicio->codigo, inicio->NIF, inicio->rsv, inicio->tipomeio, inicio->bateria, inicio->autonomia, inicio->localização, inicio->preço);
            inicio = inicio->seguinte;
        }
        else
        {
            inicio = inicio->seguinte;
        }

    }
    return(0);
}
void editarMobilidade(Mobilidade* inicio, int codigo)
{
    Mobilidade* atual = inicio;
    int opção = 0;
    float bateria = 0, preço = 0;
    char autonomia[50];
    while (inicio != NULL)
    {
        if (inicio->codigo == codigo)
        {
            printf("O que pretende mudar?\n");
            printf("1 - Bateria\n2 - Autonomia\n3 - Preco por minuto\n");
            scanf("%d", &opção);
            switch (opção)
            {
            case 1:
                printf("Digite a nova percentagem de bateria: ");
                scanf("%s", &bateria);
                inicio->bateria = bateria;
                return(inicio);
                break;
            case 2:
                printf("Digite a nova autonomia: ");
                scanf("%s", &autonomia);
                strcpy(inicio->autonomia, autonomia);
                return(inicio);
                break;
            case 3:
                printf("Digite o novo custo por minuto do veiculo: \n");
                scanf("%f", &preço);
                inicio->preço = preço;
                return(inicio);
                break;
            default:
                exit(0);
                break;
            }
        }
        else
        {
            inicio = inicio->seguinte;
        }


    }
}
Mobilidade* removerMobilidade(Mobilidade* inicio, int codigo)
{
    Mobilidade* atual = inicio, * anterior = inicio, * aux;

    if (inicio == NULL)
    {
        return(NULL);
    }
    else if (atual->codigo == codigo)
    {
        aux = atual->seguinte;
        free(atual);
        printf("Meio de trasporte removido com sucesso!\n");
        return (aux);
    }
    else
    {
        while ((atual != NULL) && (atual->codigo != codigo))
        {
            anterior = atual;
            atual = atual->seguinte;
        }
        if (atual == NULL)return(inicio);
        else
        {
            anterior->seguinte = atual->seguinte;
            free(atual);
            printf("Meio de trasporte removido com sucesso!\n");
            return(inicio);
        }
    }

}
void ordenaçãoMobilidade(Mobilidade* inicio) {
     
    Mobilidade* atual = inicio;
    Mobilidade* mobilidade = NULL;
    int aux;


    for (atual; atual != NULL; atual = atual->seguinte) {
        for (mobilidade = atual->seguinte; mobilidade != NULL; mobilidade = mobilidade->seguinte) {
            if (atual->bateria < mobilidade->bateria) {
                aux = mobilidade->bateria;
                mobilidade->bateria = atual->bateria;
                atual->bateria = aux;
            }
        }
    }
}
Mobilidade* alugarMobilidade(Mobilidade* inicio, int NIF, int rsv)
{
    while (inicio != NULL)
    {
        if (inicio->codigo == rsv)
        {
            inicio->NIF = NIF;
            inicio->rsv = 1;
            return(inicio);
        }
        else
        {
            inicio = inicio->seguinte;
        }
    }

} 