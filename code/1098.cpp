#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[101],b[101];
void down(int low,int high){
    int i=low,j=low*2;
    while(j<=high){
        if(j+1<=high&&b[j+1]>b[j])
            j++;
        if(b[i]<b[j]){
            swap(b[i],b[j]);
            i=j;
            j=i*2;
        }
        else break;
    }
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(i=2;i<=n&&b[i]>=b[i-1];i++);
    for(j=i;j<=n&&b[j]==a[j];j++);
    if(j==n+1){
        printf("Insertion Sort\n");
        sort(b,b+i+1);
    }
    else{
        printf("Heap Sort\n");
        for(i=n;i>=1&&b[i]>b[1];i--);
        swap(b[1],b[i]);
        down(1,i-1);
    }
    for(i=1;i<=n;i++){
        if(i>1) printf(" ");
        printf("%d",b[i]);
    }
    return 0;
}