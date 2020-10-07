#include<cstdio>
#include<queue>
using namespace std;
int main()
{
    int np,ng,i,temp,w[1000],rank[1000];
    queue<int> q;
    scanf("%d%d",&np,&ng);
    for(i=0;i<np;i++)
        scanf("%d",&w[i]);
    for(i=0;i<np;i++){
        scanf("%d",&temp);
        q.push(temp);
    }
    while(q.size()>1){
        int size=q.size(),num;
        if(size%ng>0) num=size/ng+1;//分组数
        else num=size/ng;
        for(int j=0;j<num;j++){
            int count=ng,max=q.front();
            if(size%ng>0&&j==num-1) count=size%ng;
            while(count--){ //选出每组中的最大值
                int temp=q.front();
                rank[temp]=num+1;
                q.pop();
                if(w[temp]>w[max]) max=temp;
            }
            q.push(max);
        }
    }
    rank[q.front()]=1;
    for(i=0;i<np;i++){
        printf("%d",rank[i]);
        if(i<np-1) printf(" ");
    }
    return 0;
}