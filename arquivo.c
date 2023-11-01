#include <stdio.h>
#include <stdlib.h>

void LeArquivo(int *V, int tam) {
  FILE *arq;
  arq = fopen("Bancodedados.txt", "r");
  if (arq == NULL) {
    printf("Erro de alocacao ou Falha no arquivo \n");
  } else {
    for (int i = 0; i < tam; i++) {
      fscanf(arq, "%d\n", &V[i]);
    }
    fclose(arq);
  }
}

void SalvarArquivoOriginal(int *V, int tam, char *nome) {
  FILE *arq;
  arq = fopen(nome, "w");

  if (arq == NULL) {
    printf("Erro de alocacao ou Falha no arquivo \n");
  } else {
    for (int i = 0; i < tam; i++) {
      fprintf(arq, "%d", V[i]);
      if (i < tam - 1)
        fprintf(arq, "\n");
    }
    fclose(arq);
  }
}

void SalvarArquivoOrdenado(int *V, int tam, char *nome, double time, int comparacoes, int trocas) {
  FILE *arq;
  arq = fopen(nome, "w");

  if (arq == NULL) {
    printf("Erro de alocacao ou Falha no arquivo \n");
  } else {
    for (int i = 0; i < tam; i++) {
      fprintf(arq, "%d", V[i]);
      if (i < tam - 1)
        fprintf(arq, "\n");
    }
    fprintf(arq, "\n\nTempo decorrido: %f", time);
    fprintf(arq, "\nComparações: %d", comparacoes);
    fprintf(arq, "\nTrocas: %d", trocas);
    fclose(arq);
  }
}