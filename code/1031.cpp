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
    for(i=0;i<n1-1;i++){    //���ǰn1-1��
        printf("%c",a[i]);
        for(j=0;j<n2-2;j++) //���n2-2���ո�
            printf(" ");
        printf("%c\n",a[len-i-1]);
    }
    a[n1+n2-1]='\0';    //������һ��
    printf("%s\n",a+n1-1);
    return 0;
}