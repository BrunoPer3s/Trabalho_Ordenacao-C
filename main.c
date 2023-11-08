#include "./Funcoes/Arquivo/arquivo.h"
#include "./Funcoes/Binaria/insercaoBinaria.h"
#include "./Funcoes/Bolha/bolha.h"
#include "./Funcoes/Direta/insercaoDireta.h"
#include "./Funcoes/Gera/gera.h"
#include "./Funcoes/HeapSort/heapSort.h"
#include "./Funcoes/Imprime/imprime.h"
#include "./Funcoes/QuickSort/quickSort.h"
#include "./Funcoes/Selecao/selecao.h"
#include "./Funcoes/ShellSort/shellsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  int tam = 100;
  int V[tam];
  char bancodedados[50];

  sprintf(bancodedados, "Aleatorio%d.txt", tam);

  // char bancodedados[50]="Aleatorio10000.txt";

  geraVetorOrdenado(V, tam);

  geraVetorInvOrdenado(V, tam);

  geraVetorAleatorio(V, tam);

  LeArquivo(V, tam, bancodedados);

  ordenaBolha(V, tam);

  LeArquivo(V, tam, bancodedados);

  insercaoDireta(V, tam);

  LeArquivo(V, tam, bancodedados);

  insercaoBinaria(V, tam);

  LeArquivo(V, tam, bancodedados);

  shellsort(V, tam);

  LeArquivo(V, tam, bancodedados);

  selecao(V, tam);

  LeArquivo(V, tam, bancodedados);

  heapSort(V, tam);

  LeArquivo(V, tam, bancodedados);

  quickSortIni(V, tam, 0, tam);

  LeArquivo(V, tam, bancodedados);

  quickSortCentro(V, tam, 0, tam);

  LeArquivo(V, tam, bancodedados);

  quickSortMediana(V, tam, 0, tam);

  return 0;
}