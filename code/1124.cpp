#include<iostream>
#include<string>
#include<map>
#define MAX 1010
using namespace std;
int main()
{
    int m,k,s;
    string forward[MAX];
    map<string,int> mp;
    cin>>m>>k>>s;
    for(int i=1;i<=m;i++)
        cin>>forward[i];
    int i=s,tag=0;
    while(i<=m){
        if(mp[forward[i]]==0){
            cout<<forward[i]<<endl;
            mp[forward[i]]++;
            tag=1;
            i+=k;
        }else
            i++;
    }
    if(!tag) cout<<"Keep going..."<<endl;
    return 0;
}