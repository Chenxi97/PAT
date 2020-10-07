#include<cstdio>
#define MAX 10000
int main()
{
    int n,i,q[MAX],dp[MAX][2];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&q[i]);
    dp[0][0]=dp[0][1]=q[0];
    for(i=1;i<n;i++){
        if(q[i]>q[i]+dp[i-1][1])
            dp[i][0]=dp[i][1]=q[i];
        else{
            dp[i][1]=q[i]+dp[i-1][1];
            dp[i][0]=dp[i-1][0];
        }
    }
    int max=-1,ans=-1;
    for(i=0;i<n;i++){
        if(dp[i][1]>max){
            max=dp[i][1];
            ans=i;
        }
    }
    if(max<0)
        printf("0 %d %d\n",q[0],q[n-1]);
    else
        printf("%d %d %d\n",max,dp[ans][0],q[ans]);
    return 0;
}