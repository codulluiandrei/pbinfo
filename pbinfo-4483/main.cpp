#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s[101];
    cin>>s;
    for(int i=0;i<strlen(s);i++)
        for(int j=i+1;j<strlen(s);j++)
            if(strchr("aeiou",s[i]) && strchr("aeiou",s[j]) && s[i]<s[j])
                swap(s[i],s[j]);
    cout<<s;
    return 0;
}