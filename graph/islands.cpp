/*   Largest Piece
Send Feedback
Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
Constraints :
1<=N<=50
Input Format :
Line 1 : An integer N denoting the size of cake
Next N lines : N characters denoting the cake
Output Format :
Size of the biggest piece of '1's and no '0's
Sample Input :
2
11
01
Sample Output :
3  */


int DFS(int** edges,int n,int i,bool *visited){
   visited[i]=true;
    for(int j=1;j<=n;j++){
        if(j==i){
            continue;
        }
        if(edges[i][j]==1){
            if(visited[j]){
                continue;
            }
            DFS(edges,n,j,visited);
        }
    }
    return 1;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
    int** edges=new int*[n+2];
    for(int i=1;i<=n;i++){
        edges[i]=new int[n+2];
        for(int j=1;j<=n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        edges[u[i-1]][v[i-1]]=1;
         edges[v[i-1]][u[i-1]]=1;
    }
    bool *visited=new bool[n+2];
    for(int i=1;i<=n;i++){
        visited[i]=false;
    }
    int count=0;
    for(int i=1;i<=n;i++){
    if(!visited[i]){
      count+=DFS(edges,n,i,visited);
    }
    }
    return count;
}
