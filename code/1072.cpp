#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 1020
#define INF 1<<30
using namespace std;
struct node{
    int v,w;
    node(int _v,int _w):v(_v),w(_w){}
};
int n,m,ds,k,d[MAX];
bool vis[MAX];
vector<node> G[MAX];
int stoi(char *a){
    int ans;
    if(a[0]=='G'){
        sscanf(a+1,"%d",&ans);
        ans+=n;
    }
    else sscanf(a,"%d",&ans);
    return ans;
}
void dijkstra(int s){
    fill(d,d+MAX,INF);
    fill(vis,vis+MAX,false);
    d[s]=0;
    for(int i=0;i<n+m;i++){
        int u=-1,MIN=INF;
        for(int j=1;j<=n+m;j++){
            if(vis[j]==false&&d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int j=0;j<G[u].size();j++){
            int v=G[u][j].v,dis=G[u][j].w;
            if(vis[v]==false&&d[v]>d[u]+dis)
                d[v]=d[u]+dis;
        }
    }
}
bool judge(int &ans,double &avg){
    int sum=0;
    ans=INF;
    for(int i=1;i<=n;i++){
        if(d[i]>ds) 
            return false;//存在大于ds的距离，返回false
        if(d[i]<ans)
            ans=d[i];
        sum+=d[i];
    }
    avg=(double)sum/(double)n;
    return true;
}
int main()
{
    char p1[5],p2[5];
    int dist;
    scanf("%d%d%d%d",&n,&m,&k,&ds);
    for(int i=0;i<k;i++){
        scanf(" %s %s%d",p1,p2,&dist);
        int pos1=stoi(p1),pos2=stoi(p2);
        G[pos1].push_back(node(pos2,dist));
        G[pos2].push_back(node(pos1,dist));
    }   
    int maxdis=0,sta=-1;
    double avgdis;
    for(int i=n+1;i<=n+m;i++){//枚举每个可能的加油站
        int ans;
        double avg;
        dijkstra(i);
        if(!judge(ans,avg)) continue;
        if(ans>maxdis&&ans<=ds){
            sta=i;
            maxdis=ans;
            avgdis=avg;
        }
        else if(ans==maxdis&&avg<avgdis){
            sta=i;
            avgdis=avg;
        }
    }
    if(sta==-1) printf("No Solution\n");
    else
        printf("G%d\n%.1lf %.1lf\n",sta-n,(double)maxdis,avgdis);
    return 0;
}