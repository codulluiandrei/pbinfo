#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("tabel1.in");
ofstream g ("tabel1.out");
int val['z' + 1],apare[12],n,k,j,s,i,y;
char x;
int main()
{
    f >> n;
    for(i = 1; i <= n; i++)
    {
        f >> x >> y;
        val[x] = y;
    }
    while(f >> x)
        if(isdigit(x)) // daca e cifra
            apare[x - '0']++; // vector de freventa in care contorizez cifrele care apar
        else if(val[x]) // daca e litera si a fost modificata in tabel
            s += val[x] ; // adaug la suma
        else s += x; // daca e litera si nu a fost modificata,adaug la suma
    g << s << '\n';
    for(i = 0;i <= 9;i++)
        if(apare[i])
        k++;
    // am contorizat cate cifre am in sir
    for(i = 9,j = 1;j <= k / 2;i--)
        if(apare[i])
        g << i,j++;
    // afisez prima jumatate din numarul deal-vale
    if(k % 2 == 0)
        j = 1;
    else j = 0;
    for(i = 0;j <= k / 2;i++)
        if(apare[i])
        g << i,j++;
    // afisez a doua jumatate din numarul deal-vale
    return 0;
}