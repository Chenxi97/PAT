#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
struct fraction{
    ll up,down;
};
ll gcd(ll a,ll b){
    return !b?a:gcd(b,a%b);
}
fraction reduction(fraction a){
    if(a.down<0){
        a.down=-a.down;
        a.up=-a.up;
    }
    if(a.up==0) a.down=1;
    else{
        ll d=gcd(abs(a.up),abs(a.down));
        a.down/=d;
        a.up/=d;
    }
    return a;
}
void show(fraction a){
    if(a.down==1) printf("%lld\n",a.up);
    else if(abs(a.up)>a.down)
        printf("%lld %lld/%lld\n",a.up/a.down,abs(a.up)%a.down,a.down);
    else
        printf("%lld/%lld\n",a.up,a.down);
}
fraction add(fraction a,fraction b){
    fraction ans;
    ans.up=a.up*b.down+b.up*a.down;
    ans.down=a.down*b.down;
    return reduction(ans);
}
int main()
{
    int n,i;
    fraction sum={0,1},temp;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld/%lld",&temp.up,&temp.down);
        sum=add(sum,temp);
    }
    show(sum);
    return 0;
}