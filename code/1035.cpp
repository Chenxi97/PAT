#include<cstdio>
#include<cstring>
#include<cstdlib>
typedef struct{
    int tag;
    char uid[11],pwd[11];
}User;
int main()
{
    int n,i,j,len,number=0;
    User *u;
    char a[5]="10lO",b[5]="@%Lo";

    scanf("%d",&n);
    u=(User*)malloc(sizeof(User)*n);
    for(i=0;i<n;i++){
        scanf(" %s %s",u[i].uid,u[i].pwd);
        len=strlen(u[i].pwd);
        u[i].tag=0;
        for(j=0;j<len;j++){
            char *p=strchr(a,u[i].pwd[j]);
            if(p!=NULL){
                u[i].tag=1;
                u[i].pwd[j]=b[p-a];
            }
        }
        if(u[i].tag) number++;
    }
    if(number!=0) printf("%d\n",number);
    else if(n==1) printf("There is 1 account and no account is modified\n");
    else printf("There are %d accounts and no account is modified\n",n);
    for(i=0;i<n;i++)
        if(u[i].tag)
            printf("%s %s\n",u[i].uid,u[i].pwd);
    return 0;
}