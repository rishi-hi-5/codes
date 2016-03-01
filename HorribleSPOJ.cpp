#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
#include<stack>
using namespace std;
vector<int> v,st;

struct treerecur{
	int st;
	int et;
};
stack<treerecur> s;

void construct_segtree(){
	
}


int main(){
	
	int n;
	int temp
	cin>>n;
	int size_of_tree;

	for(int i=0;i<n;i++){
		cin>>temp;
		v.push_back(temp);
	}
	size_of_tree=2*pow(2,log2(n))-1;
	st.clear()
	st=new vector<int>(size_of_tree);
	construct_segtree();
	return 0;
}
