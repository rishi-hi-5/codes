#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;
struct no_and_visit{
	int no;
	int visit;
};
vector<no_and_visit> v;
void compute_prime(){
	struct no_and_visit no;

    int *a=new int[100000];
    memset(a,0,sizeof(a));
    for(int j=2;j<50;j++){
    	if(a[j]==0)
	    for(int i=2;i<50000;i++){
	    		if(i*j>10000)
	    			break;
	    		a[i*j]=1;
	    	}
	}
          

    for(int i=1000;i<10000;i++){
    	if(a[i]!=1){
    		no.no=a[i];
    		no.visit=0;
    		v.push_back(no);
    	}
    }
}

int main(){
    int t;
    compute_prime();
	return 0;
}
