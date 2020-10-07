#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define MAX 26*26*26+1
struct node{
    int v,w;
    node(int _v,int _w):v(_v),w(_w){}
};
vector<node> v[MAX];
int n,k,totaltime=0,maxt=-1,head,num=0;
bool t[MAX]={0};
char maps[MAX][4];
int weight[MAX]={0};
int stoi(char *s){//�ַ�����ϣ
    int sum=0;
    for(int i=0;i<3;i++)
        sum=sum*26+s[i]-'A';
    strcpy(maps[sum],s);
    return sum;
}
void dfs(int ver){
    t[ver]=true;
    num++;
    if(weight[ver]>maxt){//�ҵ�Ȩ�����Ľڵ�
        maxt=weight[ver];
        head=ver;
    }
    for(int i=0;i<v[ver].size();i++){
        totaltime+=v[ver][i].w;//���ۼӱ�Ȩ��dfs
        if(t[v[ver][i].v]==false)            
            dfs(v[ver][i].v);
    }
}
int main()
{
    char a[4],b[4];
    int time;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf(" %s %s%d",a,b,&time);
        int p1=stoi(a),p2=stoi(b);
        weight[p1]+=time;
        weight[p2]+=time;
        v[p1].push_back(node(p2,time));//�����
        v[p2].push_back(node(p1,0));//������Ϊ0��ֹ�ظ�����
    }
    int ans[MAX]={0},count=0;
    for(int i=0;i<MAX;i++){
        if(v[i].size()==0||t[i]==true) continue;
        totaltime=0;
        maxt=-1;
        num=0;
        dfs(i);
        if(totaltime>k&&num>2){
            count++;
            ans[head]=num;
        }
    }
    printf("%d\n",count);
    for(int i=0;i<MAX;i++)
        if(ans[i]!=0)//Ҫ���ֵ������
            printf("%s %d\n",maps[i],ans[i]);
    return 0;
}