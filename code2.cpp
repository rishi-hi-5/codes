    #include<iostream>
    //#include<math.h>
    #define min(a,b) (a<b?a:b)
    using namespace std;
    long long p[1000001]={0};
    int main()
    {
    int n,k,flag=0;
    //for(int j=0;j<6;j++)cout<<p[j]<<" ";
    long long req=1000000000;
    //cout<<min(2,5)<<min(2,2)<<min(5,2);
    cin>>n>>k;
    long long a[n+1];
    for(int i=1;i<=n;i++)
    {
    cin>>a[i];
    if(!p[a[i]] || p[a[i]]>min(i,n+1-i))
    p[a[i]]=min(i,n+1-i);
    //for(int j=0;j<6;j++)cout<<p[j]<<" ";
    //cout<<"\n";
    }
    for(int i=1;i<=n;i++)
    {
    if(k-a[i]>0 && p[k-a[i]]>0 && k-a[i]!=a[i])
    {
    flag=1;
    //cout<<i<<" ";
    if(max(p[a[i]],p[k-a[i]])<req)req=max(p[a[i]],p[k-a[i]]);
    }
    }
    if(flag==0)
    cout<<"-1\n";
    else
    cout<<req<<"\n";
    } 
