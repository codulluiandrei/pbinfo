#include <iostream>
using namespace std;
int log_2(unsigned long long x)
{
    int rez = 0;
    while(x) { x /= 2; ++rez; }
    return rez-1;
}
int main()
{
    unsigned long long n;
    cin >> n;
    // Orice numar n poate fi scris sub forma 2^a+l
    // Raspunsul pentru orice intrebare este l*2+1
    // Pe baza acestei observatii, exista doua posibilitati
    // de a calcula rezultatul
    // 1. Calculam efectiv l*2+1
    // 2. Mutam primul bit de 1 (citind numarul de la stanga la dreapta)
    //    si il ducem in coada
    // Solutia 1:
    cout << (n - ((unsigned long long)1 << (unsigned long long)log_2(n))) * 2 + 1;
    return 0;
}