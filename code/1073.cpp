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
    c=s.substr(0,pos);//系数
    ctag=c[0]=='+'?0:1;
    c.erase(c.begin());//去掉系数的正负号
    e=s.substr(pos+1,len-pos-1);//指数
    etag=e[0]=='+'?0:1;
    e.erase(e.begin());//去掉指数的正负号
    sscanf(e.c_str(),"%d",&exp);
    c.erase(c.begin()+1);//去掉系数中的小数点
    if(etag==1){//系数为负，直接在前边添零
        for(int i=0;i<exp;i++)
            c="0"+c;
        c.insert(1,".");
    }else{//系数为正
        int clen=c.length();
        if(exp<clen-1)//指数较小时，移动小数点
            c.insert(exp+1,".");
        else if(exp>clen-1)//指数较大时，在后边添零
            for(int i=0;i<exp-clen+1;i++)
                c+="0";
    }
    if(ctag) c="-"+c;
    cout<<c<<endl;
    return 0;
}