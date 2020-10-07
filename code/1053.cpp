#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 100
struct node{
    int w;
    vector<int> child;
}Node[MAX];
int n,weight;
vector<int> ans;
bool cmp(int a,int b){
    return Node[a].w>Node[b].w;
}
void dfs(int root,int wei){
    if(wei>weight) return;  //大于给定权重
    if(wei==weight){    //等于给定权重
        if(Node[root].child.size()!=0) return;  //不是叶子节点
        for(int j=0;j<ans.size();j++){
            if(j>0) printf(" ");
            printf("%d",ans[j]);
        }
        printf("\n");
    }
    for(int i=0;i<Node[root].child.size();i++){
        int cid=Node[root].child[i];
        ans.push_back(Node[cid].w); //将孩子节点的权重加入路径
        dfs(cid,wei+Node[cid].w);
        ans.pop_back(); //回溯
    }
}
int main()
{
    int m,k,id,cid;
    scanf("%d%d%d",&n,&m,&weight);
    for(int i=0;i<n;i++)
        scanf("%d",&Node[i].w);
    for(int i=0;i<m;i++){
        scanf("%d%d",&id,&k);
        for(int j=0;j<k;j++){
            scanf("%d",&cid);
            Node[id].child.push_back(cid);
        }
        sort(Node[id].child.begin(),Node[id].child.end(),cmp);//将孩子节点按权重排序
    }
    ans.push_back(Node[0].w);
    dfs(0,Node[0].w);
    return 0;
}