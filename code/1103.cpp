#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int n,k,p,maxsum=0;
vector<int> vt,ans,temp;
void DFS(int num,int nowk,int nown,int sum){
    if(nowk==k&&nown==n){   //符合条件
        if(sum>maxsum){ //由于是从最大的数开始递归，只要符合因数和最大就可以
            maxsum=sum;
            ans=temp;
        }
        return;
    }
    if(num==0||nowk>k||nown>n) return; 
    temp.push_back(num);    //选择num
    DFS(num,nowk+1,nown+vt[num],sum+num);
    temp.pop_back();
    DFS(num-1,nowk,nown,sum);   //不选num
}
int main()
{
    int i;
    scanf("%d%d%d",&n,&k,&p);
    for(i=0;i<k;i++)
        ans.push_back(0);
    int max=(int)pow(n,1.0/p)+1;
    for(i=0;i<=max;i++) //vt记录1~max的p次方
        vt.push_back((int)pow(1.0*i,p));
    DFS(max,0,0,0); //深度优先搜索
    if(ans[0]==0) printf("Impossible");
    else{
        printf("%d = %d^%d",n);
        for(i=1;i<k;i++)
            printf(" + %d^%d",ans[i],p);
    }
    printf("\n");
    return 0;
}