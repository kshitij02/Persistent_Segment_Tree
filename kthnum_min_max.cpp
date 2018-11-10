#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct seg_tree{
	int value;
	struct seg_tree *left,* right;
};
seg_tree * create_node(int data){
	seg_tree *temp =(seg_tree *)malloc(sizeof(struct seg_tree));
	temp->left=temp->right=NULL;
	temp->value=data;
	return temp;
}
seg_tree * insert_value(int arr[],int i ,int j){
	seg_tree * node,* left , * right;
	if(i==j){
		node=create_node(arr[i]);
		return node;
	}
	int mid=(i+j)/2,val;
	left=insert_value(arr,i,mid);
	right=insert_value(arr,mid+1,j);
	val=left->value+right->value;
	node=create_node(val);
	node->left=left;
	node->right=right;
	return node;
}
seg_tree * update_seg(int value,int index ,int i ,int j,seg_tree * previous_root){ 
 	seg_tree * node,* left , * right;
 	node=(seg_tree *)malloc(sizeof(struct seg_tree));
 	int mid=(i+j)/2,val;
	if(i==j && i==index){
		node=create_node(value);
		return node;
	}
	if(index<=mid){
	left=update_seg(value,index,i,mid,previous_root->left);
	}
	else{
	left=previous_root->left;
	}
	if(index>=mid+1){
	right=update_seg(value,index,mid+1,j,previous_root->right);
	}
	else{
	right=previous_root->right;
	}
	val=left->value+right->value;
	node=create_node(val);
	node->left=left;
	node->right=right;
	return node;
}
bool cmp (int a ,int b){
	return a>b;
}
vector< seg_tree * > insert(int arr[],std::vector<int> v,int arr_size,int flag){
	int count[arr_size]={};
	int index=0;
	vector <seg_tree * >root_arr;
	seg_tree * root=insert_value(count,0,arr_size-1);
	root_arr.push_back(root);
	for(int i=0;i<arr_size;i++){
		if(flag==2)
		index=lower_bound(v.begin(),v.end(),arr[i],cmp)-v.begin();
		// cout<<index<<endl;
		else
			index=lower_bound(v.begin(), v.end(),arr[i])-v.begin();
		count[index]=1;
		root=update_seg(1,index,0,arr_size-1,root);
		root_arr.push_back(root);
	}
 	return root_arr;
}

int knum(seg_tree * root1,seg_tree * root2,int i,int j,int k){
	if(root1->left==NULL && root1->right==NULL)
	{
		return j;
	}
	int mid=(i+j)/2;
	int val=(root1->left->value-root2->left->value);
	if(val>=k){
		// cout<<"left "<<i<<" "<<j<<" "<<root->value<<" "<<k<<endl;
		return knum(root1->left,root2->left,i,mid,k);
	}
	// cout<<"right "<<i<<" "<<j<<" "<<root->value<<" "<<k-(root->left->value)<<endl;
	return knum(root1->right,root2->right,mid+1,j,k-val);
}
void traversal(seg_tree * root){
	if(root->left!=NULL && root->right!=NULL){
		traversal(root->left);
		traversal(root->right);
	}
	cout<<root->value<<" ";
}

int main(){
	ios_base::sync_with_stdio(0);
	std::vector<int> v;
	int n,q,flag;
	// cout<<"Enter number of elements in array\n";
	cin>>n>>q;
	cout<<"For min 1 \nFor max 2\n";
	cin>>flag;
	while(flag!=1 && flag!=2 ){
		cout<<"For min 1 \nFor max 2\n";
		cin>>flag;
	}

	// cout<<"Enter the elements of Array\n";
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		v.push_back(arr[i]);
	}
	//cout<<c<<" "<<v.size()<<endl;
	if(flag==1)sort(v.begin(),v.end());
	else if(flag==2){
		//cout<<"hey\n";
		sort(v.begin(), v.begin()+n, cmp);
		//cout<<c<<" "<<v.size()<<endl;
	 
	}
	// for(int i=0;i<n;i++){
	// 	cout<<v[i]<<" ";
	// }
	 vector<seg_tree *> root;
	 root=insert(arr,v,n,flag);
	//traversal(root);
	// for(int i=0;i<n+1;i++){
	// 	traversal(root[i]);
	// 	cout<<endl;
	// }
	while (q--){
		int i,j,k;
		cin>>i>>j;
		cin>>k;
		int x=knum(root[j],root[i-1],0,n-1,k);
		cout<<v[x]<<endl;
	}
	return 0;
}