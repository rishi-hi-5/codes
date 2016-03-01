//graph implementation for detecting the cycle

#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100000];
bool visit[100000] = {false, };

bool hasCycle(int start){
vector<int>::iterator iter;
visit[start] = true;
for(iter = adj[start].begin(); iter!=adj[start].end(); iter++){
if(!visit[*iter])
return hasCycle(*iter);
else
return true;
}
return false;
}

int main(){
adj[1].push_back(2);
adj[1].push_back(3);
adj[2].push_back(3);
adj[3].push_back(1);
adj[3].push_back(4);
adj[3].push_back(3);

hasCycle(3)? cout<<"This graph has a cycle.\n" : cout<<"This graph do not have a cycle.\n";

return 0;

}