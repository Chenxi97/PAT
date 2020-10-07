#include<cstdio>
#include<cstring>
typedef struct student{
    char name[11],id[11];
    int grade;
}Stu;
Stu s[101];
int main()
{
    int n,i,l,h,grade,tag=1;
    char name[11],id[11];

    for(i=0;i<101;i++)
        strcpy(s[i].id,"");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %s %s%d",name,id,&grade);
        strcpy(s[grade].name,name);
        strcpy(s[grade].id,id);
    }
    scanf("%d%d",&l,&h);
    for(i=h;i>=l;i--){    
        if(s[i].id[0]!='\0'){
            tag=0;
            printf("%s %s\n",s[i].name,s[i].id);
        }
    }
    if(tag) printf("NONE\n");
    return 0;
}