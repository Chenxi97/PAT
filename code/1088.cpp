#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct fra{
    ll up,down;
};
ll gcd(ll a,ll b){
    return !b?a:gcd(b,a%b);
}
fra reduction(fra a){
    if(a.down<0){
        a.down=-a.down;
        a.up=-a.up;
    }
    if(a.up==0) a.down=1;
    else{
        ll d=gcd(abs(a.up),abs(a.down));
        a.up/=d;
        a.down/=d;
    }
    return a;
}
fra add(fra a,fra b){
    fra ans;
    ans.up=a.up*b.down+a.down*b.up;
    ans.down=a.down*b.down;
    return reduction(ans);
}
fra minu(fra a,fra b){
    fra ans;
    ans.up=a.up*b.down-b.up*a.down;
    ans.down=a.down*b.down;
    return reduction(ans);
}
fra multi(fra a,fra b){
    fra ans;
    ans.up=a.up*b.up;
    ans.down=a.down*b.down;
    return reduction(ans);
}
fra divid(fra a,fra b){
    fra ans;
    ans.up=a.up*b.down;
    ans.down=a.down*b.up;
    return reduction(ans);
}
void show(fra a){ 
    if(a.up>=0){
        if(a.down==1) printf("%lld",a.up);
        else if(a.up>a.down)
            printf("%lld %lld/%lld",a.up/a.down,abs(a.up)%a.down,a.down);
        else
            printf("%lld/%lld",a.up,a.down);
    }
    else{
        if(a.down==1) printf("(%lld)",a.up);
        else if(abs(a.up)>a.down)
            printf("(%lld %lld/%lld)",a.up/a.down,abs(a.up)%a.down,a.down);
        else
            printf("(%lld/%lld)",a.up,a.down);
    }
}
int main()
{
    fra a,b;

    scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);
    a=reduction(a);
    b=reduction(b);
    show(a);
    printf(" + ");
    show(b);
    printf(" = ");
    show(add(a,b));
    printf("\n");
    show(a);
    printf(" - ");
    show(b);
    printf(" = ");
    show(minu(a,b));
    printf("\n");
    show(a);
    printf(" * ");
    show(b);
    printf(" = ");
    show(multi(a,b));
    printf("\n");
    show(a);
    printf(" / ");
    show(b);
    printf(" = ");
    if(b.up==0) printf("Inf");
    else show(divid(a,b));
    printf("\n");
    return 0;
}