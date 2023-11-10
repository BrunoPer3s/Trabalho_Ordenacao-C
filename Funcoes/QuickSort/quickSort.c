#include <stdio.h>
#include <stdlib.h>

void particaoIni(int *v, int esq, int dir, int *i, int *j, int *comparacoes, int *trocas) {
  *i = esq;
  *j = dir;
  int pivo, aux;

  pivo = v[esq];

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
  int meio = (esq + dir + 1) / 2;

  if (v[esq] > v[meio] && v[esq] < v[dir]) {
    pivo = v[esq];
  } else {
    if (v[meio] > v[dir] && v[meio] < v[dir]) {
      pivo = v[meio];
    } else {
      pivo = v[dir];
    }
  }

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

void quickSortIni(int *v, int tam, int esq, int dir, int *comparacoes, int *trocas) {

  int i, j;

  particaoIni(v, esq, dir, &i, &j, comparacoes, trocas);
  (*comparacoes) += (j - esq + 1);
  (*trocas) += (j - esq + 1);
  if (i < dir) {
    quickSortIni(v, tam, i, dir, comparacoes, trocas);
  }
  if (j > esq) {
    quickSortIni(v, tam, esq, j, comparacoes, trocas);
  }
}

void quickSortMediana(int *v, int tam, int esq, int dir, int *comparacoes, int *trocas) {

  int i, j;

  particaoMediana(v, esq, dir, &i, &j, comparacoes, trocas);

  if (i < dir) {
    quickSortMediana(v, tam, i, dir, comparacoes, trocas);
  }
  if (j > esq) {
    quickSortMediana(v, tam, esq, j, comparacoes, trocas);
  }
}

void quickSortCentro(int *v, int tam, int esq, int dir, int *comparacoes, int *trocas) {

  int i, j;

  particaoCentro(v, esq, dir, &i, &j, comparacoes, trocas);

  if (i < dir) {
    quickSortCentro(v, tam, i, dir, comparacoes, trocas);
  }
  if (j > esq) {
    quickSortCentro(v, tam, esq, j, comparacoes, trocas);
  }
}