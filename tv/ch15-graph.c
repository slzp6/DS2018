/* code: ch15-graph.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>

#define  DIRECTED_GRAPH 1
#define  UNDIRECTED_GRAPH 2

struct g_node {
  int vertex;
  struct g_node *next;
};
typedef struct g_node G_NODE_TYPE;

struct g_list {
  int num_members;
  G_NODE_TYPE *head;
};
typedef struct g_list G_LIST_TYPE;

struct graph {
  int num_vertices;
  int graph_cat;
  G_LIST_TYPE *g_list_array;
};
typedef struct graph G_GRAPH_TYPE;

/* ------------------------------------------ */
G_NODE_TYPE *graph_newnode (int v) {
  G_NODE_TYPE *node;
  node = malloc (sizeof (G_NODE_TYPE));
  if (!node) {
    printf ("ERROR: Can not allocate memory.\n");
    exit (-1);
  }
  node->vertex = v;
  node->next = NULL;

  return node;
}

/* ------------------------------------------ */
G_GRAPH_TYPE *graph_create (int n, int category) {
  int i;
  G_GRAPH_TYPE *graph;
  graph = malloc (sizeof (G_GRAPH_TYPE));
  if (!graph) {
    printf ("ERROR: Can not allocate memory.\n");
    exit (-1);
  }
  graph->num_vertices = n;
  graph->graph_cat = category;

  graph->g_list_array = malloc (n * sizeof (G_LIST_TYPE));
  if (!graph->g_list_array) {
    printf ("ERROR: Can not  allocate memory.\n");
    exit (-1);
  }
  for (i = 0; i < n; i++) {
    graph->g_list_array[i].head = NULL;
    graph->g_list_array[i].num_members = 0;
  }
  return graph;
}

/* ------------------------------------------ */
void graph_add_edge (G_GRAPH_TYPE * graph, int source, int target) {
  G_NODE_TYPE *node;

  source = source - 'a';
  target = target - 'a';
  node = graph_newnode (target);
  node->next = graph->g_list_array[source].head;
  graph->g_list_array[source].head = node;
  graph->g_list_array[source].num_members++;

  if (graph->graph_cat == UNDIRECTED_GRAPH) {
    node = graph_newnode (source);
    node->next = graph->g_list_array[target].head;
    graph->g_list_array[target].head = node;
    graph->g_list_array[target].num_members++;
  }
}

/* ------------------------------------------ */
void graph_destroy (G_GRAPH_TYPE * graph) {
  int v;
  G_NODE_TYPE *g_list;
  G_NODE_TYPE *tmp;

  if (graph) {
    if (graph->g_list_array) {
      for (v = 0; v < graph->num_vertices; v++) {
	g_list = graph->g_list_array[v].head;
	while (g_list) {
	  tmp = g_list;
	  g_list = g_list->next;
	  free (tmp);
	}
      }
      free (graph->g_list_array);
    }
    free (graph);
  }
}

/* ------------------------------------------ */
void graph_display (G_GRAPH_TYPE * graph) {
  int i;
  printf ("#vertices: %d\n", graph->num_vertices);
  printf ("------------------\n");
  for (i = 0; i < graph->num_vertices; i++) {
    G_NODE_TYPE *g_list = graph->g_list_array[i].head;
    printf ("%c: ", i + 'a');
    while (g_list) {
      printf ("%c ", g_list->vertex + 'a');
      g_list = g_list->next;
    }
    printf ("\n");
  }
  printf ("------------------\n");
}

/* ------------------------------------------ */
int main () {
  G_GRAPH_TYPE *ug;
  ug = graph_create (4, UNDIRECTED_GRAPH);
  graph_add_edge (ug, 'c', 'd');
  graph_add_edge (ug, 'c', 'b');
  graph_add_edge (ug, 'c', 'a');
  graph_add_edge (ug, 'b', 'a');
  printf ("graph (undirected)\n");
  graph_display (ug);
  graph_destroy (ug);


  G_GRAPH_TYPE *dg;
  dg = graph_create (4, DIRECTED_GRAPH);
  graph_add_edge (dg, 'c', 'd');
  graph_add_edge (dg, 'c', 'b');
  graph_add_edge (dg, 'c', 'a');
  graph_add_edge (dg, 'b', 'a');
  printf ("graph (directed)\n");
  graph_display (dg);
  graph_destroy (dg);

  return 0;
}
