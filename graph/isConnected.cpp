/*
#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>
void dfs(unordered_map<int,vector<int>* >&adjacencyList,int v1,unordered_map<int,bool> &visited){
    vector<int> *adjacentVertices=adjacencyList[v1];
    //mark it visited to avoid calling it over vertex again
    visited[v1]=true;
    //reccursion call
    for(int i=0;i<adjacentVertices->size();i++){
        if(visited.count(adjacentVertices->at(i))==0){
            dfs(adjacencyList,adjacentVertices->at(i),visited);
        }
    }
}
bool isConnected(unordered_map<int,vector<int>* >&adjacencyList){
    unordered_map<int,bool> visited;
    int startVertex=adjacencyList.begin()->first;
    dfs(adjacencyList,startVertex,visited);
    return visited.size()==adjacencyList.size();
}
int main(){
    int v;cin>>v;int e;cin>>e;
    //taking graph input and creating adjacency list
    unordered_map<int,vector<int> *>adjacencyList;
    for(int i=0;i<v;i++){
        vector<int> *v1=new vector<int>;
        adjacencyList[i]=v1;
    }
    int count=1;
    while(count<=e){
        int source,dest;
        cin>>source>>dest;
        adjacencyList[source]->push_back(dest);
        adjacencyList[dest]->push_back(source);
        count++;
    }
    if(isConnected(adjacencyList)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}
*/

#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>
void dfs(unordered_map<int,vector<int>* >&adjacencyList,int v1,unordered_map<int,bool> &visited){
    vector<int> *adjacentVertices=adjacencyList[v1];
    //mark it visited to avoid calling it over vertex again
    visited[v1]=true;
    //reccursion call
    for(int i=0;i<adjacentVertices->size();i++){
        if(visited.count(adjacentVertices->at(i))==0){
            dfs(adjacencyList,adjacentVertices->at(i),visited);
        }
    }
}
bool isConnected(unordered_map<int,vector<int>* >&adjacencyList){
    unordered_map<int,bool> visited;
    int startVertex=adjacencyList.begin()->first;
    dfs(adjacencyList,startVertex,visited);
    return visited.size()==adjacencyList.size();
}
int main(){
    int v;cin>>v;int e;cin>>e;
    //taking graph input and creating adjacency list
    unordered_map<int,vector<int> *>adjacencyList;
    for(int i=0;i<v;i++){
        vector<int> *v1=new vector<int>;
        adjacencyList[i]=v1;
    }
    int count=1;
    while(count<=e){
        int source,dest;
        cin>>source>>dest;
        adjacencyList[source]->push_back(dest);
        adjacencyList[dest]->push_back(source);
        count++;
    }
    if(isConnected(adjacencyList)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}
