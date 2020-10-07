#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct student{
    int id,ge,total,admit,rank,p[5];
}Stu;
typedef struct school{
    int qt,rank;
    vector<int> ad;
}Sch;
Sch c[100];
Stu s[40000];
bool cmp1(Stu a,Stu b){
    if(a.total!=b.total) return a.total>b.total;
    else return a.ge>b.ge;
}
int main()
{
    int n,m,k,i,j;

    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++){   //ѧУ�ṹ�帳ֵ
        c[i].rank=0;
        scanf("%d",&c[i].qt);
    }
    for(i=0;i<n;i++){   //ѧ���ṹ�帳ֵ
        scanf("%d%d",&s[i].ge,&s[i].total);
        for(j=0;j<k;j++)
            scanf("%d",&s[i].p[j]);
        s[i].id=i;
        s[i].admit=-1;
        s[i].total+=s[i].ge;
    }
    sort(s,s+n,cmp1);   //���򲢼�¼����
    s[0].rank=1;
    for(i=1;i<n;i++){
        if (s[i].total==s[i-1].total&&s[i].ge==s[i-1].ge)
            s[i].rank=s[i-1].rank;
        else s[i].rank=i+1;
    }
    for(j=0;j<n;j++){   //��������һ��ѧ����ʼ¼ȡ
        for(i=0;i<k;i++){
            if(s[j].admit!=-1) continue;
            int pf=s[j].p[i];
            if(c[pf].ad.size()<c[pf].qt||s[j].rank==c[pf].rank){
                c[pf].rank=s[j].rank;   //��¼��ǰѧ������
                c[pf].ad.push_back(s[j].id);
                s[j].admit=pf;               
            }
        }
    }
    for(i=0;i<m;i++){   //ÿ��ѧУ��ѧ��˳�����¼ȡ��ѧ��
        int size=c[i].ad.size();
        sort(c[i].ad.begin(),c[i].ad.end());
        for(j=0;j<size;j++){
            printf("%d",c[i].ad[j]);
            if(j!=size-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}