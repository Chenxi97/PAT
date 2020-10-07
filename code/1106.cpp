#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
#define MAX 100000
vector<int> node[MAX];
int n,minl=MAX,num=0;
double p,r;
void dfs(int root,int level){
    if(node[root].size()==0){
        if(level<minl){
            minl=level;
            num=1;
        }else if(level==minl)
            num++;
    }
    for(int i=0;i<node[root].size();i++)
        dfs(node[root][i],level+1);
}
int main()
{
    int k,child;
    scanf("%d%lf%lf",&n,&p,&r);
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            scanf("%d",&child);
            node[i].push_back(child);
        }
    }
    dfs(0,0);
    printf("%.4lf %d\n",pow(1.0+r/100,minl)*p,num);
    return 0;
}