#include<stdio.h>
#include<stdlib.h>
struct tree1
{
   int data;
   struct tree1 *left;
    struct tree1 *right;
};
struct tree1 *root=NULL;    
struct tree1 *insert(struct tree1 *root,int data)
{
    if(root==NULL)
    {
        root=(struct tree1 *)malloc(sizeof(struct tree1));
        root->data=data;
        root->left=NULL;
        root->right=NULL;
    }
    else if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=insert(root->right,data);
    }
    return root;
}
void preorder(struct tree1 *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct tree1 *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(struct tree1 *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int main()
{
    int n,i,data;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        root=insert(root,data);
    }
    printf("Preorder traversal\n");
    preorder(root);
    printf("\nInorder traversal\n");
    inorder(root);
    printf("\nPostorder traversal\n");
    postorder(root);
    return 0;
}
