#include<iostream>
#include<string>
using namespace std;
bool islegal(string s){
    double ans=0,tag=1;
    if(s[0]=='-'){  //去掉开头的负号
        tag=-1;
        s.erase(s.begin());
    }
    int len=s.length(),count=0,p=s.length();//"."的初始位置设为字符串末尾
    if(len==0||s[0]=='.') return false; //如果开头是"."或者没有字符，返回错误
    for(int i=0;i<len;i++){//查找"."的位置，多于一个时返回错误
        if(s[i]=='.'){
            if(++count>1) return false;
            p=i;
        }
        else if(!isdigit(s[i])) return false;//非数字时返回错误
    }
    if(len-p>3) return false;//"."后数字多于两个返回错误
    sscanf(s.c_str(),"%lf",&ans);
    if(ans>1000) return false;  //大于1000返回错误
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