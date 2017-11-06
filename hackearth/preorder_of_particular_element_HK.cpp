#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node*root;

void preorder(struct node* p,int node,int f){
    if(p!=NULL){
        if(p->data==node){
            f=1;
        }
        if(f==1){
            printf("%d\n",p->data);
        }
        preorder(p->left,node,f);
        preorder(p->right,node,f);
    }
}

void insert(int node){
    if(root==NULL){
        struct node* temp=(struct node*) malloc(sizeof(struct node));
        temp->data=node;
        root=temp;
    }
    else{
        struct node*p=root;
        while(1){
            if(p->data>node){
                if(p->left==NULL){
                    struct node* temp=(struct node*) malloc(sizeof(struct node));
                    temp->data=node;  
                    p->left=temp;
                    break;
                }
                p=p->left;
            }
            else{
                if(p->right==NULL){
                    struct node* temp=(struct node*) malloc(sizeof(struct node));
                    temp->data=node;
                    p->right=temp;
                    break;
                }
                p=p->right;
            }
        }
    }
}

int main()
{
    int nnode;
    int node;
    cin>>nnode;
    while(nnode--){
        cin>>node;
        insert(node);
    }
    cin>>node;
    struct node*p=root;
    preorder(p,node,0);
    return 0;
}
