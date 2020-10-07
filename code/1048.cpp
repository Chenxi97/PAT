#include<cstdio>
int main()
{
    int n,m,c,i,f[501]={0};

    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&c);
        f[c]++;
    }
    for(i=1;i<501;i++){
        if(f[i]==0) continue;
        f[i]--;
        if(m-i>0&&m-i<501&&f[m-i]>0){
            printf("%d %d\n",i,m-i);
            return 0;
        }        
        f[i]++;
    }
    printf("No Solution\n");
    return 0;
}