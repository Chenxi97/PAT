#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,i,j,k,a,b,nv,v;
    vector<pair<int,int> > vi;

    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        vi.push_back(make_pair(a,b));   //包含两个顶点的结构体
    }
    scanf("%d",&k);
    map<int,int> mp;
    for(i=0;i<k;i++){
        scanf("%d",&nv);
        vector<int> ve(n,0);
        for(j=0;j<nv;j++){  //读取顶点集合
            scanf("%d",&v);
            ve[v]=1;
        }
        for(j=0;j<m;j++){   //检验每条边是否包含集合中的顶点
            if(ve[vi[j].first]==0&&ve[vi[j].second]==0)
                break;
        }
        if(j==m) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}