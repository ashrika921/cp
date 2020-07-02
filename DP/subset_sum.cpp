/*   Subset Sum - Problem
Send Feedback
Given a set of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.

Input Format
First line contains a single integer n (1<=n<=1000)
Second line contains n space separated integers (1<=a[i]<=1000)
Last line contains a single positive integer k (1<=k<=1000)
Output Format
Output Yes if there exists a subset whose sum is k, else output No.
Sample Input
3
1 2 3
4
Sample Output
Yes   */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;cin>>sum;
    int dp[n+1][sum+1]={0};
   for(int i=0;i<=sum;i++){
       dp[0][i]=0;
   }
    for(int j=0;j<=n;j++){
        dp[j][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
             dp[i][j]=dp[i-1][j];
            if(j>=arr[i-1]){
            dp[i][j]=dp[i][j]||dp[i-1][j-arr[i-1]];
            }
        }
    }
  //  for(int i=0;i<=n;i++){
  //      for(int j=0;j<=sum;j++){
  //          cout<<dp[i][j]<<" ";
  //      }
  //      cout<<endl;
  //  }
 //   cout<<dp[n][sum]<<endl;
    if(dp[n][sum]==0){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
    return 0;
}
