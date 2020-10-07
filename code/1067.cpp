#include<cstdio>
int main()
{
    int n,i,s=0,k=0,tag=0,p[100000],
        hash[100000]={0};

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&p[i]);
        if(i==p[i]) s++;
    }
    if(p[0]!=0) tag=2;
    for(i=0;i<n;i++){
        if(p[i]!=i&&hash[i]==0){
            int j=i;
            while(hash[j]==0){
                hash[j]=1;
                j=p[j];
            }
            k++;
        }
    }
    printf("%d\n",n-s+k-tag);
    return 0;
}