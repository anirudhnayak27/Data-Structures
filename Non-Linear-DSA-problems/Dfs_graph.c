// DFS in graphs
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_VERTICES 10
struct Node {
    int vertex;
    struct Node* next;
};
struct Graph {
    struct Node* adjacencyList[MAX_VERTICES];
};
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void initGraph(struct Graph* graph) {
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        graph->adjacencyList[i] = NULL;
    }
}
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}
void deleteEdge(struct Graph* graph, int src, int dest) {
    struct Node* currNode = graph->adjacencyList[src];
    struct Node* prevNode = NULL;
    while (currNode != NULL && currNode->vertex != dest) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    if (currNode == NULL) {
        return;
    }
    if (prevNode == NULL) {
        graph->adjacencyList[src] = currNode->next;
    }
    else {
        prevNode->next = currNode->next;
    }
    free(currNode);
}
void printGraph(struct Graph* graph) {
    int v;
    for (v = 0; v < MAX_VERTICES; v++) {
        struct Node* temp = graph->adjacencyList[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
bool DFS(struct Graph* graph, int v, bool visited[]) {
    visited[v] = true;
    printf("%d ", v);
    struct Node* temp = graph->adjacencyList[v];
    while (temp) {
        if (visited[temp->vertex] == false) {
            DFS(graph, temp->vertex, visited);
        }
        temp = temp->next;
    }
}
int main() {
    struct Graph graph;
    initGraph(&graph);
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 0);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 3);
    printGraph(&graph);
    bool visited[MAX_VERTICES];
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
    }
    printf("\n DFS traversal starting from vertex 2: ");
    DFS(&graph, 2, visited);
    return 0;
}