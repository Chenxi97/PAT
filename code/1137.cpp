#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct stu{
    string id;
    int gp,gm,gf,g;
};
vector<stu> s;
bool cmp(stu a,stu b){
    if(a.g!=b.g) return a.g>b.g;
    else return a.id<b.id;
}
int main()
{
    int p,n,m,i,g;
    string id;
    map<string,int> mp;

    cin>>p>>n>>m;
    stu temp={"",-1,-1,-1,-1};
    for(i=0;i<p;i++){   //ֻ������ϰ�ɼ�����200���û���Ϣ
        cin>>temp.id>>temp.gp;
        if(temp.gp<200) continue;
        s.push_back(temp);
        mp[temp.id]=s.size()-1;
    }
    for(i=0;i<n;i++){   //���гɼ�
        cin>>id>>g;
        if(mp.find(id)!=mp.end())
            s[mp[id]].gm=g;
    }
    for(i=0;i<m;i++){   //��ĩ�ɼ�
        cin>>id>>g;
        if(mp.find(id)!=mp.end())
            s[mp[id]].gf=g;
    }
    int len=s.size();
    for(i=0;i<len;i++){ //�������ճɼ�
        if(s[i].gm>s[i].gf)
            s[i].g=s[i].gm*0.4+s[i].gf*0.6+0.5;
        else
            s[i].g=s[i].gf;
    }
    sort(s.begin(),s.end(),cmp);
    for(i=0;i<len;i++)
        if(s[i].g>=60)
            printf("%s %d %d %d %d\n",s[i].id.c_str(),s[i].gp,s[i].gm,
            s[i].gf,s[i].g);
    return 0;
}