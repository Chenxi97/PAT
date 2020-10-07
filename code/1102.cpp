#include<cstdio>
#include<queue>
using namespace std;
struct node{
    int lchild,rchild;
}Node[10];
int n,ct=0;
bool ha[256]={0};
void level(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        printf("%d",now);
        ct++;
        if(ct<n) printf(" ");
        else printf("\n");
        if(Node[now].lchild!=-1) q.push(Node[now].lchild);
        if(Node[now].rchild!=-1) q.push(Node[now].rchild);
    }
}
void in(int root){
    if(root==-1) return;
    in(Node[root].lchild);
    printf("%d",root);
    ct++;
    if(ct<n) printf(" ");
    else printf("\n");
    in(Node[root].rchild);
}
int ctod(char a){
    int ans;
    if(a=='-') ans=-1;
    else{
        ans=a-'0';
        ha[ans]=true;
    }
    return ans;
}
int main()
{
    int i;
    char c1,c2;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %c %c",&c1,&c2);
        Node[i].lchild=ctod(c2);//创建二叉树时直接翻转
        Node[i].rchild=ctod(c1);
    }
    int root;
    for(i=0;i<n;i++)
        if(ha[i]==false)
            root=i;
    level(root);
    ct=0;
    in(root);
    return 0;
}