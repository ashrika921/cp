/*
Perimeter with conditions
Send Feedback
Aahad gives an array of integers and asks Harshit to find which three elements form a triangle (non-degenerate). The task seems easy to Harshit.
So, Aahad adds some conditions to this task -
1. Find the triangle with maximum perimeter
2. If there are two or more combinations with same value of maximum perimeter, then find the one with the longest side.
3.If there are more than one combinations which satisfy all the above conditions the find with maximum longest minimum side.
Input Format
The First line contains no of elements of array: N
Each T lines contains N space-separated integers: A [i]
Output Format
The output contains three space-separated elements that denote the length of the sides of triangle. If no such triangle is possible, then print -1.
Constraints
1 =< N <= 10^5
1 <= A[i] <= 10^9
Time Limit: 1 second
Sample Input1:
5
1 1 1 3 3
Sample Output1:
1 3 3
Sample Input2:
3
2 2 4
Sample Output3:
-1
Explaination
In the First Sample case, the elements that form a triangle with maximum perimeter is 1,3,3.
In the Second Sample case, the elements that can form a triangle are degenerate, so, we printed -1. */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
   ll n;cin>>n;
    ll a[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ll dp[n-2];
    for(ll i=0;i<n-2;i++){
        if(a[i]+a[i+1]<=a[i+2]){
            dp[i]=-1;
            continue;
        }
         if(a[i+1]+a[i+2]<=a[i]){
            dp[i]=-1;
             continue;
        }
         if(a[i+2]+a[i]<=a[i+1]){
            dp[i]=-1;
             continue;
        }
        dp[i]=a[i]+a[i+1]+a[i+2];
    }
    ll j=n-3;
    while(dp[j]==-1){
        j--;
    }
    if(j==-1){
        cout<<-1<<endl;
        return 0;
    }
    ll peri=dp[j];int x=a[j];int y=a[j+1];int z=a[j+2];
    ll maxi=max(x,max(y,z));
    ll mini=min(x,min(y,z));
    j=j-1;
    while(peri>=dp[j]){
        ll new_max=max(a[j],max(a[j+1],a[j+2]));
        ll new_min=min(a[j],min(a[j+1],a[j+2]));
        if(new_max>maxi){
            maxi=new_max;
            mini=new_min;
            peri=dp[j];
            x=a[j];y=a[j+1];z=a[j+2];
        }else if(new_min>mini){
             maxi=new_max;
            mini=new_min;
            peri=dp[j];
            x=a[j];y=a[j+1];z=a[j+2];
        }
            j--;
    }

    cout<<x<<" "<<y<<" "<<z<<endl;
}
