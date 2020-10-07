#include<cstdio>
#include<algorithm>
using namespace std;
int a[100000];
int cmp(int a,int b){
    return a>b;
}
int main()
{
    int n,i;

    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n,cmp);
    for(i=0;i<n;i++)
        if(a[i]<=i+1) break;
    printf("%d\n",i);
    return 0;
}