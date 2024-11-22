#ifndef FUNCOES
#define FUNCOES

int Aleat(int min, int max);

void GeraVetAleat(int vet[], int tam);

void SelecSort(int vet[],int n,int *trocas);

void QuickSort1(int vetor[], int n, int *comp, int *trocas);

void QuickSort2(int vetor[], int n,  int *comp, int *troca);

void shellSort1(int vetor[], int tamanho, int *comp,int *troca);

void shellSort2(int vetor[], int tamanho, int *comp, int *troca);

void PesqSeq(int vet[],int tam,int chave);

void BuscaBin(int vet[],int chave,int esq,int dir);

void ImprimeParteVet(int vet[]);

void mediacompPrimeiroShell(int vet[], int vet2[], int *media);

void mediacompSegundoShell(int vet[], int vet2[], int *media);

void mediacompPrimeiroQuick(int vet[], int vet2[], int *media);

void mediacompSegundoQuick(int vet[], int vet2[], int *media);

void desvio_padrao(int vet2[], int media);

#endif