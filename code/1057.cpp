#include<cstdio>
#include<cmath>
#include<stack>
#define BMAX 317
#define BNUM 316
#define MAX 100010
using namespace std;
int b[BMAX]={0},a[MAX]={0};
stack<int> s;
void findmedien(void){
    int k=(s.size()+1)/2,sum=0,i,j;
    for(i=0;i<=BMAX;i++){       
        if(sum+b[i]>=k) break;
        sum+=b[i];
    }
    for(j=i*BNUM;j<MAX;j++){
        sum+=a[j];
        if(sum>=k) break;
    }
    printf("%d\n",j);
}
int main()
{
    int n,i,num;
    char cmd[12];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %s",cmd);
        if(cmd[1]=='u'){
            scanf("%d",&num);
            s.push(num);
            b[num/BNUM]++;
            a[num]++;
        }else{
            if(s.empty())
                printf("Invalid\n");
            else if(cmd[1]=='o'){
                num=s.top();
                printf("%d\n",num);
                s.pop();
                b[num/BNUM]--;
                a[num]--;
            }else{
                findmedien();
            }
        }
    }
    return 0;
}