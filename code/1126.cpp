#include<iostream>
#include<algorithm>
#define MAX 510
using namespace std;
int G[MAX][MAX],num=0,n;
bool vis[MAX]={0};
void dfs(int s){
    vis[s]=true;
    num++;
    for(int i=1;i<=n;i++)
        if(G[s][i]==1&&vis[i]==false)
            dfs(i);
}
int main()
{
    int m,i,v1,v2,degree[MAX]={0};
    fill(G[0],G[0]+MAX*MAX,0);
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>v1>>v2;
        degree[v1]++;
        degree[v2]++;
        G[v1][v2]=G[v2][v1]=1;
    }    
    int ct=0;
    for(i=1;i<=n;i++){
        if(i>1) cout<<" ";
        cout<<degree[i];
        if(degree[i]%2==1)
            ct++;
    }
    cout<<endl;
    dfs(1);
    if(num<n)//非连通图
        cout<<"Non-Eulerian";
    else{//连通图
        if(ct==0) cout<<"Eulerian";
        else if(ct==2) cout<<"Semi-Eulerian";
        else cout<<"Non-Eulerian";
    }
    cout<<endl;
    return 0;
}