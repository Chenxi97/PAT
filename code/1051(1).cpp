#include<cstdio>
int main()
{
    int n,m,k,i,j,a[1001];
    scanf("%d%d%d",&m,&n,&k);
    for(i=0;i<k;i++){
        for(j=0;j<n;j++)          
            scanf("%d",&a[j]);
        bool out[1001]={0};
        int pre,max=0,tag=1;
        for(j=0;j<n;j++){
            if(a[j]-j>m) tag=0; //���ջ�����ִ���������tagΪ0
            for(pre=a[j]+1;pre<max;pre++)   //����д��ڵ�ǰ����С��max����δ��ջ��tagΪ0
                if(out[pre]==false) tag=0;
            out[a[j]]=true; //��ջ����Ϊtrue
            if(a[j]>max) max=a[j];  //max��¼�ѳ�ջ�������
        }
        if(tag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}