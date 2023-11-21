#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

bool isEmpty() {
    return (front == -1 && rear == -1);
}

bool isFull() {
    return (rear == MAX_SIZE - 1);
}

void enqueue(int item) {
    if (isFull()) {
        printf("Error: Queue is full.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = item;
    display();
}

int dequeue() {
    if (isEmpty()) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    int item = queue[front];
    if (front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }
    display();
    return item;
}
void display()
{
    FILE *f=fopen("output.txt","w");
    int i;
    if(isEmpty())
    {
             printf("Error: Queue is empty.\n");
        return -1;
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d->",queue[i]);
            fprintf(f,"%d\n",queue[i]);
        }
    }
    fclose(f);
    printf("\n");
}
int main() {
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
            enqueue(num);
            break;
            case 2:num=dequeue();
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

/*
typedef struct node {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int item) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    new_node->data = item;
    new_node->next = NULL;
    if (front == NULL) {
        front = rear = new_node;
    }
    else {
        rear->next = new_node;
        rear = new_node;
    }
}

int dequeue() {
    if (front == NULL) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    Node* temp = front;
    int item = temp->data;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    return item;
}

int main() {
    enqueue(5);
    enqueue(10);
    enqueue(15);
    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue()); // will result in error
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = NULL;
    if (rear == NULL) {
        front = rear = new_node;
        return;
    }
    rear->next = new_node;
    rear = new_node;
}

void dequeue() {
    if (front == NULL) {
        printf("Error: Queue underflow\n");
        return;
    }
    struct Node* temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

int frontElement() {
    if (front == NULL) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    return front->data;
}

int isEmpty() {
    return front == NULL;
}

int main() {
    enqueue(5);
    enqueue(10);
    enqueue(15);
    printf("%d\n", frontElement());
    dequeue();
    printf("%d\n", frontElement());
    dequeue();
    printf("%d\n", frontElement());
    dequeue();
    printf("%d\n", isEmpty());
    return 0;
}
*/
