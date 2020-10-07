#include<iostream>
#include<algorithm>
#define MAX 10010
using namespace std;
int main()
{
    int n;
    double a[MAX];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    double sum=a[0];//开始设为第一段的长度
    for(int i=1;i<n;i++)
        sum=(sum+a[i])/2;
    int ans=sum;
    cout<<ans<<endl;
    return 0;
}