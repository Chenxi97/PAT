#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n;
struct node{
    int data,height;
    node *left,*right;
};
node *makenode(int m){
    node *now=new node;
    now->data=m;
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
void insert(node *&root,int m){
    if(root==NULL) root=makenode(m);
    else if(root->data>m){
        insert(root->left,m);
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
        insert(root->right,m);
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
node *create(void){
    int num;
    node *root=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        insert(root,num);
    }
    return root;
}
void level(node *root){//层序遍历
    int count=0;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *now=q.front();
        q.pop();
        printf("%d",now->data);
        count++;
        if(count<n) printf(" ");
        else printf("\n");
        if(now->left!=NULL) q.push(now->left);
        if(now->right!=NULL) q.push(now->right);
    }
}
int tag=0;
void dfs(node*root,int k){//判断是否为完全二叉树
    if(root==NULL) return;
    if(k>n) tag=1;
    dfs(root->left,2*k);
    dfs(root->right,2*k+1);
}
int main()
{
    scanf("%d",&n);
    node* root=create();
    level(root);
    dfs(root,1);
    printf(tag?"NO\n":"YES\n");
    return 0;
}