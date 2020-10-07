#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#define MAX 10010
#define INF 1<<30
using namespace std;
vector<int> G[MAX],pre[MAX],ver;
map<pair<int,int>,int> line;
int n,st,ed,d[MAX];
bool inq[MAX];
void spfs(int s){
    fill(inq,inq+MAX,false);
    fill(d,d+MAX,INF);
    queue<int> q;
    q.push(s);
    inq[s]=true;
    d[s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=false;
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(d[v]>d[u]+1){
                d[v]=d[u]+1;
                pre[v].clear();
                pre[v].push_back(u);
                if(inq[v]==false){
                    inq[v]=true;
                    q.push(v);
                }
            }else if(d[v]==d[u]+1){
                pre[v].push_back(u);
                if(inq[v]==false){
                    inq[v]=true;
                    q.push(v);
                }
            }
        } 
    }
}
vector<pair<int,int> > temp,ans;
int mint;
void dfs(int u,int before){
    if(u==st){
        temp.push_back(make_pair(u,0));
        if(temp.size()<mint){
            mint=temp.size();
            ans=temp;
        }
        temp.pop_back();
        return;
    }
    for(int i=0;i<pre[u].size();i++){
        int v=pre[u][i];
        int l=line[make_pair(v,u)];
        if(l!=before) temp.push_back(make_pair(u,l));
        dfs(v,l);
        if(l!=before) temp.pop_back();
    }
}
int main()
{
    int m,s1,s2;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&m,&s1);
        ver.push_back(s1);
        for(int j=1;j<m;j++){
            scanf("%d",&s2);
            ver.push_back(s2);
            G[s1].push_back(s2);
            G[s2].push_back(s1);
            line[make_pair(s1,s2)]=line[make_pair(s2,s1)]=i;
            s1=s2;
        }
    }
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d%d",&st,&ed);
        spfs(st);
        temp.clear();
        ans.clear();
        mint=INF;
        dfs(ed,-1);
        printf("%d\n",d[ed]);
        int start=st;
        for(int i=ans.size()-2;i>=0;i--){
            printf("Take Line#%d from %04d to %04d.\n",
                ans[i].second,start,ans[i].first);
            start=ans[i].first;
        }
    }
    return 0;
}