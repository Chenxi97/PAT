#include<cstdio>
#include<algorithm>
using namespace std;
struct Node{
    int data,next;
}node[100000];
int main()
{
    int n,i,k,head,ad;
    scanf("%d%d%d",&head,&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&ad);
        scanf("%d%d",&node[ad].data,&node[ad].next);
    }
    int now=head,a[100000],num=0;
    while(now!=-1){ //�ȱ���һ�������޳���Ч�ڵ�
        a[num++]=now;
        now=node[now].next;
    }
    for(i=0;i<=num-k;i+=k)//ÿk������תһ��
        reverse(a+i,a+i+k);
    for(i=0;i<num-1;i++)
        printf("%05d %d %05d\n",a[i],node[a[i]].data,a[i+1]);
    printf("%05d %d -1\n",a[i],node[a[i]].data);//���һ�����⴦��
    return 0;
}