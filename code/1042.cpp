#include<cstdio>
int main()
{
    int card[55],order[55],b[55];
    char c[6]="SHCDJ";
    int i,j,k;

    scanf("%d",&k);
    for(i=1;i<55;i++){
        card[i]=i;
        scanf("%d",&order[i]);
    }
    for(i=0;i<k;i++){   //洗牌
        for(j=1;j<55;j++)
            b[order[j]]=card[j];
        for(j=1;j<55;j++)
            card[j]=b[j];
    }
    for(i=1;i<55;i++){  //根据下标计算输出花色
        card[i]-=1;
        printf("%c%d",c[card[i]/13],card[i]%13+1);
        if(i!=54) printf(" ");
    }
    printf("\n");
    return 0;
}