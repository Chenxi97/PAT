#include<cstdio>
#include<queue>
#include<algorithm>
#define MAX 1010
#define INF 1<<30
using namespace std;
struct node{
    int time,lea;
}custom[MAX];
int n,m,k,q;
queue<node> que[20];
int endtime[20];//队列最后一个人的离开时间
int tom(int h,int m){
    return h*60+m;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for(int i=1;i<=k;i++)
        scanf("%d",&custom[i].time);
    int begin=tom(8,0),end=tom(17,0),count=1;
    fill(endtime,endtime+n,begin);//初始时间设为8点
    for(int i=begin;i<=end;i++){//按时间循环
        for(int j=0;j<n;j++)//队首出队
            if(!que[j].empty()&&que[j].front().lea==i)
                que[j].pop();        
        while(count<=k){//有位置则入队
            int MIN=INF,ans=-1;
            for(int j=0;j<n;j++){
                if(MIN>que[j].size()&&que[j].size()<m){
                    MIN=que[j].size();
                    ans=j;
                }
            }
            if(ans==-1) break;
            if(endtime[ans]>=end) custom[count].lea=INF;//如果前边的人出队时间超过17:00就设为INF
            else custom[count].lea=endtime[ans]+custom[count].time;
            endtime[ans]=custom[count].lea;
            que[ans].push(custom[count++]);
        }
    }
    for(int i=count;i<=k;i++)
        custom[i].lea=INF;
    int index;
    for(int i=0;i<q;i++){
        scanf("%d",&index);
        int time=custom[index].lea;
        if(time==INF) printf("Sorry\n");
        else printf("%02d:%02d\n",time/60,time%60);
    }
    return 0;
}