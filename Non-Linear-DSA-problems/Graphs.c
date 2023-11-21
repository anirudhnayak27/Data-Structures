#include <stdio.h>
#include <stdlib.h>

// Maximum number of vertices
#define MAX_VERTICES 10

// Structure for a graph node
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for the graph
struct Graph {
    struct Node* adjacencyList[MAX_VERTICES];
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the graph
void initGraph(struct Graph* graph) {
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        graph->adjacencyList[i] = NULL;
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from source to destination
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // Uncomment the following lines if the graph is undirected
    /*
    // Add an edge from destination to source
    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
    */
}

// Function to delete an edge from the graph
void deleteEdge(struct Graph* graph, int src, int dest) {
    struct Node* currNode = graph->adjacencyList[src];
    struct Node* prevNode = NULL;

    // Find the edge to be deleted
    while (currNode != NULL && currNode->vertex != dest) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    // If the edge is found, delete it
    if (currNode != NULL) {
        if (prevNode != NULL) {
            prevNode->next = currNode->next;
        } else {
            graph->adjacencyList[src] = currNode->next;
        }
        free(currNode);
    }
}

// Function to display the graph
void displayGraph(struct Graph* graph) {
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        struct Node* currNode = graph->adjacencyList[i];
        printf("Adjacency list of vertex %d\n", i);
        while (currNode != NULL) {
            printf("%d -> ", currNode->vertex);
            currNode = currNode->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct Graph graph;
    initGraph(&graph);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 4);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);

    printf("Graph after insertions:\n");
    displayGraph(&graph);

    deleteEdge(&graph, 1, 4);
    deleteEdge(&graph, 2, 3);

    printf("Graph after deletions:\n");
    displayGraph(&graph);

    return 0;
}
