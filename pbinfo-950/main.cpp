#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f ("cerc3.in");
ofstream g ("cerc3.out");
int n;
struct cerc
{
    int a, b;
};
cerc v[310];
void citire ()
{
    f>>n;
    int r, o;
    for (int i=1; i<=n; i++)
    {
        f>>o>>r;
        v[i].a=o-r;
        v[i].b=o+r;
    }
}
bool comp (cerc x, cerc y)
{
    return x.b<y.b;
}
void rez ()
{
    int x, nr=1;
    x=v[1].b;
    for (int i=1; i<n; i++)
    {
        if (x<v[i+1].a)
        {
            nr++;
            x=v[i+1].b;
        }
    }
    g<<nr;
}
int main ()
{
    citire ();
    sort (v+1, v+n+1, comp);
   // for (int i=1; i<=n; i++) cout<<v[i].a<<<<v[i].b<<endl;
    rez ();
    return 0;
}
