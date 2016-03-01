#include<cstdio>
#include<iostream>
#include<map>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
struct func{
	bool operator()(pair<string,long int> &lp,pair<string,long int> &rp) const {
		return lp.second>rp.second;
	}
};
int main(){
	long int t,temp;
	long int pos_nos,no_of_comp;
	string player;
	long int multi;
	long int no;
	long int val;
	long int k=0;
	long int inc;
	vector<pair<string,long int> > player_details;
	cin>>t;
	while(t--){
		map<string,vector<long int> > player_stat;
		vector<long int> v;
		player_details.clear();
		cin>>pos_nos;
		for(long int i=0;i<pos_nos;i++){
			cin>>temp;
			v.push_back(temp);
		}
		cin>>no_of_comp;
		for(long int i=0;i<no_of_comp;i++){
			cin>>multi;
			for(long int j=0;j<pos_nos;j++){
				cin>>player;
				player_stat[player].push_back(multi*v.at(j));
				sort(player_stat[player].begin(),player_stat[player].end(),std::greater<long int>());
			}
		}
		cin>>no;
		val=0;
		inc=0;
		for (map<string,vector<long int> >::iterator it=player_stat.begin();it!=player_stat.end();it++){
			val=0;
			while(inc!=2&&inc<it->second.size()){
				val+=it->second.at(inc);
				inc++;
			}
			inc=0;
			player_details.push_back(make_pair(it->first,val));
		}
		sort(player_details.begin(),player_details.end(),func());
		cout<<"Case #"<<k+1<<":"<<endl;
		inc=1;
		for(vector<pair<string,long int> >::iterator it = player_details.begin();it!=player_details.end();it++){
			cout<<inc<<": "<<it->first<<endl;
			inc++;
		}
		k++;
	}

	return 0;
}
