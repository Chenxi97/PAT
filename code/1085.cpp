#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n,i,ans=0;
    long long p,a[100000];
    
    scanf("%d%lld",&n,&p);
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    for(i=0;i<n;i++){
        int mid,left=i+ans,right=n;
        while(left<right){
            mid=(left+right)/2;
            if(a[mid]>a[i]*p)
                right=mid;
            else
                left=mid+1;
        }
        ans=max(left-i,ans);
    }
    printf("%d\n",ans);
    return 0;
}