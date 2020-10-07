#include<cstdio>
#include<vector>
using namespace std;
#define MAX 101
vector<int> Node[MAX];
int n,num[MAX]={0},g=1;
void dfs(int root,int layer){
    num[layer]++;
    if(num[layer]>num[g])
        g=layer;
    for(int i=0;i<Node[root].size();i++)
        dfs(Node[root][i],layer+1);
}
int main()
{
    int m,k,id,child;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&id,&k);
        for(int j=0;j<k;j++){
            scanf("%d",&child);
            Node[id].push_back(child);
        }
    }
    dfs(1,1);
    printf("%d %d\n",num[g],g);
    return 0;
}