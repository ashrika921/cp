/*
Coding Ninjas
Send Feedback
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
Input Format :
Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
Assume input to be 0-indexed based
Output Format :
Return 1 if there is a path which makes the sentence “CODINGNINJA” else return 0.
Constraints :
1 <= N <= 100
1 <= M <= 100
Sample Input :
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output :
1
*/

bool issafe(char edges[][MAXN],int i,int j,int n,int m,bool** visited,string s,int len){
    if(i<0 || j<0 || i>=n || j>=m || visited[i][j] || edges[i][j]!=s[len]){
        return false;
    }
    return true;
}
bool DFS(char edges[][MAXN],int n,int m,int i,int j,bool **visited,string s,int len,int* x,int* y){

    if(len==s.length()){
       return true;
   }
    for(int k=0;k<8;k++){
        if(issafe(edges,i+x[k],j+y[k],n,m,visited,s,len)){
            visited[i][j]=1;
        bool ans = DFS(edges,n,m,i+x[k],j+y[k],visited,s,len+1,x,y);
            if(ans){
                return true;
            }
           if(!ans){
            visited[i][j]=0;
           }
        }
    }
    return false;
}
int solve(char Graph[][MAXN],int N, int M)
{
	bool** visited=new bool*[N+1];
    for(int i=0;i<=N;i++){
        visited[i]=new bool[M+1];
        for(int j=0;j<=M;j++){
            visited[i][j]=0;
        }
    }
     int x[]={-1,-1,-1,0,0,1,1,1};
     int y[]={-1,0,1,-1,1,-1,0,1};
    string s="CODINGNINJA";
    bool ans=0;
    int len=s.length();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            bool isValid=DFS(Graph,N,M,i,j,visited,s,0,x,y);
            if(isValid==1){
                return true;
            }
        }
    }
    return false;
}
