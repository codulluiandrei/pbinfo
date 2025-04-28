#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    string s;
    cin>>s;
    for(int i=0;i<s.size()-1;i++)
    {
        if(tolower(s[i])==tolower(s[i+1]))
        {
            c=tolower(s[i]);
            int j=i+1;
            while(tolower(s[j])==c)
            j++;
            s.erase(i,j-i),i--;
            i=-1;
        }
    }
    cout<<s;
    return 0;
}