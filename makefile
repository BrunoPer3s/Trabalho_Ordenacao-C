all: compila executa

compila: main.o arquivo.o bolha.o gera.o imprime.o insercaoDireta.o insercaoBinaria.o shellsort.o selecao.o heapSort.o quickSort.o
	gcc main.o arquivo.o bolha.o gera.o imprime.o insercaoDireta.o insercaoBinaria.o shellsort.o selecao.o heapSort.o quickSort.o -o prog

main.o: main.c
	gcc -c main.c

arquivo.o: ./Funcoes/Arquivo/arquivo.c
	gcc -c ./Funcoes/Arquivo/arquivo.c

bolha.o: ./Funcoes/Bolha/bolha.c
	gcc -c ./Funcoes/Bolha/bolha.c

gera.o: ./Funcoes/Gera/gera.c
	gcc -c ./Funcoes/Gera/gera.c

imprime.o: ./Funcoes/Imprime/imprime.c
	gcc -c ./Funcoes/Imprime/imprime.c

insercaoDireta.o: ./Funcoes/Direta/insercaoDireta.c
	gcc -c ./Funcoes/Direta/insercaoDireta.c

insercaoBinaria.o: ./Funcoes/Binaria/insercaoBinaria.c
	gcc -c ./Funcoes/Binaria/insercaoBinaria.c

shellsort.o: ./Funcoes/ShellSort/shellsort.c
	gcc -c ./Funcoes/ShellSort/shellsort.c

selecao.o: ./Funcoes/Selecao/selecao.c
	gcc -c ./Funcoes/Selecao/selecao.c

heapSort.o: ./Funcoes/HeapSort/heapSort.c
	gcc -c ./Funcoes/HeapSort/heapSort.c

quickSort.o: ./Funcoes/QuickSort/quickSort.c
	gcc -c ./Funcoes/QuickSort/quickSort.c

executa:
	./prog

clean:
	rm main.o arquivo.o bolha.o gera.o imprime.o insercaoDireta.o insercaoBinaria.o shellsort.o selecao.o heapSort.o quickSort.o prog