/////  MINIMUM IN SUBARRAY
/*
Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.
Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.
Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].
Contraints:
1≤N,Q,y≤10^5
1≤l,r,x≤N
Sample Input :
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5
Sample Output :
1
1
2
1
*/
#include<bits/stdc++.h>
using namespace std;
void build_tree(int *arr,int *tree,int start,int end,int treeNode){// //start=starting index of array,,,,,,,end=ending index of array
    if(start==end){
        tree[treeNode]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    build_tree(arr,tree,start,mid,2*treeNode);
    build_tree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);
}
int query(int * tree,int start,int end,int treeNode,int left,int right){ //start=starting index of array,,,,,,,end=ending index of array
    if(start>right || end<left){
        return INT_MAX;
    }
    if(start>=left && end<=right){
        return tree[treeNode];
    }
    int mid=(start+end)/2;
    int ans1=query(tree,start,mid,2*treeNode,left,right);
    int ans2=query(tree,mid+1,end,2*treeNode+1,left,right);
   return min(ans1,ans2);
}
void update(int *arr,int* tree,int start,int end,int treeNode,int idx,int value){   //start=starting index of array,,,,,,,end=ending index of array
    if(start==end){
        arr[idx]=value;
        tree[treeNode]=value;
        return;
    }
    int mid=(start+end)/2;
    if(idx>mid){
        update(arr,tree,mid+1,end,2*treeNode+1,idx,value);
    }else{
        update(arr,tree,start,mid,2*treeNode,idx,value);
    }
    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);
}
int main() {
    int n;cin>>n;int q;cin>>q;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int * tree=new int[4*n];
    build_tree(arr,tree,1,n,1);
   while(q--){
        char qwe;cin>>qwe;int left;cin>>left;int right;cin>>right;
        if(qwe=='q'){
        cout<<query(tree,1,n,1,left,right)<<endl;
        }else{
            update(arr,tree,1,n,1,left,right);
        }
    }
}
