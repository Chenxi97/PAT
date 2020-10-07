#include<cstdio>
struct node{
    int left,right;
}Node[20];
int n,cbt[21];
bool hash[20]={0};
int ctoi(char *c){
    int ans;
    if(c[0]=='-') return -1;
    else{
        sscanf(c,"%d",&ans);
        hash[ans]=true;
        return ans;
    }
}
void pre(int root,int index){
    if(root==-1||index>n) return;
    cbt[index]=root;
    pre(Node[root].left,index*2);
    pre(Node[root].right,index*2+1);
}
int main()
{
    int i;
    char lid[3],rid[3];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %s %s",lid,rid);//因为数字有可能有两位，不能用%c
        Node[i].left=ctoi(lid);
        Node[i].right=ctoi(rid);
    }
    int root;
    for(i=0;i<n;i++){
        if(hash[i]==false)
            root=i;
        cbt[i+1]=-1;
    }
    pre(root,1);
    for(i=1;i<=n;i++)
        if(cbt[i]==-1) break;
    if(i==n+1) printf("YES %d\n",cbt[n]);
    else printf("NO %d\n",root);
    return 0;
}