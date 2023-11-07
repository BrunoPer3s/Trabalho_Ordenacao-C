#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LeArquivo(int *V, int tam) {
  FILE *arq;
  arq = fopen("./Dados/Bancodedados.txt", "r");
  if (arq == NULL) {
    printf("Erro de alocacao ou Falha no arquivo\n");
  } else {
    for (int i = 0; i < tam; i++) {
      fscanf(arq, "%d\n", &V[i]);
    }
    fclose(arq);
  }
}

void SalvarArquivoOriginal(int *V, int tam, char *nome) {
  FILE *arq;
  char caminho[50] = "./Dados/";
  strcat(caminho, nome);
  arq = fopen(caminho, "w");

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

  char caminho[50] = "./Saidas/";
  strcat(caminho, nome);
  arq = fopen(caminho, "w");

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