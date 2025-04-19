#include <iostream>
#include <fstream>
using namespace std;
ifstream f("divigrup.in");
ofstream g("divigrup.out");
int a[201], divi[201], i, j, k, n, x, d, p, aux;
int main()
{
    f >> n;
    for (i = 1; i <= n; i++)
    {
        f >> a[i];
        //se determină numărul de divizori folosind descompunerea în factori primi
        x = a[i];
        d = 2;
        p = 1;
        while (d * d <=x )
        {
            k = 0;
            while (x % d == 0)
            {
                k++;
                x /= d;
            }
            if (k) p *= (k + 1);
            d++;
        }
        if (x != 1) p *= 2;
        divi[i] = p;//se reține numărul de divizori pentru fiecare valoare citită
    }
    //se ordonează vectorul descrescător după numărul de divizori și la număr de divizori egali, crescător după valoare
    for (i = 1; i <= n-1; i++)
        for (j = i+1; j <= n; j++)
            if (divi[i] < divi[j])
            {
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
                aux = divi[i];
                divi[i] = divi[j];
                divi[j] = aux;
            }
            else if (divi[i] == divi[j] && a[i] > a[j])
                {
                    aux = a[i];
                    a[i] = a[j];
                    a[j] = aux;
                }
    //se numără câte divigrupuri există
    k = 0;
    for (i = 2; i <= n; i++)
        if (divi[i] != divi[i-1])
        k++;
    g << k+1 << '\n';
    //se identifică și apoi afișează fiecare divigrup, precedat de numărul de elemente ce-l compun
    i = 1;
    while (i <= n-1)
    {
        j = i + 1;
        while (divi[j] == divi[i] && j <= n)
            j++;
        if (j - i == 0 && i == n) g << 1 << ' ' << a[n];
         else {
                g << j-i << ' ';
                for (k = i; k <= j-1; k++)
                        g << a[k] << ' ';
                }
        i = j;
        g << '\n';
    }
    //cazul particular, când printre numerele citite se găsește o singură dată valoarea 1, care are un singur divizor
    if (j - i == 0 && i == n) g << 1 << ' ' << a[n];
    return 0;
}