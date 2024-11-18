// int vet[1024] numeros entre 0 e 2048 aleatorios, gerar a qualquer momento e imprimir uma pequena parte do vetor
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int Aleat(int min, int max){
    return rand() % (max - min + 1) + min;
}

void GeraVetAleat(int vet[], int tam,int min, int max){
    int i;
    for (i = 1; i < tam; i++)
        vet[i] = Aleat(min,max);
    
    return;
}

void SelecSort(int vet[],int n){
    int i,j,min,aux;
    for (i = 1; i < n; i++){
        min = i;
        for (j = i + 1; j <= n; j++)
            if (vet[j] < vet[min])
                min = j;
        aux = vet[min];
        vet[min] = vet[i];
        vet[i] = aux;
    }
}

void QuickSort1(int vetor[], int n,int *comp) {
    if (n <= 1) {
        return; /* Se o vetor tiver tamanho 0 ou 1 já está ordenado */
    }

    int menor = 0;
    int maior = n - 1;
    int comparacoes;

    /* Escolhe o pivô como o último elemento */
    int pivo = vetor[maior];
    int i = menor - 1;

    /* Particionamento */
    for (int j = menor; j < maior; j++) {
        comparacoes++;
        if (vetor[j] < pivo) {
            i++;
            /* Troca vetor[i] e vetor[j] */
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }
    *comp = comparacoes;

    /* Coloca o pivô na posição correta */
    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[maior];
    vetor[maior] = temp;
    int novoPivo = i + 1;

    /* Recursividade*/ 
    QuickSort1(vetor, novoPivo,comp); /* Ordena a parte esquerda */
    QuickSort1(vetor + novoPivo + 1, n - novoPivo - 1,comp); /* Ordena a parte direita */
}

void QuickSort2(int vetor[], int n) {
    if (n <= 1) {
        return; /* Se o vetor tiver tamanho 0 ou 1 já está ordenado */
    }

    int menor = 0;
    int maior = n - 1;

    /* Escolhe o pivô como um numero aleatorio entre os indices do vetor */
    int indice_aleat = Aleat(menor,maior);
    int pivo = vetor[indice_aleat];
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
    QuickSort2(vetor, novoPivo); /* Ordena a parte esquerda */
    QuickSort2(vetor + novoPivo + 1, n - novoPivo - 1); /* Ordena a parte direita */
}

void shellSort1(int vetor[], int tamanho,int *comp) {

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
            }
            vetor[proximo] = valor;
        }
        salto = salto/3;
    }
    *comp = comparacoes;
}

void shellSort2(int vetor[], int tamanho,int *comp) {

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
            }
            vetor[proximo] = valor;
        }
        salto = (salto - 1) / 2;
    }
    *comp = comps;
}

void PesqSeq(int vet[],int tam,int chave){
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

void Principal(int vet[]){
    int cont;
    for (cont = 0; cont < 1000; cont++){
        
    }
}

int main(){
    int tam,esq,dir,chave,min,max,num,qtde,contador,media;
    double desvio,somatorio;
    int vet[1024];
    int vet2[1000];

    srand(time(NULL));

    //testes
    tam = 1024;esq = 1;dir = 1023;min = 0,max = 2048;

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
            printf ("qtde :%d\n", qtde);
            break;
        case 4:
            QuickSort2(vet,tam);
            break;
        case 5:
            shellSort1(vet,tam,&qtde);
            printf ("qtde :%d\n", qtde);
            break;
        case 6:
            shellSort2(vet,tam,&qtde);
            printf ("qtde :%d\n", qtde);
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
            for (int i = 0; i < 1000; i++){
                GeraVetAleat(vet,tam,min,max);
                QuickSort1(vet,tam,&qtde);
                vet2[i] = qtde;
                contador += qtde;
            }
            printf ("Quantidade de comparacoes na ordenacao 1000x: %d\n", contador);
            for (int i = 0; i < 1000; i++){
                somatorio += (vet2[i] - media) * (vet2[i] - media);
            }
            media = contador/tam;//media
            somatorio = somatorio/1000;
            desvio = sqrt(somatorio);
            printf ("Desvio %.2f\n", desvio);

        default:
            break;
        }
    } 

    return 0;
}