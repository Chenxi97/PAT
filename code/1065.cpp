#include<cstdio>
int main()
{
    int t,i,tag;
    long long a,b,c,sum;

    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%lld%lld%lld",&a,&b,&c);
        sum=a+b;
        if(a>0&&b>0&&sum<=0) tag=1;  //�����ʱ�ض�����c
        else if(a<0&&b<0&&sum>=0) tag=0; //�����ʱ�ض�С��c
        else tag=(sum>c);
        printf("Case #%d: %s\n",i,tag?"true":"false");
    }
    return 0;
}