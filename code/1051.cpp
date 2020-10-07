#include<cstdio>
#include<stack>
using namespace std;
int main()
{
    int n,m,k,i,j,a[1001];
    stack<int> s;
    scanf("%d%d%d",&m,&n,&k);
    for(i=0;i<k;i++){
        for(j=1;j<=n;j++)          
            scanf("%d",&a[j]);
        while(!s.empty())
            s.pop();
        bool flag=true;
        int current=1;
        for(j=1;j<=n;j++){
            s.push(j);
            if(s.size()>m){
                flag=false;
                break;
            }
            while(!s.empty()&&s.top()==a[current]){
                s.pop();
                current++;
            }
        }
        if(flag&&s.empty()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}