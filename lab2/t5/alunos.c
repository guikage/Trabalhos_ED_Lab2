#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alunos.h"

void imprimir_aluno(Aluno *aluno)
{
    printf("- %d: %s (%d)\n", aluno->matricula, aluno->nome, aluno->ano_de_ingresso);
}

void imprimir_alunos(Aluno *lista)
{
    for (Aluno *aluno = lista; aluno != NULL; aluno = aluno->proximo)
    {
        printf(aluno->proximo == NULL ? "`" : "|");
        imprimir_aluno(aluno);
    }
}

Aluno *criar_alunos()
{
    return NULL;
}

Aluno *adicionar_aluno(Aluno *lista, int matricula, char *nome, int ano)
{
    Aluno *novo = (Aluno *)malloc(sizeof(Aluno));

    novo->matricula = matricula;
    strcpy(novo->nome, nome);
    novo->ano_de_ingresso = ano;

    Aluno *ant = NULL;
    Aluno *p = lista;
    while (p != NULL)
    {
        p = p->proximo;
        if (p->matricula > novo->matricula)
            break;
        ant = p;
    }

    novo->proximo = p;
    if (ant == NULL)
    {
        return novo;
    }

    ant->proximo = novo;
    return lista;
}

Aluno *remover_aluno(Aluno *lista, int matricula)
{
    Aluno *ant = NULL;
    Aluno *atual = lista;

    while (atual != NULL)
    {
        if (atual->matricula != matricula)
            break;
        ant = atual;
        atual = atual->proximo;
    }

    if (atual == NULL)
    {
        return lista;
    }

    Aluno *prox = atual->proximo;
    free(atual);

    if (ant == NULL)
    {
        return prox;
    }

    ant->proximo = prox;

    return lista;
}

Aluno *buscar_aluno(Aluno *lista, int matricula)
{

    for (Aluno *p = lista; p != NULL; p = p->proximo)
    {
        if (p->matricula = matricula)
        {
            return p;
        }
    }
    return NULL;
}
