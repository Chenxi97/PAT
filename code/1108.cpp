#include<iostream>
#include<string>
using namespace std;
bool islegal(string s){
    double ans=0,tag=1;
    if(s[0]=='-'){  //ȥ����ͷ�ĸ���
        tag=-1;
        s.erase(s.begin());
    }
    int len=s.length(),count=0,p=s.length();//"."�ĳ�ʼλ����Ϊ�ַ���ĩβ
    if(len==0||s[0]=='.') return false; //�����ͷ��"."����û���ַ������ش���
    for(int i=0;i<len;i++){//����"."��λ�ã�����һ��ʱ���ش���
        if(s[i]=='.'){
            if(++count>1) return false;
            p=i;
        }
        else if(!isdigit(s[i])) return false;//������ʱ���ش���
    }
    if(len-p>3) return false;//"."�����ֶ����������ش���
    sscanf(s.c_str(),"%lf",&ans);
    if(ans>1000) return false;  //����1000���ش���
    return true;
}
int main()
{
    int n,i,count=0;
    double sum=0.0,ans;
    string s;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>s;
        if(islegal(s)==true){
            count++;
            sscanf(s.c_str(),"%lf",&ans);
            sum+=ans;
        }else
            printf("ERROR: %s is not a legal number\n",s.c_str());
    }
    printf("The average of %d",count);
    if(count==0) printf(" numbers is Undefined\n");
    else if(count==1) printf(" number is %.2lf\n",sum/count);
    else printf(" numbers is %.2lf\n",sum/count);
    return 0;
}