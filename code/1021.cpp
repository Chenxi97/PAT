#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#define MAX 10010
using namespace std;
int n,maxl=0;
set<int> ans;
vector<int> v[MAX];
bool travel[MAX]={0};
void dfs(int ver,int layer){
    travel[ver]=true;
    if(layer>maxl){
        maxl=layer;
        ans.clear();
        ans.insert(ver);
    }
    else if(layer==maxl)
        ans.insert(ver);
    for(int i=0;i<v[ver].size();i++){
        int verti=v[ver][i];
        if(travel[verti]==false)
            dfs(verti,layer+1);
    }
}
int main()
{
    int v1,v2;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&v1,&v2);
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    dfs(1,1);//从节点1开始遍历
    int num=1;
    for(int j=1;j<=n;j++){
        if(travel[j]==false){
            dfs(j,1);
            num++;
        }
    }
    if(num>1){//多于1个连通块
        printf("Error: %d components\n",num);
        return 0;
    }
    memset(travel,false,sizeof(travel));//重置travel数组
    set<int> temp=ans;//保存上一步的结果
    dfs(*ans.begin(),1);//在结果中任选一个节点遍历
    for(set<int>::iterator i=temp.begin();i!=temp.end();i++)
        ans.insert(*i);//合并结果
    for(set<int>::iterator i=ans.begin();i!=ans.end();i++)
        printf("%d\n",*i);
    return 0;
}