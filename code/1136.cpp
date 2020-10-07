#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool isp(string s){
    int len=s.length();
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-i-1])
            return false;
    }
    return true;
}
string add(string a,string b){
    string ans="";
    int up=0;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(int i=0;i<a.length()||i<b.length();i++){
        int now=a[i]+b[i]+up-2*'0';
        up=now/10;
        now%=10;
        ans+=now+'0';
    }
    if(up!=0)
        ans+=up+'0';
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<10&&!isp(s);i++){
        string temp=s;
        reverse(s.begin(),s.end());
        cout<<temp<<" + "<<s<<" = ";
        s=add(s,temp);
        cout<<s<<endl;
    }
    if(isp(s))
        cout<<s<<" is a palindromic number.\n";
    else
        cout<<"Not found in 10 iterations.\n";
    return 0;
}