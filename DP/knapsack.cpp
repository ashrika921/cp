/*  TIME-COMPLEXITY:O(n*W)  Space-Complexity:O(n*W) */
int knapsack(int* weights, int* values, int n, int maxWeight){
    int dp[n+2][maxWeight+2]={0};
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int w=0;w<=maxWeight;w++){
        dp[0][w]=0;
    }
    for(int i=1;i<=n;i++){
        for(int w=1;w<=maxWeight;w++){
            dp[i][w]=dp[i-1][w];
            if(weights[i-1]<=w){
                if(dp[i][w]<=values[i-1]+dp[i-1][w-weights[i-1]]){
                    dp[i][w]=values[i-1]+dp[i-1][w-weights[i-1]];
                }
            }
        }
    }
    return dp[n][maxWeight];
}

/*optimized space complexity : O(W)  */

int knapsack(int weights[], int values[], int n, int W){
    int mat[2][W+1];
 //   memset(mat,0,sizeof(mat));
    for(int i=0;i<=1;i++){
        for(int j=0;j<=W;j++){
            mat[i][j]=0;
        }
    }
    int i=0;
    while(i<n){
        int j=0;
        if(i%2!=0){
              while(++j <= W){
                if(weights[i]<=j){
                    mat[1][j]=max(values[i]+mat[0][j-weights[i]],mat[0][j]);
                }else{
                    mat[1][j]=mat[0][j];
                }
            }
            i++;
        }
        else{
            while(++j <= W){
                if(weights[i]<=j){
                    mat[0][j]=max(values[i]+mat[1][j-weights[i]],mat[1][j]);
                }else{
                    mat[0][j]=mat[1][j];
                }
            }
            i++;
        }
    }
    return (n%2!=0)?mat[0][W] : mat[1][W];
}
