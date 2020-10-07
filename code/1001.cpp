#include<cstdio>
#include<cstring>
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	char s[10];
	sprintf(s,"%d",a+b);
	int len=strlen(s);
	for(int i=0;i<len;i++){
		printf("%c",s[i]);
		if(s[i]=='-') continue;
		if((i+1)%3==len%3&&i!=len-1)
			printf(",");
	}
	printf("\n");
	return 0;
}