 #include "graph.h"

graph_t *graphInit(unsigned int vertices){

  graph_t* graph     = malloc(sizeof(graph_t));
  graph->size        = vertices;
  graph->used        = 0;
  graph->vertices    = malloc(vertices* sizeof(vertex_t));

  return graph;
}

vertex_t* vertexInit(unsigned int value) {

  vertex_t* vertex    = malloc(sizeof(vertex_t));

  vertex->edges       = NULL;
  vertex->used        = 0;
  vertex->size        = 0;
  vertex->value       = value;
  vertex->index       = -1;
  vertex->prv         = -1;
  vertex->dst         = INFINITY;

  return vertex;
}

edge_t* edgeInit(unsigned int p1, unsigned int p2, double weight){

  edge_t* edge = malloc(sizeof(edge_t));

  edge->p1     =p1;
  edge->p2     =p2;
  edge->weight =weight;

  return edge;

}

void edgeResize(vertex_t *vertex, unsigned int newSize) {

  if(vertex->size== 0)vertex->size = 1;

  else vertex->size *=2;

  vertex->edges = realloc(vertex->edges, vertex->size * sizeof(edge_t));

}

void graphResize(graph_t *graph, unsigned int newSize) {

  graph->size = newSize;

  graph->vertices = realloc(graph->vertices, graph->size * sizeof(vertex_t));

}

void graphAddVertex(graph_t* graph, unsigned int value) {

  if(graph->size == graph->used) graphResize(graph,graph->size * 2);

  vertex_t* v = &graph->vertices[graph->used];

  *v = *vertexInit(value);

  graph->used++;

}

void graphAddEdge(graph_t *graph, unsigned int p1, unsigned int p2,double weight) {

  vertex_t* vertex = &graph->vertices[p1];

  if(vertex->size == vertex->used) edgeResize(vertex);


  edge_t* edge = &vertex->edges[vertex->used];

  *edge = *edgeInit(p1,p2,weight);

  graph->vertices[p1].used++;

}

void graphDestroy(graph_t* graph) {

  for(auto unsigned int i =0; i< graph->used; i++)free(graph->vertices[i].edges);

  free(graph->vertices);

  free(graph);

}
