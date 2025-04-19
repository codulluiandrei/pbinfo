#include <iostream>
#include <cstring>
using namespace std;
int n,P[128];
char X[11],s[11],v[]="aeiou";
void back(int k)
{
    for(int i=0;i<n;i++)
        if(!P[(int)s[i]])
        {
            X[k]=s[i];
            P[(int)s[i]]=1;
            if(strchr(v,X[0]))
                if(k==n-1)
                {
                    if(strchr(v,X[n-1]))
                        cout<<X<<"\n";
                }
                else back(k+1);
            else ;
            P[(int)s[i]]=0;
        }
}
int main()
{
    cin>>s;
    n=strlen(s);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(s[i]>s[j])
            {
                char aux=s[i]; s[i]=s[j]; s[j]=aux;
            }
    back(0);
    return 0;
}