#include<cstdio>
#define MAX 12
//����һ����λ������n�Լ���ߵ���λ��Ϊ0ʱ������1�����򷵻�0
int all0(int *a,int n)
{
    int tag=1;
    do{
        if(a[n++]!=0) tag=0;
    }while(n%4!=0);
    return tag;
}

int main()
{
    int n,i,a[MAX];
    char ch1[3][5]={"Qian","Bai","Shi"},
        ch2[10][5]={"ling","yi","er","san","si",
        "wu","liu","qi","ba","jiu"};
    
    scanf("%d",&n);
    //����ֵ����
    if(n<0){
        printf("Fu ");
        n=-n;
    }
    if(!n){
        printf("ling\n");
        return 0;
    }
    //tagָʾ�Ƿ������˵�һ��Ҫ������ַ���midtagָʾǰ���Ƿ������"ling"
    int tag=0,midtag=0;
    for(i=MAX-1;i>=0;i--){
        a[i]=n%10;
        n/=10;
    }
    for(i=0;i<MAX;i++){
        //����ǰ�ߵ�0
        if(!a[i]&&!tag)
            continue;  
        //����Ϊ��ʱ
        if(!a[i]){
            //������λ��ĩβ���㲢��ǰ��û���������ling��ʱ�������ling��
            if(!all0(a,i)&&!midtag){       
                printf(" ");
                printf("%s",ch2[a[i]]);
                midtag=1;
            }
        }
        //���ַ���ʱ������midtag
        else{
            if(tag) printf(" ");
            printf("%s",ch2[a[i]]);
            midtag=0;
        }
        //���ǧ���١�ʮ
        if(a[i]&&i%4!=3) printf(" %s",ch1[i%4]);
        //����λȫΪ��ʱ���������λ
        if(i==3&&!all0(a,0)) printf(" Yi");
        if(i==7&&!all0(a,4)) printf(" Wan");
        tag=1;
    }
    printf("\n");
    return 0;
}