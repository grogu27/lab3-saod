a.out : main.o graph.o MinHeap.o
	gcc main.o graph.o MinHeap.o -o a.out -lm

main.o : main.c
	gcc -c main.c -o main.o -lm

coder.o : graph.c
	gcc -c graph.c -o graph.o -lm

command.o : MinHeap.c
	gcc -c MinHeap.c -o MinHeap.o -lm
