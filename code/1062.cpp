#include<cstdio>
#include<algorithm>
using namespace std;
typedef struct person{
    int stage,id,virtue,talent,total;
}Person;
Person p[100000];
bool cmp(Person a,Person b){
    if(a.stage!=b.stage) return a.stage<b.stage;
    else if(a.total!=b.total) return a.total>b.total;
    else if(a.virtue!=b.virtue) return a.virtue>b.virtue;
    else return a.id<b.id;
}
int main()
{
    int n,v,t,l,h,id,m=0,i;

    scanf("%d%d%d",&n,&l,&h);
    for(i=0;i<n;i++){
        scanf("%d%d%d",&p[m].id,&v,&t);
        if(v<l&&t<l) continue;
        p[m].total=v+t;
        if(v>=h&&t>=h) p[m].stage=1;
        else if(v>=h) p[m].stage=2;
        else if(v>=t) p[m].stage=3;
        else p[m].stage=4;
        p[m].virtue=v;
        p[m].talent=t;
        m++;
    }
    sort(p,p+m,cmp);
    printf("%d\n",m);
    for(i=0;i<m;i++)
        printf("%d %d %d\n",p[i].id,p[i].virtue,p[i].talent);
    return 0;
}