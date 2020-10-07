#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 510
#define INF 1<<30
using namespace std;
int n,cmax,sp,dij[MAX][MAX],weight[MAX],d[MAX];
bool vis[MAX]={0};
vector<int> pre[MAX];
void dijtravel(int s){
    fill(d,d+MAX,INF);
    d[s]=0;
    for(int i=0;i<=n;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<=n;j++){
            if(d[j]<MIN&&vis[j]==false){
                MIN=d[j];
                u=j;
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int v=0;v<=n;v++){
            if(vis[v]==false&&dij[u][v]!=INF){
                if(d[u]+dij[u][v]<d[v]){
                    d[v]=d[u]+dij[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[u]+dij[u][v]==d[v])
                    pre[v].push_back(u);
            }
        }
    }
}
vector<int> ans,temp;
int minremain=INF,minneed=INF;
void dfs(int s){
    if(s==0){
        temp.push_back(s);
        int need=0,remain=0;
        for(int i=temp.size()-1;i>=0;i--){
            int id=temp[i];
            if(weight[id]>0)//需要带走的自行车
                remain+=weight[id];
            else{
                if(remain>abs(weight[id]))
                    remain-=abs(weight[id]);
                else{
                    need+=abs(weight[id])-remain;
                    remain=0;
                }
            }
        }
        if(need<minneed){
            minremain=remain;
            minneed=need;
            ans=temp;
        }else if(need==minneed&&remain<minremain){
            minremain=remain;
            ans=temp;
        }
        temp.pop_back();
        return;
    }
    temp.push_back(s);
    for(int i=0;i<pre[s].size();i++)
        dfs(pre[s][i]);
    temp.pop_back();
}
int main()
{
    int m,s1,s2,len,half;
    fill(dij[0],dij[0]+MAX*MAX,INF);//初始化dij数组
    scanf("%d%d%d%d",&cmax,&n,&sp,&m);
    half=cmax/2;//容量的一半
    for(int i=1;i<=n;i++){
        scanf("%d",&weight[i]);
        weight[i]-=half;
    }
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&s1,&s2,&len);
        dij[s1][s2]=dij[s2][s1]=len;
    }
    dijtravel(0);
    dfs(sp);
    printf("%d ",minneed);
    for(int i=ans.size()-1;i>=0;i--){
        if(i<ans.size()-1) printf("->");
        printf("%d",ans[i]);
    }
    printf(" %d\n",minremain);
    return 0;
}