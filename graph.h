#include <limits.h>
#include <stdlib.h>
#include <sys/time.h>
#include <limits.h>
#include <stdio.h>

struct Graph *graph_create(int nvertices);
void graph_free(struct Graph *g);
double wtime();
void generate_connected_graph(Graph *graph)
void generate_grid_graph(Graph *graph)
void print_shortest(Graph *graph, int src)
void print_graph(Graph *graph)
void Dijekstra(struct heap *Q, Graph *graph, int src)
void get_result(struct heap *Q, Graph *graph, int src)


typedef struct Graph {
  int nvertices; /*/    Число вершин       /*/
  int **m;       /*/    Матрица n x n      /*/
  int *D;        /*/   кратчайшие пути     /*/
  int *H;        /*/  посещенные вершины   /*/
  int *prev;     /*/ восстановление  пути  /*/
} Graph;