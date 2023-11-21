// BFS in graphs
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_VERTICES 10
struct Node {
    int vertex;
    struct Node* next;
};
struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}
int isEmpty(struct Queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1)
        printf("\nQueue is Full!!");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            printf("Resetting queue ");
            q->front = q->rear = -1;
        }
    }
    return item;
}

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
bool BFS(struct Graph* graph, int startVertex, bool visited[]) {
    struct Node* temp;
    int currVertex;
    struct Queue* q = createQueue();
    visited[startVertex] = true;
    enqueue(q, startVertex);
    while (!isEmpty(q)) {
        currVertex = dequeue(q);
        printf("Visited %d\n", currVertex);
        temp = graph->adjacencyList[currVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (visited[adjVertex] == false) {
                visited[adjVertex] = true;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    return true;
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    initGraph(graph);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 6);
    printGraph(graph);
    bool visited[MAX_VERTICES];
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
    }
    BFS(graph, 0, visited);
    return 0;
}
