#include<cstdio>
#include<vector>
using namespace std;
vector<int> node[100];
int n,levelnum[100]={0},maxlevel=0;
void dfs(int root,int level){
    if(node[root].size()==0){
        if(level>maxlevel) maxlevel=level;
        levelnum[level]++;
    }
    for(int i=0;i<node[root].size();i++)
        dfs(node[root][i],level+1);
}
int main()
{
    int m,id,k,cid;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&id,&k);
        for(int j=0;j<k;j++){
            scanf("%d",&cid);
            node[id].push_back(cid);
        }
    }
    dfs(1,0);
    for(int i=0;i<=maxlevel;i++){
        printf("%d",levelnum[i]);
        if(i<maxlevel) printf(" ");
    }
    return 0;
}