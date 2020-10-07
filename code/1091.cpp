#include<cstdio>
#include<queue>
using namespace std;
struct node{
    int x,y,z;
}Node;
int a[1286][128][60],m,n,l,t;
int X[6]={0,0,0,0,-1,1};
int Y[6]={0,0,-1,1,0,0};
int Z[6]={-1,1,0,0,0,0};
int inq[1286][128][60]={0};
bool judge(int x,int y,int z){
    if(z<0||z>=l||x<0||x>=m||y<0||y>=n) return false;
    if(a[x][y][z]==0||inq[x][y][z]==1) return false;
    return true;
}
int bfs(int x,int y,int z){
    int count=0;
    queue<node> q;
    Node.x=x,Node.y=y,Node.z=z;
    q.push(Node);
    inq[x][y][z]=1;
    while(!q.empty()){
         node top=q.front();
         q.pop();
         count++;
         for(int i=0;i<6;i++){
             int newx=top.x+X[i];
             int newy=top.y+Y[i];
             int newz=top.z+Z[i];
             if(judge(newx,newy,newz)){
                 Node.x=newx,Node.y=newy,Node.z=newz;
                 q.push(Node);
                 inq[newx][newy][newz]=1;                 
             }
         }
    }
    if(count>=t) return count;
    else return 0;
}
int main()
{
    int i,j,k;
    scanf("%d%d%d%d",&m,&n,&l,&t);
    for(i=0;i<l;i++)    //ÏÈ±éÀúÇÐÆ¬²ãÊý
        for(j=0;j<m;j++)
            for(k=0;k<n;k++)
                scanf("%d",&a[j][k][i]);
    int ans=0;
    for(i=0;i<l;i++)
        for(j=0;j<m;j++)
            for(k=0;k<n;k++)
                if(a[j][k][i]==1&&inq[j][k][i]==0)
                    ans+=bfs(j,k,i);
    printf("%d\n",ans);
    return 0;
}