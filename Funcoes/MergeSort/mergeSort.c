#include <stdio.h>
#include <stdlib.h>

void intercalar(int *v, int tam, int inicio, int meio, int fim, int *comparacoes, int *trocas) {
  int i = inicio;
  int j = meio + 1;
  int k = 0;
  int Tmp[tam];
  while (i <= meio || j <= fim) {
    (*comparacoes)++;

    if (v[j] < v[i]) {
      (*trocas)++;
    }

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

void mergeSort(int *v, int tam, int inicio, int fim, int *comparacoes, int *trocas) {
  int meio;

  if (inicio < fim) {
    meio = (inicio + fim) / 2;
    mergeSort(v, tam, inicio, meio, comparacoes, trocas);
    mergeSort(v, tam, meio + 1, fim, comparacoes, trocas);
    intercalar(v, tam, inicio, meio, fim, comparacoes, trocas);
  }
}