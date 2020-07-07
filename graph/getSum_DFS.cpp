#include <iostream>
#include<queue>
using namespace std;
vector<int>* getPathHelper(int** edges,int n,int sv,int ev,bool* visited){
    if(sv==ev){
        vector<int>* output=new vector<int>();
        output->push_back(ev);
        return output;
    }
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(edges[sv][i] && !visited[i]){
            vector<int>* smallOutput = getPathHelper(edges,n,i,ev,visited);
            if(smallOutput!=NULL){
                smallOutput->push_back(sv);
                return smallOutput;
            }
        }
    }
    return NULL;
}
vector<int>* getPath(int** edges,int n,int sv,int ev){
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    vector<int>* output=getPathHelper(edges,n,sv,ev,visited);
    delete[] visited;
    return output;
}
int main() {
    int n;cin>>n;
    int e;cin>>e;
    int** edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    int sv,ev;
    cin>>sv>>ev;
    vector<int>* output=getPath(edges,n,sv,ev);
    if(output!=NULL){
        for(int i=0;i<output->size();i++){
            cout<<output->at(i)<<" ";
        }
        delete output;
    }
    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
}
