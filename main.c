#include "funk.h"

int main() {
  int src = 1;
  struct heap *Q = heap_create( MAX_VERTICES_GRID);

  Graph *graph_test = graph_create(5);
  Graph *graph_connected = graph_create(MAX_VERTICES);
  Graph *graph_grid = graph_create(MAX_VERTICES_GRID);

  generate_connected_graph(graph_connected);
  generate_grid_graph(graph_grid);


  // Граф из лекции
  graph_test->m[0][1] = 10;
  graph_test->m[0][3] = 30;
  graph_test->m[0][4] = 100;
  graph_test->m[1][0] = 10;
  graph_test->m[1][2] = 50;
  graph_test->m[2][1] = 50;
  graph_test->m[2][3] = 20;
  graph_test->m[2][4] = 10;
  graph_test->m[3][0] = 30;
  graph_test->m[3][2] = 20;
  graph_test->m[3][4] = 60;
  graph_test->m[4][0] = 100;
  graph_test->m[4][2] = 10;
  graph_test->m[4][3] = 60;
  

  printf("\nTest graph");
  get_result(Q, graph_test, src);
  print_shortest(graph_test, 5);
  print_graph(graph_test);


  printf("\nConnected graph");
  get_result(Q, graph_connected, src);
  print_shortest(graph_connected, MAX_VERTICES);
  print_graph(graph_connected);


  printf("\nGrid graph");
  get_result(Q, graph_grid, src);
  print_shortest(graph_grid, MAX_VERTICES_GRID);
  //print_graph(graph_grid);

  
  graph_free(graph_connected);
  graph_free(graph_grid);
  graph_free(graph_test);
  heap_free(Q);

  return 0;
}
