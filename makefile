all: comp comp2

comp: gerador.o arquivo.o gera.o
	gcc gerador.o arquivo.o gera.o -o gera

comp2: ordena.o arquivo.o bolha.o imprime.o insercaoDireta.o insercaoBinaria.o shellSort.o selecao.o heapSort.o quickSort.o mergeSort.o bucketSort.o radixSort.o
	gcc ordena.o arquivo.o bolha.o imprime.o insercaoDireta.o insercaoBinaria.o shellSort.o selecao.o heapSort.o quickSort.o mergeSort.o bucketSort.o radixSort.o -o ordena

gerador.o: gerador.c
	gcc -c gerador.c

ordena.o: ordena.c
	gcc -c ordena.c

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

shellSort.o: ./Funcoes/ShellSort/shellSort.c
	gcc -c ./Funcoes/ShellSort/shellSort.c

selecao.o: ./Funcoes/Selecao/selecao.c
	gcc -c ./Funcoes/Selecao/selecao.c

heapSort.o: ./Funcoes/HeapSort
	gcc -c ./Funcoes/HeapSort/heapSort.c

quickSort.o: ./Funcoes/QuickSort/quickSort.c
	gcc -c ./Funcoes/QuickSort/quickSort.c

mergeSort.o: ./Funcoes/MergeSort/mergeSort.c
	gcc -c ./Funcoes/MergeSort/mergeSort.c

bucketSort.o: ./Funcoes/BucketSort/bucketSort.c
	gcc -c ./Funcoes/BucketSort/bucketSort.c

radixSort.o: ./Funcoes/RadixSort/radixSort.c
	gcc -c ./Funcoes/RadixSort/radixSort.c

clean:
	rm gerador.o ordena.o arquivo.o bolha.o gera.o imprime.o insercaoDireta.o insercaoBinaria.o shellSort.o selecao.o heapSort.o quickSort.o mergeSort.o bucketSort.o radixSort.o gera ordena