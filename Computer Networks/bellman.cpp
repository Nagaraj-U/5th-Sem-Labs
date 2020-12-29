#include<bits/stdc++.h>
using namespace std;

void bellman(int cost[][20],int n,int src,int e,int graph[][3])
{
    int distance[n];
    for(int i=0;i<n;i++){
        distance[i] = INT_MAX;
    }
    distance[src] = 0;
    for(int i=0;i<(n-1);i++){
        for(int j=0;j<e;j++){
            if((distance[graph[j][0]] + graph[j][2]) < distance[graph[j][1]]){
                distance[graph[j][1]] = distance[graph[j][0]] + graph[j][2];
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << i << " " << distance[i] << endl; 
    }

}

int main()
{
    int n;
    int cost[20][20];
    cout << "enter number of nodes" << endl;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> cost[i][j];
        }
    }
    int src;
    cout << "enter source node " << endl;
    cin >> src;
    int e = 0;
    int graph[20][3];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cost[i][j] != 0){
                int u = i;
                int v = j;
                int w = cost[i][j];
                graph[e][0] = u;
                graph[e][1] = v;
                graph[e][2] = w;
                e++;

            }
        }
    }

    //   int graph[][3] = { { 0, 1, -1 }, { 0, 2, 4 }, 
    //                    { 1, 2, 3 }, { 1, 3, 2 },  
    //                    { 1, 4, 2 }, { 3, 2, 5 },  
    //                    { 3, 1, 1 }, { 4, 3, -3 } }; 
    //                    e = 8;
    bellman(cost,n,src,e,graph);
    return 0;
}

/*

6
0 6 4 5 0 0 
0 0 0 0 -1 0
0 -2 0 0 3 0
0 0 -2 0 0 -1
0 0 0 0 0 3
0 0 0 0 0 0
enter source node 
0
0 0
1 1
2 3
3 5
4 0
5 3
*/