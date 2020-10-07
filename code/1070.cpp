#include<cstdio>
#include<algorithm>
using namespace std;
struct cake{
    double t,total,p;
}c[1000];
bool cmp(cake a,cake b){
    return a.p>b.p;
}
int main()
{
    int n,i;
    double pro=0.0,d,s=0.0;

    scanf("%d%lf",&n,&d);
    for(i=0;i<n;i++)
        scanf("%lf",&c[i].t);
    for(i=0;i<n;i++){
        scanf("%lf",&c[i].total);
        c[i].p=c[i].total/c[i].t;
    }
    sort(c,c+n,cmp);
    for(i=0;i<n;i++){
        if(d-s>=c[i].t){
            s+=c[i].t;
            pro+=c[i].total;
        }
        else{
            pro+=(d-s)*c[i].p;
            break;
        }
    }
    printf("%.2lf\n",pro);
    return 0;
}