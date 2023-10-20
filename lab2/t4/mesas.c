#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mesas.h"

Mesa *distribui_mesas(int m, int n){
    //recebe o numero de linhas e de colunas
    //retorna uma matriz de mesas (representada como vetor simples)
    
    Mesa *mesas = (Mesa*)malloc(m * n * sizeof(Mesa));
    for(int i = 0; i < m * n; i++){
        mesas[i].numero = i+1;
        mesas[i].disponivel = true;
        mesas[i].pessoas = 0;
        mesas[i].comanda = 0;
    }
}

Mesa *encontra_mesa

int preenche_mesa(Mesa *mesa, int m, int n, int pessoas){
    //recebe a matriz de mesas, o tamanho (m e n) e o numero de pessoas de um grupo
    //retorna quantas pessoas sobraram do grupo
    //se todas pessoas do grupo puderam sentar, retorna 0

    int i;
    for(i = 0; i < m * n; i++){
        if(mesas[i].disponivel) break;
    }
    if(i == m * n) return pessoas;
    mesa->disponivel = false;
    mesas->comanda = mesas[i].numero;
    if(pessoas <= 4){
        mesa->pessoas = pessoas;
        return 0;
    }
    mesa->pessoas = 4;
    return pessoas - 4;
}

int esvazia_mesa(Mesa *mesas, int numero){
    //recebe a matriz de mesas e o numero da mesa a ser liberada
    //retorna o numero de pessoas que sairam do restaurante
    //se mesa nao estava ocupada, retorna 0
    
    int n = numero-1;
    if(mesas[n].disponivel) return 0;
    mesas[n].disponivel = true;
    mesas[n].comanda = 0;
    int pessoas = mesas[n].pessoas;
    mesas[n].pessoas = 0;
    return pessoas;
}
