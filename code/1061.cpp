#include<cstdio>
#include<cstring>
#include<ctype.h>
int main()
{
    char a[61],b[61],week[7][4]={"MON","TUE","WED",
        "THU","FRI","SAT","SUN"};
    int i,j;

    scanf(" %s %s",a,b);    //��ȡǰ���У�������
    for(i=0;i<61;i++)
        if(a[i]==b[i]&&a[i]>='A'&&a[i]<='G'){
            printf("%s ",week[a[i]-'A']);
            break;
        }
    for(j=i+1;j<61;j++){    //��Сʱ
        if(a[j]!=b[j]) continue;
        if(a[j]>='A'&&a[j]<='N'){
            printf("%02d",a[j]-'A'+10);
            break;
        }
        if(isdigit(a[j])){
            printf("%02d",a[j]-'0');
            break;
        }
    }
    scanf(" %s %s,",a,b);   //��ȡ�����У������
    for(i=0;i<61;i++)
        if(a[i]==b[i]&&isalpha(a[i])){
            printf(":%02d\n",i);
            break;
        }
    return 0;
}