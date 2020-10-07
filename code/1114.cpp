#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 10010
using namespace std;
struct node{
    int est,area;
}Node[MAX];
struct fnode{
    int id,num;
    double ar,as;
};
int n,minid,asum,esum,ct;
vector<int> G[MAX];
vector<fnode> ans;
bool vis[MAX]={0},had[MAX]={0},exist[MAX]={0};
bool cmp(fnode a,fnode b){
    if(a.ar!=b.ar) return a.ar>b.ar;
    else return a.id<b.id;
}
void dfs(int root){
    ct++;
    if(root<minid) minid=root;
    vis[root]=true;
    if(had[root]==true){
        asum+=Node[root].area;
        esum+=Node[root].est;
    }
    for(int i=0;i<G[root].size();i++){
        int id=G[root][i];
        if(vis[id]==false)
            dfs(id);
    }
}
int main()
{
    int id,k,c,fa,mo;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&id,&fa,&mo,&k);
        had[id]=true;
        if(fa!=-1){
            G[id].push_back(fa);        
            G[fa].push_back(id);
        }
        if(mo!=-1){
            G[id].push_back(mo);
            G[mo].push_back(id);
        }
        exist[mo]=exist[fa]=exist[id]=true;
        for(int j=0;j<k;j++){
            scanf("%d",&c);
            exist[c]=true;
            G[id].push_back(c);
            G[c].push_back(id);
        }
        scanf("%d%d",&Node[id].est,&Node[id].area);
    }
    for(int i=0;i<MAX;i++){
        if(exist[i]==true&&vis[i]==false){
            minid=i;
            asum=esum=ct=0;
            dfs(i);
            fnode temp={minid,ct,(double)asum/ct,(double)esum/ct};
            ans.push_back(temp);
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0;i<ans.size();i++)
        printf("%04d %d %.3lf %.3lf\n",ans[i].id,ans[i].num,
        ans[i].as,ans[i].ar);
    return 0;
}