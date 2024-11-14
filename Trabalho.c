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

void QuickSort1(int vetor[], int n) {
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
        if (vetor[j] < pivo) {
            i++;
            /* Troca vetor[i] e vetor[j] */
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }

    /* Coloca o pivô na posição correta */
    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[maior];
    vetor[maior] = temp;
    int novoPivo = i + 1;

    /* Recursividade*/ 
    QuickSort1(vetor, novoPivo); /* Ordena a parte esquerda */
    QuickSort1(vetor + novoPivo + 1, n - novoPivo - 1); /* Ordena a parte direita */
}

// descobrir oque é o n no alg do professor
void ShellSort(int vet[],int n){
    int i,j,aux,k=1;
    

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

int main(){
    int tam,esq,dir,chave,min,max;
    int vet[1024];

    //testes
    tam = 1023;esq = 1;dir = 1023;min = 0,max = 2048;
    printf ("Digite a chave a ser buscada no vetor: \n");
    scanf ("%d", &chave);

    GeraVetAleat(vet,tam,min,max);
    PesqSeq(vet,tam,chave);
    ImprimeParteVet(vet);
    QuickSort1(vet,tam);
    ImprimeParteVet(vet);
    BuscaBin(vet,chave,esq,dir);


    return 0;
}