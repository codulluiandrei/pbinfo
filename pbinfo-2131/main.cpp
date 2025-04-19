#include <bits/stdc++.h>
using namespace std;
ifstream f("ghiozdan.in");
ofstream g("ghiozdan.out");
const int NMax = 100002;
int d,k,t;
int a[NMax];
bool OK(int dim){   ///functia care verifica daca Iulica poate
                    ///lua un ghiozdan de capacitate dim pentru a ajunge la destinatie
                    ///Returneaza 1 daca este posibil si 0 daca nu poate ajunge la destinatie
    int drum_ramas = t;///variabila care retine cati km mai poate merge Iulica nemancat,
    				   ///initial, aceasta avand valoarea t
    for(int i = 1; i <= k; ++i)
        if(a[i] - a[i - 1] > dim)
            drum_ramas -= (a[i] - a[i - 1] - dim);
    if(drum_ramas < 0)
        return 0;
    return 1;
}
int cautbin(int lo,int hi){
    int mid;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        int ok1 = OK(mid);
        int ok2 = OK(mid - 1);
        if(ok1 == 1 && ok2 == 0){///daca se poate ajunge la patinoar cu g = mid si nu se poate cu g = mid - 1
                                ///insemna ca mid este valoarea minima pentru g
            return mid;
        }else
        if(ok1 == 1){
            hi = mid - 1;
        }else
        if(ok2 == 0){
            lo = mid + 1;
        }
    }
    return 0;
}
int main()
{
    f >> d >> k >> t;   /// se citesc datele
    a[0] = 0;           ///se pune pe pozitia zero, casa lui Iulica
    for(int i = 1; i <= k; ++i)
        f >> a[i];      ///se citesc magazinele
    a[++k] = d;         ///se adauga pozitia patinoarului
    int G = cautbin(0,d);
    g << G << '\n';
    return 0;
}