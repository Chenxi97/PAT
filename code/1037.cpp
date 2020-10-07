#include<cstdio>
#include<algorithm>
using namespace std;
int c[100000],p[100000];
int main()
{
    int nc,np,i,sum=0;

    scanf("%d",&nc);
    for(i=0;i<nc;i++)
        scanf("%d",&c[i]);
    scanf("%d",&np);
    for(i=0;i<np;i++)
        scanf("%d",&p[i]);
    sort(c,c+nc);
    sort(p,p+np);
    for(i=0;i<nc&&i<np&&c[i]<0&&p[i]<0;i++)
        sum+=c[i]*p[i];
    for(i=1;i<=nc&&i<=np&&c[nc-i]>0&&p[np-i]>0;i++)
        sum+=c[nc-i]*p[np-i];
    printf("%d\n",sum);
    return 0;
}