#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#define MAX 1000
using namespace std;

struct point{
	int x;
	int y;
};

typedef struct point point;

struct line{
	point p1;
	point p2;
};

bool isCollinear(point p,point q,point r){
	return (q.x>=min(p.x,r.x)&&q.x<=max(p.x,r.x)&&q.y>=min(p.y,r.y)&&q.y<=max(p.y,r.y));
}

int checkTheOrientation(point p, point q,point r){
	int val=((q.y-p.y)*(r.x-q.x)-(r.y-q.y)*(q.x-p.x));
	if(val==0) return 0;
        else if(val>0)return 1;
	else if(val<0)return 2;	
}

bool TheyIntersect(line l1,line l2){
	int o1=checkTheOrientation(l1.p1,l1.p2,l2.p1);
	int o2=checkTheOrientation(l1.p1,l1.p2,l2.p2);
	int o3=checkTheOrientation(l2.p1,l2.p2,l1.p1);
	int o4=checkTheOrientation(l2.p1,l2.p2,l1.p2);
	
	if(o1!=o2&&o3!=o4)
		return true;

	else if(o1==0&&isCollinear(l1.p1,l2.p1,l1.p2))return true;	
	else if(o2==0&&isCollinear(l1.p1,l2.p2,l1.p2))return true;
	else if(o3==0&&isCollinear(l2.p1,l1.p1,l2.p2))return true;
	else if(o1==0&&isCollinear(l2.p1,l1.p2,l2.p2))return true;
	return false;
}
int n,m;

class UF{
	public:
		int set[MAX];
		void init(){
			for(int i=0;i<n;i++){
				set[i]=i;
			}
		}
		int find(int obj){
			while(set[obj]!=obj){
				obj=set[obj];
			}
			return obj;
		}
		bool areInSameSet(int obj1,int obj2){
			return (find(obj1)==find(obj2));
		}
		void makeUnionOfSets(int obj1,int obj2){
			int r1=find(obj1);
			int r2=find(obj2);
			set[r2]=r1;
		}
};


int main(){

	int t,a,b;
	point p1,p2;
	line l;
	vector<line> v;
	cin>>t;
	while(t--){
		cin>>n>>m;
		UF Connectivity;
		Connectivity.init();
		for(int i=0;i<n;i++){
			cin>>p1.x>>p1.y>>p2.x>>p2.y;
			l.p1=p1;
			l.p2=p2;
			v.push_back(l);
		}
		for(int i=0;i<v.size();i++){
			for(int j=i+1;j<v.size();j++)
			if(TheyIntersect(v.at(i),v.at(j))){
				Connectivity.makeUnionOfSets(i,j);	
			}
		}
		for(int i=0;i<m;i++){
			cin>>a>>b;
			if(Connectivity.areInSameSet(a-1,b-1))
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		v.clear();
	}
	return 0;
}
