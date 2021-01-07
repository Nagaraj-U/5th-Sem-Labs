#include<bits/stdc++.h>
using namespace std;

void bellman(int graph[10][3],int n,int e,int src)
{
    int* dist = new int[n];
    for(int i=0;i<n;i++){
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    for(int i=0;i<(n-1);i++){
        for(int j=0;j<e;j++){
            int start = graph[j][0];
            int end = graph[j][1];
            int weight = graph[j][2];
            if(dist[start] != INT_MAX && dist[start] + graph[j][2] < dist[end]){
                dist[end] = graph[j][2] + dist[start];
            }
        }
    }

    for(int i=0;i<e;i++){
        int start = graph[i][0];
        int end = graph[i][1];
        if(dist[start] != INT_MAX && dist[start] + graph[i][2] < dist[end]){
            cout << "graph contain negative weight cycle" << endl;
        }
    }
    cout << "vertex ditance from source" << endl;
    for(int i=0;i<n;i++){
        cout << src << " to " << i << "  " << dist[i] << endl; 
    }
    return;
}

int main()
{
    cout << "hello" << endl;
    int graph[10][3];
    int n,e;
    cout << "enter number of vertices and edges" << endl;
    cin >> n ;
    cin >> e;
    int arr[20][3];
    for(int i=0;i<e;i++){
        int start,end,weight;
        cin >> start;
        cin  >> end;
        cin  >> weight;
        arr[i][0] = start;
        arr[i][1] = end;
        arr[i][2] = weight;
    }
    int src;
    cout << "enter source" << endl;
    cin >> src;
    bellman(arr,n,e,src);
    return 0;
} 
