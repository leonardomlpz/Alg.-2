// int vet[1024] numeros entre 0 e 2048 aleatorios, gerar a qualquer momento e imprimir uma pequena parte do vetor
#include <stdio.h>
#include <stdlib.h>

int Aleat(int min, int max){
    return rand() % (max - min + 1) + min;
}

void GeraVetAleat(int vet[], int tam,int min, int max){
    int i;
    for (i = 0; i < tam; i++)
        vet[i] = Aleat(min,max);
    
    return;
}

void QuickSort1(){
    
}
// descobrir oque é o n no alg do professor
void ShellSort(int vet[]){
    int i,j,aux,k=1;
    // remover depois
    int n;

    do{
        k = k*3 + 1;
    } while (k <= n);
    do{
        k = k/3;
        for (i = k+1; i <= n; i++){
            aux = vet[i];
            j=i;
            while (vet[j-k]>aux && j > k){
                vet[j] = vet[j-k];
                j = j-k;
                if (j <= k)
                    break;
            }
            vet[i]=aux;
        }
    }while (k != 1);
}




void PesqSeq(int vet[],int tam,int chave){
    int i = 0;
    while (tam > i){
        if (vet[tam] == chave){
            printf ("Chave %d encontrada na posição %d do vetor\n", vet[tam],tam);
            return;
        }
        tam--;
    }
    printf ("Chave não encontrada\n");
    return;
}

void BuscaBin(int vet[],int chave,int esq,int dir){
    int meio;
    if (esq < dir){
        pritnf ("Chave não encontrada\n");
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