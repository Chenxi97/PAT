#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 50010
using namespace std;
int w[MAX]={0};
vector<int> v;//�洢ǰk����
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
        w[m]++;//m�ĸ�����һ
        if(in[m]==false){//m����������
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
        sort(v.begin(),v.end(),cmp);//����
    }
    return 0;
}