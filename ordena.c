#include "./Funcoes/Arquivo/arquivo.h"
#include "./Funcoes/Binaria/insercaoBinaria.h"
#include "./Funcoes/Bolha/bolha.h"
#include "./Funcoes/Direta/insercaoDireta.h"
#include "./Funcoes/HeapSort/heapSort.h"
#include "./Funcoes/Imprime/imprime.h"
#include "./Funcoes/QuickSort/quickSort.h"
#include "./Funcoes/Selecao/selecao.h"
#include "./Funcoes/ShellSort/shellsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char *argv[]) {

  if (argc != 4) {
    printf("Você deve fornecer exatamente 3 argumentos na execução.\n");
    printf("Deve seguir o padrão: \n./ordena bolha n entrada.txt.\n");
    printf("bolha -> Método de ordenação\n");
    printf("n -> O tamanho do vetor a ser ordenado\n");
    printf("entrada.txt -> Nome do banco de dados\n");
    exit(0);
  }

  char *metodo = argv[1];
  char *tamanho = argv[2];
  char *arquivo = argv[3];

  int tam = atoi(argv[2]);

  int V[tam];

  if (strcmp(metodo, "bolha") == 0) {
    LeArquivo(V, tam, arquivo);
    ordenaBolha(V, tam);
  } else {
    if (strcmp(metodo, "insercaodireta") == 0) {
      LeArquivo(V, tam, arquivo);
      insercaoDireta(V, tam);
    } else {
      if (strcmp(metodo, "insercaobinaria") == 0) {
        LeArquivo(V, tam, arquivo);
        insercaoBinaria(V, tam);
      } else {
        if (strcmp(metodo, "shellsort") == 0) {
          LeArquivo(V, tam, arquivo);
          shellsort(V, tam);
        } else {
          if (strcmp(metodo, "selecaodireta") == 0) {
            LeArquivo(V, tam, arquivo);
            selecao(V, tam);
          } else {
            if (strcmp(metodo, "heapsort") == 0) {
              LeArquivo(V, tam, arquivo);
              heapSort(V, tam);
            } else {
              if (strcmp(metodo, "quicksortini") == 0) {
                LeArquivo(V, tam, arquivo);
                quickSortIni(V, tam, 0, tam);
              } else {
                if (strcmp(metodo, "quicksortcentro") == 0) {
                  LeArquivo(V, tam, arquivo);
                  quickSortCentro(V, tam, 0, tam);
                } else {
                  if (strcmp(metodo, "quicksortmediana") == 0) {
                    LeArquivo(V, tam, arquivo);
                    quickSortMediana(V, tam, 0, tam);
                  } else {
                    if (strcmp(metodo, "mergesort") == 0) {
                      exit(0);
                    } else {
                      if (strcmp(metodo, "radixsort") == 0) {
                        exit(0);
                      } else {
                        if (strcmp(metodo, "bucketsort") == 0) {
                          exit(0);
                        } else {
                          printf("Algum dado foi passado errado!!!\n");
                          exit(0);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}