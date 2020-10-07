#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll radix(ll *a,ll rad,ll len){
    ll ans=0;
    for(int i=0;i<len;i++)
        ans=a[i]+ans*rad;
    return ans;
}
ll binary(ll *a,ll left,ll right,ll len,ll x){
    ll mid,ans;
    while(left<=right){
        mid=(left+right)/2;
        ans=radix(a,mid,len);
        if(ans==x) return mid;
        else if(ans>x||ans<0)   //计算结果有可能溢出
            right=mid-1;
        else
            left=mid+1;
    }
    return 0;
}
int main()
{
    ll tag,len,a[10],b[10],n1,low=0,rad;
    char s1[11],s2[11];

    scanf("%s %s %lld%lld",s1,s2,&tag,&rad);
    if(tag==2) swap(s1,s2);
    for(int i=0;i<strlen(s1);i++){  //将每位对应的十进制数保存在数组中
        if(s1[i]<='9') b[i]=s1[i]-'0';
        else b[i]=s1[i]-'a'+10;
    }
    n1=radix(b,rad,strlen(s1));
    len=strlen(s2);
    for(int i=0;i<len;i++){
        if(s2[i]<='9') a[i]=s2[i]-'0';
        else a[i]=s2[i]-'a'+10;
        low=low>a[i]?low:a[i];
    }
    ll ans=binary(a,low+1,n1+1,len,n1);
    if(ans) printf("%lld\n",ans);
    else printf("Impossible\n");
    return 0;
}