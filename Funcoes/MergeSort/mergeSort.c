#include "../Arquivo/arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t comeco, final;
double tempo_decorrido;
int comparacoes = 0;
int trocas = 0;

void intercalar(int *v, int tam, int inicio, int meio, int fim) {
  int i = inicio;
  int j = meio + 1;
  int k = 0;
  int Tmp[tam];
  while (i <= meio || j <= fim) {
    if (i == meio + 1 || (v[j] < v[i] && j != fim + 1)) {
      Tmp[k] = v[j];
      j++;
      k++;
    } else {
      Tmp[k] = v[i];
      i++;
      k++;
    }
  }
  for (i = inicio; i <= fim; i++) {
    v[i] = Tmp[i - inicio];
  }
}

void mergeSort(int *v, int tam, int inicio, int fim) {
  int meio;
  if (inicio + fim == tam) {
    comeco = clock();
  }
  if (inicio < fim) {
    meio = (inicio + fim) / 2;
    mergeSort(v, tam, inicio, meio);
    mergeSort(v, tam, meio + 1, fim);
    intercalar(v, tam, inicio, meio, fim);
  }
  if (inicio + fim == tam) {
    char nome[50];
    char pasta[50] = "MergeSort/";
    sprintf(nome, "MergeSort%d.txt", tam);
    final = clock();
    tempo_decorrido = ((double)(final - comeco)) / CLOCKS_PER_SEC;
    SalvarArquivoOrdenado(v, tam, nome, pasta, tempo_decorrido, comparacoes, trocas);
  }
}