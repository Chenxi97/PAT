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
            if(a[j]-j>m) tag=0; //如果栈内数字大于容量，tag为0
            for(pre=a[j]+1;pre<max;pre++)   //如果有大于当前数字小于max的数未出栈，tag为0
                if(out[pre]==false) tag=0;
            out[a[j]]=true; //出栈后设为true
            if(a[j]>max) max=a[j];  //max记录已出栈的最大数
        }
        if(tag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}