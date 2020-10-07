#include<cstdio>
#include<algorithm>
using namespace std;
struct station{
    double p,d;
}s[501];
bool cmp(station a,station b){
    return a.d<b.d;
}
int main()
{
    int n,i,j;
    double pri=0.0,dis=0.0,cmax,c=0.0,d,davg,dmax;

    scanf("%lf%lf%lf%d",&cmax,&d,&davg,&n);
    for(i=0;i<n;i++)
        scanf("%lf%lf",&s[i].p,&s[i].d);
    s[n].d=d;   //��Ŀ�ĵؿ���һ������վ�������ͼ���Ϊ���
    s[n].p=0;
    sort(s,s+n+1,cmp);  //������վ����������
    if(s[0].d!=0){  //û�о���Ϊ��ļ���վʱ���˳�����
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    dmax=davg*cmax;
    for(i=0;i<n;i=j){
        if(s[i].d+dmax<s[i+1].d)    //�޷�������һ������վʱ���˳�ѭ��
            break;
        int tag=0;
        for(j=i+1;s[i].d+dmax>=s[j].d;j++){ //�ڵ�ǰ����վ�Ŀɴ������Ѱ�Ҽ۸���͵ļ���վ           
            if(s[i].p>=s[j].p){ //�ҵ���tag��Ϊ1
                tag=1;
                break;
            }
        }
        if(tag){    //���ͼӵ����ÿ��Ե�����һ���ͼ۵͵ļ���վ
            pri+=((s[j].d-s[i].d)/davg-c)*s[i].p;
            c=0;
        }
        else{   //���ͼ���
            j--;
            pri+=(cmax-c)*s[i].p;
            c=cmax-(s[j].d-s[i].d)/davg;
        }
    }
    if(i==n) printf("%.2lf\n",pri); //�����˳�������Ŀ�ĵ�
    else printf("The maximum travel distance = %.2lf\n",s[i].d+dmax);   //��ǰ�˳�����������
    return 0;
}
