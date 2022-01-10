#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>


struct Graph {
    int nVertex;
    int *nEdges;
    int **edges;
    int **w;
};


/*********************************************************
* Heap operations
**********************************************************/
struct Heap {
  int *value;    // Heap value: The distance of the node
  int *vertice;  // Heap node: Identifies the vertice that the node represents
  int *posV;     // The position of a vertice in the heap
  int heapSize;  // Number of elements in the heap
};

struct Heap *allocateHeap( int nVertex ) {

  struct Heap *heap = (struct Heap *) malloc( sizeof(struct Heap) );
  heap->value     = (int *) malloc( sizeof(int) * 2 * nVertex );
  heap->vertice = (int *) malloc( sizeof(int) * 2 * nVertex );
  heap->posV     = (int *) malloc( sizeof(int) * nVertex );
  heap->heapSize = nVertex;

  int i;
  for (i=0; i<2*nVertex; i++)
    heap->value[i] = INT_MAX;

  for (i=0; i<nVertex; i++) {
    heap->posV[i]    = i;
    heap->vertice[i] = i;
  }

  return heap;
}

void exchangePos( struct Heap *heap, int pos1, int pos2 ) {

    int value    = heap->value[pos1];
    int vertice = heap->vertice[pos1];

    heap->value[pos1]    = heap->value[pos2];
    heap->vertice[pos1] = heap->vertice[pos2];

    heap->value[pos2] = value;
    heap->vertice[pos2] = vertice;

    heap->posV[ heap->vertice[pos1] ] = pos1;
    heap->posV[ heap->vertice[pos2] ] = pos2;
}


int extractMin( struct Heap *heap ) {

  int verticeMin = heap->vertice[0];
 
  heap->value[0]   = heap->value[heap->heapSize-1];
  heap->vertice[0] = heap->vertice[heap->heapSize-1];
  heap->posV[ heap->vertice[0] ] = 0;

  heap->value[heap->heapSize-1] = INT_MAX;
  heap->heapSize = heap->heapSize - 1;


  // heapify  
  int pos = 0;
  while ((heap->value[2*pos+1] < heap->value[pos]) || (heap->value[2*pos+2] < heap->value[pos])) {
    if (heap->value[2*pos+1] < heap->value[2*pos+2]) {
      exchangePos( heap, 2*pos+1, pos );
      pos = 2*pos+1;
    }
    else {
      exchangePos( heap, 2*pos+2, pos );
      pos = 2*pos+2;
    }
  }
  return verticeMin;
}

// Reweighting Function
void updateValue( struct Heap *heap, int vertice, int value ) {

  int pos = heap->posV[vertice];
  heap->value[pos] = value;

  while (pos > 0 && heap->value[(pos-1)/2] > heap->value[pos]) {
    exchangePos( heap, (pos-1)/2, pos );
    pos = (pos-1)/2;
  }
}

// Create the Random Graph
struct Graph *createRandomGraph(int nVertex, int nEdges, int seed) {
    
    srandom(seed);
    
    struct Graph *graph = (struct Graph *) malloc( sizeof(struct Graph) );
    graph->nVertex = nVertex;
    graph->nEdges = (int *)  malloc( sizeof(int)    * nVertex );
    graph->edges  = (int **) malloc( sizeof(int *)  * nVertex );    
    graph->w        = (int **) malloc( sizeof(int *)  * nVertex );    

    int k,v;
    for (v=0; v<nVertex; v++) {
        graph->edges[v] = (int *) malloc( sizeof(int) * nVertex );            
        graph->w[v]       = (int *) malloc( sizeof(int) * nVertex );            
        graph->nEdges[v] = 0;
    }

    for (k=0; k<nEdges; k++) {
        int source = random() % nVertex;
        int dest   = random() % nVertex;
        int w      = 1 + (random() % 10);

        
        while (source == dest)
            dest = random() % nVertex;
        graph->edges[source][ graph->nEdges[source] ] = dest;
        graph->edges[dest][ graph->nEdges[dest] ] = source;                            
        graph->w[source][ graph->nEdges[source]++ ] = w;
        graph->w[dest][ graph->nEdges[dest]++ ] = w;

    }
   
    return graph;
}

// Main function of the Johnson algorithm
int *johnson(struct Graph *graph, int source) {
    
    int nVisitados = 0;
    int nVertex = graph->nVertex;
    
    struct Heap *heap = allocateHeap( nVertex );

    int *l = (int *) malloc( sizeof(int) * nVertex );

    int k,v;
    for (v=0; v<nVertex; v++)
      l[v] = INT_MAX;
    l[source] = 0;
         
    updateValue( heap, source, 0 );
    
    for (v=0; v<nVertex; v++) {        
        int min = extractMin(heap);

        for (k=0; k < graph->nEdges[min]; k++) {
            int dest = graph->edges[min][k];
            if ( l[ dest ] > l[min] + graph->w[min][k] ) {
                l[ dest ] = l[min] + graph->w[min][k];    
                updateValue( heap, dest, l[min] + graph->w[min][k] );
            }
        }
    }
    
    return l;
}

int main(int argc, char ** argv) {
    
    int nVertex = 0;
    int nEdges  = 0;
    int seed = 5;
    float mean_valueance = 0.0;
    
//    FILE *File;
//    if ((File=fopen(argv[1],"r"))==NULL)
//    return 1;

//    fscanf(File,"%d\n",&nVertex);
//    fscanf(File,"%d\n",&nEdges);
//    fscanf(File,"%f\n",&mean_valueance);
//    fclose(File);

    fscanf(stdin,"%d\n",&nVertex);
    fscanf(stdin,"%d\n",&nEdges);
    fscanf(stdin,"%f\n",&mean_valueance);
    
    struct Graph *graph = createRandomGraph(nVertex, nEdges, seed);

    int *value = johnson(graph,0);

    double mean = 0;
    int v;
    for (v=0; v<graph->nVertex; v++){
        mean += value[v];
    }
    
    printf("Mean SSSP = %.4f\n", mean / nVertex);
        
    assert(fabs(mean_valueance - (mean / nVertex)) <  1e-3);
     

    for (v=0; v<nVertex; v++) {
      free(graph->edges[v]);
      free(graph->w[v]);
    }
    free(graph->nEdges);
    free(graph->edges);
    free(graph->w);    
    free(graph);
            
    free(value);
    
}
