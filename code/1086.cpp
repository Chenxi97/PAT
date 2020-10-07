#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
struct node{
    int data;
    node *lchild,*rchild;
};
vector<int> in,pre;
int n,count=0;
node *create(int inL,int inR,int preL,int preR){
    if(preL>preR) return NULL;
    node *root=new node;
    root->data=pre[preL];
    int k;
    for(k=inL;k<=inR;k++)
        if(in[k]==pre[preL]) break;
    int lnum=k-inL;
    root->lchild=create(inL,k-1,preL+1,preL+lnum);
    root->rchild=create(k+1,inR,preL+lnum+1,preR);
    return root;
}
void post(node *root){
    if(root==NULL) return;
    post(root->lchild);
    post(root->rchild);
    printf("%d",root->data);
    if(count<n-1) printf(" ");
    count++;
}
int main()
{
    int i,pnum;
    char temp[5];
    stack<int> s;
    in.push_back(0);
    pre.push_back(0);
    scanf("%d",&n);
    for(i=0;i<2*n;i++){
        scanf(" %s",temp);
        if(temp[1]=='u'){
            scanf("%d",&pnum);
            pre.push_back(pnum);
            s.push(pnum);
        }
        else{
            int inum=s.top();
            s.pop();
            in.push_back(inum);
        }
    }
    node *root=create(1,n,1,n);
    post(root);
    return 0;
}