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
        if(!isalpha(s[i])&&!isdigit(s[i])&&len>0){  //�����ǵ����ַ����ҵ��ʳ��ȴ�����             
            mp[s.substr(begin,len)]++;
            len=0;
        }
        else if(isalpha(s[i])||isdigit(s[i])){  //�����ַ�
            s[i]=tolower(s[i]); //ת��ΪСд
            if(len==0) begin=i; //���ʳ���Ϊ0�����ÿ�ͷ
            len++;
        }
    }
    if(len>0) mp[s.substr(begin,len)]++;
    int max=0;  //������
    string maxs;    //�������ĵ���
    for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
        if(it->second>max){
            max=it->second;
            maxs=it->first;
        }
    }
    cout<<maxs<<" "<<max<<endl;
    return 0;
}       