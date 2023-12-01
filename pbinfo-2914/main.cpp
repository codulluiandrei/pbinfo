#include<bits/stdc++.h>
using namespace std;

string sx(string str1,string str2)
{
    int t=0;
    if (str1.length()>str2.length())
        swap(str1,str2);
    string str="";
    int n1=str1.length(),n2=str2.length();
    int dif=n2-n1;
    for(int i=n1-1;i>=0;i--)
    {
        int sum=((str1[i]-'0')+(str2[i+dif]-'0')+t);
        str.push_back(sum%10+'0');
        t=sum/10;
    }
    for(int i=n2-n1-1;i>=0;i--)
    {
        int sum=((str2[i]-'0')+t);
        str.push_back(sum%10+'0');
        t=sum/10;
    }
    if(t)
        str.push_back(t+'0');
    reverse(str.begin(),str.end());
    return str;
}

int main()
{
    unsigned long long n;
    cin>>n;
    cout<<sx(to_string(n),to_string(n-1));
}
