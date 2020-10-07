#include<cstdio>
#include<algorithm>
#define MAX 10010
#define TAB 110
#define INF 1<<30
using namespace std;
struct node{
    int arr,time,tag,ser;
}cus[MAX];
int n,k,m;
int endtime[TAB],sernum[TAB];
bool vtable[TAB]={0},in[MAX]={0};
int tos(int h,int m,int s){
    return h*3600+m*60+s;
}
void tohour(int s){
    printf("%02d:%02d:%02d ",s/3600,s%3600/60,s%60);
}
int findvip(int c,int t){//寻找队列中的vip顾客
    for(int i=c;i<n;i++)
        if(cus[i].tag==1&&cus[i].arr<=t&&in[i]==false)
            return i;
    return c;
}
bool cmp(node a,node b){
    return a.arr<b.arr;
}
bool cmp1(node a,node b){
    return a.ser<b.ser;
}
int main()
{
    int hh,mm,ss,tnum;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d:%d:%d%d%d",&hh,&mm,&ss,&cus[i].time,&cus[i].tag);
        cus[i].arr=tos(hh,mm,ss);
        if(cus[i].time>120) cus[i].time=120;
        cus[i].time*=60;
    }
    scanf("%d%d",&k,&m);
    for(int i=0;i<m;i++){
        scanf("%d",&tnum);
        vtable[tnum]=true;
    }
    sort(cus,cus+n,cmp);//按到达时间排序
    int begin=tos(8,0,0),end=tos(21,0,0);
    fill(endtime,endtime+TAB,begin);
    fill(sernum,sernum+TAB,0);
    for(int c=0;c<n;c++){
        if(in[c]) continue;
        int MIN=INF,ans=-1;
        if(cus[c].tag==1){//如果顾客是vip，那么要寻找结束时间最小的桌子，且vip桌子优先
            for(int i=1;i<=k;i++){
                if(MIN>endtime[i]){
                    MIN=endtime[i];
                    ans=i;
                }
                //寻找时间最早的第一个vip桌子
                else if(MIN==endtime[i]&&vtable[ans]==false&&vtable[i]==true)
                    ans=i;
            }
        }
        if(cus[c].tag==0){//普通顾客，寻找结束时间最早的球桌
            for(int i=1;i<=k;i++){
                if(MIN>endtime[i]){
                    MIN=endtime[i];
                    ans=i;
                }
            }
        }
        int now=c;
        if(vtable[ans]==true) now=findvip(c,MIN);
        if(now!=c) c--;
        if(cus[now].arr>MIN)
            cus[now].ser=cus[now].arr;
        else
            cus[now].ser=MIN;
        endtime[ans]=cus[now].ser+cus[now].time;
        if(cus[now].ser<end) sernum[ans]++;
        in[now]=true;
    }
    sort(cus,cus+n,cmp1);//按服务时间排序
    for(int i=0;i<n;i++){
        if(cus[i].ser<end){
            tohour(cus[i].arr);
            tohour(cus[i].ser);
            int time=double(cus[i].ser-cus[i].arr)/60.0+0.5;
            printf("%d\n",time);
        }
    }
    for(int i=1;i<=k;i++){
        if(i>1) printf(" ");
        printf("%d",sernum[i]);
    }
    return 0;
}