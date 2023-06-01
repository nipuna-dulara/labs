#include <iostream>
using namespace std;
#include <limits.h>
  
#define V 6

int minDistance(int dist[], bool sptSet[])
{

    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}
  

float printSolution(int dist[],int src)
{
    cout << "Times from " << src << endl;
    cout << "City \t\t time from Source" << endl;
    int sum = 0;
    for (int i = 0; i < V; i++){
        cout << i << " \t\t\t\t" << dist[i] << endl;
        sum += dist[i];
    }
    float avg = sum/6;
    cout << "AVG - " << avg; 
    return avg;
}

float dijkstra(int graph[V][V], int src)
{
    int dist[V];
                 
  
    bool sptSet[V];
    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX; 
        sptSet[i] = false;
    }

    dist[src] = 0;
  

    for (int count = 0; count < V - 1; count++) {
 
        int u = minDistance(dist, sptSet);
  
        sptSet[u] = true;
  

        for (int v = 0; v < V; v++)

            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]){
                    dist[v] = dist[u] + graph[u][v];
                }
               
    }
  
    return printSolution(dist,src);
}
int main (){
    int g[V][V] = {
{0,10,0,0,15,5},
{10,0,10,30,0,0},
{0,10,0,12,5,0},
{0,30,12,0,0,20},
{15,0,5,0,0,0},
{5,0,0,20,0,0}
};
int min = INT_MAX;
int min_I;
for (int i = 0; i < V; i++){
    int x =dijkstra(g,i);
    if(min > x ){
        min_I = i;
    }

}
cout << "minimum averages is "<< min_I;



    return 0;
}