#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node* link;
} NODE;

NODE* getNode(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

void insertEnd(NODE** head, int data) {
    NODE* newNode = getNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    NODE* cur = *head;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = newNode;
}

void display(NODE* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE* temp = head;
    while (temp != NULL) {
        printf(" (%d) -> ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
void display2(NODE* head) {
    FILE*f2=fopen("positive.txt","w");
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE* temp = head;
    while (temp != NULL) {
        printf(" (%d) -> ", temp->data);
        fprintf(f2,"%d\t:%d\n",temp->data,(&temp->data));
        temp = temp->link;
    }
    fclose(f2);
    printf("\n");
}
void display1(NODE* head) {
FILE*f1=fopen("negative.txt","w");
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE* temp = head;
    while (temp != NULL) {
        printf(" (%d) -> ", temp->data);
        fprintf(f1,"%d\t:%d\n",temp->data,(&temp->data));
        temp = temp->link;
    }
    fclose(f1);
    printf("\n");
}
void sortPositiveNegative(NODE* head, NODE** posHead, NODE** negHead) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE* temp = head;
    while (temp != NULL) {
        if (temp->data >= 0) {
            insertEnd(posHead, temp->data);
            temp = temp->link;
        } else {
            insertEnd(negHead, temp->data);
            temp = temp->link;
        }
    }
    printf("done\n");
}
int generate_random_number(int p, int q)
{
    return rand()%(q-p+1)+p;
}
int main() {
    int n, p, q,num,i;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("Enter the value of p: ");
    scanf("%d",&p);
    printf("Enter the value of q: ");
    scanf("%d",&q);
    srand(time(0));
    FILE* file = fopen("input.txt", "w");
    if (file == NULL)
    {
        printf("Failed to open file for writing.\n");
    }
    for (i=0;i<n;i++)
    {
        num = generate_random_number(p, q);
        fprintf(file, "%d\n", num);
    }
    fclose(file);
    printf("done\n");
    NODE* head = NULL;
    FILE* input;
    input = fopen("input.txt", "r");

    NODE* posHead = NULL;
    NODE* negHead = NULL;

    int choice;
    int num1;
    srand(time(0));
    while (1) {
        printf("1. Insert\n2. Display\n3.Sort\n4. Display Positive\n5. Display Negative\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                while (!feof(input)) {
                    fscanf(input, "%d", &num1);
                    insertEnd(&head, num1);
                }
                break;
            case 2:
                display(head);
                break;
            case 6:
                exit(0);
                break;
            case 3:
                sortPositiveNegative(head, &posHead, &negHead);
                break;
            case 4:
                display2(posHead);
                break;
            case 5:
                display1(negHead);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

