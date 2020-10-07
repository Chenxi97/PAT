#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef struct rd{
    char id[7],name[9];
    int grade;
}Rd;
Rd r[100000];
int c;
bool cmp(Rd a,Rd b){    
	if(c==2&&strcmp(a.name,b.name)!=0) 
        return strcmp(a.name,b.name)<0;
	else if(c==3&&a.grade!=b.grade) 
        return a.grade<b.grade;
    else 
        return strcmp(a.id,b.id)<0;
}
int main()
{
    int n,i;

    scanf("%d %d",&n,&c);
    for(i=0;i<n;i++)
        scanf(" %s %s %d",r[i].id,r[i].name,&r[i].grade);
    sort(r,r+n,cmp);
    for(i=0;i<n;i++)
        printf("%s %s %d\n",r[i].id,r[i].name,r[i].grade);
    return 0;
}