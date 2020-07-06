/*
Horrible Queries
Send Feedback
World is getting more evil and it's getting tougher to get into the Evil League of Evil. Since the legendary Bad Horse has retired, now you have to correctly answer the evil questions of Dr. Horrible, who has a PhD in horribleness (but not in Computer Science). You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -
0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.

1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
Input
In the first line you'll be given T, number of test cases.

Each test case will start with N (N <= 100 000) and C (C <= 100 000). After that you'll be given C commands in the format as mentioned above. 1 <= p, q <= N and 1 <= v <= 10^7.
Output
Print the answers of the queries.
Input:
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8
0 5 7 14
1 4 8
Output:
80
508
*/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
ll tree[1000000],lazy[1000000],n;


void update(ll node,ll start,ll end,ll l,ll r,ll val) //start=starting index of array,,,,,,,end=ending index of array
{

      if(lazy[node]!=0)
      {
            tree[node]+=lazy[node]*(end-start+1);
            if(start!=end)
            {
                  lazy[node*2]+=lazy[node];
                  lazy[node*2+1]+=lazy[node];
            }
            lazy[node]=0;
      }
      if(start>r||end<l||start>end)
      return;
      if(start>=l&&end<=r)
      {

            tree[node]+=val*(end-start+1);
            if(start!=end)
            {
            lazy[node*2]+=val;
            lazy[(node*2)+1]+=val;
            }
            return;
      }
      ll mid=(start+end)/2;
      update(node*2,start,mid,l,r,val);
      update(node*2+1,mid+1,end,l,r,val);
      tree[node]=tree[node*2]+tree[(node*2)+1];


      }
ll query(ll node,ll start,ll end,ll l,ll r) //start=starting index of array,,,,,,,end=ending index of array
{
      if(start>end||start>r||end<l)
      return 0;
      if(lazy[node]!=0)
      {
            tree[node]+=lazy[node]*(end-start+1);
            if(start!=end)
            {
                  lazy[node*2]+=lazy[node];
                  lazy[(node*2)+1]+=lazy[node];
            }
            lazy[node]=0;
      }

      if(start>=l&&end<=r)
      {

            return tree[node];
      }
      ll mid=(start+end)/2;
      ll a=query(2*node,start,mid,l,r);
      ll b=query(2*node+1,mid+1,end,l,r);
      return a+b;
}
int main() {
ll int i,j,k,t,r,u,v,p,q,c,l,val;
cin>>t;
for(i=0;i<t;i++)
{
      cin>>n>>c;
    memset(lazy, 0, sizeof lazy);
    memset(tree,0,sizeof tree);
      for(j=0;j<c;j++)
      {
            cin>>l;
            if(l==0)
            {
                 cin>>p>>q>>val;
                 update(1,0,n-1,p-1,q-1,val);
            }
            else
            {
                  cin>>p>>q;
                  ll ansi=query(1,0,n-1,p-1,q-1);
                  cout<<ansi<<endl;
            }
      }
}
    return 0;
}
