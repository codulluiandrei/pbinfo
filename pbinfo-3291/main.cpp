#include <iostream>
using namespace std;

unsigned int v[940000]; /// suficienti biti pentru a reprezenta orice valoare intre 0 si 30 mil
unsigned int duplicat;

int adauga (unsigned int x)
{
    int poz1 = x/32;  /// al catelea element din vectorul v va contine bitul cu numarul x
    int poz2 = x%32;  /// al catelea bit din v[poz1] este bitul al x-ulea
    unsigned int i=1;
    if (v[poz1] & (i<<poz2)) return 0;
    v[poz1] |= (i<<poz2);
    return 1;
}

int main()
{
    bool gasit=false;
    while(!gasit)
    {
        int x;
        cin >> x;
        if (!adauga(x))
        {
            duplicat=x;
            gasit=true;
        }
    }
    cout << duplicat;
    return 0;
}
