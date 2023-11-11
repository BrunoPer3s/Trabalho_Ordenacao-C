#include "../Arquivo/arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenaBolha(int *v, int tam) {

  clock_t inicio, fim;
  double tempo_decorrido;
  inicio = clock();

  int aux;
  int comparacoes = 0;
  int trocas = 0;
  for (int i = 0; i < tam - 1; i++) {
    for (int j = 0; j < tam - i - 1; j++) {
      comparacoes++;
      if (v[j] > v[j + 1]) {
        aux = v[j];
        v[j] = v[j + 1];
        v[j + 1] = aux;
        trocas++;
      }
    }
  }

  char nome[50];
  char pasta[50] = "Bolha/";
  sprintf(nome, "Bolha%d.txt", tam);
  fim = clock();
  tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

  SalvarArquivoOrdenado(v, tam, nome, pasta, tempo_decorrido, comparacoes, trocas);

  char metodo[50] = "Bolha";

  Relatorios(tam, metodo, tempo_decorrido, comparacoes, trocas);
}