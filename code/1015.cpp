#include<cstdio>
#include<cmath>
bool isprime(int a){
    if(a<=1) return false;
    int sqr=(int)sqrt(1.0*a);
    for(int i=2;i<=sqr;i++)
        if(a%i==0) return false;
    return true;
}
int toradix(int n,int radix){
    int a[30],num=0,ans;
    do{
        a[num++]=n%radix;
        n/=radix;
    }while(n>0);
    ans=a[0];
    for(int i=1;i<num;i++){
        ans*=radix;
        ans+=a[i];
    }
    return ans;
}
int main()
{
    int n,d;

    scanf("%d",&n);
    while(n>=0){
        scanf("%d",&d);
        printf("%s\n",isprime(n)&&isprime(toradix(n,d))?"Yes":"No");
        scanf("%d",&n);
    }
    return 0;
}