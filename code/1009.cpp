#include<cstdio>
#include<cstring>
int main()
{
    double a[1001]={0.0},ans[2001]={0.0};//ans指数上限为a,b的两倍
    int k,i,j,e,n=0;
    double c;

    scanf("%d",&k);
    for(i=0;i<k;i++){
        scanf("%d%lf",&e,&c);
        a[e]=c;
    }
    scanf("%d",&k);
    for(i=0;i<k;i++){
        scanf("%d%lf",&e,&c);
        for(j=0;j<1001;j++){
            if(a[j]!=0.0)
                ans[j+e]+=a[j]*c;
        }
    }

    for(i=0;i<2001;i++)
        if(ans[i]!=0.0) n++;
    printf("%d",n);
    for(i=2000;i>=0;i--)
        if(ans[i]!=0.0)
            printf(" %d %.1lf",i,ans[i]);
    printf("\n");
    return 0;
}