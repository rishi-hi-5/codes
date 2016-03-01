#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string pivalue="31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

int main() {
    int t;
    int cnt;
    char ch;
    int flag;
    string res,str;
    cin>>t;
    int l=t;
    t++;
    while(t--){
        cnt=0;
        res="";
        flag=0;
        getline(cin,str);
	if(l==t)
		continue;
        cout<<str<<"\n";
        for(int i=0;i<str.length();i++){
            if(str[i]==' '){
                res+=(char)(cnt+'0');
                cnt=0;
            }
            else
                cnt++;
        }
        
        for(int i=0;i<res.length();i++){
            cout<<res[i]<<" "<<pivalue[i]<<"\n";
            if(res[i]==pivalue[i]){
                continue;
            }
            else{
               flag=1; 
               break;
            }
        }
        if(flag==0)
            cout<<"It's a pi song.\n";
        else
            cout<<"It's not a pi song.\n";
    }
    return 0;
}

