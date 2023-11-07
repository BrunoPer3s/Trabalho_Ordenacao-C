
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void LeArquivo(int *V, int tam) {
  FILE *arq;
  arq = fopen("./Dados/Bancodedados.txt", "r");
  if (arq == NULL) {
    printf("Erro de alocacao ou Falha no arquivo \n");
  } else {
    for (int i = 0; i < tam; i++) {
      fscanf(arq, "%d\n", &V[i]);
    }
    fclose(arq);
  }
}

void imprime(int *V, int tam) {
  for (int i = 0; i < tam; i++) {
    printf("%d ", V[i]);
  }
  printf("\n");
}

int main() {
  int tam = 100;
  int V[tam];
  LeArquivo(V, tam);

  imprime(V, tam);
  /*for (int i = 0; i < tam; i++) {
    printf("%d ", V[i]);
  }
  printf("\n");*/

  return 0;
}
