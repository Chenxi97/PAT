#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,i,j,hash[256]={0};
    string s;

    cin>>n>>s;
    int len=s.length();
    for(i=0;i<=len-n;i++){
        for(j=1;j<n&&s[i+j]==s[i];j++);
        if(j==n){   //s[i]���ߵ�n-1������ͬ,�ж�Ϊ����
            if(hash[s[i]]==0)
                hash[s[i]]=1;
            i+=(n-1);
        }
        else hash[s[i]]=-1; //������
    }
    for(i=0;i<len;i++){ //�������
        if(hash[s[i]]==1){
            cout<<s[i];
            hash[s[i]]=2;
        }
    }
    cout<<endl;
    for(i=0;i<len;i++){ //���ԭ�����ַ���
        cout<<s[i];
        if(hash[s[i]]>0)
            i+=(n-1);
    }
    return 0;
}