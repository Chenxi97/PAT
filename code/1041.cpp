#include<cstdio>
int main()
{
    int n,i,num[10001]={0},b[100000];

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&b[i]);
        num[b[i]]++;
    }
    for(i=0;i<n;i++){
        if(num[b[i]]==1){
            printf("%d\n",b[i]);
            break;
        }
    }
    if(i==n) printf("None\n");
    return 0;
}