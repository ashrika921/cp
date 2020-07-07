/*
Code : All connected components
Send Feedback
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
Different components in new line
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1
2 3
Sample Input 2:
4 3
0 1
1 3
0 3
Sample Output 2:
0 1 3
2
*/
#include <bits/stdc++.h>
using namespace std;
void ConnectedComponents(unordered_map<int,vector<int>* >&adjacencyList,unordered_map<int,bool>&visited,vector<int>*smallOutput,int v){
    smallOutput->push_back(v);
    visited[v]=true;
    vector<int>*adjVertices=adjacencyList[v];
    for(int i=0;i<adjVertices->size();i++){
        if(visited.count(adjVertices->at(i))==0){
            ConnectedComponents(adjacencyList,visited,smallOutput,adjVertices->at(i));
        }
    }
}
vector<vector<int>*>* allConnectedComponents(unordered_map<int,vector<int>*>&adjacencyList){
    unordered_map<int,bool>visited;
    vector<vector<int>*> *output=new vector<vector<int>*>;
    int i=0;
    while(visited.size() !=adjacencyList.size()){
        for(;i<adjacencyList.size();i++){
            if(visited.count(i)==0){
                vector<int>* smallOutput=new vector<int>;
                ConnectedComponents(adjacencyList,visited,smallOutput,i);
                output->push_back(smallOutput);
            }
        }
    }
    return output;
}
int main() {
    int n,e;
    cin>>n>>e;
    //taking graph input and creating adjacency list
    unordered_map<int,vector<int>* >adjacencyList;
    for(int i=0;i<n;i++){
        vector<int> *v=new vector<int>;
        adjacencyList[i]=v;
    }
    int count=1;
    while(count<=e){
        int source,dest;
        cin>>source>>dest;
        adjacencyList[source]->push_back(dest);
        adjacencyList[dest]->push_back(source);
        count++;
    }
    vector<vector<int>*> *output = allConnectedComponents(adjacencyList);
    for(int i=0;i<output->size();i++){
        vector<int> *component=output->at(i);
        sort(component->begin(),component->end());
    for(int j=0;j<component->size();j++){
        cout<<component->at(j)<<" ";
    }
    cout<<endl;
    }
}
