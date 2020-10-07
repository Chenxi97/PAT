#include<cstdio>
#include<set>
using namespace std;
int getf(int a){
    int ans=0;
    while(a>0){
        ans+=a%10;
        a/=10;
    }
    return ans;
}
int main()
{
    set<int> st;
    int n,num;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        st.insert(getf(num));
    }
    printf("%d\n",st.size());
    for(set<int>::iterator i=st.begin();i!=st.end();i++){
        if(i!=st.begin()) printf(" ");
        printf("%d",*i);
    }
    return 0;
}