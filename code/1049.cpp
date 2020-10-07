#include<cstdio>
int main()
{
    int n,factor=1,count=0,now,low,high;

    scanf("%d",&n);
    while(n/factor>0){
        low=n%factor;
        now=(n/factor)%10;
        high=n/10/factor;
        if(now==0)
            count+=high*factor;
        else if(now==1)
            count+=high*factor+low+1;
        else
            count+=(high+1)*factor;
        factor*=10;
    }
    printf("%d\n",count);
    return 0;
}
