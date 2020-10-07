#include<cstdio>
#include<set>
#include<algorithm>
#define MAX 50010
using namespace std;
struct node{
    int num,data;
    node(int _num,int _data):num(_num),data(_data){}
};
int w[MAX]={0};
struct cmp{
    bool operator ()(const node &a,const node &b){
        if(a.num!=b.num) return a.num>b.num;
        else return a.data<b.data;
    }
};
set<node,cmp> s;
int main()
{
    int n,k,m;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        if(i>0){
            printf("%d:",m);
            int ct=0;
            for(auto it=s.begin();it!=s.end()&&ct<k;it++,ct++)
                printf(" %d",it->data);
            printf("\n");
        }       
        auto pos=s.find(node(w[m],m));
        if(pos!=s.end()) s.erase(pos);
        w[m]++;//m的个数加一
        s.insert(node(w[m],m));       
    }
    return 0;
}