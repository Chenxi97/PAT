#include<cstdio>
#include<algorithm>
#define MAXK 110
#define MAX 10010
#define INF 1<<30
using namespace std;
struct node{
    int arr,time;
}Node[MAX];
int endtime[MAXK];
int n,k,ct=0;
bool cmp(node a,node b){
    return a.arr<b.arr;
}
double que(void){
    int sum=0;
    for(int i=0;i<ct;i++){
        int MIN=INF,ans=-1;
        for(int j=0;j<k;j++){//寻找最早空闲的窗口
            if(MIN>endtime[j]){
                MIN=endtime[j];
                ans=j;
            }
        }
        if(endtime[ans]>=Node[i].arr){//在窗口空闲之前来
            sum+=endtime[ans]-Node[i].arr;
            endtime[ans]+=Node[i].time;
        }else//在窗口空闲之后来
            endtime[ans]=Node[i].arr+Node[i].time;
    }
    if(ct==0) return 0;//没有顾客返回零
    else return (double)sum/ct/60;
}
int main()
{
    int hh,mm,ss,t,time;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d:%d:%d %d",&hh,&mm,&ss,&t);
        if((time=hh*3600+mm*60+ss)>17*3600)
            continue;
        Node[ct].arr=time;
        Node[ct++].time=t>=60?3600:t*60;
    }
    sort(Node,Node+ct,cmp);
    fill(endtime,endtime+MAXK,8*3600);
    printf("%.1lf\n",que());
    return 0;
}