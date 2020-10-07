#include<cstdio>
#include<unordered_set>
using namespace std;
int main()
{
    int n,m,k,temp,s1,s2;
    unordered_set<int> st[51];

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&m);
        for(int j=0;j<m;j++){
            scanf("%d",&temp);
            st[i].insert(temp);
        }
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d%d",&s1,&s2);
        int shared=0;
        for(unordered_set<int>::iterator j=st[s1].begin();j!=st[s1].end();j++){
            if(st[s2].find(*j)!=st[s2].end())
                shared++;
        }
        printf("%.1lf%%\n",(double)shared/(st[s1].size()+st[s2].size()-shared)*100);
    }
    return 0;
}