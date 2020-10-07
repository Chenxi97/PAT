#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int i,n,a[100000];

    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int sum1=0,sum2=0,j;
    for(i=0;i<n/2;i++)
        sum1+=a[i];
    for(j=i;j<n;j++)
        sum2+=a[j];
    printf("%d %d\n",n%2,sum2-sum1);
    return 0;
}