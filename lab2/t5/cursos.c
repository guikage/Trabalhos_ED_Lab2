#include <stdio.h>
#include <stdlib.h>

#include "cursos.h"

void imprimir_curso(Curso *curso) {
    printf("• %d: %s (%s)\n", curso->codigo, curso->nome, curso->centro);
}

void imprimir_cursos(Curso *arvore) {
    if (cursos_vazio(arvore)) {
        return;
    }

    imprimir_cursos(arvore->esquerda);
    imprimir_curso(arvore);
    imprimir_cursos(arvore->direita);
}

void imprimir_curso_com_alunos(Curso *curso) {
    imprimir_curso(curso);
    imprimir_alunos(curso->alunos);
    printf("\n");
}

void imprimir_cursos_com_alunos(Curso *arvore) {
    if (cursos_vazio(arvore)) {
        return;
    }

    imprimir_cursos_com_alunos(arvore->esquerda);
    imprimir_curso_com_alunos(arvore);
    imprimir_cursos_com_alunos(arvore->direita);
}