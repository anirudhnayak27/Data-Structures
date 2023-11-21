#include<stdio.h>
#include<stdlib.h>
int visited[6]={0};
    int adj[6][6]={{ 0, 1, 0, 0, 0, 1 },
        { 1, 0, 1, 0, 0, 0 },
        { 1, 0, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 1, 0 },
        { 0, 0, 0, 1, 0, 1 },
        { 1, 0, 0, 0, 1, 0 }
    };;
void DFS(int i){
    int j;
    printf("%d ",i);
    visited[i]=1;
    for(j=0;j<7;j++){
        if(!visited[j] && adj[i][j]==1){
            DFS(j);
        }
    }
}
int main(){
    int n;
    printf("Enter the starting node: ");
    scanf("%d",&n);
    DFS(n);
    return 0;
}