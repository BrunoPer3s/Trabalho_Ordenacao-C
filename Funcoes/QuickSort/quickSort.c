#include "../Arquivo/arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void particaoIni(int *v, int esq, int dir, int *i, int *j, int *comparacoes, int *trocas) {

  *i = esq;
  *j = dir;
  int pivo, aux;

  pivo = dir;

  while (*i <= *j) {
    while (v[*i] < pivo && *i < dir) {
      (*i)++;
      (*comparacoes)++;
    }
    while (v[*j] > pivo && *j > esq) {
      (*j)--;
      (*comparacoes)++;
    }
    if (*i <= *j) {
      aux = v[*i];
      v[*i] = v[*j];
      v[*j] = aux;
      (*i)++;
      (*j)--;
      (*trocas)++;
    }
  }
}

void particaoMediana(int *v, int esq, int dir, int *i, int *j, int *comparacoes, int *trocas) {

  *i = esq;
  *j = dir;
  int pivo, aux;
  int mediana;
  int meio = (esq + dir) / 2;

  if (v[esq] > v[meio] && v[esq] < v[dir]) {
    mediana = esq;
  } else {
    if (v[meio] > v[dir] && v[meio] < v[dir]) {
      mediana = meio;
    } else {
      mediana = dir;
    }
  }

  pivo = mediana;

  while (*i <= *j) {
    while (v[*i] < pivo && *i < dir) {
      (*i)++;
      (*comparacoes)++;
    }
    while (v[*j] > pivo && *j > esq) {
      (*j)--;
      (*comparacoes)++;
    }
    if (*i <= *j) {
      aux = v[*i];
      v[*i] = v[*j];
      v[*j] = aux;
      (*i)++;
      (*j)--;
      (*trocas)++;
    }
  }
}

void particaoCentro(int *v, int esq, int dir, int *i, int *j, int *comparacoes, int *trocas) {
  *i = esq;
  *j = dir;
  int pivo, aux;

  pivo = v[(esq + dir) / 2];

  while (*i <= *j) {
    while (v[*i] < pivo && *i < dir) {
      (*i)++;
      (*comparacoes)++;
    }
    while (v[*j] > pivo && *j > esq) {
      (*j)--;
      (*comparacoes)++;
    }
    if (*i <= *j) {
      aux = v[*i];
      v[*i] = v[*j];
      v[*j] = aux;
      (*i)++;
      (*j)--;
      (*trocas)++;
    }
  }
}

void quickSortIni(int *v, int tam, int esq, int dir) {

  clock_t inicio, fim;
  double tempo_decorrido;
  inicio = clock();
  int comparacoes = 0;
  int trocas = 0;
  int i, j;

  particaoIni(v, esq, dir, &i, &j, &comparacoes, &trocas);
  comparacoes += (j - esq + 1);
  trocas += (j - esq + 1);
  if (i < dir) {
    quickSortIni(v, tam, i, dir);
  }
  if (j > esq) {
    quickSortIni(v, tam, esq, j);
  }

  if ((dir + esq) == tam) {
    char nome[50];
    sprintf(nome, "QuickSortIni%d.txt", tam);
    fim = clock();
    tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    SalvarArquivoOrdenado(v, tam, nome, tempo_decorrido, comparacoes, trocas);
  }
}

void quickSortMediana(int *v, int tam, int esq, int dir) {

  clock_t inicio, fim;
  double tempo_decorrido;
  inicio = clock();
  int comparacoes = 0;
  int trocas = 0;
  int i, j;

  particaoMediana(v, esq, dir, &i, &j, &comparacoes, &trocas);
  comparacoes += (j - esq + 1);
  trocas += (j - esq + 1);
  if (i < dir) {
    quickSortMediana(v, tam, i, dir);
  }
  if (j > esq) {
    quickSortMediana(v, tam, esq, j);
  }

  if ((dir + esq) == tam) {
    char nome[50];
    sprintf(nome, "QuickSortMediana%d.txt", tam);
    fim = clock();
    tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    SalvarArquivoOrdenado(v, tam, nome, tempo_decorrido, comparacoes, trocas);
  }
}

void quickSortCentro(int *v, int tam, int esq, int dir) {

  clock_t inicio, fim;
  double tempo_decorrido;
  inicio = clock();
  int comparacoes = 0;
  int trocas = 0;
  int i, j;

  particaoCentro(v, esq, dir, &i, &j, &comparacoes, &trocas);
  comparacoes += (j - esq + 1);
  trocas += (j - esq + 1);
  if (i < dir) {
    quickSortCentro(v, tam, i, dir);
  }
  if (j > esq) {
    quickSortCentro(v, tam, esq, j);
  }

  if ((dir + esq) == tam) {
    char nome[50];
    sprintf(nome, "QuickSortCentro%d.txt", tam);
    fim = clock();
    tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    SalvarArquivoOrdenado(v, tam, nome, tempo_decorrido, comparacoes, trocas);
  }
}