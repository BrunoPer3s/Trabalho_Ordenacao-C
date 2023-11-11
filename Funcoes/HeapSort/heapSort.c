#include "../Arquivo/arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void criaHeap(int *v, int inicio, int final, int *comparacoes, int *trocas) {
  int aux = v[inicio];
  int j = inicio * 2 + 1;
  while (j <= final) {
    if (j < final) {
      if (v[j] < v[j + 1]) {
        j++;
      }
    }

    if (aux < v[j]) {
      (*comparacoes)++;
      (*trocas)++;
      v[inicio] = v[j];
      inicio = j;
      j = 2 * inicio + 1;
    } else {
      break;
    }
  }
  v[inicio] = aux;
}

void heapSort(int *v, int tam) {
  clock_t inicio, fim;
  double tempo_decorrido;
  inicio = clock();

  int comparacoes = 0;
  int trocas = 0;

  for (int i = (tam - 1) / 2; i >= 0; i--) {
    comparacoes++;
    criaHeap(v, i, tam - 1, &comparacoes, &trocas);
  }

  for (int i = tam - 1; i > 0; i--) {
    comparacoes++;
    trocas++;
    int aux = v[0];
    v[0] = v[i];
    v[i] = aux;
    criaHeap(v, 0, i - 1, &comparacoes, &trocas);
  }

  char nome[50];
  char pasta[50] = "HeapSort/";
  sprintf(nome, "HeapSort%d.txt", tam);
  fim = clock();
  tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

  SalvarArquivoOrdenado(v, tam, nome, pasta, tempo_decorrido, comparacoes, trocas);

  char metodo[50] = "Heap Sort";

  Relatorios(tam, metodo, tempo_decorrido, comparacoes, trocas);
}