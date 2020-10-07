#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
struct stu{
    int id,g[4],rank[4],bg;
}s[2000];
int tag;
bool cmp(stu a,stu b){
    return a.g[tag]>b.g[tag];
}
int main()
{
    int n,m,i,j,id;
    char p[5]="ACME";
    map<int,int> mp;

    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&s[i].id,&s[i].g[1],
        &s[i].g[2],&s[i].g[3]);
        s[i].g[0]=(s[i].g[1]+s[i].g[2]+s[i].g[3])/3;
        s[i].bg=0;
    }
    for(i=0;i<4;i++){
        tag=i;
        sort(s,s+n,cmp);
        s[0].rank[i]=1;
        for(j=0;j<n;j++){
            if(s[j].g[i]==s[j-1].g[i])
                s[j].rank[i]=s[j-1].rank[i];
            else
                s[j].rank[i]=j+1;
            if(s[j].rank[i]<s[j].rank[s[j].bg])
                s[j].bg=i;
        }
    }
    for(j=0;j<n;j++)
        mp[s[j].id]=j;
    for(i=0;i<m;i++){
        scanf("%d",&id);
        map<int,int>::iterator it=mp.find(id);
        if(it==mp.end()) printf("N/A\n");
        else{
            int r=s[it->second].bg;
            printf("%d %c\n",s[it->second].rank[r],p[r]);   
        }
    }
    return 0;
}