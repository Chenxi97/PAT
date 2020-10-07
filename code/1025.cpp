#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef struct student{
    char id[14];
    int score,lnum,lrank;
}Stu;
Stu stu[30000];
bool cmp(Stu a,Stu b){
    if(a.score!=b.score) return a.score>b.score;
    else return strcmp(a.id,b.id)<0;
}
int main()
{
    int k,n,i,j,rank,num=0;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&k);
        for(j=0;j<k;j++,num++){
            stu[num].lnum=i+1;
            scanf(" %s %d",stu[num].id,&stu[num].score);
        }
        sort(stu+num-k,stu+num,cmp);    //考场内排名
        for(j=0;j<k;j++){
            if(j==0) rank=1;
            else rank=stu[num-k+j-1].score==stu[num-k+j].score?rank:j+1;
            stu[num-k+j].lrank=rank;
        }
    }
    sort(stu,stu+num,cmp);  //总排名
    printf("%d\n",num);
    for(i=0;i<num;i++){
        if(i==0) rank=1;
        else rank=stu[i].score==stu[i-1].score?rank:i+1;
        printf("%s %d %d %d\n",stu[i].id,rank,stu[i].lnum,
            stu[i].lrank);
    }
    return 0;
}