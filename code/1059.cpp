#include<iostream>
#include<cmath>
using namespace std;
#define MAX 100010
struct factor{
    int x,times;
}f[10];
int prime[MAX],pnum=0;
bool p[MAX]={0};
void findprime(void){
    for(int i=2;i<MAX;i++){
        if(p[i]==false){
            prime[pnum++]=i;
            for(int j=i+i;j<MAX;j+=i)
                p[j]=true;
        }
    }
}
int main()
{
    int n,num=0;
    findprime();
    cin>>n;
    if(n==1){   //1需要特别判断
        cout<<"1=1"<<endl;
        return 0;
    }
    cout<<n<<"=";
    int sqr=(int)sqrt(1.0*n);
    for(int i=0;prime[i]<=sqr;i++){
        if(n%prime[i]==0){
            f[num].x=prime[i];
            f[num].times=0;
            while(n%prime[i]==0){
                f[num].times++;
                n/=prime[i];
            }
            num++;
        }
    }
    if(n!=1){   //最多有一个大于sqrt(n)的质因子
        f[num].x=n;
        f[num++].times=1;
    }
    for(int i=0;i<num;i++){
        printf("%d",f[i].x);
        if(f[i].times>1) printf("^%d",f[i].times);
        if(i<num-1) printf("*");
    }
    printf("\n");
    return 0;
}