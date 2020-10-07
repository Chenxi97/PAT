#include<cstdio>
#include<algorithm>
#define MAX 1010
using namespace std;
int main()
{
    int m,n,q[MAX];
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&n);
        int flag=1;
        for(int j=0;j<n;j++)
            scanf("%d",&q[j]);
        for(int a=0;a<n;a++)//两两枚举
            for(int b=a+1;b<n;b++)
                //在同一行或者对角线上就置flag为0
                if(b-a==abs(q[a]-q[b])||q[a]==q[b]){
                    flag=0;
                    break;
                }
        printf(flag?"YES\n":"NO\n");
    }
    return 0;
}