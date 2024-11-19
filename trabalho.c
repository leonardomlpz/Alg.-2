// int vet[1024] numeros entre 0 e 2048 aleatorios, gerar a qualquer momento e imprimir uma pequena parte do vetor
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "funcoes.h"

int main(){
    int tam,esq,dir,chave,min,max,num,media,trocas;
    double desvio,somatorio;
    int vet[1024];
    int vet2[1000];

    int qtde = 0, contador = 0;

    srand(time(NULL));

    //testes
    tam = 1024;esq = 1;dir = 1023;min = 0,max = 2048;qtde = 0,trocas = 0;

    printf ("Digite 1 para começar\n");
    scanf ("%d", &num);

    printf ("Digite 0 para encerrar o programa\n");
    printf ("Digite 1 para gerar um vetor de num aleatorios\n");
    printf ("Digite 2 para imprimir uma parte do vetor\n");
    printf ("Digite 3 para ordenar o vetor utilizando o primeiro QuickSort\n");
    printf ("Digite 4 para ordenar o vetor utilizando o segundo QuickSort\n");
    printf ("Digite 5 para ordenar o vetor utilizando o primeiro ShellSort\n");
    printf ("Digite 6 para ordenar o vetor utilizando o segundo ShellSort\n");
    printf ("Digite 7 para ordenar o vetor utilizando o SelecSort\n");
    printf ("Digite 10 para realizar o calculo de media e desvio padrao\n");
    while (num != 0){
        
        scanf ("%d", &num);

        switch (num)
        {
        case 1:
            GeraVetAleat(vet,tam,min,max);
            break;
        case 2:
            ImprimeParteVet(vet);
            break;
        case 3:
            QuickSort1(vet,tam,&qtde);
            printf ("qtde :%lld\n", qtde);
            qtde = 0;
            break;
        case 4:
            trocas = 0;
            GeraVetAleat(vet,tam,min,max);
            QuickSort2(vet,tam,&qtde,&trocas);
            printf ("Qtde Trocas =%d\n", trocas);
            break;
        case 5:
            shellSort1(vet,tam,&qtde,&trocas);
            printf ("qtde :%lld\n", qtde);
            break;
        case 6:
            shellSort2(vet,tam,&qtde);
            printf ("qtde :%lld\n", qtde);
            break;
        case 7:
            SelecSort(vet,tam);
            break;
        case 8:
            printf ("Digite a chave a ser buscada no vetor: \n");
            scanf ("%d", &chave);
            PesqSeq(vet,tam,chave);
            break;
        case 9:
            printf ("Digite a chave a ser buscada no vetor: \n");
            scanf ("%d", &chave);
            BuscaBin(vet,chave,1,dir);
            break;
        case 10:
            qtde = 0;
            contador = 0;
            trocas = 0;
            somatorio = 0;
            for (int i = 0; i < 1000; i++){
                qtde = 0;
                GeraVetAleat(vet,tam,min,max);
                shellSort1(vet,tam,&qtde,&trocas);
                vet2[i] = qtde;
                contador = contador + qtde;
            }
            printf ("Quantidade de comparacoes na ordenacao 1000x: %lld\n", contador);
            //media da quantidade de comparacoes
            media = contador/1000;
            printf ("media = %d\n", media);
            for (int i = 0; i < 1000; i++){
                somatorio = somatorio + (pow(vet2[i] - media, 2));
            }

            printf ("Qtde Trocas =%d\n", trocas/1000);

            printf ("%d %d %d\n", vet2[0],vet2[1],vet2[2]);
            //somatorio divido pela quantidade de repeticao do for
            somatorio = somatorio/1000;
            printf ("somatorio = %.2f\n", somatorio);
            //desvio padrao
            desvio = sqrt(somatorio);
            printf ("Desvio %.2f\n", desvio);

        default:
            break;
        }
    } 

    return 0;
}