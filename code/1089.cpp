#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n,i,j,tag=0,a[101],b[101];

    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(i=2;i<=n&&b[i]>=b[i-1];i++);   //������һ�������Ԫ��ʱ�˳�
    for(j=i;j<=n&&b[j]==a[j];j++);   //���ʣ�µ���ԭ������ͬ��Ϊ��������
    if(j==n+1){ //��������
        printf("Insertion Sort\n");
        sort(b+1,b+i+1);
    }
    else{   //�鲢����
        printf("Merge Sort\n");
        for(int step=2;step/2<=n;step*=2){
            for(i=step+1;i<=n&&b[i]>=b[i-1];i+=step*2);
            if(i<=n){
                step*=2;
                for(j=1;j<=n;j+=step)
                    sort(b+j,b+min(n+1,j+step));
                break;
            }
        }
    }
    for(j=1;j<n;j++)
        printf("%d ",b[j]);
    printf("%d\n",b[j]);
    return 0;
}