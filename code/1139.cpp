#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#define MAX 10010
using namespace std;
bool f[MAX][MAX]={0};//存储朋友关系
vector<int> v[MAX];//存储同性朋友
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first!=b.first) return a.first<b.first;
    else return a.second<b.second;
}
int main()
{
    string f1,f2;
    int n,m,k,id1,id2;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>f1>>f2;
        sscanf(f1.c_str(),"%d",&id1);
        sscanf(f2.c_str(),"%d",&id2);
        id1=abs(id1);
        id2=abs(id2);
        if(f1.length()==f2.length()){//字符串长度相同即为同性朋友
            v[id1].push_back(id2);
            v[id2].push_back(id1);
        }
        f[id1][id2]=f[id2][id1]=true;
    }
    cin>>k;
    vector<pair<int,int> > ans;
    for(int i=0;i<k;i++){
        ans.clear();
        cin>>id1>>id2;
        id1=abs(id1);
        id2=abs(id2);
        for(int a=0;a<v[id1].size();a++){
            int f1=v[id1][a];
            if(f1==id2) continue;
            for(int b=0;b<v[id2].size();b++){
                int f2=v[id2][b];
                if(f2==id1) continue;
                if(f[f1][f2]==true)
                    ans.push_back(make_pair(f1,f2));
            }
        }
        sort(ans.begin(),ans.end(),cmp);
        printf("%d\n",ans.size());
        for(int j=0;j<ans.size();j++)
            printf("%04d %04d\n",ans[j].first,ans[j].second);
    }
    return 0;
}