/*
Program 4: Given a graph find shortest paths from source to all nodes in the
graph using Dijkstra’s shortest path algorithm.
*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int n;

int findMinVertex(bool visited[n],int distance[n],int n){
    int minVertex = -1;
    for(int i=0;i<n;i++){
        if(!visited[i] && ((distance[minVertex] > distance[i]) || minVertex == -1)){
            minVertex = i;
        }
    }
    return minVertex;
}

void dij(int cost[][n],int n,int source)
{
    bool visited[n];
    int distance[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
        distance[i] = 9999;
    }
    distance[source] = 0;
    for(int i=0;i<n-1;i++){
        int minVertex = findMinVertex(visited,distance,n);
        visited[minVertex] = true;
        for(int j=0;j<n;j++){
            if(!visited[j] && cost[minVertex][j] != 0){
                int currDistance = distance[minVertex] + cost[minVertex][j];
                if(currDistance < distance[j]){
                    distance[j] = currDistance;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        printf("%d \t",i);
        printf("%d \t",distance[i]);
        printf("\n");
    }
    return;
}

int main()
{
    
    scanf("%d",&n);
    int cost[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    printf("enter source node\n");
    int source;
    scanf("%d",&source);
    dij(cost,n,source);
    return 0;
   
}


/*
5
0 10 0 30 100
10 0 50 0 0
0 50 0 20 10
30 0 20 0 60
100 0 10 60 0
enter source node
1
Node   Dist
0       10      
1       0
2       50
3       40      
4       60
*/
