#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n1,n2,n;
    char a[5];

    scanf("%d",&n);
    while(1){
        sprintf(a,"%04d",n);
        sort(a,a+4);
        sscanf(a,"%d",&n2);
        reverse(a,a+4);
        sscanf(a,"%d",&n1);
        n=n1-n2;
        printf("%04d - %04d = %04d\n",n1,n2,n);
        if(n==0||n==6174) break;
    }
    return 0;
}