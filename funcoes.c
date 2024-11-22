#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "funcoes.h"

int Aleat(int min, int max){
    return rand() % (max - min + 1) + min;
}

void GeraVetAleat(int vet[], int tam){
    int i;
    int min = 0;
    int max = 2048;
    for (i = 1; i < tam; i++)
        vet[i] = Aleat(min,max);
    
    return;
}

void SelecSort(int vet[],int n, int *trocas){
    int i,j,min,aux;
    for (i = 1; i < n; i++){
        min = i;
        for (j = i + 1; j <= n; j++)
            if (vet[j] < vet[min])
                min = j;
        *trocas = *trocas + 1;
        aux = vet[min];
        vet[min] = vet[i];
        vet[i] = aux;
    }
}

void QuickSort1(int vetor[], int n, int *comp, int *trocas) {
    if (n <= 1) {
        return; /* Se o vetor tiver tamanho 0 ou 1 já está ordenado */
    }

    int menor = 0;
    int maior = n - 1;

    /* Escolhe o pivô como o último elemento */
    int pivo = vetor[maior];
    int i = menor - 1;

    /* Particionamento */
    for (int j = menor; j < maior; j++) {
        *comp = *comp + 1;
        if (vetor[j] < pivo) {
            i++;
            /* Troca vetor[i] e vetor[j] */
            *trocas = *trocas + 1;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }

    /* Coloca o pivô na posição correta */
    *trocas = *trocas + 1;
    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[maior];
    vetor[maior] = temp;
    int novoPivo = i + 1;

    /* Recursividade*/ 
    QuickSort1(vetor, novoPivo,comp,trocas); /* Ordena a parte esquerda */
    QuickSort1(vetor + novoPivo + 1, n - novoPivo - 1,comp,trocas); /* Ordena a parte direita */
}

void QuickSort2(int vetor[], int n, int *comp, int *troca) {
    if (n <= 1) {
        return;
    }

    int menor = 0;
    int maior = n - 1;

    /* Escolhe o pivô aleatoriamente */
    int pivotIndex = rand() % n;
    int temp = vetor[pivotIndex];
    vetor[pivotIndex] = vetor[maior];
    vetor[maior] = temp;

    int pivo = vetor[maior];
    int i = menor - 1;

    /* Particionamento */
    for (int j = menor; j < maior; j++) {
        *comp = *comp + 1;
        if (vetor[j] < pivo) {
            i++;
            /* Troca vetor[i] e vetor[j] */
            *troca = *troca + 1;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }

    /* Coloca o pivô na posição correta */
    *troca = *troca + 1;
    temp = vetor[i + 1];
    vetor[i + 1] = vetor[maior];
    vetor[maior] = temp;
    int novoPivo = i + 1;

    /* Recursividade */ 
    QuickSort2(vetor, novoPivo, comp, troca);  /* Ordena a parte esquerda */
    QuickSort2(vetor + novoPivo + 1, n - novoPivo - 1, comp, troca); /* Ordena a parte direita */
}

void shellSort1(int vetor[], int tamanho, int *comp,int *troca) {

int atual=0;
int proximo=0; 
int valor=0;
int salto = 1;
int comparacoes = 0;
    
    while(salto < tamanho) {
        salto = 3*salto+1;
    }

    while (salto > 0) {
        for(atual = salto; atual < tamanho; atual++) {
            valor = vetor[atual];
            proximo = atual;
            while (proximo > salto-1 && valor <= vetor[proximo-salto]) {
                comparacoes++;
                vetor[proximo] = vetor[proximo-salto];
                proximo = proximo - salto;

                *troca = *troca + 1;
            }
            vetor[proximo] = valor;
        }
        salto = salto/3;
    }
    *comp = comparacoes;
}

void shellSort2(int vetor[], int tamanho, int *comp, int *troca) {

    int atual = 0;
    int proximo = 0;
    int valor = 0;
    int salto = 1;
    int comps = 0;
    
    //usando a sequência de Hibbard
    while (salto <= tamanho / 2) {
        salto = salto * 2 + 1;
    }
    
    while (salto > 0) {
        for (atual = salto; atual < tamanho; atual++) {
            valor = vetor[atual];
            proximo = atual;
            while (proximo >= salto && valor < vetor[proximo - salto]) {
                comps++;
                vetor[proximo] = vetor[proximo - salto];
                proximo = proximo - salto;

                *troca = *troca + 1;
            }
            vetor[proximo] = valor;
        }
        salto = (salto - 1) / 2;
    }
    *comp = comps;
}

void PesqSeq(int vet[],int tam,int chave){
    vet[0]= chave;
    while (vet[tam] != chave)
        tam--;

    if (tam > 0){
        printf ("Chave %d encontrada na posição %d do vetor\n", vet[tam],tam);
        return;
    }
    printf ("Chave não encontrada\n");
    return;
}

void BuscaBin(int vet[],int chave,int esq,int dir){
    int meio;
    if (esq > dir){
        printf ("Chave não encontrada\n");
        return;
    }
    else{
        meio = (esq + dir)/2;
        if (chave == vet[meio]){
            printf ("Chave %d encontrada na posição %d do vetor\n", chave,meio);
            return;
        }
        if (chave < vet[meio])
            BuscaBin(vet,chave,esq,meio-1);
        else BuscaBin(vet,chave,meio+1,dir);
    }
}

void ImprimeParteVet(int vet[]){
    int tam_prov = 25;
    printf ("[%d]",vet[1]);
    for (int i = 2; i < tam_prov; i++){
        printf (" [%d]", vet[i]);
    }
    printf ("\n");
}

void mediacompPrimeiroShell(int vet[], int vet2[], int *media){
    int qtde = 0;
    int trocas = 0;
    int tam = 1024;
    int contador = 0;
    for (int i = 0; i < 1000; i++){
        qtde = 0;
        GeraVetAleat(vet,tam);
        shellSort1(vet,tam,&qtde,&trocas);
        vet2[i] = qtde;
        contador = contador + qtde;
    }
    *media = trocas/1000;
    printf ("Media de comparacoes do primeiro ShellSort: %d\n", contador/1000);
    printf ("Media da quantidade de trocas: %d\n", *media);
}

void mediacompSegundoShell(int vet[], int vet2[], int *media){
    int qtde = 0;
    int trocas = 0;
    int tam = 1024;
    int contador = 0;
    for (int i = 0; i < 1000; i++){
        qtde = 0;
        GeraVetAleat(vet,tam);
        shellSort2(vet,tam,&qtde,&trocas);
        vet2[i] = qtde;
        contador = contador + qtde;
    }
    *media = contador/1000;
    printf ("Media de comparacoes do segundo ShellSort: %d\n", contador/1000);
    printf ("Media da quantidade de trocas: %d\n", trocas/1000);
}

void mediacompPrimeiroQuick(int vet[], int vet2[], int *media){
    int qtde = 0;
    int trocas = 0;
    int tam = 1024;
    int contador = 0;
    for (int i = 0; i < 1000; i++){
        qtde = 0;
        GeraVetAleat(vet,tam);
        QuickSort1(vet,tam,&qtde,&trocas);
        vet2[i] = qtde;
        contador = contador + qtde;
    }
    *media = contador/1000;
    printf ("Media de comparacoes do primeiro QuickSort: %d\n", contador/1000);
    printf ("Media da quantidade de trocas: %d\n", trocas/1000);
}

void mediacompSegundoQuick(int vet[], int vet2[], int *media){
    int qtde = 0;
    int trocas = 0;
    int tam = 1024;
    int contador = 0;
    for (int i = 0; i < 1000; i++){
        qtde = 0;
        GeraVetAleat(vet,tam);
        QuickSort2(vet,tam,&qtde,&trocas);
        vet2[i] = qtde;
        contador = contador + qtde;
    }
    *media = contador/1000;
    printf ("Media de comparacoes do segundo QuickSort: %d\n", contador/1000);
    printf ("Media da quantidade de trocas: %d\n", trocas/1000);
}

void desvio_padrao(int vet2[], int media){
    double somatorio = 0;
    double desvio = 0;
    for (int i = 0; i < 1000; i++){
        somatorio = somatorio + (pow(vet2[i] - media, 2));
    }
    //somatorio dividido pela quantidade de repeticao do for
    somatorio /= 1000;
    desvio = sqrt(somatorio);

    printf ("Desvio padrao: %.2f\n", desvio);
}
