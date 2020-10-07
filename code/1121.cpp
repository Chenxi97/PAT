#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> ans;
    int n,m,i,c1,c2,iscp[100010]={0},g[10010],
        cp[50010]={0};
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&c1,&c2);
        iscp[c1]=i;
        iscp[c2]=i;
    }
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&g[i]);
        int cpid=iscp[g[i]];
        if(cpid>0)
            cp[cpid]++;
    }
    for(i=0;i<m;i++){
        int cpid=iscp[g[i]];
        if(cpid==0)
            ans.push_back(g[i]);
        else if(cp[cpid]<2)
            ans.push_back(g[i]);
    }
    sort(ans.begin(),ans.end());
    int len=ans.size();
    printf("%d\n",len);
    for(i=0;i<len;i++){
        if(i>0) printf(" ");
        printf("%05d",ans[i]);  //¹Ì¶¨5Î»Êä³ö
    }
    return 0;
}