#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,i,max=100000001,c[100001];
    vector<int> ans;

    scanf("%d%d",&n,&m);
    c[0]=0;
    for(i=1;i<=n;i++){
        scanf("%d",&c[i]);
        c[i]+=c[i-1];
    }
    for(i=1;i<=n;i++){
        int left=i,right=n,mid;
        while(left<right){
            mid=(left+right)/2;
            if(c[mid]-c[i-1]>=m)
                right=mid;
            else
                left=mid+1;
        }
        int x=c[left]-c[i-1];
        if(x>=m){
            if(x<max){
                ans.clear();                
                max=x;
            }
            if(x==max){
                ans.push_back(i);
                ans.push_back(left);
            }
        }
    }
    for(i=0;i<ans.size();i+=2)
        printf("%d-%d\n",ans[i],ans[i+1]);
    return 0;
}