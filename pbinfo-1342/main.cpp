// Back: 20p
// Pd: 100p
#include<fstream>
using namespace std;
#define dim 301
ifstream in("nrsubsircresc.in");
ofstream out("nrsubsircresc.out");
long long sol[dim]; /// sol[i] = nr. de subsiruri strict crescatoare care au ultimul element v[i]
long long v[dim];
long long n;
int main()
{
    long long i,j,s;
    //
    in>>n;
    for(i=0; i<n; ++i) in>>v[i];
    //
    for(i=0; i<n; ++i)
    {
        sol[i] = 1; /// v[i] de unul singur
        for(j=0; j<i; ++j)
            if(v[i] > v[j]) /// daca v[i] este mai mare decat un predecesor de-al sau
                sol[i] += sol[j]; /// acesta ii poate continua toate sirurile
    }
    s=0;
    for(i=0; i<n; ++i) s += sol[i];
    out<<s<<"\n";
    return 0;
}