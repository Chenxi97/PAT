#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    string s;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>s;
        int len=s.length()/2;
        int a=stoi(s.c_str());
        string s1=s.substr(0,len);
        s.erase(s.begin(),s.begin()+len);
        int b=stoi(s.c_str())*stoi(s1.c_str());
        if(b==0) printf("No\n");
        else printf(a%b==0?"Yes\n":"No\n");
    }
    return 0;
}