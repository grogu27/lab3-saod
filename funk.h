#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define MAX_VERTICES 20 // Максимальное количество вершин
#define MAX_VERTICES_GRID 100 * 100 // Максимальное количество вершин

typedef struct heapnode {
  int key;   
  int value; 
} heapnode;

typedef struct heap {
  int maxsize;            /* Максимальный размер кучи */
  int nnodes;             /* Число элементов */
  struct heapnode *nodes; //* Массив элементов. 
                             
} heap;

struct heap *heap_create(int maxsize);
void heap_free(struct heap *h);
void heap_swap(struct heapnode *a, struct heapnode *b);
struct heapnode *heap_min(struct heap *h);
int get_index(struct heap *h, int value);
int heap_insert(struct heap *h, int key, int value);
void heap_heapify(struct heap *h, int index);
struct heapnode heap_extract_min(struct heap *h);
int heap_decrease_key(struct heap *h, int index, int newkey);
double wtime();

typedef struct Graph {
  int nvertices; /*/    Число вершин       /*/
  int **m;       /*/    Матрица n x n      /*/
  int *D;        /*/   кратчайшие пути     /*/
  int *H;        /*/  посещенные вершины   /*/
  int *prev;     /*/ восстановление  пути  /*/
} Graph;

struct Graph *graph_create(int nvertices);
void graph_free(struct Graph *g);
void generate_connected_graph(Graph *graph);
void generate_grid_graph(Graph *graph);
void print_shortest(Graph *graph, int src);
void print_graph(Graph *graph);
void Dijekstra(struct heap *Q, Graph *graph, int src);
void get_result(struct heap *Q, Graph *graph, int src);


