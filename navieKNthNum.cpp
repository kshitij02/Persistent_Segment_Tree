#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	clock_t t;
  	//int f;
  	t = clock(); 

	int n,q,l;
	cin>>n>>q;
	vector<int > v(n);
	for (l=0;l<n;l++){
		cin>>v[l];
	}
	// std::vector<int> x=v;
	// sort(x.begin(),x.end());
	// for(l=0;l<x.size();l++){
	// 	cout<<x[l]<<" ";
	// }
	int max_space=0;
	int space_counter=0;
	while(q--){
		int i,j;
		cin>>i>>j;
		vector<int> vec;
		for(l=i-1;l<=j-1;l++){
			vec.push_back(v[l]);
		}
		space_counter=(sizeof(int)*vec.size());
		if(max_space<space_counter){
			max_space=space_counter;
		}
		sort(vec.begin(),vec.end());
		 //cout<<vec.size()<<"\n";
		// if (q==25)
		//  for(l=0;l<vec.size();l++){
		//  	cout<<l<<" "<<vec[l]<<"\n";
		//  }
		int k;
		cin>>k;
		//cout<<"i "<<i<<" j"<<j<<"k "<<k<<"\n";
		cout<<vec[k-1]<<"\n";
	}
	t = clock() - t;
  	printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
  	printf("Program took this %d space\n",max_space);
	return 0;
}