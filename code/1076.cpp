#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n,l,k,layer[1010]={0};
vector<int> v[1010];
bool t[1010]={0};
int bfs(int id){
    queue<int> q;
    int num=0;
    q.push(id);
    t[id]=true;//��Ӻ���Ϊtrue
    while(!q.empty()){
        int now=q.front();
        q.pop();
        num++;       
        if(layer[now]<l){//��ǰ����������lʱ����һ��������
            for(int i=0;i<v[now].size();i++)
                if(t[v[now][i]]==false){
                    t[v[now][i]]=true;
                    layer[v[now][i]]=layer[now]+1;
                    q.push(v[now][i]);
                }
        }
    }
    return num;
}
int main()
{
    int m,id;
    scanf("%d%d",&n,&l);
    for(int i=1;i<=n;i++){        
        scanf("%d",&m);
        for(int j=0;j<m;j++){
            scanf("%d",&id);
            v[id].push_back(i);
        }
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d",&id);
        memset(layer,0,sizeof(layer));//���ò�������
        memset(t,false,sizeof(t));
        int num=0;        
        printf("%d\n",bfs(id)-1);
    }
    return 0;
}