#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};

void preorder(struct node* p){
    if(p!=NULL){
        preorder(p->left);
        printf("%d",p->data);
        preorder(p->right);
    }
}

int main()
{
    int t,val,len;
    char* str;
    int i;
    struct node* root=NULL;
    struct node*p=NULL;
    struct node*temp=NULL;
    scanf("%d %d",&t,&val);
    root =(struct node*) malloc(sizeof(struct node));
    root->data=val;
    while(t--){
        len=0;
        scanf("%s",str);
        scanf("%d",val);
        while(str[len]!='\0'){
            len++;
        }
        p=root;
        for (i=0;i<len;i++){
            if(str[i]=='L'){
                if(i==len-1){
                    temp=(struct node*) malloc (sizeof (struct node));
                    temp->data=val;
                    p->left=temp;
                }
                p=p->left;
            }
            else if(str[i]=='R'){
                if(i==len-1){
                    temp=(struct node*) malloc (sizeof (struct node));
                    temp->data=val;
                    p->right=temp;
                }
                p=p->right;
            }
        }
        
        preorder(root);
        
    }
    return 0;
}
