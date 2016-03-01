#include<cstdio>
#include<iostream>
#define gc getchar_unlocked
#define MAX 100
#include<vector>
using namespace std;
class UnionFind {
private:
   // int set[MAX];
    vector<int>set;
    int numObjects;
public:

    UnionFind(int n) : numObjects(n) {
        for (int i = 0; i < numObjects; ++i)
            set.push_back(i);
    }

    int find(int obj) {
        while (set.at(obj) != obj) {
            obj = set.at(obj);
        }
        return obj;
    }

    bool areInSameSet(int obj1, int obj2) {
        return find(obj1) == find(obj2);
    }
    void unionSet(int obj1, int obj2) {
        int r1 = find(obj1);
        int r2 = find(obj2);

        // union s2 into s1, now simply merge tree rooted at r2 with r1
        set.at(r2) = r1;
    }
    void clearvector(){
	set.clear();	
    }
};
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
void solve()
{
		
	int n,m,a,b,q,x,y;	
	bool flag;
		n=read_int();
		m=read_int();
		UnionFind u(n);
		while(m--)
		{
			a=read_int();
			b=read_int();
			u.unionSet(a,b);
		}
		q=read_int();
		while(q--)
		{
			x=read_int();
			y=read_int();
			flag=u.areInSameSet(x,y);
			if(flag==true)
				printf("YO\n");
			else
				printf("NO\n");
		}
}
int main()
{
	int t;
	t=read_int();
	while(t--)
	{
		solve();
	}
	
	return 0;
}	
