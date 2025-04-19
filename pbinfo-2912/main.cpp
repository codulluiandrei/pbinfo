#include<bits/stdc++.h>
using namespace std;
string px(string num1, string num2)
{
    int n1=num1.size();
    int n2=num2.size();
    if(n1==0||n2==0)
       return "0";
    vector<int> rez(n1+n2,0);
    int i_n1=0;
    int i_n2=0;
    for(int i=n1-1;i>=0;i--)
    {
        int t=0;
        int n1=num1[i]-'0';
        i_n2=0;
        for(int j=n2-1;j>=0;j--)
        {
            int n2=num2[j]-'0';
            int sum=n1*n2+rez[i_n1+i_n2]+t;
            t=sum/10;
            rez[i_n1+i_n2]=sum%10;
            i_n2++;
        }
        if(t>0)
            rez[i_n1+i_n2]+=t;
        i_n1++;
    }
    int i=rez.size()-1;
    while(i>=0 && rez[i]==0)
       i--;
    if(i==-1)
       return "0";
    string s="";
    while(i>=0)
        s+=to_string(rez[i--]);
    return s;
}
int main()
{
    unsigned long long n;
    cin>>n;
    cout<<px(to_string(n),"2");
}