#include<cstdio>
#define MAX 10010
bool prime[MAX]={0},ha[MAX]={0};
int size;
int findprime(int n){
    for(int i=2;i<MAX;i++)
        if(prime[i]==false){
            if(i>=n) return i;
            for(int j=i*2;j<MAX;j+=i)
                prime[j]=true;
        }
}
int hash(int n){
    int i=1,key=n%size;
    while(ha[key]==true){
        key=(n%size+i*i)%size;
        i++;
        if(i>size) return -1;
    }
    ha[key]=true;
    return key;
}
int main()
{
    int n,m,i,num;

    scanf("%d%d",&m,&n);
    size=findprime(m);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        int key=hash(num);
        if(key==-1) printf("-");
        else printf("%d",key);
        if(i<n-1) printf(" ");
    }
    printf("\n");
    return 0;
}