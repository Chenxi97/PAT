#include<iostream>
#include<string>
#define MAX 21
using namespace std;
struct node{
    string op;
    int lchild,rchild;
}Node[MAX];
bool ischild[MAX]={0};
int root;
void inorder(int r){
    if(r==-1) return;
    if(r!=root&&(Node[r].lchild!=-1||Node[r].rchild!=-1)) cout<<"(";
    inorder(Node[r].lchild);
    cout<<Node[r].op;
    inorder(Node[r].rchild);
    if(r!=root&&(Node[r].lchild!=-1||Node[r].rchild!=-1)) cout<<")";
}
int main()
{
    int n,l,r;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>Node[i].op>>l>>r;
        if(l!=-1) ischild[l]=true;
        if(r!=-1) ischild[r]=true;
        Node[i].lchild=l;
        Node[i].rchild=r;
    }
    for(int i=1;i<=n;i++)
        if(ischild[i]==false)
            root=i;
    inorder(root);
    cout<<endl;
    return 0;
}