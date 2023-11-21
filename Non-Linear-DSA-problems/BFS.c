//Queues: Linked List Implementation
#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Queue {
    struct Node *front, *rear;
};
struct Node* newNode(int k) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = k;
    temp->next = NULL;
    return temp;
}
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(struct Queue* q, int k) {
    struct Node* temp = newNode(k);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;
    struct Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    return temp;
}
int main() {
    struct Queue* q = createQueue();
    int u;
    int i=4;
    int visited[7]={0};
    int adj[7][7]={{0,1,1,0,0,0,0},
                   {1,0,0,1,1,0,0},
                   {1,0,0,0,0,1,1},
                   {0,1,0,0,0,0,0},
                   {0,1,0,0,0,0,0},
                   {0,0,1,0,0,0,0},
                   {0,0,1,0,0,0,0}};
    enqueue(q,0);
    visited[i]=1;
    printf("%d ",i);
    while(q->front!=NULL){
        u=q->front->data;
        dequeue(q);
        printf("%d ",u);
        for(i=0;i<7;i++){
            if(adj[u][i]==1 && visited[i]==0){
                enqueue(q,i);
                visited[i]=1;
            }
        }
    }

    return 0;
}
