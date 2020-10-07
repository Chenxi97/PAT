#include<cstdio>
#include<cstring>
struct bign{
    int n[22],len;
    bign(){
        memset(n,0,sizeof(n));
        len=0;
    }
};
bign multi(bign a,int b){
    int up=0;
    bign ans;
    for(int i=0;i<a.len;i++){
        int temp=a.n[i]*b+up;
        ans.n[i]=temp%10;
        up=temp/10;
    }
    ans.len=a.len;
    while(up!=0){
        ans.n[ans.len++]=up%10;
        up/=10;
    }
    return ans;
}
int main()
{
    int i;
    bign a;
    char s[23];
    int count[10]={0};

    scanf("%s",s);
    int len=strlen(s);
    for(i=0;i<len;i++){
        a.n[i]=s[len-1-i]-'0';
        count[a.n[i]]++;
        a.len++;
    }
    bign ans=multi(a,2);
    for(i=0;i<ans.len;i++){
        if(count[ans.n[i]]==0)
            break;
        count[ans.n[i]]--;
    }
    if(i==ans.len) printf("Yes\n");
    else printf("No\n");
    for(i=ans.len-1;i>=0;i--)
        printf("%d",ans.n[i]);
    printf("\n");
    return 0;
}