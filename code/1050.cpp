#include<cstdio>
#include<cstring>
int main()
{
    int i,lena,lenb,asc[256]={0};
    char a[10010],b[10010];

    fgets(a,10010,stdin);
    fgets(b,10010,stdin);
    lena=strlen(a);
    lenb=strlen(b);
    for(i=0;i<lenb;i++)
        asc[b[i]]=1;
    for(i=0;i<lena;i++)
        if(asc[a[i]]==0)
            printf("%c",a[i]);
    printf("\n");
    return 0;
}