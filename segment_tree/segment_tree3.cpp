/*
Maximum Sum In Subarray
Send Feedback
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.
Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output
Your program should output the results of the M queries, one
query per line.
Sample Input:
3
-1 2 3
1
1 2
Sample Output:
2
*/

#include<bits/stdc++.h>
using namespace std;
struct node{
  int prefixsum;
  int  sum;
  int suffixsum;
  int maxsum;
};
void buildTree(int *arr, node* tree,int treeIndex,int start,int end){ //start=starting index of array,,,,,,,end=ending index of array
    if(start==end){
        tree[treeIndex].maxsum=arr[start];
        tree[treeIndex].sum=arr[start];
        tree[treeIndex].prefixsum=arr[start];
        tree[treeIndex].suffixsum=arr[start];
        return;
    }
    int mid=(start+end)/2;
    buildTree(arr,tree,2*treeIndex,start,mid);
    buildTree(arr,tree,2*treeIndex+1,mid+1,end);
    tree[index].sum=tree[2*index].sum+tree[2*index+1].sum;
    tree[index].prefixsum=max();
    return;
}
node query(node * tree,int start,int end,int treeNode,int left,int right){ //start=starting index of array,,,,,,,end=ending index of array
    node parentNode;
    parentNode.BPS=INT_MIN;
    parentNode.BSS=INT_MIN;
    parentNode.maxSum=INT_MIN;
    parentNode.sum=INT_MIN;
    if(start>right || end<left){
        return parentNode;
    }
    if(start>=left && end<=right){
        return tree[treeNode];
    }
    int mid=(start+end)/2;
    node leftChild=query(tree,start,mid,2*treeNode,left,right);
    node rightChild=query(tree,mid+1,end,2*treeNode+1,left,right);
    parentNode.BPS=max(leftChild.BPS,leftChild.sum+rightChild.BPS);
    parentNode.BSS=max(rightChild.BSS,rightChild.sum+leftChild.BSS);
    parentNode.sum=leftChild.sum+rightChild.sum;
    parentNode.maxSum=max(parentNode.BPS,max(parentNode.BSS,parentNode.sum));
    return parentNode;
}
int main() {
    int n;cin>>n;
    int* arr= new int[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int m;cin>>m;
    node* tree=new node[4*n];
    buildTree(arr,tree,1,1,n);
    while(m--){
        int x;cin>>x;int y;cin>>y;
      node ans=query(tree,1,n,1,x,y);
        cout<<ans.maxSum<<endl;
    }
}
