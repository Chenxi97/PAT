#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct person{
    char name[10];
    int height;
}p[10010];
bool cmp(person a,person b){
    if(a.height!=b.height) return a.height>b.height;
    else return strcmp(a.name,b.name)<0;
}
void format(int begin,int n){
    int maxodd=n%2==0?n-1:n-2;  //�������ֵ
    for(int i=maxodd;i>0;i-=2)  //���������λ
        printf("%s ",p[begin+i].name);
    for(int i=0;i<n;i+=2){  //�����ż��λ
        if(i>0) printf(" ");
        printf("%s",p[begin+i].name);
    }
    printf("\n");
}
int main()
{
    int n,k,i;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf(" %s%d",p[i].name,&p[i].height);
    sort(p,p+n,cmp);
    int m=n/k,lm=n%k+m;
    format(0,lm);   //������һ��
    for(i=lm;i<n;i+=m)  //���ʣ����
        format(i,m);
    return 0;
}