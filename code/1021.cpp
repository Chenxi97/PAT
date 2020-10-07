#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#define MAX 10010
using namespace std;
int n,maxl=0;
set<int> ans;
vector<int> v[MAX];
bool travel[MAX]={0};
void dfs(int ver,int layer){
    travel[ver]=true;
    if(layer>maxl){
        maxl=layer;
        ans.clear();
        ans.insert(ver);
    }
    else if(layer==maxl)
        ans.insert(ver);
    for(int i=0;i<v[ver].size();i++){
        int verti=v[ver][i];
        if(travel[verti]==false)
            dfs(verti,layer+1);
    }
}
int main()
{
    int v1,v2;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&v1,&v2);
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    dfs(1,1);//�ӽڵ�1��ʼ����
    int num=1;
    for(int j=1;j<=n;j++){
        if(travel[j]==false){
            dfs(j,1);
            num++;
        }
    }
    if(num>1){//����1����ͨ��
        printf("Error: %d components\n",num);
        return 0;
    }
    memset(travel,false,sizeof(travel));//����travel����
    set<int> temp=ans;//������һ���Ľ��
    dfs(*ans.begin(),1);//�ڽ������ѡһ���ڵ����
    for(set<int>::iterator i=temp.begin();i!=temp.end();i++)
        ans.insert(*i);//�ϲ����
    for(set<int>::iterator i=ans.begin();i!=ans.end();i++)
        printf("%d\n",*i);
    return 0;
}