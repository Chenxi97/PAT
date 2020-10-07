#include<iostream>
#include<cctype>
#include<map>
#include<string>
using namespace std;
int main()
{
    string s;
    map<string,int> mp;
    getline(cin,s);
    int i,size=s.length(),begin=0,len=0;
    for(i=0;i<size;i++){
        if(!isalpha(s[i])&&!isdigit(s[i])&&len>0){  //遇见非单词字符并且单词长度大于零             
            mp[s.substr(begin,len)]++;
            len=0;
        }
        else if(isalpha(s[i])||isdigit(s[i])){  //单词字符
            s[i]=tolower(s[i]); //转换为小写
            if(len==0) begin=i; //单词长度为0则重置开头
            len++;
        }
    }
    if(len>0) mp[s.substr(begin,len)]++;
    int max=0;  //最大次数
    string maxs;    //次数最多的单词
    for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
        if(it->second>max){
            max=it->second;
            maxs=it->first;
        }
    }
    cout<<maxs<<" "<<max<<endl;
    return 0;
}       