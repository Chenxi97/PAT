#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 26*26*26*10
using namespace std;
int stoid(char *a){
    int id=0;
    for(int i=0;i<3;i++)
        id=id*26+a[i]-'A';
    id=id*10+a[3]-'0';
    return id;
}
int main()
{
    char sid[5];
    vector<int> vt[MAX];
    int n,k,cid,snum;

    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){
        scanf("%d%d",&cid,&snum);
        for(int j=0;j<snum;j++){
            scanf(" %s",sid);
            vt[stoid(sid)].push_back(cid);
        }
    }
    for(int i=0;i<n;i++){
        scanf(" %s",sid);
        printf("%s",sid);
        vector<int> temp=vt[stoid(sid)];
        int len=temp.size();
        printf(" %d",len);
        sort(temp.begin(),temp.end());
        for(int j=0;j<len;j++)
            printf(" %d",temp[j]);
        printf("\n");
    }
    return 0;
}