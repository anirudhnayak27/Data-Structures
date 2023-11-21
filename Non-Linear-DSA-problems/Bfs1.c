#include<stdio.h>
#include<stdlib.h>
struct graph{
    int data;
    struct graph* next;
};
struct queue{
 struct graph* front,* rear;
};
struct graph* newvertex(int k) {
    struct graph* temp = (struct graph*)malloc(sizeof(struct graph));
    temp->data = k;
    temp->next = NULL;
    return temp;
}
struct queue* createQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(struct queue* q, int k) {
    struct graph* temp = newvertex(k);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
struct graph* dequeue(struct queue* q) {
    if (q->front == NULL)
        return NULL;
    struct graph* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    return temp;
}
int main(){
    struct queue *q=createQueue();
    int i,j;
    int row,col;//vertices and edges
    printf("\nEnter number of vertices: ");
    scanf("%d",&row);
    int visited[100]={0};
    printf("\nEnter number of edges: ");
    scanf("%d",&col);
     int mat[row][col];
    printf("\nEnter the matrix (row-wise): \n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    printf("\nMatric:\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d",mat[i][j]);
        }
        printf("\n");
    }
    int k=mat[0][0];
    int l,u;
    enqueue(q,k);
    printf("\nEnter staring vertex: ");
    scanf("%d",&l);
    printf("\nBFS:\n");
    printf("%d",k);
    visited[l]=1;
    while(q->front!=NULL){
        u=q->front->data;
        dequeue(q);
        printf("%d ",u);
        for(i=0;i<row;i++){
            if(mat[u][i]==1 && visited[i]==0){
                enqueue(q,i);
                visited[i]=1;
            }
        }
    }

    return 0;
}