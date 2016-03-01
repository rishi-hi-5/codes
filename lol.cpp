#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> v;
int size;
int findmin(){
    int mini=1001;
    for(int i=0;i<size;i++){
        cout<<v.at(i)<<"\n";
        if(mini>v.at(i)&&v.at(i)<=0){
            mini=v.at(i);
        }    
    }
    return mini;
}
bool finish(){
 for(int i=0;i<size;i++){
        if(v.at(i)!=0){
            return false;
        }
    }
   
  return true;
}
int main() {
    
    
    int temp;
    int mini;
    int cnt;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    while(!finish())
    {
        cnt=0;
        mini=findmin();  

	for(int i=0;i<size;i++){
	        if(v.at(i)!=0){
	            return false;
	        }
	    }
        for(int i=0;i<v.size();i++){
            cnt++;
        }
    }  
    //cout<<cnt<<"\n";
    return 0;
}

