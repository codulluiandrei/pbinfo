#include<fstream>
#include<cstring>
using namespace std;
ifstream cin("lumini.in");
ofstream cout("lumini.out");
char s[25],nume[25];
int n,i,x,k,solutie,nrdiv,sol[130],e,o;
int prime[60]= { 2, 3, 5, 7, 11,
                 13,17,19,23,29,
                 31,37,41,43,47,
                 53,59,61,67,71,
                 73,79,83,89,97,
                 101,103,107,109,113,
                 127,131,137,139,149,
                 151,157,163,167,173,
                 179,181,191,193,197,
                 199,211,223,227,229,
                 233,239,241,251,257
               };
int main()
{
    ///preprocesarea tuturor valorilor posibile...
    sol[1]=1;
    for(i=2;i<=65536;i++)
    {
        x=i;
        nrdiv=1;
        k=0;
        while(prime[k]*prime[k]<=x)
        {
            e=0;
            while(x%prime[k]==0)
                e++, x/=prime[k];
            nrdiv*=(e+1);
            k++;
        }
        if (x>1)
        {
            nrdiv*=2;
        }
        if (nrdiv<=120)
        if (sol[nrdiv]==0)  sol[nrdiv]=i;
    }
    cin>>o;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x>>s;
        if (sol[x]>solutie)
        {
            solutie=sol[x];
            strcpy(nume,s);
        }
    }
    if (o==1)
        cout << solutie;
    if (o==2)
        cout << nume;
}