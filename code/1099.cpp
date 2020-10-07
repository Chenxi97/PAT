#include<cstdio>
#include<queue>
#include<algorithm>
#define MAX 101
using namespace std;
struct node{
    int data;
    int lchild,rchild;
}Node[MAX];
int n,a[MAX],index=0;
void inorder(int root){ //÷––Ú±È¿˙
    if(root==-1) return;
    inorder(Node[root].lchild);
    Node[root].data=a[index++];
    inorder(Node[root].rchild);
}
int ct=0;
void level(int root){   //≤„–Ú±È¿˙
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        printf("%d",Node[now].data);
        ct++;
        if(ct<n) printf(" ");
        if(Node[now].lchild!=-1) q.push(Node[now].lchild);
        if(Node[now].rchild!=-1) q.push(Node[now].rchild);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&Node[i].lchild,&Node[i].rchild);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    inorder(0);
    level(0);
    return 0;
}