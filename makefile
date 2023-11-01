all: compila executa
compila: main.o arquivo.o bolha.o gera.o imprime.o insercaoDireta.o insercaoBinaria.o shellsort.o selecao.o heapSort.o
	gcc main.o arquivo.o bolha.o gera.o imprime.o insercaoDireta.o insercaoBinaria.o shellsort.o selecao.o heapSort.o -o prog
main.o: main.c
	gcc -c main.c
arquivo.o: arquivo.c
	gcc -c arquivo.c
bolha.o: bolha.c
	gcc -c bolha.c
gera.o: gera.c
	gcc -c gera.c
imprime.o: imprime.c
	gcc -c imprime.c
insercaoDireta.o: insercaoDireta.c
	gcc -c insercaoDireta.c
insercaoBinaria.o: insercaoBinaria.c
	gcc -c insercaoBinaria.c
shellsort.o: shellsort.c
	gcc -c shellsort.c
selecao.o: selecao.c
	gcc -c selecao.c
heapSort.o: heapSort.c
	gcc -c heapSort.c
executa:
	./prog
clean:
	rm main.o arquivo.o bolha.o gera.o imprime.o insercaoDireta.o insercaoBinaria.o shellsort.o selecao.o heapSort.o prog