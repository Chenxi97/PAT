#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 100000
struct Node{
    int ad,key,next,valid;
}node[MAX];
bool cmp(Node a,Node b){
    if(a.valid==0||b.valid==0)//有效节点排列在数组左侧
        return a.valid>b.valid;
    else return a.key<b.key;//按key升序排列
}
int main()
{
    int head,n,i,ad;
    for(i=0;i<MAX;i++)
        node[i].valid=0;
    scanf("%d%d",&n,&head);
    for(i=0;i<n;i++){
        scanf("%d",&ad);
        node[ad].ad=ad;
        scanf("%d%d",&node[ad].key,&node[ad].next);
    }
    int count=0,now;
    for(now=head;now!=-1;now=node[now].next){
        count++;
        node[now].valid=1;  //将链表中的节点的有效位设为1
    }
    sort(node,node+MAX,cmp);
    if(count==0) printf("0 -1\n");  //没有节点的特例
    else printf("%d %05d\n",count,node[0].ad);
    for(i=0;i<count;i++){
        if(i<count-1) printf("%05d %d %05d\n",node[i].ad,node[i].key,node[i+1].ad);
        else printf("%05d %d -1\n",node[i].ad,node[i].key);
    }
    return 0;
}