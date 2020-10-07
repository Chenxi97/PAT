#include<cstdio>
#include<algorithm>
using namespace std;
struct station{
    double p,d;
}s[501];
bool cmp(station a,station b){
    return a.d<b.d;
}
int main()
{
    int n,i,j;
    double pri=0.0,dis=0.0,cmax,c=0.0,d,davg,dmax;

    scanf("%lf%lf%lf%d",&cmax,&d,&davg,&n);
    for(i=0;i<n;i++)
        scanf("%lf%lf",&s[i].p,&s[i].d);
    s[n].d=d;   //把目的地看作一个加油站，并把油价设为最低
    s[n].p=0;
    sort(s,s+n+1,cmp);  //将加油站按距离排序
    if(s[0].d!=0){  //没有距离为零的加油站时，退出程序
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    dmax=davg*cmax;
    for(i=0;i<n;i=j){
        if(s[i].d+dmax<s[i+1].d)    //无法到达下一个加油站时，退出循环
            break;
        int tag=0;
        for(j=i+1;s[i].d+dmax>=s[j].d;j++){ //在当前加油站的可达距离内寻找价格更低的加油站           
            if(s[i].p>=s[j].p){ //找到后将tag置为1
                tag=1;
                break;
            }
        }
        if(tag){    //将油加到正好可以到达下一个油价低的加油站
            pri+=((s[j].d-s[i].d)/davg-c)*s[i].p;
            c=0;
        }
        else{   //将油加满
            j--;
            pri+=(cmax-c)*s[i].p;
            c=cmax-(s[j].d-s[i].d)/davg;
        }
    }
    if(i==n) printf("%.2lf\n",pri); //正常退出，到达目的地
    else printf("The maximum travel distance = %.2lf\n",s[i].d+dmax);   //提前退出，输出最长距离
    return 0;
}
