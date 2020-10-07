#include<cstdio>
#include<cstring>
int main()
{
    char a[81];
    int len,n1,n2,i,j;

    scanf("%s",a);
    len=strlen(a);
    n1=(len+2)/3;
    n2=len+2-2*n1;
    for(i=0;i<n1-1;i++){    //输出前n1-1行
        printf("%c",a[i]);
        for(j=0;j<n2-2;j++) //输出n2-2个空格
            printf(" ");
        printf("%c\n",a[len-i-1]);
    }
    a[n1+n2-1]='\0';    //输出最后一行
    printf("%s\n",a+n1-1);
    return 0;
}