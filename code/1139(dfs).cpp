#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#define MAX 10010
using namespace std;
vector<int> f[MAX];
vector<int> temp;
vector<pair<int,int> >ans;
bool vis[MAX]={0};
int gender[MAX],ed;
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first!=b.first) return a.first<b.first;
    else return a.second<b.second;
}
void dfs(int s,int same,int layer){    
    if(s==ed){
        if(temp.size()==3)
            ans.push_back(make_pair(temp[1],temp[2]));
        return;
    }
    if(layer>=4) return;
    temp.push_back(s);
    vis[s]=true;
    for(int i=0;i<f[s].size();i++){
        int fid=f[s][i];
        if(vis[fid]==true) continue;
        if((same&&gender[fid]==gender[s])
            ||(!same&&layer%2==1&&gender[fid]==gender[s])
            ||(!same&&layer%2==0&gender[fid]!=gender[s]))
            dfs(fid,same,layer+1);
    }
    temp.pop_back();
    vis[s]=false;
}

int main()
{
    int n,m,q,id1,id2;
    char i1[6],i2[6];
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf(" %s %s",i1,i2);
        int tag1=1,tag2=1;
        if(i1[0]=='-') tag1=-1;
        if(i2[0]=='-') tag2=-1;        
        sscanf(i1,"%d",&id1);
        sscanf(i2,"%d",&id2);
        id1=abs(id1);
        id2=abs(id2);
        gender[id1]=tag1;
        gender[id2]=tag2;
        f[id1].push_back(id2);
        f[id2].push_back(id1);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d%d",&id1,&id2);
        id1=abs(id1);
        ed=abs(id2);
        int same=gender[id1]==gender[ed]?1:0;
        temp.clear();
        ans.clear();
        dfs(id1,same,1);
        printf("%d\n",ans.size());
        sort(ans.begin(),ans.end(),cmp);
        for(int i=0;i<ans.size();i++)
            printf("%04d %04d\n",ans[i].first,ans[i].second);
    }
    return 0;
}