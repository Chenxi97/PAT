#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
struct node{
    int data;
    node *lchild;
    node *rchild;
};
int n,in[31],post[31];
vector<int> ans;
node *create(int inL,int inR,int postL,int postR){
    if(postL>postR) return NULL;
    node *root=new node;
    root->data=post[postR];
    int i;
    for(i=inL;i<=inR;i++)
        if(in[i]==post[postR]) break;
    int lnum=i-inL;
    root->lchild=create(inL,i-1,postL,postL+lnum-1);
    root->rchild=create(i+1,inR,postL+lnum,postR-1);
    return root;
}
void order(node *root){
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node *n=q.front();
        q.pop();
        ans.push_back(n->data);
        if(n->lchild!=NULL) q.push(n->lchild);
        if(n->rchild!=NULL) q.push(n->rchild);
    }
}
int main()
{
    node *tree;
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&post[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&in[i]);
    tree=create(1,n,1,n);
    order(tree);
    for(i=0;i<ans.size();i++){
        if(i>0) printf(" ");
        printf("%d",ans[i]);
    }
    return 0;
}