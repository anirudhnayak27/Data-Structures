#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

int visited[10]={0};
// Structure for the graph
struct Graph {
    int numVertices;
    int numEdges;
    int incidenceMatrix[MAX_VERTICES][MAX_EDGES];
};

// Function to initialize the graph
void initGraph(struct Graph* graph, int vertices, int edges) {
    int i, j;
    graph->numVertices = vertices;
    graph->numEdges = edges;
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < edges; j++) {
            graph->incidenceMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int edgeIndex, int vertex1, int vertex2) {
    graph->incidenceMatrix[vertex1][edgeIndex] = 1;
    graph->incidenceMatrix[vertex2][edgeIndex] = 1;
}

// Function to delete an edge from the graph
void deleteEdge(struct Graph* graph, int edgeIndex) {
    int i;
    for (i = 0; i < graph->numVertices; i++) {
        graph->incidenceMatrix[i][edgeIndex] = 0;
    }
}

// Function to display the graph's incidence matrix
void displayGraph(struct Graph* graph) {
    int i, j;
    printf("Incidence Matrix:\n");
    for (i = 0; i < graph->numVertices; i++) {
        for (j = 0; j < graph->numEdges; j++) {
            printf("%d ", graph->incidenceMatrix[i][j]);
        }
        printf("\n");
    }
}

void DFS(int i,struct Graph* graph){
    int j;
    printf("%d ",i);
    visited[i]=1;
    for(j=0;j<graph->numVertices;j++){
        if(!visited[j] && graph->incidenceMatrix[i][j]==1){
            DFS(j,graph);
        }
    }
}

int main() {
    struct Graph graph;
    int vertices, edges, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    initGraph(&graph, vertices, edges);

    printf("Enter the incidence matrix (row by row):\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < edges; j++) {
            scanf("%d", &graph.incidenceMatrix[i][j]);
        }
    }

    printf("\nGraph:\n");
    displayGraph(&graph);

    // Example operations (add/delete edge)
    // addEdge(&graph, edges, 0, 1);
    // edges++;
    // deleteEdge(&graph, 1);
    int k;
    printf("\nEnter starting vertex: ");
    scanf("%d",&k);
    printf("\nDFS:");
    DFS(k,&graph);

    printf("\nGraph after operations:\n");
    displayGraph(&graph);

    return 0;
}
