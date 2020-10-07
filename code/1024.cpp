#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bign{
    int d[100];
    int len;
    bign(){
        memset(d,0,sizeof(d));
        len=0;
    }
};
bign add(bign a,bign b){
    bign ans;
    int up=0;
    for(int i=0;i<a.len||i<b.len;i++){
        int temp=a.d[i]+b.d[i]+up;
        ans.d[ans.len++]=temp%10;
        up=temp/10;
    }
    if(up!=0)
        ans.d[ans.len++]=up;
    return ans;
}
bool judge(bign a){
    for(int i=0;i<a.len/2;i++)
        if(a.d[i]!=a.d[a.len-1-i])
            return false;
    return true;
}
bign reve(bign a){
    reverse(a.d,a.d+a.len);
    return a;
}
int main()
{
    int i,k;
    char s[101];
    bign a;

    scanf("%s%d",s,&k);
    a.len=strlen(s);
    for(i=0;i<a.len;i++)
        a.d[i]=s[a.len-1-i]-'0';
    for(i=0;i<k&&!judge(a);i++)
        a=add(a,reve(a));
    for(int j=a.len-1;j>=0;j--)
        printf("%d",a.d[j]);
    printf("\n%d\n",i);
    return 0;
}