#ifndef FUNCOES
#define FUNCOES

int Aleat(int min, int max);

void GeraVetAleat(int vet[], int tam,int min, int max);

void SelecSort(int vet[],int n);

void QuickSort1(int vetor[], int n, int *comp);

void QuickSort2(int vetor[], int n,  int *comp, int *troca);

void shellSort1(int vetor[], int tamanho, int *comp,int *troca);

void shellSort2(int vetor[], int tamanho, int *comp);

void PesqSeq(int vet[],int tam,int chave);

void BuscaBin(int vet[],int chave,int esq,int dir);

void ImprimeParteVet(int vet[]);

#endif