#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alunos.h"

void imprimir_aluno(Aluno *aluno) {
    printf("- %d: %s (%d)\n", aluno->matricula, aluno->nome, aluno->ano_de_ingresso);
}

void imprimir_alunos(Aluno *lista) {
    for (Aluno *aluno = lista; aluno != NULL; aluno = aluno->proximo) {
        printf(aluno->proximo == NULL ? "`" : "|");
        imprimir_aluno(aluno);
    }
}