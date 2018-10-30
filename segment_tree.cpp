#include <cmath>
#include <cstdio>
#include <vector>
#include <bits/stdc++.h> 
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>      
using namespace std;
#define MAX_INT 100000

struct seg_tree{
	int value;
	struct seg_tree *left,* right;
};
int sum (int a, int b)
{ 
	return a+b; 
}

int max (int a, int b)
{ 
	if(a>b)
		return a;
	return b;
}

int min_m(int a ,int b){
	if(a>b)
		return b;
	return a;	
}

seg_tree * create_node(int data){
	seg_tree *temp =(seg_tree *)malloc(sizeof(struct seg_tree));
	temp->left=temp->right=NULL;
	temp->value=data;
	return temp;
}

seg_tree * insert_value(int arr[],int i ,int j,int (*functocall)(int,int)){
	seg_tree * node,* left , * right;
	if(i==j){
		node=create_node(arr[i]);
		return node;
	}
	int mid=(i+j)/2,val;
	left=insert_value(arr,i,mid,functocall);
	right=insert_value(arr,mid+1,j,functocall);
	val=functocall(left->value,right->value);
	node=create_node(val);
	node->left=left;
	node->right=right;
	return node;
}
seg_tree *insert(int arr[],int arr_size,int (*functocall)(int,int)){
 	seg_tree * root=insert_value(arr,0,arr_size-1,functocall);
 	return root;

}
seg_tree *update_seg(int value,int l ,int r,int i ,int j
	,seg_tree * previous_root,int (*functocall)(int ,int )){ 
 	seg_tree * node,* left , * right;
 	node=(seg_tree *)malloc(sizeof(struct seg_tree));
 	int mid=(i+j)/2,val;
 	//cout<<i<<" "<<j<<l<<" "<<r<<" "<<mid<<"\n";
	if(i==j && i==l && r==j){
		node=create_node(value);
		return node;
	}
	if(l<=mid){
	left=update_seg(value,l,r,i,mid,previous_root->left,functocall);
	}
	else{
	left=previous_root->left;
	}
	if(r>=mid+1){
	right=update_seg(value,l,r,mid+1,j,previous_root->right,functocall);
	}
	else{
	right=previous_root->right;
	}
	val=functocall( left->value,right->value);
	node=create_node(val);
	node->left=left;
	node->right=right;
	return node;
}


void traversal(seg_tree * root){
	if(root->left!=NULL && root->right!=NULL){
		traversal(root->left);
		traversal(root->right);
	}
	cout<<root->value<<"\n";
}

int querry_seq_tree(seg_tree *root,int i ,int j , int low ,int high
	,int (*functocall)(int,int)){
		if(root){
			//cout<<i<<" "<<j<<" "<<l<<" "<<r<<" "<<root->value<<"\n";
		if(low>j || high<i){
			if((*functocall)==(*min_m))
				return MAX_INT;
			return 0;}
		if(i>=low && j<=high){
			//cout<<"high";
			return root->value;
		}
		int mid =(i+j)/2;
		return functocall(querry_seq_tree(root->left,i,mid,low,high,functocall),
		querry_seq_tree(root->right,mid+1,j,low,high,functocall));	
}
return 0;
}
int kth_min_max_element(seg_tree *root ,int k , int count){
	seg_tree * left, * right,*second_left ,*second_right;
	if(k==count){
		return root->value;
	}
	else{
		left=root->left;
		right=root->right;
		count++;
		if(left!=NULL&& left->value==root->value){
			second_right=left->right;
			second_left=left->left;
			//cout<<left->value<<" "<<right->value<<" "<<second_left->value<<" "<<second_right->value<<"\n";
		
			if(left->left!=NULL &&second_left->value > right->value ){//&& left->value!=second_left->value){
				
				return kth_min_max_element(second_left,k,count);
			}
			else if(left->right!=NULL && second_right->value > right->value ){//&& left->value!=second_right->value){
				
				return kth_min_max_element(second_right,k,count);
			}
			
			return kth_min_max_element(right,k,count);
		}
		else if(right!=NULL){
			second_right=right->right;
			second_left=right->left;
			//cout<<left->value<<" "<<right->value<<" ";//<<second_left->value<<" "<<second_right->value;
			if(right->right!=NULL && second_right->value > left->value){ //&& right->value!=second_right->value){
				return kth_min_max_element(second_right,k,count);
			}
			else if(right->left!=NULL && second_left->value > left->value){// && right->value !=second_left->value){
				return kth_min_max_element(second_left,k,count);
			}
			
			return kth_min_max_element(left,k,count);	
		}
	}
}
bool version_checker(int &v , int size){
	cout<<"Enter Version in which you want to querry from 0 to "<<size<<"\n";
	cin>>v;		
	if(v<=size)
		return true;
	else{
		cout<<"No such Version exits\n";
		return false;
	}

}

int main(){
	int n;
	cout<<"Enter number of elements in array\n";
	cin>>n;
	cout<<"Enter the elements of Array\n";
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Enter Operation for Segment Tree \n# sum \n# min \n# max\n";
	string operationToPreform;
	cin>>operationToPreform;
	int (*functocall)(int ,int);
	if(operationToPreform.compare("sum")==0){
		functocall=sum;
	}
	else if(operationToPreform.compare("min")==0){
		functocall=min_m;
	}
	else if(operationToPreform.compare("max")==0){
		functocall=max;
	}
	else{
		cout<<"Invalid Operation\n";
		exit(0);
	}
	vector<seg_tree *> version_list;
	seg_tree *root=insert(arr,n,functocall);
	traversal(root);
	version_list.push_back(root);
	int a,b,v;
	char ch ;
	//int k;
	// while(1){
	// cin>>k;
	// cout<<kth_min_max_element(root,k,0);
	// }/*
	while(1){
		cout<<"Enter choice responding to operation you want to prefrom \n";
		cout<<"# q for Query\n# u for Update \n# t for traversal \n# e for exit \n";
		cin>>ch;
		if(ch=='q'){	//Version
			if(!version_checker(v,version_list.size()-1)){
				continue;
			}
			cout<<"Enter Range in which you want to prefrom querry operation\n";		
			cin>>a>>b;
			if(a>=0 && b<n && a<=b)	
				cout<<querry_seq_tree(version_list[v],0,n-1,a,b,functocall)<<endl;
			else{
				cout<<"Invalid Range\n";
				continue;
			}
		}
		if(ch=='u'){		//Update
			int l,r,value;
			if(!version_checker(v,version_list.size()-1)){
				continue;
			}
			cout<<"Enter index in which you want to update value and updated value\n";
			cin>>l>>value;
			r=l;
			if(l<n&& l>=0){
			seg_tree * next_root=update_seg(value,l,r,0,n-1,version_list[v],functocall);
			traversal(next_root);
			version_list.push_back(next_root);
			}
			else{
				cout<<"Invalid value of Index \n";
				continue;
			}
		}
		if(ch=='t'){		//Traversal
			if(!version_checker(v,version_list.size()-1)){
			continue;
			}
			traversal(version_list[v]);
		}
		if(ch=='e'){		//Exit
			cout<<"Thank You! :)\n";
			break;
		}
	}
	return 0;

}