#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 10010
#define MAXI 101
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    int n,m,i,dp[MAXI],w[MAXN],choice[MAXN][MAXI];
    fill(choice[0],choice[0]+MAXI*MAXN,0);
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);
    sort(w,w+n,cmp);//逆序排列
    for(int v=0;v<=m;v++)
        dp[v]=0;
    for(i=0;i<n;i++){
        for(int v=m;v>=w[i];v--){
            if(dp[v-w[i]]+w[i]>=dp[v]){//状态转移方程
                dp[v]=dp[v-w[i]]+w[i];
                choice[i][v]=1;
            }
        }
    }
    int MAX=-1,ans=-1;
    for(int v=0;v<=m;v++){
        if(dp[v]>MAX){
            MAX=dp[v];
            ans=v;
        }
    }
    if(ans!=m){//无解
        printf("No Solution\n");
        return 0;
    }
    bool flag[MAXN]={0};//寻找最优解路径
    for(i=n-1;i>=0;i--){
        if(choice[i][ans]==1){
            flag[i]=true;
            ans-=w[i];
        }
    }
    int tag=1;
    for(i=n-1;i>=0;i--){
        if(flag[i]==true){
            if(tag) tag=0;
            else printf(" ");
            printf("%d",w[i]);            
        }
    }
    return 0;
}