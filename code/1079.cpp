#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct node{
    int p,layer;
    vector<int> child;
}Node[100000];
int n;
double ans=0.0,p,r,sales[100000];
void layer(int root){
    queue<int> q;
    Node[root].layer=0;
    q.push(root);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        if(Node[now].child.size()==0)   //叶子结点，计算费用
            ans+=Node[now].p*sales[Node[now].layer];
        for(int i=0;i<Node[now].child.size();i++){
            int child=Node[now].child[i];
            Node[child].layer=Node[now].layer+1;
            q.push(child);
        }
    }
}
int main()
{
    int i,num,temp;
    scanf("%d%lf%lf",&n,&p,&r);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        if(num==0){
            scanf("%d",&temp);
            Node[i].p=temp;
        }else{
            for(int j=0;j<num;j++){
                scanf("%d",&temp);
                Node[i].child.push_back(temp);
            }
        }
    }
    sales[0]=p; //费用
    for(i=1;i<n;i++)
        sales[i]=sales[i-1]*(1.0+r/100);
    layer(0);
    printf("%.1lf\n",ans);
    return 0;
}