// DFS in graph intput from user

#include <stdio.h>
#include <stdlib.h>
#define SIZE 40
void DFS(int i,int visited[],int adj[][SIZE]){
    int j;
    printf("%d ",i);
    visited[i]=1;
    for(j=0;j<SIZE;j++){
        if(!visited[j] && adj[i][j]==1){
            DFS(j,visited,adj);
        }
    }
}
int main(){
    int n,row,col;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d",&row,&col);
    int adj[row][col];
    printf("Enter the adjacency matrix: ");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    int visited[row];
    printf("Enter the starting node: ");
    scanf("%d",&n);
    DFS(n,visited,adj);
    return 0;
}     