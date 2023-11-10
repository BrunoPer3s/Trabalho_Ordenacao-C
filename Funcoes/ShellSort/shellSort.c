#include "../Arquivo/arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellsort(int *v, int tam) {

  clock_t inicio, fim;
  double tempo_decorrido;
  inicio = clock();

  int aux;
  int comparacoes = 0;
  int trocas = 0;
  int j;
  int h = 1;

  while (h < tam) {
    h = (3 * h) + 1;
  }
  while (h > 1) {
    h = (h / 3);
    for (int i = h; i < tam; i++) {
      aux = v[i];
      j = i - h;
      while (j >= 0 && aux < v[j]) {
        v[j + h] = v[j];
        j = j - h;
        comparacoes++;
        trocas++;
      }
      v[j + h] = aux;
    }
  }

  char nome[50];
  char pasta[50] = "ShellSort/";
  sprintf(nome, "ShellSort%d.txt", tam);
  fim = clock();
  tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

  SalvarArquivoOrdenado(v, tam, nome, pasta, tempo_decorrido, comparacoes, trocas);
}