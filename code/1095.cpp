#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
struct record{
    char pnum[8];
    int time,sta;
}r[10000];
vector<record> p;
bool cmp1(record a,record b){
    if(strcmp(a.pnum,b.pnum)!=0) return strcmp(a.pnum,b.pnum)<0;
    else return a.time<b.time;
}
bool cmp2(record a,record b){
    return a.time<b.time;
}
int main()
{
    int n,k,i,j,hh,mm,ss,maxtime=0;
    char status[4];

    scanf("%d%d",&n,&k);    //读取数据
    for(i=0;i<n;i++){
        scanf(" %s %d:%d:%d %s",r[i].pnum,&hh,&mm,&ss,status);
        r[i].time=hh*3600+mm*60+ss;
        r[i].sta=strcmp(status,"in")==0?1:-1; 
    }
    sort(r,r+n,cmp1);   //排序
    map<string,int> mp;
    for(i=1;i<n;i++){   //将成对的进出记录保存到另一个数组中
        if(strcmp(r[i].pnum,r[i-1].pnum)==0&&
            r[i].sta==-1&&r[i-1].sta==1){
            p.push_back(r[i-1]);
            p.push_back(r[i]);
            mp[r[i].pnum]+=r[i].time-r[i-1].time; //map中int初始化值为0
            if(maxtime<mp[r[i].pnum])   //最长停车时间
                maxtime=mp[r[i].pnum];
        }
    }
    sort(p.begin(),p.end(),cmp2);   //按时间排序
    int time,m=p.size(),num,lastnum=0,lastj=0;
    for(i=0;i<k;i++){
        scanf("%d:%d:%d",&hh,&mm,&ss);
        time=hh*3600+mm*60+ss;
        for(j=lastj,num=lastnum;j<m;j++){
            if(time<p[j].time) break;
            num+=p[j].sta;
        }
        lastj=j;    //由于查询条目是按时间顺序的，保存之前的记录可以节省查询时间
        lastnum=num;
        printf("%d\n",num);
    }
    for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++)  //输出车牌号
        if(it->second==maxtime)
            printf("%s ",it->first.c_str());
    printf("%02d:%02d:%02d\n",maxtime/3600,(maxtime%3600)/60,maxtime%60);
    return 0;
}