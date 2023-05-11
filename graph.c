#include "funk.h"
//#include "MinHeap.h"

#define MAX_VERTICES 20 // Максимальное количество вершин
#define MAX_VERTICES_GRID 100 * 100 // Максимальное количество вершин

struct Graph *graph_create(int nvertices) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->nvertices = nvertices;
  graph->m = (int **)malloc(nvertices * sizeof(int *));
  for (int i = 0; i < nvertices; i++) {
    graph->m[i] = (int *)calloc(nvertices, sizeof(int));
  }
  graph->D = (int *)calloc(nvertices + 1, sizeof(int));
  graph->H = (int *)calloc(nvertices + 1, sizeof(int));
  graph->prev = (int *)calloc(nvertices + 1, sizeof(int));
  return graph;
}

void graph_free(struct Graph *g) {
  free(g->m);
  free(g->H);
  free(g->D);
  free(g->prev);
  free(g);
}

/*/-->---->--->Генерация связного графа<---<--<----/*/
void generate_connected_graph(Graph *graph) {
  for (int i = 0; i < graph->nvertices - 1; i++) {
      int weight = 1 + rand() % 100;
      graph->m[i][i+1] = graph->m[i+1][i] = weight;
  }
  graph->m[0][graph->nvertices - 1] = graph->m[graph->nvertices - 1][0] = 1 + rand()%100;
}

/*/-->---->--->Генерация граф-решетки<---<--<----/*/
void generate_grid_graph(Graph *graph) {
  int grid_size = sqrt(graph->nvertices);
  for (int i = 0; i < grid_size; i++) {
    for (int j = 0; j < grid_size; j++) {
      int vertex = i * grid_size + j;
      int weight = rand() % 100;
      if (j + 1 < grid_size) {
        graph->m[vertex][vertex + 1] = weight;
        graph->m[vertex + 1][vertex] = weight;
      }
      if (i + 1 < grid_size) {
        graph->m[vertex][vertex + grid_size] = weight;
        graph->m[vertex + grid_size][vertex] = weight;
      }
    }
  }
}
void print_shortest(Graph *graph, int src){
	int tmp = src;
	int counter = 0;
	int *arr = (int*)calloc(sizeof(int), graph->nvertices);
	while(graph->prev[tmp] != -1){
		arr[graph->nvertices - counter - 1] = graph->prev[tmp];
		tmp = graph->prev[tmp];
		counter += 1;
	}
  printf(" path: ");
	for(int i = 0; i < graph->nvertices; i++){
	if (arr[i] != 0)
		printf("%d ", arr[i]);
	}
	printf("%d\n\n", src);
	free(arr);
}	

void print_graph(Graph *graph) {
for (int i = 0; i < graph->nvertices; i++) {
    for (int j = 0; j < graph->nvertices; j++) {
      printf("%2d ", graph->m[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}


void Dijekstra(struct heap *Q, Graph *graph, int src) {
  graph->H[src] = src;
  graph->D[src] = 0;
  graph->prev[src] = -1;
  heap_insert(Q, graph->D[src], src);
  for (int i = 1; i < graph->nvertices + 1; i++) {
    if (i != src) {
      graph->H[i] = 0;
      graph->D[i] = INT_MAX;
      graph->prev[i] = -1;
      heap_insert(Q, graph->D[i], i);
    }
  }
  for (int i = 1; i < graph->nvertices + 1; i++) {
    // for (int ii = 1; ii <= Q->nnodes; ii++) {
    // printf("{%d, %d} ", Q->nodes[ii].key, Q->nodes[ii].value);
    // }
    struct heapnode v = heap_extract_min(Q);
    // printf(" -> {%d, %d},  ", v.key, v.value);
    int vertex = v.value;
    graph->H[vertex] = vertex;

    for (int j = 1; j < graph->nvertices + 1; j++) {
      if (graph->m[vertex - 1][j - 1] && !graph->H[j]) {
        if (graph->D[vertex] + graph->m[vertex - 1][j - 1] < graph->D[j]) {
          graph->D[j] = graph->D[vertex] + graph->m[vertex - 1][j - 1];
          heap_decrease_key(Q, j, graph->D[j]);
          graph->prev[j] = vertex;
        }
      }
    }
  }
}

void get_result(struct heap *Q, Graph *graph, int src) {
  double timer = 0.0f;
  timer = wtime();
  Dijekstra(Q, graph, src);
  timer = wtime() - timer;


  printf("| vertex: %d\n", graph->nvertices);
  printf("\n time:\t %.12f\n D:\t", timer);
  for (int i = 0; i < graph->nvertices && i < 20; i++) {
    printf("%2.1d ", graph->D[i + 1]);
  }

  printf("\n prev:\t");
  for (int i = 0; i < graph->nvertices && i < 20; i++) {
    printf("%2.1d ", graph->prev[i + 1]);
  }
  printf("\n");
}