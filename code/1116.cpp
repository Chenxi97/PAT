#include<cstdio>
#define MAX 10010
bool p[MAX]={0};
void findprime(void){
    for(int i=2;i<MAX;i++){
        if(p[i]==false){
            for(int j=i+i;j<MAX;j+=i)
                p[j]=true;
        }
    }
}
int main()
{
    int n,k,i,id,rank[MAX]={0},check[MAX]={0};
    findprime();    //È·ÊµÈÝÒ×Íü
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&id);
        rank[id]=i+1;
    }
    scanf("%d",&k);
    for(i=0;i<k;i++){
        scanf("%d",&id);
        if(rank[id]==0)
            printf("%04d: Are you kidding?\n",id);
        else if(check[id]==0){
            if(rank[id]==1)
                printf("%04d: Mystery Award\n",id);
            else if(!p[rank[id]])
                printf("%04d: Minion\n",id,rank[id]);
            else 
                printf("%04d: Chocolate\n",id);
            check[id]=1;
        }
        else
            printf("%04d: Checked\n",id);      
    }
    return 0;
}