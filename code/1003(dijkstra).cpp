#include<cstdio>
#include<vector>
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
int re[MAX],d[MAX],rnum[MAX]={0},num[MAX]={0};
bool vis[MAX]={0};
void dijtravel(int s){
    fill(d,d+n,INF);
    d[s]=0;
    rnum[s]=re[s];
    num[s]=1;
    for(int i=0;i<n;i++){
        int u=-1,minl=INF;
        for(int j=0;j<n;j++)
            if(vis[j]==false&&d[j]<minl){
                u=j;
                minl=d[j];
            }
        if(u==-1) return;
        vis[u]=true;
        for(int j=0;j<v[u].size();j++){
            int ver=v[u][j].v;
            if(vis[ver]==false){
                if(d[ver]>d[u]+v[u][j].w){
                    d[ver]=d[u]+v[u][j].w;
                    rnum[ver]=rnum[u]+re[ver];
                    num[ver]=num[u];
                }
                else if(d[ver]==d[u]+v[u][j].w){
                    if(rnum[ver]<rnum[u]+re[ver])
                        rnum[ver]=rnum[u]+re[ver];
                    num[ver]+=num[u];//最短路径条数和点权无关
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
        scanf("%d",&re[i]);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&c1,&c2,&len);
        v[c1].push_back(node(c2,len));
        v[c2].push_back(node(c1,len));
    }
    dijtravel(sou);
    printf("%d %d\n",num[des],rnum[des]);
    return 0;
}