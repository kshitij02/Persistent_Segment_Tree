#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int n,q,l;
	cin>>n>>q;
	vector<int > v(n);
	for (l=0;l<n;l++){
		cin>>v[l];
	}
	while(q--){
		int i,j;
		cin>>i>>j;
		vector<int> vec;
		for(l=i;l<=j;l++){
			vec.push_back(v[l]);
		}
		sort(vec.begin(),vec.end());
		int k;
		cin>>k;
		cout<<vec[k-1]<<"\n";
	}
	return 0;
}