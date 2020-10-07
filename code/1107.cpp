#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> hobby[1001];
int n,friends[1001];
void init(void){
    for(int i=0;i<1001;i++)
        friends[i]=-1;
}
int findroot(int f){
    while(friends[f]>0)
        f=friends[f];
    return f;
}
void befriends(int f1,int f2){
    int r1=findroot(f1);
    int r2=findroot(f2);
    if(r1!=r2){        
        friends[r1]+=friends[r2];
        friends[r2]=r1;
    }
}
void find(void){
    for(int i=1;i<1001;i++){
        if(hobby[i].size()!=0){
            int f1=hobby[i][0];
            for(int j=1;j<hobby[i].size();j++)
                befriends(f1,hobby[i][j]);
        }
    }
}
int main()
{
    int k,h;
    init();
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d:",&k);
        for(int j=0;j<k;j++){
            scanf("%d",&h);
            hobby[h].push_back(i);
        }
    }
    find();
    vector<int> ans;
    for(int i=1;i<=n;i++)
        if(friends[i]<0) ans.push_back(-friends[i]);
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int i=ans.size()-1;i>=0;i--){       
        printf("%d",ans[i]);
        if(i>0) printf(" ");
    }
    return 0;
}