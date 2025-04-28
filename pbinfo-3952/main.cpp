#include<fstream>
using namespace std;
ifstream fin("partitiimultime3.in");
ofstream fout("partitiimultime3.out");
int n,X[21],m;
int maxim(int n)
{
    int max=0;
    for(int i=1;i<=n;i++)
        if(X[i]>max) max=X[i];
    return max;
}
void afis()
{
    int max=maxim(n),ok=1;
    for(int i=1;i<=max;i++)
    {
        int c=0;
        for(int j=1;j<=n;j++)
            if(X[j]==i) c++;
        if(c!=m) ok=0;
    }
    if(ok)
    {
        for(int i=1;i<=max;i++)
        {
           for(int j=1;j<=n;j++)
                if(X[j]==i)  fout<<j;
           fout<<"*";
        }
        fout<<"\n";
    }
}
void back(int k)
{
    int max=maxim(k-1);
    for(int i=1;i<=max+1;i++)
    {
        X[k]=i;
        if(k==n) afis();
        else back(k+1);
    }
}
int main()
{
   fin>>n>>m;
   if(n%m!=0) fout<<"IMPOSIBIL";
   else back(1);
   return 0;
}