#include<cstdio>
int main()
{
    int n,i;
    double a,sum=0.0;

    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lf",&a);
        sum+=a*i*(n-i+1);
    }
    printf("%.2lf\n",sum);
    return 0;
}