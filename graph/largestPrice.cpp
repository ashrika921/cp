#include <iostream>
using namespace std;
int visited[NMAX][NMAX];
char A[NMAX][NMAX];
int cx[]={0,0,-1,1};
int cy[]={1,-1,0,0};
int dfs(int x,int y,int n){
    if(visited[x][y]){
        return 0;
    }
    visited[x][y]=1;
    int count=1;
    for(int i=0;i<4;i++){
        int dx=x+cx[i];
        int dy=y+cy[i];
        if(dx>=0 && dx<n && dy>=0 && dy<n && A[dx][dy]=='1'){
            count+=dfs(dx,dy,n);
        }
    }
     return count;
}
int solve(int n,char cake[NMAX][NMAX]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A[i][j]=cake[i][j];
        }
    }
    int maxsize=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]=='1'&&visited[i][j]==0){
                maxsize=max(maxsize,dfs(i,j,n));
            }
        }
    }
     return maxsize;
}
