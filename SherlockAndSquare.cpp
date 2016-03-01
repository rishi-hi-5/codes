#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int ffn(int a,int b){
    int n;
    for(int i=a;i<=b;i++)
    {
        if(sqrt(i)==(int)sqrt(i)){
            return i;
        }
        
    }
    return -1;
}
int main() {
    long long int a,b,t,cnt;
    cin>>t;
    
    while(t--)
    {
        cin>>a>>b;
        cnt=0;
        int x=ffn(a,b);
        if(x==-1){
            cout<<"0"<<"\n";
            continue;
        }
        if(x==b){
            cout<<"1"<<"\n";
            continue;
        }
        for(int i=x;i<=b;i++)
        {
           int n=sqrt(i);
            i=(n+1)*(n+1);
            i--;
            //cout<<i<<"\n";
            if((n*n)>=a&&(n*n)<=b)
            {
                //cout<<n*n<<"\n";
                cnt++;
            }
            else
                break;
        }
               cout<<cnt<<"\n";
    }
    return 0;
}

