#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 1010
int n,bst[MAX],a[MAX],num=0;
void inorder(int root){//ÖÐÐò±éÀú
    if(root>n) return;
    inorder(root*2);
    bst[root]=a[num++];
    inorder(root*2+1);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    inorder(1);
    for(int i=1;i<=n;i++){
        printf("%d",bst[i]);
        if(i<n) printf(" ");
    }
    return 0;
}