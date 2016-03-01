#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
bool isfraction(float no)
{
     string s=to_string(no);
     int pos=s.find('.');
     int flag=0;
     for(int i=pos;i<s.length();i++)
         switch(s[i])
         {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                flag=1;
            break;
            case 0:
            continue;
         }
    if(flag==1)
        return true;
    else
        return false;
}

int main() {
    long long int a,b,t,cnt;
    cin>>t;
    cin>>a>>b;
    while(t--)
    {
        cnt=0;
        for(int i=a;i<=b;i++)
        {
            if(isfraction(sqrt(i)))
            {
                cnt++;
            }
        }
               cout<<cnt<<"\n";
    }
    return 0;
}

