#include<cstdio>
#include<algorithm>
#define MAX 10010
using namespace std;
int father[MAX];
int findfather(int n){
    if(father[n]==-1) return n;
    else{
        int f=findfather(father[n]);
        father[n]=f;
        return f;
    }
}
void uni(int a,int b){
    int fa=findfather(a);
    int fb=findfather(b);
    if(fa!=fb)
        father[fa]=fb;
}
int main()
{
    int n,k,i,b1,b2,q,maxb=0;
    fill(father,father+MAX,-1);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&k,&b1);
        maxb=max(b1,maxb);
        for(int j=0;j<k-1;j++){
            scanf("%d",&b2);
            maxb=max(b2,maxb);
            uni(b1,b2);
        }
    }
    int ct=0;
    for(i=1;i<=maxb;i++){
        if(father[i]==-1)
            ct++;
    }
    printf("%d %d\n",ct,maxb);
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d%d",&b1,&b2);
        int fa=findfather(b1);
        int fb=findfather(b2);
        printf(fa==fb?"Yes\n":"No\n");
    }
    return 0;
}