#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//bool cmp(string a,string b){
//    if(b.length()>a.length()&&b.find(a)==0)
//        return a<b.substr(b.find(a)+a.length(),b.length()-a.length());
//    else if(a.length()>b.length()&&a.find(b)==0)
//        return b>a.substr(a.find(b)+b.length(),a.length()-b.length());
//    else
//        return a<b;
//}
bool cmp(string a,string b){    //�����������������С������������ô�ܵ�����Ҳ����С
    return a+b<b+a;
}
int main()
{
    int n,i;
    string s[10000],ans;

    scanf("%d",&n);
    for(i=0;i<n;i++)
        cin>>s[i];
    sort(s,s+n,cmp);
    for(i=0;i<n;i++)    //�ϳ�һ���ַ���
        ans+=s[i];
    for(i=0;ans[i]=='0'&&i<ans.length()-1;i++) ;
    ans.erase(ans.begin(),ans.begin()+i);   //ɾ��ǰ����
    cout<<ans<<endl;
    return 0;
}