/*
Program 4: Given a graph find shortest paths from source to all nodes in the
graph using Dijkstra’s shortest path algorithm.
*/

/*
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

    
    
    #include <iostream>
#include<bits/stdc++.h>
using namespace std;

int getMinVertex(int* distance,bool* visited,int n){
    int minVertex = -1;
    for(int i=0;i<n;i++){  //getting min vertex from remaining unvisited nodes which has less distance value
        if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])){
            minVertex = i;
        }
    }
    
    return minVertex;
}

void dijkstras(int** edges,int n,int source){
    bool* visited = new bool[n];
    int* distance = new int[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[source] = 0;
    
    for(int i=0;i<n-1;i++){
        int minVertex = getMinVertex(distance,visited,n);
        visited[minVertex] = true;
        
        for(int j=0;j<n;j++){
            if(!visited[j] && edges[minVertex][j] != 0){
                if(distance[j] > (distance[minVertex] + edges[minVertex][j])){ //better way exist to reach 'j' node from minVertex
                    distance[j] = (distance[minVertex] + edges[minVertex][j]);
                }
            }
        }
    }
    
    //distance array contains distance of each node from source i.e '0th vertex'
    for(int i=0;i<n;i++){
        cout << i <<  " " << distance[i] << endl;
    }
    
    return;
}

int main()
{
  
    int n,e;
    cout << "enter number of vertices and edges" << endl;

    cin >> n >> e;
    int** edges = new int*[n]();
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
    }
    cout << "enter start end weight for all edges"<< endl;
    for(int i=0;i<e;i++){
        int start,end,w;
        cin >> start >> end >> w;
        edges[start][end] = w;
        edges[end][start] = w;
    }
    int source ;
    cout << "enter source" << endl;
    cin >> source;
    dijkstras(edges,n,source);
  return 0;
}

/*
enter number of vertices and edges
4 6
enter start end weight for all edges
0 1 2
0 3 3
0 2 1
1 2 3
1 3 4
2 3 3
enter source
1
0 2
1 0
2 3
3 4

*/
