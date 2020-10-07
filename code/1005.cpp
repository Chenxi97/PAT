#include<cstdio>
#include<cstring>
int main()
{
    int sum=0,i;
    char c,s[4],number[10][6]={"zero","one","two","three",
        "four","five","six","seven","eight","nine"};

    while((c=getchar())!='\n')
        sum+=(c-'0');
    sprintf(s,"%d",sum);
    int len=strlen(s);
    for(i=0;i<len-1;i++)
        printf("%s ",number[s[i]-'0']);
    printf("%s\n",number[s[i]-'0']);
    return 0;
}