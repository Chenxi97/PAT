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
        a[i]=sum;   //每一点到第一点的距离
    }
    
    scanf("%d",&m);
    for(i=0;i<m;i++){
        int len=0;
        scanf("%d%d",&e1,&e2);
        if(e1>e2){  //交换两点
            temp=e1;
            e1=e2;
            e2=temp;
        }
        len=a[e2-1]-a[e1-1];
        if(len>sum-len) len=sum-len;    //求最短距离
        printf("%d\n",len);
    }
    return 0;
}
