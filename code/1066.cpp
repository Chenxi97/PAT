#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
    int data,height;
    node *left,*right;
};
node *makenode(int n){
    node *now=new node;
    now->data=n;
    now->height=1;
    now->left=now->right=NULL;
    return now;
}
int getheight(node *root){
    if(root==NULL) return 0;
    return root->height;
}
int getbalance(node *root){
    return getheight(root->left)-getheight(root->right);
}
void update(node *root){
    root->height=max(getheight(root->left),getheight(root->right))+1;
}
void L(node *&root){
    node *temp=root->right;
    root->right=temp->left;
    temp->left=root;   
    update(root);   //自下向上更新树的高度
    update(temp);
    root=temp;
}
void R(node *&root){
    node *temp=root->left;
    root->left=temp->right;
    temp->right=root;
    update(root);
    update(temp);
    root=temp;
}
void insert(node *&root,int n){
    if(root==NULL) root=makenode(n);
    else if(root->data>n){
        insert(root->left,n);
        update(root);
        if(getbalance(root)==2){
            if(getbalance(root->left)==1)
                R(root);
            else if(getbalance(root->left)==-1){
                L(root->left);
                R(root);
            }
        }
    }
    else{
        insert(root->right,n);
        update(root);
        if(getbalance(root)==-2){
            if(getbalance(root->right)==-1)
                L(root);
            else if(getbalance(root->right)==1){
                R(root->right);
                L(root);
            }
        }
    }
}
node *create(int n){
    int num;
    node *root=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        insert(root,num);
    }
    return root;
}
int main()
{
    int n;
    scanf("%d",&n);
    node* root=create(n);
    printf("%d\n",root->data);
    return 0;
}