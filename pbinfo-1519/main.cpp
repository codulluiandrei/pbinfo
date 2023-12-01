#include <iostream>
#include <fstream>
using namespace std;
ifstream f("dans.in");
ofstream g("dans.out");
int main()
{
int n,t,c,s,i,tmin,tmax,nc;
f>>n;
s=0;// timpul total
tmin=15; // timp minim
tmax=0; // timp maxim
nc=0;//numar total de copii
for (i=1;i<=n;i++)
{f>>t>>c;
s=s+t;
nc=nc+c;
if (tmin>t) tmin=t;
if (tmax<t) tmax=t;
}
if (s<=90) {g<<"DA"<<endl;
            g<<90-s<<endl;}
else {g<<"NU"<<endl;
            g<<s-90<<endl;}
g<<nc<<endl;
g<<tmax<<" "<<tmin;
g.close();
}
