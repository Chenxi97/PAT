#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 100000
struct Node{
    int ad,key,next,valid;
}node[MAX];
bool cmp(Node a,Node b){
    if(a.valid==0||b.valid==0)//��Ч�ڵ��������������
        return a.valid>b.valid;
    else return a.key<b.key;//��key��������
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
        node[now].valid=1;  //�������еĽڵ����Чλ��Ϊ1
    }
    sort(node,node+MAX,cmp);
    if(count==0) printf("0 -1\n");  //û�нڵ������
    else printf("%d %05d\n",count,node[0].ad);
    for(i=0;i<count;i++){
        if(i<count-1) printf("%05d %d %05d\n",node[i].ad,node[i].key,node[i+1].ad);
        else printf("%05d %d -1\n",node[i].ad,node[i].key);
    }
    return 0;
}