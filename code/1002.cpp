#include<cstdio>
#include<cstring>
int main()
{
    double a[10][2],b[10][2],c[20][2];
    int i,j,k,an,bn;
	
    scanf("%d",&an);
    for(i=0;i<an;i++)
        scanf("%lf%lf",&a[i][0],&a[i][1]);
    scanf("%d",&bn);
    for(i=0;i<bn;i++)
        scanf("%lf%lf",&b[i][0],&b[i][1]);

    i=j=k=0;
    while(i<an&&j<bn){  //ָ����ͬʱ��ͣ���ͬʱֱ�Ӵ���
        if(a[i][0]>b[j][0]){
            c[k][0]=a[i][0];
            c[k++][1]=a[i++][1];
        }
        else if(a[i][0]<b[j][0]){
            c[k][0]=b[j][0];
            c[k++][1]=b[j++][1];
        }
        else{
            c[k][0]=a[i][0];
            c[k][1]=a[i++][1]+b[j++][1];
            if(c[k][1]!=0.0) k++;	//��Ϊ��ʱk������
        }
    }

    if(i<an)    //ֱ�ӱ�����һ������ʽʣ�µ���
        while(i<an){
            c[k][0]=a[i][0];
            c[k++][1]=a[i++][1];
        }
    if(j<bn)
        while(j<bn){
            c[k][0]=b[j][0];
            c[k++][1]=b[j++][1];
        }

    printf("%d",k);
    for(i=0;i<k;i++)
        if(c[i][1])	//���ϵ���������
            printf(" %.0lf %.1lf",c[i][0],c[i][1]);
    printf("\n");
    return 0;
}