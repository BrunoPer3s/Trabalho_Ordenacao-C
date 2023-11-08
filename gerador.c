#include "./Funcoes/Arquivo/arquivo.h"
#include "./Funcoes/Gera/gera.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char *argv[]) {

  if (argc != 3) {
    printf("Você deve fornecer exatamente 2 argumentos na execução.\n");
    printf("Deve seguir o padrão: \n./gera -c n.\n");
    printf("-c -> Para crescente\n");
    printf("-d -> Para decrescente\n");
    printf("-a -> Para Aleatório\n");
    printf(" n -> Valor inteiro de caracteres que deseja gerar\n");
    exit(0);
  }

  char *metodo = argv[1];
  char *tamanho = argv[2];

  int tam = atoi(argv[2]);

  int V[tam];

  if (strcmp(metodo, "-a") == 0) {
    geraVetorAleatorio(V, tam);
  } else {
    if (strcmp(metodo, "-c") == 0) {
      geraVetorOrdenado(V, tam);
    } else {
      if (strcmp(metodo, "-d") == 0) {
        geraVetorInvOrdenado(V, tam);
      } else {
        printf("Algum dado foi passado errado!!!\n");
        exit(0);
      }
    }
  }
}