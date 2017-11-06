#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;
struct Tnode{
    struct Tnode* node[26];
    long int maxWeight;
    int endOfWord;
};
struct Tnode*root;

int convert(char ch){
    return ch-97;
}
void insert_string_into_trie(string s,int wt){
    struct Tnode*p=root;
    for(int i=0;i<s.length();i++){
       if(p->node[convert(s[i])]==NULL){
            struct Tnode*temp=(struct Tnode*) malloc(sizeof(struct Tnode));
            temp->maxWeight=wt;
            p->node[convert(s[i])]=temp;
       }
       else{
            if(p->node[convert(s[i])]->maxWeight<wt){
                p->node[convert(s[i])]->maxWeight=wt;
            }
       }
        p=p->node[convert(s[i])];
    }
}


int search_into_trie(string s){
    struct Tnode*p=root;

    for(int i=0;i<s.length();i++){
        if(p->node[convert(s[i])]==NULL){
            return -1;
        }
        else if(i==s.length()-1){
            return p->node[convert(s[i])]->maxWeight;
        }
        p=p->node[convert(s[i])];
    }
    return -1;
}
int main()
{
    long int n,q,wt;
    string s;
    cin>>n>>q;
    root=(struct Tnode*) malloc(sizeof(struct Tnode));
    while(n--){
        cin>>s>>wt;
        insert_string_into_trie(s,wt);
    }
    while(q--){
        cin>>s;
        cout<<search_into_trie(s)<<endl;
    }
    return 0;
}
