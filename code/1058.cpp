#include<cstdio>
#define MAX 100000000
int main()
{
    int a[3],b[3],ans[3]={0},sco[3]={MAX,17,29},i;

    scanf("%d.%d.%d",&a[0],&a[1],&a[2]);
    scanf(" %d.%d.%d",&b[0],&b[1],&b[2]);
    for(i=2;i>=0;i--)
        if((ans[i]+=a[i]+b[i])>=sco[i]){
            ans[i-1]+=ans[i]/sco[i];
            ans[i]%=sco[i];
        }
    printf("%d.%d.%d\n",ans[0],ans[1],ans[2]);
    return 0;
}