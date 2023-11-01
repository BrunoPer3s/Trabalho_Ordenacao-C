#include "arquivo.h"
#include "bolha.h"
#include "gera.h"
#include "imprime.h"
#include "insercaoBinaria.h"
#include "insercaoDireta.h"
#include "shellsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int tam = 100;
  int V[tam];
  LeArquivo(V, tam);

  geraVetorOrdenado(V, tam);

  geraVetorInvOrdenado(V, tam);

  geraVetorAleatorio(V, tam);

  ordenaBolha(V, tam);

  LeArquivo(V, tam);

  insercaoDireta(V, tam);

  LeArquivo(V, tam);

  insercaoBinaria(V, tam);

  LeArquivo(V, tam);

  shellsort(V, tam);

  // imprime(V, tam);
  /*for (int i = 0; i < tam; i++) {
    printf("%d ", V[i]);
  }
  printf("\n");*/

  return 0;
}
