#include<iostream>
#include<string>
#include<map>
#include<vector>
#define MAX 210
#define INF 1<<30
using namespace std;
int n,k,de;
int weight[MAX],G[MAX][MAX],d[MAX],num[MAX]={0};
bool vis[MAX]={0};
map<string,int> cton;
map<int,string> ntoc;
vector<int> pre[MAX];
void dijkstra(int s){
    fill(d,d+MAX,INF);
    d[s]=0;
    num[s]=1;
    for(int i=0;i<n;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&d[j]<MIN){
                MIN=d[j];
                u=j;
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int v=0;v<n;v++){
            if(G[u][v]!=INF&&vis[v]==false){
                if(d[v]>d[u]+G[u][v]){
                    d[v]=d[u]+G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                    num[v]=num[u];
                }
                else if(d[v]==d[u]+G[u][v]){
                    num[v]+=num[u];
                    pre[v].push_back(u);
                }
            }
        }
    }
}
vector<int> ans,temp;
int maxhappy=-1,maxavg=-1;
void dfs(int v){
    if(v==0){
        temp.push_back(v);
        int value=0;
        for(int i=temp.size()-2;i>=0;i--)
            value+=weight[temp[i]];
        int avg=value/(temp.size()-1);
        if(value>maxhappy){
            maxhappy=value;
            ans=temp;
            maxavg=avg;
        }
        else if(value==maxhappy&&avg>maxavg){
            ans=temp;
            maxavg=avg;
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
    string c1,c2,sou;
    cin>>n>>k>>sou;
    cton[sou]=0;
    ntoc[0]=sou;
    for(int i=1;i<=n-1;i++){
        cin>>c1>>weight[i];
        if(c1=="ROM") de=i;
        cton[c1]=i;
        ntoc[i]=c1;
    }
    int len;
    fill(G[0],G[0]+MAX*MAX,INF);//��ʼ��ͼ
    for(int i=0;i<k;i++){
        cin>>c1>>c2>>len;
        int cn1=cton[c1],cn2=cton[c2];
        G[cn1][cn2]=G[cn2][cn1]=len;
    }
    dijkstra(0);
    dfs(de);
    printf("%d %d %d %d\n",num[de],d[de],maxhappy,maxavg);
    for(int i=ans.size()-1;i>=0;i--){
        if(i<ans.size()-1) printf("->");
        printf("%s",ntoc[ans[i]].c_str());
    }
    return 0;
}