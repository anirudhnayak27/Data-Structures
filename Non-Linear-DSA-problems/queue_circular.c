#include <stdio.h>
#include <stdlib.h>
#define max 10
typedef struct {
    int queue[max];
    int front;
    int rear;
    int count;
} cir;

void initialize(cir *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int is_empty(cir *q) {
    return q->count == 0;
}

int is_full(cir *q) {
    return q->count == max;
}

void enqueue(cir *q, int item) {
    if (is_full(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % max;
    q->queue[q->rear] = item;
    q->count++;
}

int dequeue(cir *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->queue[q->front];
    q->front = (q->front + 1) % max;
    q->count--;
    return item;
}

int main() {
    cir queue;
    initialize(&queue);
    FILE*fp=fopen("input.txt","r");
    int num,ch;
    while(1)
    {
        printf("1.push\n2.pop\n3.display\n4.Exit\n\n");
        printf("Enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the data\n");
            fscanf(fp,"%d",&num);
            enqueue(&queue,num);
            break;
            case 2:num=dequeue(&queue);
            break;
            case 3:display();
            break;
            case 4:exit(0);
            break;
            default:printf("Enter valid choice\n");
            break;
        }
    }
    fclose(fp);
    return 0;
}

