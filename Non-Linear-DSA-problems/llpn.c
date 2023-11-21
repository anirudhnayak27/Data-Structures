#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;

}NODE;
NODE* getNode(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void display(struct node *head)
{
    struct node *t;
   if(head==NULL)
   {
     printf("the nextded list is empty\n");
   }
   else
   {
      t=head;
      while(t!=NULL)
      {
         printf("%d->",t->data);
         t=t->next;
      }
      printf("\n");
   }
}

void insertEnd(NODE** head, int data) {
    NODE* newNode = getNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    NODE* cur = *head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
}
int generate_random_number(int p, int q)
{
    return rand()%(q-p+1)+p;
}
int main()
{
    struct node *newnode,*head;
   int n, p, q,num,i;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("Enter the value of p: ");
    scanf("%d",&p);
    printf("Enter the value of q: ");
    scanf("%d",&q);
    srand(time(0));
    FILE* file = fopen("Input.txt", "w");
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
    FILE*fp=fopen("input.txt","r");
    while (!feof(fp))
        {
                    fscanf(fp, "%d", &num);
                    insertEnd(&head, num);
                }
    for(i=0;i<n;i++)
    {
        display(head);
    }
    fclose(fp);

}
