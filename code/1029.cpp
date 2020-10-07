#include<cstdio>
#include<cstdlib>
int main()
{
    long *a,*b,temp;
    int n,m;

    scanf("%d",&n);
    a=(long *)malloc(sizeof(long)*n);
    for(int i=0;i<n;i++)
        scanf("%ld",&a[i]);
    scanf("%d",&m);
    b=(long *)malloc(sizeof(long)*m);
    for(int i=0;i<m;i++)
        scanf("%ld",&b[i]);
    int mid=(n+m-1)/2,j=0,i=0;
    while(i+j<mid&&i<n&&j<m){
        if(a[i]<b[j]) i++;
        else if(a[i]>b[j]) j++;
        else{
            i++;j++;
        }
    }
    if(i+j<mid&&i==n)
        while(i+j<mid) j++;
    if(i+j<mid&&j==m)
        while(i+j<mid) i++;
    if(i<n&&j<m) temp=a[i]>b[j]?b[j]:a[i];
    else temp=i==n?b[j]:a[i];
    printf("%ld\n",temp);
    free(a);
    free(b);
    return 0;
}