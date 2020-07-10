#include <bits/stdc++.h>
using namespace std;
class edge{
    public:
    int src;
    int dest;
    int weight;
};
bool compare(edge e1,edge e2){
    return e1.weight<e2.weight;
}
int getParent(int v,int* parent){
    if(parent[v]==v){
        return v;
    }
   return getParent(parent[v],parent);
}
edge* kruskals(edge* edges,int n,int e){
    sort(edges,edges+e,compare);
    edge* output=new edge[n-1];
    int * parent=new int[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    int count=0;
    int i=0;
    while(count<n-1){
        edge currentEdge=edges[i];
        int srcParent=getParent(currentEdge.src,parent);
        int destParent=getParent(currentEdge.dest,parent);
        if(srcParent!=destParent){
            output[count]=currentEdge;
            count+=1;
            parent[srcParent]=destParent;
        }
        i+=1;
    }
    return output;
}

int main()
{
  int V, E;
  cin >> V >> E;
   edge* edges=new edge[E];
    for(int i=0;i<E;i++){
        int s;int d;int w;
        cin>>s>>d>>w;
        edges[i].src=s;
        edges[i].dest=d;
        edges[i].weight=w;
    }
    edge* output=kruskals(edges,V,E);
    for(int i=0;i<V-1;i++){
        if(output[i].src<output[i].dest){
            cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }else{
             cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight<<endl;
        }
    }
  return 0;
}

