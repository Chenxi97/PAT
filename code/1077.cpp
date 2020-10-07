#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    char ans[260],a[260];
    int i,j,n,len1,len2,len;

    scanf("%d\n",&n);
    fgets(ans,260,stdin);
    reverse(ans,ans+strlen(ans));
    for(i=1;i<n;i++){
        fgets(a,260,stdin);
        len1=strlen(ans);
        len2=strlen(a);
        reverse(a,a+len2);
        len=min(len2,len1);
        for(j=0;j<len;j++)
            if(a[j]!=ans[j]){
                ans[j]='\0';
                break;
            }
    }
    reverse(ans,ans+strlen(ans));
    if(ans[0]=='\n')
        printf("nai\n");
    else
        printf("%s",ans);
    return 0;
}