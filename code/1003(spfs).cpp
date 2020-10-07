#include<cstdio>
#include<vector>
#include<set>
#include<queue>
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
bool inq[MAX]={0};
set<int> pre[MAX];
void spfa(int s){
    fill(d,d+n,INF);
    num[s]=1;
    d[s]=0;
    w[s]=weight[s];
    queue<int> q;
    q.push(s);
    inq[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=false;//设为不在队列中
        for(int i=0;i<v[u].size();i++){
            int ver=v[u][i].v;
            if(d[ver]>d[u]+v[u][i].w){
                d[ver]=d[u]+v[u][i].w;
                w[ver]=w[u]+weight[ver];
                num[ver]=num[u];
                pre[ver].clear();
                pre[ver].insert(u);
                if(inq[ver]==false){
                    q.push(ver);
                    inq[ver]=true;
                }
            }
            else if(d[ver]==d[u]+v[u][i].w){
                if(w[ver]<w[u]+weight[ver])
                    w[ver]=w[u]+weight[ver];
                num[ver]=0;
                pre[ver].insert(u);
                for(set<int>::iterator it=pre[ver].begin();it!=pre[ver].end();it++)
                    num[ver]+=num[*it];
                if(inq[ver]==false){
                    q.push(ver);
                    inq[ver]=true;
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
    spfa(sou);
    printf("%d %d\n",num[des],w[des]);
    return 0;
}