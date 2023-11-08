#include "../Arquivo/arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insercaoBinaria(int *v, int tam) {

  clock_t inicio, fim;
  double tempo_decorrido;
  inicio = clock();

  int comparacoes = 0;
  int trocas = 0;
  int j;
  int aux = 0;
  int esq;
  int dir;
  int meio;
  for (int i = 1; i < tam; i++) {
    aux = v[i];
    esq = 0;
    dir = i - 1;
    while (esq <= dir) {
      comparacoes++;
      meio = (esq + dir) / 2;
      if (v[meio] <= aux) {
        esq = meio + 1;
      } else {
        dir = meio - 1;
      }
    }
    for (int j = i; j > esq; j--) {
      v[j] = v[j - 1];
      trocas++;
    }
    v[esq] = aux;
  }

  char nome[50];
  char pasta[50] = "Binaria/";
  sprintf(nome, "InsercaoBinaria%d.txt", tam);
  fim = clock();
  tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

  SalvarArquivoOrdenado(v, tam, nome, pasta, tempo_decorrido, comparacoes, trocas);
}