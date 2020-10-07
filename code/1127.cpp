#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 30
using namespace std;
struct node{
    int data;
    node *left,*right;
    int level;
};
int n,post[MAX],in[MAX],lnum[MAX]={0};
vector<int> ans;
node* maketree(int postL,int postR,int inL,int inR){
    if(postL>postR) return NULL;
    node *root;
    root=new node;
    root->data=post[postR];
    int k;
    for(k=inL;k<=inR&&in[k]!=root->data;k++);
    int lnum=k-inL;
    root->left=maketree(postL,postL+lnum-1,inL,k-1);
    root->right=maketree(postL+lnum,postR-1,k+1,inR);
    return root;
}
int maxl=0;
void level(node *root){//层序遍历
    queue<node*> q;
    root->level=0;
    q.push(root);
    while(!q.empty()){
        node *now=q.front();
        q.pop();
        ans.push_back(now->data);
        int l=now->level;
        maxl=max(maxl,l);
        lnum[l]++;
        if(now->left!=NULL){
            now->left->level=l+1;
            q.push(now->left);
        }
        if(now->right!=NULL){
            now->right->level=l+1;
            q.push(now->right);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>in[i];
    for(int i=0;i<n;i++)
        cin>>post[i];
    node *root;
    root=maketree(0,n-1,0,n-1);
    level(root);
    int begin=0;
    for(int i=0;i<=maxl;i++){
        if(i%2==0)//偶数层的数反转
            reverse(ans.begin()+begin,ans.begin()+begin+lnum[i]);
        begin+=lnum[i];
    }
    for(int i=0;i<ans.size();i++){
        if(i>0) cout<<" ";
        cout<<ans[i];
    }
    return 0;
}