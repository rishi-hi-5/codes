#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#define gc getchar_unlocked
using namespace std;

//represents neighbouring city with respective cost
struct neighbour_cost{
	int nr;
	int cost;
};
typedef struct neighbour_cost nc; 
int read_int()
{
	char ch;
	ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	int ret=0;
	while(ch>='0'&& ch<='9')
	{
		ret=ret*10+ch-48;
		ch=gc();
	}
	return ret;
} 

class comparison{
	public:
	bool operator()(nc &p1,nc &p2)const{
		return (p1.cost)>(p2.cost);
	}
};
//maintains the adjacency list for the entered city
vector<vector<nc> > adjlist;

//cost and city matrix

struct city_cost{
	int city;
	int cost;
};

typedef city_cost cc;

priority_queue <cc,vector<nc>,comparison> q;

//no of cities
int n;

int dijkstras(int i,int j){

	bool visited[n];
	//temporary variable
	//excity denotes the extracted city from the adlist;
	nc ex,cc;
	cc.nr=i;
	cc.cost=0;
	q.push(cc);
	visited[cc.nr]=true;
	while(!q.empty()){
		cc=q.top();
		q.pop();

		//if we reach our destination city break and return the respective cost
		if(cc.nr==j)
			break;
		//if we dont reach our destination city iterate through the neighbouring city;
		if(visited[cc.nr]==true)
			for(int k=0;k<adjlist[cc.nr].size();k++){
				ex=adjlist[cc.nr].at(k);
				visited[ex.nr]=true;
				//add the cost of the source
				ex.cost+=cc.cost;
				q.push(ex);
			}
	}	
	return cc.cost;
}


int main(){
	//no of test cases
	int s;
	

	//name of the city
	
	//denoting number of neighbouring city
	int p; 
	
	//nr denotes index of city connected to the given input city
	//cost denotes the cost for reaching from given city to the neighbouring city
	int nr,cost;	
	
	//neighbouring city information
	nc in;

	//no of paths to find
	int r;
	
	//resulting shortest distance between two cities;
	int res;

	s=read_int();

	while(s--){
		//maping of city and indexes
		map<const char* , int > m;
		n=read_int();
		adjlist.resize(n+2);
		//accept the cities and make an adjacency list to represent the graph
		for(int i=1;i<=n;i++){	
			const char* str1;
			scanf("%s",*str1);
			in.nr=i;
			in.cost=0;
			m[str1]=i;
			p=read_int();

			for(int j=1;j<=p;j++){
				//take the negibouring city and their cost
				nr=read_int();
				cost=read_int();
				in.nr=nr;
				in.cost=cost;
				adjlist[i].push_back(in);
			}
		}		
	
		r=read_int();

		for(int i=1;i<=r;i++){
			const char* str1,str2;
			scanf("%s",str1);
			scanf("%s",str2);
			
			//perform dijkstras for the given cities and print the result
			if(m[str1]==0||m[str2]==0||strcmp(str1,str2)){
				cout<<"0"<<endl;
				continue;
			}
			res=dijkstras(m[str1],m[str2]);
			cout<<res<<endl;
		}

		//clear the city mappings and adjlist for the next iteration
		adjlist.clear();
	}
	return 0;
}
