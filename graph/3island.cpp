/*
3 Cycle
Send Feedback
Given a graph with N vertices (numbered from 1 to N) and Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Return Format :
The count the number of 3-cycles in the given Graph
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Sample Input:
3 3
1 2 3
2 3 1
Sample Output:
1
*/
int solve(int n,int m,vector<int>u,vector<int>v)
{
    int** dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[m+1];
    }
    for(int i=1;i<=m;i++){
        dp[u[i-1]][v[i-1]]=1;
        dp[v[i-1]][u[i-1]]=1;
    }
    int count=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dp[i][j]==1){
                for(int k=1;k<=n;k++){
                    if(dp[j][k]==1 && dp[i][k]==1){
                        count+=1;
                    }
                }
            }
        }
    }
    return count/6;
}
