#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int x[8]={2,2,1,-1,-2,-2,-1,1};
int y[8]={-1,1,2,2,-1,1,-2,-2};
int v[25][25]={0};
int m,n;
struct node{
    int s1,s2;
    int cost;
};

struct sortbycost{
    bool operator()(const node& l,const node& r)const{
        return l.cost>r.cost;
    }
};

int valid(int s1,int s2,int i){
    if(s1+x[i]<=0 || s2+y[i]<=0 || s1+x[i]>m||s2+y[i]>n ||v[s1+x[i]][s2+y[i]]>=1)
        return false;
    return true;
}

void printv(){
    printf("visited graph is \n");
    for(int i =0;i<=m;i++){
        for (int j=0;j<=n;j++)
            printf("%d",v[i][j]);
        printf("\n");
    }
}
int dfs(int s1,int s2,int d1,int d2){
    priority_queue< node,vector <node> ,sortbycost > s;
    node e,ne;
    int min=1000;
    e.s1=s1;
    e.s2=s2;
    e.cost=0;
    s.push(e);
    while(!s.empty()){
        e=s.top();
        s.pop();
        if(min>e.cost && e.s1==d1 && e.s2==d2){
            v[e.s1][e.s2]=e.cost;
            min=e.cost;
        }
        printv();
        for(int i=0;i<8;i++){
            if(valid(e.s1,e.s2,i)){
                v[e.s1+x[i]][e.s2+y[i]]=e.cost+1;
                ne.s1=e.s1+x[i];
                ne.s2=e.s2+y[i];
                ne.cost=e.cost+1;
                s.push(ne);
            }
        }
    }
    return v[d1][d2];
}

int main() {
    int t;
    int s1,s2,d1,d2;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&m,&n);
        scanf("%d %d %d %d",&s1,&s2,&d1,&d2);
        if(s1==d1 && s2==d2)
            printf("0\n");
        v[s1][s2]=1;
        v[d1][d2]=-1;
        cout<<dfs(s1,s2,d1,d2)<<endl;
    }
	return 0;
}
