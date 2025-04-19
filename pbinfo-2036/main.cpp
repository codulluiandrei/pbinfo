// Implementare: Cristi Dospra
// Punctaj: 100p
// Complexitate: O(N)
#include <fstream>
#include <cmath>
using namespace std;
/*
* N = suma ceruta pentru sirul cerut
* bestLen = numarul de caractere pe care il va avea sirul cerut
* currentLen = cate caractere am folosit pana acum
* las = ultimul caracter pus
*/
ifstream fin("nume1.in");
ofstream fout("nume1.out");
int N, bestLen, currentLen;
char last = 'A';
// functie ce verifica daca pot pune un anumit caracter
bool potPune(int trebuie, char c) {
    int sum = abs(last - c); // vad cat se adauga la suma daca pun caracterul meu
    int ramase = bestLen - currentLen - 1; //vad cate caractere imi mai raman de pus
    // daca o sa mai pot pune macar unul
    if (ramase > 0) {
        sum += max(abs(c - 'A'), abs(c - 'Z')); // pun 'A' sau 'Z', ce e mai departe de caracterul meu
        ramase--; //si raman cu unul mai putin
    }
    sum += ramase * 25; //de restul pun numa 'A' si 'Z' alternativ (ca sa scot suma maxima)
    //daca am obtinut o suma mai mare sau egala totul e ok
    if (sum >= trebuie)
        return true;
    //daca nu, nu
    return false;
}
int main() {
    fin >> N; //suma ceruta a sirului
    bestLen = (N / 25) + 1 + (N % 25 != 0); //numarul de caractere pe care il va avea sirul
    fout << 'A'; //primul element va fi mereu 'A'
    currentLen = 1; //am pus momentan un singur element
    int sum = 0; //suma pe care o dau elementele de pana acum
    while (currentLen < bestLen) {
        for (int i = 'A'; i <= 'Z'; ++i) { //incerc sa pun fiecare caracter, il iau pe primul care merge
            if (potPune(N - sum, i)) { //daca il pot pune
                if (currentLen == bestLen - 1 && sum + abs(last - i) != N) //daca e ultimul element, adaugat, atunci e unic
                    continue;
                sum += abs(last - i); // adaug la suma ce imi creeaza noul element
                fout << (char)i; //il afisez
                currentLen++; //il adaug la sir
                last = i; //el este acum ultimul adaugat
                break; //nu mai are rost sa continui
            }
        }
    }
    return 0;
}