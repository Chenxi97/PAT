#include<cstdio>
#include<vector>
#define MAX 510
#define INF 1<<30
using namespace std;
int n,m,st,ed;
int d[MAX],t[MAX],Gd[MAX][MAX],Gt[MAX][MAX],num[MAX]={0};
bool vis[MAX];
vector<int> pre[MAX],stans,ftans,temp;
void dijkstra(int s,int *a,int G[MAX][MAX]){
    fill(a,a+MAX,INF);
    fill(vis,vis+MAX,false);
    a[s]=0;
    for(int i=0;i<n;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&a[j]<MIN){
                MIN=a[j];
                u=j;
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int v=0;v<n;v++){
            if(vis[v]==false&&G[u][v]!=INF){
                if(a[v]>a[u]+G[u][v]){
                    a[v]=a[u]+G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(a[v]==a[u]+G[u][v])
                    pre[v].push_back(u);
            }
        }
    }
}
int minv=INF;
void tdfs(int v){//寻找时间最短的路径
    if(v==st){
        temp.push_back(v);
        if(temp.size()<minv){
            minv=temp.size();
            ftans=temp;
        }
        temp.pop_back();
        return;
    }
    temp.push_back(v);
    for(int i=0;i<pre[v].size();i++)
        tdfs(pre[v][i]);
    temp.pop_back();
}
int mint=INF;
void ddfs(int v){//寻找距离最短的路径
    if(v==st){
        temp.push_back(v);
        int time=0;
        for(int i=temp.size()-1;i>0;i--)
            time+=Gt[temp[i]][temp[i-1]];
        if(time<mint){
            mint=time;
            stans=temp;
        }
        temp.pop_back();
    }
    temp.push_back(v);
    for(int i=0;i<pre[v].size();i++)
        ddfs(pre[v][i]);
    temp.pop_back();
}
void output(vector<int> &b){
    for(int i=b.size()-1;i>=0;i--){
        if(i<b.size()-1) printf(" -> ");
        printf("%d",b[i]);
    }
}
int main()
{
    int v1,v2,tag;
    fill(Gd[0],Gd[0]+MAX*MAX,INF);
    fill(Gt[0],Gt[0]+MAX*MAX,INF);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&v1,&v2,&tag);
        scanf("%d%d",&Gd[v1][v2],&Gt[v1][v2]);
        if(!tag){
            Gd[v2][v1]=Gd[v1][v2];
            Gt[v2][v1]=Gt[v1][v2];
        }
    }
    scanf("%d%d",&st,&ed);
    dijkstra(st,t,Gt);
    tdfs(ed);
    dijkstra(st,d,Gd); 
    ddfs(ed);
    if(ftans==stans){
        printf("Distance = %d; Time = %d: ",d[ed],t[ed]);
        output(stans);
    }else{
        printf("Distance = %d: ",d[ed]);
        output(stans);
        printf("\nTime = %d: ",t[ed]);
        output(ftans);
    }
    return 0;
}