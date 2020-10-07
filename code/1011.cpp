#include<cstdio>
int main()
{
    char re[4]="WTL";
    double odd,max,ans=1;
    int number;

    for(int i=0;i<3;i++){
        max=0.0;
        for(int j=0;j<3;j++){   //选择三个赔率中的最大值
            scanf("%lf",&odd);
            if(odd>max){
                max=odd;
                number=j;
            }
        }
        printf("%c ",re[number]);
        ans*=max;
    }
    printf("%.2lf\n",(ans*0.65-1)*2);
    return 0;
}