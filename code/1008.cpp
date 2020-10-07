#include<cstdio>
int main()
{
    int n,i,a,last,sum=0;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a);
        if(i==0) sum+=a*6;
        else if(a>last) sum+=(a-last)*6;
        else sum+=(last-a)*4;
        last=a;
        sum+=5;
    }
    printf("%d\n",sum);
    return 0;
}
