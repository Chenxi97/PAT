#include<cstdio>
#include<vector>
#define MAX 1010
using namespace std;
int n,m,k;
vector<int> v[MAX];
bool travel[MAX];
void dfs(int ver,int city){
    travel[ver]=true;
    for(int i=0;i<v[ver].size();i++){
        int vertice=v[ver][i];
        if(travel[vertice]==false&&vertice!=city)
            dfs(vertice,city);
    }
}
int dfstravel(int city){
    int num=0;
    for(int i=0;i<=n;i++)
        travel[i]=false;
    for(int i=1;i<=n;i++){
        if(travel[i]==false&&i!=city){
            num++;
            dfs(i,city);
        }
    }
    return num;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    for(int i=0;i<k;i++){
        int city;
        scanf("%d",&city);
        printf("%d\n",dfstravel(city)-1);
    }
    return 0;
}