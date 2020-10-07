#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Rd{
    char name[21];
    int date[3],time,tag;
}rd[1000];
bool cmp(Rd a,Rd b){
    if(strcmp(a.name,b.name)) return strcmp(a.name,b.name)<0;
    else return a.time<b.time;
}
double fee(const int a[3],int *rate){   //从00:00:00开始计算花费
    double ans=a[0]*rate[24]*60+a[2]*rate[a[1]];
    for(int i=0;i<a[1];i++)
        ans+=rate[i]*60;
    return ans/100;
}
int main()
{
    int rate[25],n,i,mo;
    double sum=0.0,amount;
    char name[21]="",status[10];

    rate[24]=0;
    for(i=0;i<24;i++){
        scanf("%d",&rate[i]);
        rate[24]+=rate[i];
    }
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %s %d:%d:%d:%d %s",rd[i].name,
            &mo,&rd[i].date[0],&rd[i].date[1],&rd[i].date[2],status);
        rd[i].tag=strcmp("on-line",status)?0:1;
        rd[i].time=rd[i].date[0]*24*60+rd[i].date[1]*60+rd[i].date[2];  //从00:00:00开始的分钟数
    }
    sort(rd,rd+n,cmp);
    for(i=1;i<n;i++){
        if(!strcmp(rd[i].name,rd[i-1].name)&&!rd[i].tag&&rd[i-1].tag){
            if(strcmp(name,rd[i].name)){
                if(sum!=0.0) printf("Total amount: $%.2lf\n",sum);
                strcpy(name,rd[i].name);
                printf("%s %02d\n",name,mo);
                
                sum=0.0;
            }
            printf("%02d:%02d:%02d %02d:%02d:%02d ",rd[i-1].date[0],rd[i-1].date[1],
                rd[i-1].date[2],rd[i].date[0],rd[i].date[1],rd[i].date[2]);
            amount=fee(rd[i].date,rate)-fee(rd[i-1].date,rate);            
            printf("%d $%.2f\n",rd[i].time-rd[i-1].time,amount);
            sum+=amount; 
        }
    }
    if(sum!=0.0) printf("Total amount: $%.2lf\n",sum); 
    return 0;
}