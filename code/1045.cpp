#include<cstdio>
#include<algorithm>
#define MAX 10010
using namespace std;
int main()
{
    int n,m,l,i,c,w[201],a[MAX];
    fill(w,w+201,0);
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d",&c);
        w[c]=i;
    }
    scanf("%d",&l);
    int ct=0;
    for(i=0;i<l;i++){
        scanf("%d",&c);
        if(w[c]) a[ct++]=c;
    }
    int ans=0,dp[MAX];
    for(i=0;i<ct;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(w[a[i]]>=w[a[j]]&&dp[j]+1>dp[i])
                dp[i]=dp[j]+1;
        }
        ans=max(dp[i],ans);
    }
    printf("%d\n",ans);
    return 0;
}