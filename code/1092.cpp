#include<cstdio>
#include<cstring>
int main()
{
    int i,num=0,len1,len2;
    char a[1001],b[1001],asc[128];

    scanf("%s %s",a,b);
    len1=strlen(a);
    len2=strlen(b);
    for(i=0;i<len1;i++)
        asc[a[i]]++;
    for(i=0;i<len2;i++){
        if(asc[b[i]]) asc[b[i]]--;
        else num++;
    }
    if(!num) printf("Yes %d\n",len1-len2);
    else printf("No %d\n",num);
    return 0;
}