/*You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job.
Output
Output one integer, the maximum profit that can be achieved.
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
struct job{
    ll start,finish,profit;
};
bool compare(job a,job b){
    return a.finish<b.finish;
}
int binary_search(job arr[],int index){
    int l0=0;int l1=index-1;
    while(l0<=l1){
        int mid=(l0+l1)/2;
        if(arr[index].start>=arr[mid].finish){
               if(arr[index].start>=arr[mid+1].finish){
                   l0=mid+1;
               }else{
                   return mid;
               }
        }else{
            l1=mid-1;
        }
    }
    return -1;
}
ll  find_max_profit(job arr[]){
    sort(arr,arr+n,compare);
    ll dp[n+1];
    dp[0]=arr[0].profit;
    for(ll i=1;i<n;i++){
        ll including=arr[i].profit;
     ll lnConflict = binary_search(arr,i);
        if(lnConflict!=-1){
            including+=dp[lnConflict];
        }
        dp[i]=max(dp[i-1],including);
    }
    ll ans=dp[n-1];
    return ans;
}
int main()
{
    cin>>n;
    job arr[n+1];
    for(ll i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].finish>>arr[i].profit;
    }
    cout<<find_max_profit(arr)<<endl;
    return 0;
}
