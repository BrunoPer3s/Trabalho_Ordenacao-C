#include "arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selecao(int *v, int tam) {

  clock_t inicio, fim;
  double tempo_decorrido;
  inicio = clock();

  int comparacoes = 0;
  int trocas = 0;
  int menor;

  for (int i = 0; i < tam - 1; i++) {
    menor = i;
    for (int j = i + 1; j < tam; j++) {
      comparacoes++;
      if (v[j] < v[menor])
        menor = j;
    }
    if (i != menor) {
      int aux = v[i];
      v[i] = v[menor];
      v[menor] = aux;
      trocas++;
    }
  }

  char nome[50];
  sprintf(nome, "Selecao%d.txt", tam);
  fim = clock();
  tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

  SalvarArquivoOrdenado(v, tam, nome, tempo_decorrido, comparacoes, trocas);
}