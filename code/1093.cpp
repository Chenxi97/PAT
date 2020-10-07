#include<iostream>
#include<string>
using namespace std;
int main()
{
    int i,j,count=0,cp[100000]={0},ct=0;
    string s;

    cin>>s;
    int len=s.length();
    for(i=0;i<len;i++){
        if(i>0) cp[i]=cp[i-1];
        if(s[i]=='P') cp[i]++;
    }
    for(j=len-1;j>=0;j--){
        if(s[j]=='T') ct++;
        else if(s[j]=='A')
            count=(count+cp[j]*ct)%1000000007;
    }
    cout<<count<<endl;
    return 0;
}