#include<cstdio>
#include<cstdlib>
int main()
{
    int n,m,i,*a,e1,e2,temp,sum=0;

    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*(n+1));
    a[0]=0;
    for(i=1;i<=n;i++){
        scanf("%d",&temp);
        sum+=temp;
        a[i]=sum;   //ÿһ�㵽��һ��ľ���
    }
    
    scanf("%d",&m);
    for(i=0;i<m;i++){
        int len=0;
        scanf("%d%d",&e1,&e2);
        if(e1>e2){  //��������
            temp=e1;
            e1=e2;
            e2=temp;
        }
        len=a[e2-1]-a[e1-1];
        if(len>sum-len) len=sum-len;    //����̾���
        printf("%d\n",len);
    }
    return 0;
}
