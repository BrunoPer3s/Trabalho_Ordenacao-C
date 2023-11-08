#include "../Arquivo/arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void geraVetorOrdenado(int *V, int tam) {
  for (int i = 0; i < tam; i++) {
    V[i] = i + 1;
  }
  char nome[50] = "entrada.txt";
  // sprintf(nome, "Ordenado%d.txt", tam);
  SalvarArquivoOriginal(V, tam, nome);
}

void geraVetorOrdenadoBase(int *V, int tam) {
  for (int i = 0; i < tam; i++) {
    V[i] = i + 1;
  }
}

void geraVetorInvOrdenado(int *V, int tam) {
  int i = 0;
  int aux = tam;
  while (aux > 0) {
    V[i] = aux;
    aux--;
    i++;
  }
  char nome[50] = "entrada.txt";
  // sprintf(nome, "InvOrdenado%d.txt", tam);
  SalvarArquivoOriginal(V, tam, nome);
}

void geraVetorAleatorio(int *V, int tam) {
  srand(time(NULL));
  geraVetorOrdenadoBase(V, tam);
  for (int i = tam - 1; i > 0; i--) {
    // Gere um índice aleatório no intervalo [0, i]
    int j = rand() % (i + 1);

    // Troque os elementos nas posições i e j
    int temp = V[i];
    V[i] = V[j];
    V[j] = temp;
  }
  char nome[50] = "entrada.txt";
  // sprintf(nome, "Aleatorio%d.txt", tam);
  SalvarArquivoOriginal(V, tam, nome);
}