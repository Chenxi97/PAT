#include<cstdio>
int main()
{
    int n,b,i,num=0;
    int a[32];

    scanf("%d%d",&n,&b);
    do{                 //nΪ0��ʱ��Ҳ�ܽ���һ��ѭ��
        a[num++]=n%b;
        n/=b;
    }while(n!=0);
    for(i=0;i<num/2;i++)    //���ǻ��ĵĻ���ǰ�˳�ѭ��
        if(a[i]!=a[num-i-1])
            break;
    printf("%s\n",i==num/2?"Yes":"No");
    for(i=num-1;i>0;i--)
        printf("%d ",a[i]);
    printf("%d\n",a[i]);
    return 0;
}