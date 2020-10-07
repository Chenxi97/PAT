#include<cstdio>
#define MAX 1010
struct node{
    int data;
    node *lchild,*rchild;
};
int n,pre[MAX],tag=1,flag=1;
node *create(int preL,int preR){
    if(preL>preR) return NULL;
    node *root=new node;
    root->data=pre[preL];
    int i;
    if(flag){//���������
        for(i=preL+1;i<=preR;i++)//�ҵ���һ�����ڵ��ڸ��ڵ�Ľڵ�
            if(pre[i]>=pre[preL]) break;
        for(int j=i+1;j<=preR;j++){//�������������С�ڸ��ڵ�ľ�˵������������
            if(pre[j]<pre[preL]){
                tag=0;
                return NULL;
            }
        }
    }
    else{//������
        for(i=preL+1;i<=preR;i++)
            if(pre[i]<pre[preL]) break;
        for(int j=i+1;j<=preR;j++){
            if(pre[j]>=pre[preL]){
                tag=0;
                return NULL;
            }
        }
    }
    root->lchild=create(preL+1,i-1);
    root->rchild=create(i,preR);
    return root;
}
int count=0;
void post(node *root){//�������
    if(root==NULL) return;
    post(root->lchild);
    post(root->rchild);
    printf("%d",root->data);
    count++;
    if(count<n) printf(" ");
    else printf("\n");
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&pre[i]);
    if(n>1&&pre[1]>=pre[0]) flag=0;//����ڶ����ڵ��ֵ���ڵ��ڸ��ڵ���Ϊ������
    node *root=create(0,n-1);
    printf(tag?"YES\n":"NO\n");
    if(tag) post(root);
    return 0;
}