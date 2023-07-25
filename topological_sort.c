#include<stdio.h>
#include<stdlib.h>

int n,m;
int *stack;
int top=-1;
int **adj;

void push(int x){
    top++;
    stack[top] = x;
}

void pop(){
    top--;
}

void dfs(int i, int *visited){
    visited[i] = 1;
    for(int j=0; j<n; j++){
        if(adj[i][j] == 1 && !visited[j]){
            dfs(j, visited);
        }
    }
    push(i);
}

int main()
{
    scanf("%d %d", &n, &m);

    stack = (int*)malloc(n*sizeof(int));

    adj = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++){
        adj[i] = (int*)malloc(n*sizeof(int));
    }

    int visited[n];
    for(int i=0; i<n; i++){
        visited[i] = 0;
        for(int j=0; j<n; j++){
            adj[i][j] = 0;
        }
    }

    for(int i=0; i<m; i++){
        int u,v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i,visited);
        }
    }

    for(int i=0; i<n; i++){
        printf("%d ", stack[top]);
        pop();
    }

    return 0;
}
