#include<cstdio>
#define MAX 12
//对于一个四位数，当n以及后边的数位均为0时，返回1，否则返回0
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
    //处理负值和零
    if(n<0){
        printf("Fu ");
        n=-n;
    }
    if(!n){
        printf("ling\n");
        return 0;
    }
    //tag指示是否遇到了第一个要输出的字符，midtag指示前边是否输出过"ling"
    int tag=0,midtag=0;
    for(i=MAX-1;i>=0;i--){
        a[i]=n%10;
        n/=10;
    }
    for(i=0;i<MAX;i++){
        //跳过前边的0
        if(!a[i]&&!tag)
            continue;  
        //数字为零时
        if(!a[i]){
            //不是四位数末尾的零并且前边没有输出过“ling”时，输出“ling”
            if(!all0(a,i)&&!midtag){       
                printf(" ");
                printf("%s",ch2[a[i]]);
                midtag=1;
            }
        }
        //数字非零时，重置midtag
        else{
            if(tag) printf(" ");
            printf("%s",ch2[a[i]]);
            midtag=0;
        }
        //输出千、百、十
        if(a[i]&&i%4!=3) printf(" %s",ch1[i%4]);
        //当四位全为零时，不输出单位
        if(i==3&&!all0(a,0)) printf(" Yi");
        if(i==7&&!all0(a,4)) printf(" Wan");
        tag=1;
    }
    printf("\n");
    return 0;
}