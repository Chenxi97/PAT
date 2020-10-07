#include<cstdio>
#include<cmath>
int main()
{
    int n,len,i,j;

    scanf("%d",&n);
    int sqr=sqrt(1.0*n);
    for(len=10;len>0;len--){    //11!接近2^32,所以最多有十个连续因数
        for(i=2;i<=sqr;i++){
            long long temp=1;
            for(j=0;j<len;j++)
                temp*=(i+j);
            if(n%temp==0){  //能整除就输出
                printf("%d\n",len);
                for(j=0;j<len-1;j++){
                    printf("%d*",i+j);
                }
                printf("%d\n",i+j);
                return 0;
            }
        }
    }
    printf("1\n%d\n",n);
    return 0;
}