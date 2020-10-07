#include<iostream>
#include<cstring>
#include<map>
#include<string>
using namespace std;
string mlow[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string mhigh[13]={"tret", "tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
map<string,int> m;
void etom(string s){
    int n;
    sscanf(s.c_str(),"%d",&n);
    bool tag1=(n/13>0),tag2=(n%13>0);
    if(tag1&&tag2) cout<<mhigh[n/13]<<" "<<mlow[n%13];//��λ����Ϊ��
    else if(tag1) cout<<mhigh[n/13];//ʮλ��Ϊ�㣬��λΪ��
    else cout<<mlow[n%13];//�������
    cout<<endl;
}
void mtoe(string s){
    string high,low;
    int i;
    if(s.length()>4){	//��λ��
        for(i=0;i<s.length();i++)
            if(s[i]==' ') break;
        high=s.substr(0,i);//���ݿո�ָ�
        low=s.substr(i+1,s.length()-i-1);
        cout<<m[high]+m[low]<<endl;
    }
    else cout<<m[s]<<endl;	//һλ��
}
int main()
{
    int n,i;
    string s;
    for(i=0;i<13;i++){
        m[mlow[i]]=i;
        m[mhigh[i]]=i*13;
    }
    cin>>n;
    getchar();	//��ȡ���з�
    for(i=0;i<n;i++){
        getline(cin,s);
        if(isdigit(s[0]))
            etom(s);
        else
            mtoe(s);
    }
    return 0;
}