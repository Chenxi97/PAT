#include<cstdio>
#include<map>
using namespace std;
int main()
{
    int n,m,c,i,j;
    map<int,int> mp;
    scanf("%d%d",&n,&m);
    int half=n*m/2;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&c);
            mp[c]++;
            if(mp[c]>half){
                printf("%d\n",c);
                return 0;
            }
        }
    }
}