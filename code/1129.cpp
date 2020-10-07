#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 50010
using namespace std;
int w[MAX]={0};
vector<int> v;//存储前k个数
bool in[MAX]={0};
bool cmp(int a,int b){
    if(w[a]!=w[b]) return w[a]>w[b];
    else return a<b;
}
int main()
{
    int n,k,m;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        if(i>0){
            printf("%d:",m);
            for(int j=0;j<k&&j<v.size();j++)
                printf(" %d",v[j]);
            printf("\n");
        }
        w[m]++;//m的个数加一
        if(in[m]==false){//m不在数组中
            if(v.size()<k){
                v.push_back(m);
                in[m]=true;
                sort(v.begin(),v.end(),cmp);
            }
            else if(w[m]>w[v[k-1]]||(w[m]==w[v[k-1]]&&m<v[k-1])){
                in[v[k-1]]=false;
                v.pop_back();
                v.push_back(m);
                in[m]=true;            
            }
        }
        sort(v.begin(),v.end(),cmp);//排序
    }
    return 0;
}