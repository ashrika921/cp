#include <bits/stdc++.h>
using namespace std;
int getMinVertex(bool* visited,int* weight,int n){
int minVertex=-1;
    for(int i=0;i<n;i++){
        if( !visited[i] && (minVertex==-1 || weight[minVertex]>weight[i]))
        {
            minVertex=i;
        }
    }
    return minVertex;
}
void prims(int** edges,int n){
    bool* visited=new bool[n];
    int* parent=new int[n];
    int* weight=new int[n];
    for(int i=0;i<n;i++){
        weight[i]=INT_MAX;
    }
    parent[0]=-1;
    weight[0]=0;
    for(int i=0;i<n;i++){
        int minVertex=getMinVertex(visited,weight,n);
        visited[minVertex]=true;
        for(int j=0;j<n;j++){
            if(edges[minVertex][j]!=0 && !visited[j]){
                if(weight[j]>edges[minVertex][j]){
                    weight[j]=edges[minVertex][j];
                    parent[j]=minVertex;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        if(parent[i]<i){
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }  else{
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }
    return;
}
int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
  int** edges=new int*[V];
    for(int i=0;i<V;i++){
        edges[i]=new int[V];
        for(int j=0;j<V;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<E;i++){
        int f,s,weight;
        cin>>f>>s>>weight;
        edges[f][s]=weight;
        edges[s][f]=weight;
    }
    prims(edges,V);
  return 0;
}
