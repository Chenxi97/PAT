#include<cstdio>
#include<vector>
#include<cmath>
#define MAX 100000
using namespace std;
vector<int> Node[MAX];
int n,num=0;
double p,r,ans=0.0;
void dfs(int root,int layer){
    if(Node[root].size()==0){
        if(layer>ans){
            num=1;
            ans=layer;
        }else if(layer==ans)
            num++;
    }
    for(int i=0;i<Node[root].size();i++)
        dfs(Node[root][i],layer+1);
}
int main()
{
    int root,temp;
    scanf("%d%lf%lf",&n,&p,&r);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        if(temp!=-1) Node[temp].push_back(i);
        else root=i;
    }
    dfs(root,0);
    printf("%.2lf %d\n",p*pow(1.0+r/100,ans),num);
    return 0;
}