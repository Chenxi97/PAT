#include<cstdio>
#include<cstring>
#define MAX 1010
int main()
{
    char s[MAX];
    int dp[MAX][MAX],i;
    getchar();
    gets(s);
    memset(dp,0,sizeof(dp));//³õÊ¼»¯ÎªÁã
    int len=strlen(s),ans=1;
    dp[len-1][len-1]=1;
    for(i=0;i<len-1;i++){
        dp[i][i]=1;
        if(s[i]==s[i+1]){
            dp[i][i+1]=1;
            ans=2;
        }
    }
    for(int l=3;l<=len;l++){
        for(i=0;i+l-1<len;i++){
            int j=i+l-1;
            if(s[i]==s[j]&&dp[i+1][j-1]==1){
                dp[i][j]=1;
                ans=l;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}