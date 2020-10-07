#include<cstdio>
#include<vector>
using namespace std;
#define MAX 100000
int main()
{
    int n,i,a[MAX],max[MAX]={0},min;
    vector<int> ans;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(i==0||(i>0&&a[i]>max[i-1])) max[i]=a[i];
        else max[i]=max[i-1];
    }
    min=a[n-1];
    for(i=n-1;i>=0;i--){
        if(a[i]<min) min=a[i];
        if(a[i]==max[i]&&a[i]==min)
            ans.push_back(a[i]);
    }
    int len=ans.size();
    printf("%d\n",len);
    for(i=len-1;i>=0;i--){
        printf("%d",ans[i]);
        if(i>0) printf(" ");
    }
    printf("\n");
    return 0;
}