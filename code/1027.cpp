#include<cstdio>
int main()
{
    int n,i;
    char a[14]="0123456789ABC";

    printf("#");
    for(i=0;i<3;i++){
        scanf("%d",&n);
        printf("%c%c",a[n/13],a[n%13]);  
    }
    printf("\n");
    return 0;
}