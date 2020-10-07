#include<iostream>
#include<algorithm>
#define MAX 31
using namespace std;
struct node{
    int data;
    int num;
    node *lchild,*rchild;
};
int pre[MAX];
node *maketree(int prel,int prer){
    if(prel>prer) return NULL;
    node *root;
    root=new node;
    root->data=pre[prel];
    int k;
    for(k=prel+1;k<=prer&&abs(pre[k])<abs(pre[prel]);k++);
    root->lchild=maketree(prel+1,k-1);
    root->rchild=maketree(k,prer);
    return root;
}
int tag=1;
int getnum(node *root){//root到叶子节点路径中黑色节点的数量
    if(root==NULL) return 0;
    int l=getnum(root->lchild);
    int r=getnum(root->rchild);
    return root->data>0?max(l,r)+1:max(l,r);
}
void dfs(node *root){
    if(root==NULL) return;
    if(root->data<0)//红色节点有红色孩子时设tag为0
        if((root->lchild!=NULL&&root->lchild->data<0)||
            (root->rchild!=NULL&&root->rchild->data<0))
            tag=0;
    //左右子树中黑色节点不一样时设tag为0
    if(getnum(root->lchild)!=getnum(root->rchild))
        tag=0;
    dfs(root->lchild);
    dfs(root->rchild);
}
int main(){
    int k,n;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>n;
        for(int j=0;j<n;j++)
            cin>>pre[j];
        node *root=maketree(0,n-1);
        tag=1;
        if(root->data<0) tag=0;
        else dfs(root);
        printf(tag?"Yes\n":"No\n");
    }
    return 0;
}