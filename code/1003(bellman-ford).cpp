#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
#define MAX 510
#define INF 0x3fffffff
using namespace std;
struct node{
    int v,w;
    node(int _v,int _w):v(_v),w(_w){}
};
int n;
vector<node> v[MAX];
int weight[MAX],d[MAX],w[MAX]={0},num[MAX]={0};
bool vis[MAX]={0};
set<int> pre[MAX];
void bellman(int s){
    fill(d,d+n,INF);
    d[s]=0;
    w[s]=weight[s];
    num[s]=1;
    for(int i=0;i<n-1;i++){
        for(int u=0;u<n;u++){
            for(int j=0;j<v[u].size();j++){
                int ver=v[u][j].v;
                int dis=v[u][j].w;
                if(d[ver]>d[u]+dis){
                    d[ver]=d[u]+dis;
                    w[ver]=w[u]+weight[ver];
                    num[ver]=num[u];
                    pre[ver].clear();
                    pre[ver].insert(u);
                }
                else if(d[ver]==d[u]+dis){
                    if(w[ver]<w[u]+weight[ver])
                        w[ver]=w[u]+weight[ver];
                    num[ver]=0;
                    pre[ver].insert(u);
                    for(set<int>::iterator it=pre[ver].begin();it!=pre[ver].end();it++)
                        num[ver]+=num[*it];
                }
            }
        }
    }
}
int main()
{
    int m,sou,des,c1,c2,len;
    scanf("%d%d%d%d",&n,&m,&sou,&des);
    for(int i=0;i<n;i++)
        scanf("%d",&weight[i]);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&c1,&c2,&len);
        v[c1].push_back(node(c2,len));
        v[c2].push_back(node(c1,len));
    }
    bellman(sou);
    printf("%d %d\n",num[des],w[des]);
    return 0;
}