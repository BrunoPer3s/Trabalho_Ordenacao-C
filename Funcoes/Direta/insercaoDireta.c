#include "../Arquivo/arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insercaoDireta(int *v, int tam) {

  clock_t inicio, fim;
  double tempo_decorrido;
  inicio = clock();

  int aux;
  int comparacoes = 0;
  int trocas = 0;
  int j;
  for (int i = 1; i < tam; i++) {
    aux = v[i];
    j = i - 1;
    comparacoes++;
    while (j >= 0 && aux < v[j]) {
      v[j + 1] = v[j];
      j--;
    }
    if (j != (i - 1)) {
      trocas++;
      v[j + 1] = aux;
    }
  }

  char nome[50];
  char pasta[50] = "Direta/";
  sprintf(nome, "InsercaoDireta%d.txt", tam);
  fim = clock();
  tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

  SalvarArquivoOrdenado(v, tam, nome, pasta, tempo_decorrido, comparacoes, trocas);
}