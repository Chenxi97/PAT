#include<cstdio>
#include<vector>
using namespace std;
int n,v[201][201];
int cycle(void){
    int incycle[201]={0};
    int num,vertice;
    vector<int> ver;
    scanf("%d",&num);
    for(int j=0;j<num;j++){
        scanf("%d",&vertice);
        incycle[vertice]++;
        ver.push_back(vertice);
    }
    if(ver[0]!=ver[num-1]||num!=n+1) return 0;//首尾不同或节点数不对返回false
    for(int i=1;i<=n;i++)
        if(incycle[i]==0) return 0;  //存在没有遍历到的边返回false  
    for(int i=0;i<num-1;i++){
        if(v[ver[i]][ver[i+1]]==0) //边不存在返回false
            return 0;
    }
    return 1;
}
int main()
{
    int m,k,i,j;
    for(i=0;i<201;i++)
        for(j=0;j<201;j++)
            v[i][j]=0;
    scanf("%d%d",&n,&m);
    int v1,v2;
    for(i=0;i<m;i++){
        scanf("%d%d",&v1,&v2);
        v[v1][v2]=v[v2][v1]=1;
    }
    scanf("%d",&k);
    for(i=0;i<k;i++)
        printf(cycle()?"YES\n":"NO\n");
    return 0;
}