//FRACTIONAL-KNAPSACK//
#include<bits/stdc++.h>
using namespace std;
struct Item{
int value,weight;
};
bool compare(struct Item a,struct Item b){
double value1=((double)a.value)/(a.weight);
double value2=((double)b.value)/(b.weight);
return value1>value2;
}
double fKnapsack(struct Item arr[],int W,int n){
sort(arr,arr+n,compare);
int currW=0;
double fValue=0;
for(int i=0;i<n;i++){
    if(currW+arr[i].weight<=W){
        currW+=arr[i].weight;
        fValue+=arr[i].value;
    }else{
    int rWeight=W-currW;
    fValue+=(arr[i].value)*((double)rWeight/arr[i].weight);
    break;
    }
}
return fValue;
}
int main(){
int W;cin>>W;int n;cin>>n;
struct Item arr[n+1];
for(int i=0;i<n;i++){
    cin>>arr[i].value;
    cin>>arr[i].weight;
}
cout<<fKnapsack(arr,W,n)<<" ";
}
