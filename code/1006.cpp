#include<cstdio>
#include<cstring>
int main()
{
    int et=235959,lt=0;
    int n,i,h,m,s,time;
    char ep[16],lp[16],p[16];

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s %d:%d:%d",p,&h,&m,&s);
        time=h*10000+m*100+s;
        if(time<et){
            et=time;
            strcpy(ep,p);
        }
        scanf(" %d:%d:%d",&h,&m,&s);
        time=h*10000+m*100+s;
        if(time>lt){
            lt=time;
            strcpy(lp,p);
        }
    }
    printf("%s %s\n",ep,lp);
    return 0;
}