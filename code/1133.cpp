#include<iostream>
#include<vector>
#define MAX 1000010
using namespace std;
struct node{
    int data,next;
}Node[MAX];
int main()
{
    int root,n,k,add;
    scanf("%d%d%d",&root,&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&add);
        scanf("%d%d",&Node[add].data,&Node[add].next);
    }
    vector<int> neg,less,lar;
    add=root;
    while(add!=-1){
        if(Node[add].data<0)
            neg.push_back(add);
        else if(Node[add].data>k)
            lar.push_back(add);
        else less.push_back(add);
        add=Node[add].next;
    }
    for(int i=0;i<less.size();i++)
        neg.push_back(less[i]);
    for(int i=0;i<lar.size();i++)
        neg.push_back(lar[i]);
    printf("%05d %d ",neg[0],Node[neg[0]].data);
    for(int i=1;i<neg.size();i++)
        printf("%05d\n%05d %d ",neg[i],neg[i],Node[neg[i]]);
    printf("-1\n");
    return 0;
}