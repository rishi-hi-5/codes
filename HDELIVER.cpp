#include<vector>
#include<iostream>
#include<cassert>
#include<cstdio>

using namespace std;

#define s(n)                        scanf("%d",&n)
#define forall(i,a,b)               for(int i=a;i<b;i++)

using namespace std;

typedef vector<int> VI;

/*-------------------------Main code begins now ------------------------------*/

struct UnionFind
{
    VI dad, mass;
    int N;
    UnionFind(int _N)
    {
        N = _N;
        dad.resize(N);
        mass.resize(N);
        forall(i, 0, N)
            dad[i] = -1, mass[i] = 1;
    }
    
    int find(int a)
    {
        if(dad[a] < 0) return a;
             return dad[a] = find(dad[a]);
    }
    
    void merge(int a, int b)
    {
        int c1 = find(a), c2 = find(b);
        if(c1 != c2)
        {
            N--;
            if(mass[c1] < mass[c2]) 
	      swap(c1, c2);
            mass[c1] += mass[c2];
            dad[c2] = c1;
        }
    }
    int size()
    {
        return N;
    }
};


int testnum;

void solve()
{
    int N,M;
    s(N); s(M);
    assert(N >= 1 && N <= 100);
    assert(M >= 1 && M <= 1000);


    UnionFind uf(N);
    while(M--)
    {
        int x,y; s(x); s(y);
        assert(x >= 0 && x < N);
        assert(y >= 0 && y < N);
        uf.merge(x, y);
    }
    int Q; s(Q);
    assert(Q >= 1 && Q <= 3000);
    while(Q--)
    {
        int x,y; s(x); s(y);
        assert(x >= 0 && x < N);
        assert(y >= 0 && y < N);
        if(uf.find(x) == uf.find(y))
            printf("YO\n");
        else
            printf("NO\n");
    }
}

int main()
{
    int T; s(T);
    assert(T >= 1 && T <= 100);
    for(testnum = 1;testnum <= T;testnum++)
      solve();
}
