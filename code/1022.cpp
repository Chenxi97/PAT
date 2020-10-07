#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int bid,n,m,i;
    map<string,vector<int> > book;
    string ti,au,pub,keyword,year;
    cin>>n;
    for(i=0;i<n;i++){
        scanf("%d\n",&bid);
        getline(cin,ti);    //读取书名
        book[ti].push_back(bid);
        getline(cin,au);    //读取作者
        book[au].push_back(bid);
        while(cin>>keyword){    //读取关键词
            book[keyword].push_back(bid);
            char c=getchar();
            if(c=='\n') break;
        }
        getline(cin,pub);   //读取出版社
        book[pub].push_back(bid);
        getline(cin,year);  //读取年份
        book[year].push_back(bid);
    }
    string q;
    int type;
    scanf("%d\n",&m);
    for(i=0;i<m;i++){
        scanf("%d: ",&type);
        getline(cin,q);
        printf("%d: %s\n",type,q.c_str());
        if(book[q].size()==0){
            printf("Not Found\n");
            continue;
        }
        sort(book[q].begin(),book[q].end());    //按大小排序
        for(int j=0;j<book[q].size();j++)
            printf("%07d\n",book[q][j]);
    }
    return 0;
}