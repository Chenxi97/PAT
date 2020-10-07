#include<cstdio>
#define MAX 1010
struct node{
    int data;
    node *left,*right;
};
int n,le[MAX]={0},max=0;
node *makenode(int n){
    node *now=new node;
    now->left=now->right=NULL;
    now->data=n;
    return now;
}
void insert(node* &root,int n){
    if(root==NULL) root=makenode(n);
    else if(n>root->data)
        insert(root->right,n);
    else
        insert(root->left,n);
}
void dfs(node* root,int layer){
    if(root==NULL) return;
    le[layer]++;
    if(layer>max) max=layer;
    dfs(root->left,layer+1);
    dfs(root->right,layer+1);
}
int main()
{
    int num;
    node *root=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        insert(root,num);
    }
    dfs(root,0);
    printf("%d + %d = %d\n",le[max],le[max-1],le[max-1]+le[max]);
    return 0;
}