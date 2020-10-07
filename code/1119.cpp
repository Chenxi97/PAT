#include<cstdio>
struct node{
    int data;
    node *left,*right;
};
int n,pre[32],post[32],tag=0,count=0;
node* create(int preL,int preR,int postL,int postR){
    if(preL>preR) return NULL;
    node *root=new node;
    root->data=pre[preL];
    int lnum=0,i;
    for(i=postL;i<postR;i++){    
        lnum++;
        if(post[i]==pre[preL+1]) break;        
    }
    if(i==postR-1) tag=1;//如果前序的第二个数和后序的倒数第二个数相同，答案就不唯一
    root->left=create(preL+1,preL+lnum,postL,i);
    root->right=create(preL+lnum+1,preR,i+1,postR-1);
    return root;
}
void inorder(node *root){   //中序遍历
    if(root==NULL) return;
    inorder(root->left);
    printf("%d",root->data);
    count++;
    if(count<n) printf(" ");
    else printf("\n");
    inorder(root->right);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&pre[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&post[i]);
    node* root=create(1,n,1,n);
    printf("%s\n",tag?"No":"Yes");
    inorder(root);
    return 0;
}