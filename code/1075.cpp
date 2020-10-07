#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef struct user{
    int id,tag,pnum,total,s[6];
}User;
User u[10001],u2[10001];
bool cmp(User a,User b){
    if(a.total!=b.total) return a.total>b.total;
    else if(a.pnum!=b.pnum) return a.pnum>b.pnum;
    else return a.id<b.id;
}
int main()
{
    int n,k,m,i,j,id,num,s,rank,p[6];

    scanf("%d%d%d",&n,&k,&m);
    for(i=1;i<=n;i++){
        u[i].tag=u[i].pnum=u[i].total=0;  
        memset(u[i].s,-1,sizeof(int)*6);
    }
    for(i=1;i<=k;i++)
        scanf("%d",&p[i]);
    for(i=0;i<m;i++){
        scanf("%d%d%d",&id,&num,&s);
        if(s==-1&&u[id].s[num]==-1){    //未通过编译器且最高分数为-1的置为0
            u[id].s[num]=0;
            continue;
        }
        u[id].tag=1;    //tag为1时表示有成绩
        u[id].id=id;
        if(s>u[id].s[num]){
            u[id].s[num]=s;
            
        }
    }
    int number=0;
    for(i=1;i<=n;i++){  //未通过编译器且最高分数为-1时将分数置为0
        if(u[i].tag){
            for(j=1;j<=k;j++){
                if(u[i].s[j]!=-1)
                    u[i].total+=u[i].s[j];
                if(s==p[num]) 
                    u[id].pnum++;
            }
            u2[number++]=u[i];
        }
    }
    sort(u2,u2+number,cmp);
    for(i=0;i<number;i++){
        if(i==0) rank=1;    //计算排名
        else rank=u2[i].total==u2[i-1].total?rank:i+1;
        printf("%d %05d %d",rank,u2[i].id,u2[i].total);
        for(j=1;j<=k;j++){  //输出分成绩
            if(u2[i].s[j]==-1)
                printf(" -");
            else
                printf(" %d",u2[i].s[j]);
        }
        printf("\n");
    }
    return 0;
}