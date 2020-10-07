#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 500
#define INF 0x3fffffff
using namespace std;
struct node{
    int v,w;
    node(int _v,int _w):v(_v),w(_w){}
};
int n,m,sou,des,cost[MAX][MAX],d[MAX];
bool vis[MAX]={0};
vector<node> dij[MAX];
vector<int> pre[MAX];//保存前导节点
void dijtravel(int s){
    fill(d,d+n,INF);
    d[s]=0;
    for(int i=0;i<n;i++){
        int u=-1,minl=INF;
        for(int j=0;j<n;j++)
            if(vis[j]==false&&d[j]<minl){
                minl=d[j];
                u=j;
            }
        if(u==-1) return;
        vis[u]=true;
        for(int j=0;j<dij[u].size();j++){
            int v=dij[u][j].v;
            if(vis[v]==false){
                if(d[v]>d[u]+dij[u][j].w){
                    d[v]=d[u]+dij[u][j].w;
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[v]==d[u]+dij[u][j].w)
                    pre[v].push_back(u);
            }
        }
    }
}
vector<int> temp,ans;
int minvalue=INF;
void dfs(int v){
    if(v==sou){//到达起点
        temp.push_back(v);
        int value=0;
        for(int i=temp.size()-1;i>0;i--){
            int id=temp[i],nextid=temp[i-1];
            value+=cost[nextid][id];
        }
        if(value<minvalue){
            minvalue=value;
            ans=temp;
        }
        temp.pop_back();
        return;
    }
    temp.push_back(v);
    for(int i=0;i<pre[v].size();i++)
        dfs(pre[v][i]);
    temp.pop_back();
}
int main()
{
    int c1,c2,dis,cos;
    scanf("%d%d%d%d",&n,&m,&sou,&des);
    for(int i=0;i<m;i++){
        scanf("%d%d%d%d",&c1,&c2,&dis,&cos);
        dij[c1].push_back(node(c2,dis));
        dij[c2].push_back(node(c1,dis));
        cost[c1][c2]=cost[c2][c1]=cos;
    }
    dijtravel(sou);
    dfs(des);
    for(int i=ans.size()-1;i>=0;i--)//倒序输出
        printf("%d ",ans[i]);
    printf("%d %d\n",d[des],minvalue);
    return 0;
}