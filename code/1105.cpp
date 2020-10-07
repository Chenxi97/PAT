#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAX 10010
int m[MAX][MAX],a[MAX],col,row,ct=0;
bool flag[MAX][MAX]={0};
int rl[4]={0,0,-1,1};//����
int ud[4]={1,-1,0,0};//����
bool cmp(int a,int b){
    return a>b;
}
int direct(int c,int r,int before){
    int newr=r+rl[before],newc=c+ud[before];//������
    if(newr<row&&newr>=0&&newc<col&&newc>=0&&flag[newr][newc]==false)//���յ�ǰ�����Ƿ����
        return before;
    for(int i=0;i<4;i++){//�ı䷽��
        newr=r+rl[i],newc=c+ud[i];
        if(newr<row&&newr>=0&&newc<col&&newc>=0&&flag[newr][newc]==false)
            return i;
    }
    return -1;//�ĸ����򶼲�����˵�������յ�
}
void sp(int c,int r,int n){
    m[r][c]=a[ct++];
    flag[r][c]=true;
    int d=direct(c,r,n);
    if(d==-1) return;
    else sp(c+ud[d],r+rl[d],d);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    col=pow(n,0.5);
    while(col!=0&&n%col!=0)
        col--;
    row=n/col;
    sort(a,a+n,cmp);
    sp(0,0,2);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d",m[i][j]);
            if(j<col-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}