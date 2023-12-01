// Solutie oficiala #3502 (hard_prime) -  Lorintz Alexandru, 9A, Colegiul National "Lucian Baga" Sebes

#include <bits/stdc++.h>

using namespace std;

ifstream f ("hard_prime.in");
ofstream g ("hard_prime.out");

typedef vector < int > Vec;

inline void Insert (Vec &v, int val) // functie ce insereaza un element intr-un vector astfel incat vectorul sa ramana sortat
{
    Vec::iterator it = lower_bound (v.begin(), v.end(), val);
    v.insert (it, val);
}

Vec prime; // vector in care retinem numerele prime
Vec::iterator it;

inline bool ok (int a) // verificarea primalitatii
{
    if (a == 0 || a == 1) return false; // 0 si 1 nu sunt prime
    if (a == 2 || a == 3) return true; // 2 si 3 sunt prime
    if (a % 2 == 0 || a % 3 == 0) return false; // Un numar divizibil cu 2 sau 3 nu e prim(2 si 3 au fost verificate deja).
    int rad = sqrt(a); // radical
    for (int i = 5; i <= rad; i += 6) // Vom trata toate numerele de forma 6 * k + 5 mai mici decat rad = sqrt(a) ( k incepe de la 0).
    if (a % i == 0 || a % (i + 2) == 0) return false; // In intervalul inchis determinat de 6 * k + 5 si 6 * k + 10 (6 * k + 11 = 6 * (k + 1) + 5 - urmatorul numar tratat )
    return true; // putem sa tratam doar cazurile in care a este divizibil cu un numar impar
    // a fiind si el un numar impar in acest punct.
    // Astfel, avem de verificat daca a este divizbil cu 6 * k + 5, 6 * k + 7, respectiv 6 * k + 9.
    // 6 * k + 9 este un multiplu de 3, iar a sigur nu este multiplu de 3 in acest punct, deci verificarea divizibilitatii lui a cu acesta este inutila.
    // Mai raman doar 6 * k + 5 si 6 * k + 7 ( i si (i + 2) ).
}

int main()
{
    int n, x;
    f >> n;
    while (n--)
    {
        f >> x;
        if ( ok(x) && !binary_search(prime.begin(), prime.end(), x) ) // daca x este prim si nu a fost gasit prin cautare binara in vectorul numerelor prime
        Insert(prime, x); // adaugam x in vector pe pozitia unde acesta trebuie sa se afle pentru ca vectorul sa ramana sortat
    }
    for (it = prime.begin(); it != prime.end(); ++it) g << *it << " "; // afisare
    f.close();
    g.close();
    return 0;
}
