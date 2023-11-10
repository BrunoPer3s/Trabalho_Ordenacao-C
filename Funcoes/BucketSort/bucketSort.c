#include <stdio.h>
#include <stdlib.h>

void particao(int *v, int esq, int dir, int *i, int *j, int *comparacoes, int *trocas) {
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

void quickSort(int *v, int esq, int dir, int *comparacoes, int *trocas) {
  int i, j;
  particao(v, esq, dir, &i, &j, comparacoes, trocas);
  if (i < dir) {
    quickSort(v, i, dir, comparacoes, trocas);
  }
  if (j > esq) {
    quickSort(v, esq, j, comparacoes, trocas);
  }
}

void bucketSort(int *v, int n, int *comparacoes, int *trocas) {

  int max_val = v[0];
  int min_val = v[0];

  for (int i = 1; i < n; i++) {
    if (v[i] > max_val) {
      max_val = v[i];
    }
    if (v[i] < min_val) {
      min_val = v[i];
    }
  }

  int num_buckets = 10;

  int buckets[num_buckets][n];
  int bucket_counts[num_buckets];

  for (int i = 0; i < num_buckets; i++) {
    bucket_counts[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    int bucket_index = (v[i] - min_val) / (max_val - min_val + 1) * (num_buckets - 1);
    buckets[bucket_index][bucket_counts[bucket_index]++] = v[i];
  }

  for (int i = 0; i < num_buckets; i++) {
    if (bucket_counts[i] > 0) {

      quickSort(buckets[i], 0, bucket_counts[i] - 1, comparacoes, trocas);
    }
  }
  int index = 0;
  for (int i = 0; i < num_buckets; i++) {
    for (int j = 0; j < bucket_counts[i]; j++) {
      v[index++] = buckets[i][j];
    }
  }
}