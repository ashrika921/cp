
/*https://www.codechef.com/problems/SVENGY*/
#include<bits/stdc++.h>
using namespace std;
int main(){

	long n;
	cin >> n;
	long arr[n];

	for(int i=0;i<n;i++){
		cin >> arr[i];
	}

	long curr = 0;
	long ans = 0;

	while(curr < (n-1)){
		long next = curr+1;
		while(next < (n-1)){
			if((abs(arr[curr]) > abs(arr[next])) || ((abs(arr[curr]) == abs(arr[next])
				&& (arr[curr] > 0)))){
				break;
			}else{
				next++;
			}
		}
		ans+= (next-curr)*arr[curr] + (next*next - curr*curr)*arr[curr]*arr[curr];
		curr = next;
	}
	cout << ans ;
	return 0;
}
