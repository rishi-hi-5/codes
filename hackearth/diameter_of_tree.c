#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
int m=0;
void preorder(struct node* p){
    if(p!=NULL){
        preorder(p->left);
        printf("%d ",p->data);
        preorder(p->right);
    }
}

int max(int l,int r){
    return l>r?l:r;
}

int height(struct node*p){
    if(p==NULL){
        return 0;
    }
    int l=height(p->left);
    int r=height(p->right);

    if(m<1+l+r){
        m=1+l+r;
    }

    return max(1+l,1+r);
}

int main()
{
    int t,val,len;
    char str[20];
    int i;
    struct node* root=NULL;
    struct node*p=NULL;
    struct node*temp=NULL;
    scanf("%d %d",&t,&val);
    root =(struct node*) malloc(sizeof(struct node));
    root->data=val;
    t--;
    while(t--){
        len=0;
        scanf("%s",str);
        scanf("%d",&val);
        while(str[len]!='\0'){
            len++;
        }
        p=root;
        for (i=0;i<len;i++){
            if(str[i]=='L'){
                if(i==len-1){
                    if(p->left==NULL){
                        temp=(struct node*) malloc (sizeof (struct node));
                        temp->data=val;
                        p->left=temp;
                    }
                    else{
                        p=p->left;
                        p->data=val;
                    }
                }
                else if(p->left==NULL){
                    temp=(struct node*) malloc (sizeof (struct node));
                    p->left=temp;
                }
                p=p->left;
            }
            else if(str[i]=='R'){
                if(i==len-1){
                    if(p->right==NULL){
                        temp=(struct node*) malloc (sizeof (struct node));
                        temp->data=val;
                        p->right=temp;
                    }
                    else{
                        p=p->right;
                        p->data=val;
                    }
                }
                else if(p->right==NULL){
                    temp=(struct node*) malloc (sizeof (struct node));
                    p->right=temp;
                }
                p=p->right;
            }
        }
        
    }
    preorder(root);
    int r=(height(root->left)+1+height(root->right));
    printf("\n%d\n",m>r?m:r);
    return 0;
}
