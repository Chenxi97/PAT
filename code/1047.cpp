#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 26*26*26*10+1
using namespace std;
int toid(char *a){
    int id=0;
    for(int i=0;i<3;i++)
        id=id*26+a[i]-'A';
    id=id*10+a[3]-'0';
    return id;
}
int main()
{
    vector<int> v[2501];
    int n,k,cid,cnum;
    char name[MAX][5],sid[5];

    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf(" %s%d",sid,&cnum);
        int id=toid(sid);
        strcpy(name[id],sid);
        for(int j=0;j<cnum;j++){
            scanf("%d",&cid);
            v[cid].push_back(id);
        }
    }
    for(int i=1;i<=k;i++){
        int len=v[i].size();
        printf("%d %d\n",i,len);
        sort(v[i].begin(),v[i].end());
        for(int j=0;j<len;j++)
            printf("%s\n",name[v[i][j]]);
    }
    return 0;
}