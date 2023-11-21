// insert and delete functions are same as in avl.c
// //program to insert node in avl tree
#include<stdio.h>
#include<stdlib.h>
int generate_random_number(int p, int q)
{

    return rand()%(q-p+1)+p;

}

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
int max(int a,int b)
{
    return (a>b)?a:b;
}
int height(struct node *N)
{
    if(N==NULL)
        return 0;
    return N->height;
}
struct node *newnode(int data)
{
    struct node *node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return node;
}
struct node *rightrotate(struct node *y)
{
    struct node *x=y->left;
    struct node *T2=x->right;
    x->right=y;
    y->left=T2;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}
struct node *leftrotate(struct node *x)
{
    struct node *y=x->right;
    struct node *T2=y->left;
    y->left=x;
    x->right=T2;
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return y;
}
int getbalance(struct node *N)
{
    if(N==NULL)
        return 0;
    return height(N->left)-height(N->right);
}
struct node *insert(struct node *node,int data)
{
    if(node==NULL)
        return(newnode(data));
    if(data<node->data)
        node->left=insert(node->left,data);
    else if(data>node->data)
        node->right=insert(node->right,data);
    else
        return node;
    node->height=1+max(height(node->left),height(node->right));
    int balance=getbalance(node);
    if(balance>1 && data<node->left->data)
        return rightrotate(node);
    if(balance<-1 && data>node->right->data)
        return leftrotate(node);
    if(balance>1 && data>node->left->data)
    {
        node->left=leftrotate(node->left);
        return rightrotate(node);
    }
    if(balance<-1 && data<node->right->data)
    {
        node->right=rightrotate(node->right);
        return leftrotate(node);
    }
    return node;
}
struct node *minvalue(struct node *node)
{
    struct node *current=node;
    while(current->left!=NULL)
        current=current->left;
    return current;
}
int search(struct node *root,int data)
{
    if(root==NULL)
        return 0;
    if(root->data==data)
        return 1;
    if(root->data<data)
        return search(root->right,data);
    return search(root->left,data);
}
struct node *delete(struct node *root,int data)
{
    if(root==NULL)
        return root;
    if(data<root->data)
        root->left=delete(root->left,data);
    else if(data>root->data)
        root->right=delete(root->right,data);
    else
    {
        if((root->left==NULL)||(root->right==NULL))
        {
            struct node *temp=root->left?root->left:root->right;
            if(temp==NULL)
            {
                temp=root;
                root=NULL;
            }
            else
                *root=*temp;
            free(temp);
        }
        else
        {
            struct node *temp=minvalue(root->right);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
    }
    if(root==NULL)
        return root;
    root->height=1+max(height(root->left),height(root->right));
    int balance=getbalance(root);
    if(balance>1 && getbalance(root->left)>=0)
        return rightrotate(root);
    if(balance>1 && getbalance(root->left)<0)
    {
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    if(balance<-1 && getbalance(root->right)<=0)
        return leftrotate(root);
    if(balance<-1 && getbalance(root->right)>0)
    {
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    struct node *root=NULL;
    int n,i,data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    int p,q;
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
        printf("Failed to open file for writing.\n")
    }
    for (i=0;i<n;i++)
    {
        num = generate_random_number(p, q);
        fprintf(file, "%d\n", num);
    }
    fclose(file);
    file=fopen("Input.txt","r");
    //printf("Enter the nodes: ");
    for(i=0;i<n;i++)
    {
        fscanf("%d",&data);
        root=insert(root,data);
    }
    printf("Preorder traversal of the constructed AVL tree is \n");
    preorder(root);
    printf("\nEnter the node to be deleted: ");
    scanf("%d",&data);
    root=delete(root,data);
    printf("\nPreorder traversal of the constructed AVL tree is \n");
    preorder(root);
    /*printf("Enter the node to be searched: ");
    scanf("%d",&data);
    if(search(root,data))
        printf("\nNode found");
    else
        printf("\nNode not found");*/
    printf("\nPreorder traversal of the constructed AVL tree is \n");
    preorder(root);
    return 0;
}
