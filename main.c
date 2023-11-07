#include "./Funcoes/Arquivo/arquivo.h"
#include "./Funcoes/Binaria/insercaoBinaria.h"
#include "./Funcoes/Bolha/bolha.h"
#include "./Funcoes/Direta/insercaoDireta.h"
#include "./Funcoes/Gera/gera.h"
#include "./Funcoes/HeapSort/heapSort.h"
#include "./Funcoes/Imprime/imprime.h"
#include "./Funcoes/Selecao/selecao.h"
#include "./Funcoes/ShellSort/shellsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int tam = 100;
  int V[tam];

  geraVetorOrdenado(V, tam);

  geraVetorInvOrdenado(V, tam);

  geraVetorAleatorio(V, tam);

  LeArquivo(V, tam);

  ordenaBolha(V, tam);

  LeArquivo(V, tam);

  insercaoDireta(V, tam);

  LeArquivo(V, tam);

  insercaoBinaria(V, tam);

  LeArquivo(V, tam);

  shellsort(V, tam);

  LeArquivo(V, tam);

  selecao(V, tam);

  LeArquivo(V, tam);

  heapSort(V, tam);

  return 0;
}
