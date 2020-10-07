#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef struct wealth{
    char name[10];
    int age,worth;
}Wea;
Wea w1[100000],w[20000];
bool cmp(Wea a,Wea b){
    if(a.worth!=b.worth) return a.worth>b.worth;
    else if(a.age!=b.age) return a.age<b.age;
    else return strcmp(a.name,b.name)<0;
}
int main()
{
    int n,k,i,j,h,m,a1,a2,num=0,age[201];

    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
        scanf(" %s %d %d",w1[i].name,&w1[i].age,&w1[i].worth);
    sort(w1,w1+n,cmp);
    memset(age,0,201*sizeof(int));
    for(i=0;i<n;i++){   //保存每个年龄排名前一百的人
        if(age[w1[i].age]<100){
            w[num++]=w1[i];
            age[w1[i].age]++;
        }
    }
    for(i=0;i<k;i++){
        scanf("%d %d %d",&m,&a1,&a2);        
        printf("Case #%d:\n",i+1);
        for(j=0,h=m;j<num&&h!=0;j++)
            if(w[j].age>=a1&&w[j].age<=a2){
                printf("%s %d %d\n",w[j].name,w[j].age,w[j].worth);
                h--;
            }
        if(h==m) printf("None\n");
    }
    return 0;
}