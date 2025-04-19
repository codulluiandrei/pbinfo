#include <iostream>
#include <fstream>
using namespace std;
ifstream f("porumbei.in");
ofstream g("porumbei.out");
char v[262145]; /// vectorul in care vom marca resturile gasite
long long m,n,a,x,r,p,q,r1,i;
int main()
{
    f>>m>>n;
    v[1/8]=v[1/8] | 1<<(1%8); /// (m^0)%n=1, deci marcam restul 1 ca intalnit
    a=1;
    r=1;
    while(1)
    {
        r=(r*m)%n;
        if((v[r/8] & (1<<(r%8)))!=0) /// daca bitul pe care ar trebui sa retinem restul e deja setat
        {
            q=a; /// inseamna ca inainte a mai fost un rest egal cu r, deci ne oprim
            break;  /// l-am gasit pe q asa ca ne oprim
        }
        else
            v[r/8]=v[r/8] | (1<<(r%8));
        a++;
    }
    if(r==1)
        p=0;
    else
        {
            r1=1;
            for(i=1;i<q;i++)
            {
                r1=(r1*m)%n;
                if(r1==r)
                {
                    p=i;
                    break;
                }
            }
        }
    g<<p<<" "<<q;
    return 0;
}