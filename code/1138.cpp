#include<cstdio>
#include<map>
using namespace std;
#define MAX 50010
int n,pre[MAX],in[MAX];
map<int,int> pos;//保存中序序列中每个数的位置，减少寻找根节点的时间
void find(int preL,int preR,int inL,int inR){
    if(preL==preR){
        printf("%d\n",pre[preL]);
        return;
    }
    int k=pos[pre[preL]];//根节点在中序序列中的位置
    int lnum=k-inL;
    if(preL+1<=preL+lnum) find(preL+1,preL+lnum,inL,k-1);
    else find(preL+lnum+1,preR,k+1,inR);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&pre[i]);
    for(int i=0;i<n;i++){
        scanf("%d",&in[i]);
        pos[in[i]]=i;
    }
    find(0,n-1,0,n-1);
    return 0;
}