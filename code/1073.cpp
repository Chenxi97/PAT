#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s,e,c;
    int ctag,etag,exp;
    cin>>s;
    int len=s.length();
    int pos=s.find("E");
    c=s.substr(0,pos);//ϵ��
    ctag=c[0]=='+'?0:1;
    c.erase(c.begin());//ȥ��ϵ����������
    e=s.substr(pos+1,len-pos-1);//ָ��
    etag=e[0]=='+'?0:1;
    e.erase(e.begin());//ȥ��ָ����������
    sscanf(e.c_str(),"%d",&exp);
    c.erase(c.begin()+1);//ȥ��ϵ���е�С����
    if(etag==1){//ϵ��Ϊ����ֱ����ǰ������
        for(int i=0;i<exp;i++)
            c="0"+c;
        c.insert(1,".");
    }else{//ϵ��Ϊ��
        int clen=c.length();
        if(exp<clen-1)//ָ����Сʱ���ƶ�С����
            c.insert(exp+1,".");
        else if(exp>clen-1)//ָ���ϴ�ʱ���ں������
            for(int i=0;i<exp-clen+1;i++)
                c+="0";
    }
    if(ctag) c="-"+c;
    cout<<c<<endl;
    return 0;
}