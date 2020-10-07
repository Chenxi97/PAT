#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 100000
struct Node{
    int ad,key,next,flag,order;
}node[MAX];
bool cmp(Node a,Node b){
    if(a.flag!=b.flag) return a.flag>b.flag;
    else return a.order<b.order;
}
int main()
{
    int n,i,head,ad;
    bool tag[10001]={0};
    for(i=0;i<MAX;i++)
        node[i].flag=0;
    scanf("%d%d",&head,&n);
    for(i=0;i<n;i++){
        scanf("%d",&ad);
        scanf("%d%d",&node[ad].key,&node[ad].next);
        node[ad].ad=ad;
    }
    int count=0,acount=0;
    for(int now=head;now!=-1;now=node[now].next){
        int key=abs(node[now].key);
        if(tag[key]==false){
            acount++;
            node[now].flag=2;   //有效节点
            tag[key]=true;
        }
        else           
            node[now].flag=1;   //删除节点
        count++;
        node[now].order=count;
    }
    sort(node,node+MAX,cmp);
    for(i=0;i<count;i++){
        if(i==acount-1||i==count-1) printf("%05d %d -1\n",node[i].ad,node[i].key);
        else printf("%05d %d %05d\n",node[i].ad,node[i].key,node[i+1].ad);
    }
    return 0;
}