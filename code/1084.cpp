#include<cstdio>
#include<cctype>
#include<cstring>
int main()
{
    int i;
    char a[81],b[81],asc[256]={0};

    scanf("%s %s",a,b);
    for(i=0;i<strlen(b);i++){
        asc[toupper(b[i])]=1;
    }
    for(i=0;i<strlen(a);i++){
        a[i]=toupper(a[i]);
        if(asc[a[i]]==0){
            printf("%c",a[i]);
            asc[a[i]]=1;
        }
    }
    printf("\n");
    return 0;
}