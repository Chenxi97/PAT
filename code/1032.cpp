#include<cstdio>
struct Node{
    char data;
    int next;
}node[100000];
int main()
{
    int ad1,ad2,ad,n,i,time[100000]={0};
    scanf("%d%d%d",&ad1,&ad2,&n);
    for(i=0;i<n;i++){
        scanf("%d",&ad);        
        scanf(" %c%d",&node[ad].data,&node[ad].next);
    }
    int now;
    for(now=ad1;now!=-1;now=node[now].next)
        time[now]++;    //����һ�������г��ֹ��Ľڵ���Ϊ1
    for(now=ad2;now!=-1;now=node[now].next)
        if(time[now]==1) break; //��һ�����ִ���Ϊ1�Ľڵ㼴Ϊ����
    if(now!=-1) printf("%05d\n",now);
    else printf("-1\n");
    return 0;
}