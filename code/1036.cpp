#include<cstdio>
#include<cstring>
typedef struct{
    char name[11];
    char id[11];
    int grade;
}stu;
int main()
{
    stu s[2];
    int n,i,grade;
    char name[11],id[11],gen;

    s[0].grade=-1;
    s[1].grade=101;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %s %c %s %d",name,&gen,id,&grade);
        if(gen=='F'&&grade>s[0].grade){ //男生信息
            strcpy(s[0].name,name);
            strcpy(s[0].id,id);
            s[0].grade=grade;
        }
        else if(gen=='M'&&grade<s[1].grade){    //女生信息
            strcpy(s[1].name,name);
            strcpy(s[1].id,id);
            s[1].grade=grade;
        }
    }
    for(i=0;i<2;i++){
        if(s[i].grade>100||s[i].grade<0)    //未录入信息
            printf("Absent\n");
        else
            printf("%s %s\n",s[i].name,s[i].id);
    }
    if(s[i].grade>100||s[i].grade<0) printf("NA\n");
    else printf("%d\n",s[0].grade-s[1].grade);
    return 0;
}