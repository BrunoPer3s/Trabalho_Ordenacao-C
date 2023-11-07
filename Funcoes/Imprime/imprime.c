#include <stdio.h>
#include <stdlib.h>

void imprime(int *V, int tam) {
  for (int i = 0; i < tam; i++) {
    printf("%d ", V[i]);
  }
  printf("\n");
}