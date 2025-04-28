#include<bits/stdc++.h>
using namespace std;
bool mic(string str1,string str2)
{
    int n1=str1.length(),n2=str2.length();
    if(n1<n2)
        return true;
    if(n1>n2)
        return false;
    for(int i=0;i<n1;i++)
    {
        if(str1[i]<str2[i])
            return true;
        else
        if(str1[i]>str2[i])
            return false;
    }
    return false;
}
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
string dx(string str1,string str2)
{
    if(mic(str1,str2))
        swap(str1,str2);
    string str = "";
    if(str1[0]=='0')
        return "0";
    int n1=str1.length(),n2=str2.length();
    int dif=n1-n2;
    int t=0;
    for(int i=n2-1;i>=0;i--)
    {
        int sub=((str1[i+dif]-'0')-(str2[i]-'0')-t);
        if(sub<0)
            sub+=10,t=1;
        else
            t=0;
        str.push_back(sub+'0');
    }
    for(int i=n1-n2-1;i>=0;i--)
    {
        if(str1[i]=='0'&&t)
        {
            str.push_back('9');
            continue;
        }
        int sub=((str1[i]-'0')-t);
        if (i>0||sub>0)
            str.push_back(sub+'0');
        t=0;
    }
    reverse(str.begin(),str.end());
    while(str[0]=='0' && str.size()>1)
        str.erase(str.begin()+0);
    return str;
}
string ddx(string s,string ss)
{
    int m=2,ls=0,lss=0,o1=0,o2=0,p1=0,p2=0;
    if(s[0]=='-' || ss[0]=='-')
    {
        m=1;
        if(s[0]=='-' && ss[0]!='-')
            p1=1;
        if(s[0]!='-' && ss[0]=='-')
            p2=1;
    }
    if(s[0]=='-' && ss[0]=='-')
        m=0;
    if(s[0]=='-')
        s.erase(s.begin()+0);
    if(ss[0]=='-')
        ss.erase(ss.begin()+0);
    if(s.find('.')!=-1)
        ls=s.find('.'),o1=1;
    if(ss.find('.')!=-1)
        lss=ss.find('.'),o2=1;
    if(o1)
    {
        s.erase(s.begin()+ls),ls--;
        ls=s.size()-1-ls;
    }
    if(o2)
    {
        ss.erase(ss.begin()+lss),lss--;
        lss=ss.size()-1-lss;
    }
    if(ls>lss)
        for(int i=1;i<=ls-lss;i++)
            ss+='0';
    else
    if(lss>ls)
        for(int i=1;i<=lss-ls;i++)
            s+='0';
    if(ss=="1")
    {
        return s;
    }
    if(s=="0")
    {
        return "0.000000";
    }
    string rez;
    if(mic(s,ss))
        rez="0.";
    while(mic(s,ss))
    {
        s+='0';
        if(!mic(s,ss) || (rez.size()-1-rez.find('.')==6 && rez.find('.')!=-1))
            break;
        rez+='0';
    }
    if(rez.find('.')!=-1)
    {
        if(rez.size()-1-rez.find('.')==6)
            return rez;
        else
        if(rez.size()-1-rez.find('.')<6 && rez.find('.')!=-1)
        {
            string temp;
            while(rez.size()-1-rez.find('.')<6)
            {
                int ap=0;
                while(!mic(s,ss))
                    s=dx(s,ss),ap++;
                rez+=to_string(ap);
                s+='0';
            }
            return rez;
        }
    }
    string temp;
    int j,k=s.size(),ap=0;
    for(int i=0;i<s.size() && mic(temp,ss);i++)
        temp+=s[i],j=i+1;
    while(!mic(temp,ss))
        temp=dx(temp,ss),ap++;
    rez+=to_string(ap);
    for(;j<s.size();j++)
    {
        if(rez.find('.')!=-1 && rez.size()-1-rez.find('.')==6)
        {
            if(m==1)
                rez.insert(rez.begin()+0,'-');
            return rez;
        }
        ap=0;
        if(j==k)
        {
            rez+='.';
            ls=max(ls,lss);
        }
        if(temp[0]=='0')
            temp="",temp+=s[j];
        else
            temp+=s[j];
        if(temp[0]=='0')
        {
            rez+='0';
            continue;
        }
        while(mic(temp,ss) && j<s.size())
        {
            rez+='0',temp+=s[++j];
            if(rez.size()-1-rez.find('-')==6 && rez.find('.')!=-1)
            {
                if(m==1)
                    rez.insert(rez.begin()+0,'-');
                return rez;
            }
        }
        while(!mic(temp,ss))
            temp=dx(temp,ss),ap++;
        rez+=to_string(ap);
    }
    if(m==1)
        rez.insert(rez.begin()+0,'-');
    return rez;
}
string coef(string s,string ss)
{
    string d=dx(s,ss);
	string rez="1";
	if(!mic(ss,d))
        ss=d;
	for(int i=0;i<stoll(ss);i++)
	{
		rez=px(rez,dx(s,to_string(i)));
		rez=ddx(rez,to_string(i+1));
	}
	return rez;
}
string catalan(string s)
{
	string c=coef(px(s,"2"),s);
	return ddx(c,sx(s,"1"));
}
int main()
{
	int n;
	cin>>n;
    cout<<catalan(to_string(n));
	return 0;
}