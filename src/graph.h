#pragma once

#include <stdlib.h>
#include <math.h>

typedef struct __edge {

  unsigned int p1,p2;

  double weight;

} edge_t;

typedef struct __vertex {

  edge_t* edges;

  unsigned int size, used , value;

  int index, prv;

  double dst;

} vertex_t;

typedef struct __graph {

  vertex_t* vertices;

  unsigned int size, used;

} graph_t;

vertex_t *vertexInit(unsigned int);

edge_t *edgeInit(unsigned int, unsigned int, double);

graph_t*    graphInit(unsigned int);

void        edgeResize(vertex_t*);

void        graphResize(graph_t*, unsigned int);

void        graphAddVertex(graph_t *, unsigned int);

void        graphAddEdge(graph_t *, unsigned int, unsigned int, double);

void        graphDestroy(graph_t*);
