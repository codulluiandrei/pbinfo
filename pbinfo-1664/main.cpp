//SUBIECTUL III: palindrom ciclic - solutia oficiala a facultatii ( modificata la citire , afisare si la declararea vectorului care era prea mic )
#include <fstream>
using namespace std ;
ifstream fin ("palindrom_ciclic.in") ;
ofstream fout ("palindrom_ciclic.out") ;
void citireSir(int &n, int a[]){
	fin >> n;
	for (int i = 0; i < n; i++){
		fin >> a[i];
	}
}
//verifica daca o secventa (a sirului a) care incepe pe pozitia start si
//se termina pe pozitia end este palindrom sau nu
bool estePalindrom(int a[], int start, int end){
	int i = start;
	int j = end;
	//se verifica perechi de elemente (cu indici simetrici fata de mijlocul secventei)
	//cand se gaseste o pereche de elemente diferite se opreste cautarea
	while ((a[i] == a[j]) && (i < j)){
		i++;
		j--;
	}
	//daca s-au verificat toate perechile si toate au avut elemente egale
	if (i >= j)
		return true;
	else
		return false;
}
//determina numarul de permutari ciclice care transforma un sir a cu n numere în palindrom
//daca sirul nu se poate transforma in palindrom prin permutari circulare, se returneaza -1
int numarPermutari(int n, int a[]){
	//se "dubleaza" sirul, copiind toate elementele inca o data in sir
	for (int i = 0; i < n; i++)
		a[n + i] = a[i];
	bool gasit = false;
	int i = 0;
	while ((i < n) && !gasit){
		//se verifica daca secventa care incepe pe pozitia i si are n elemente
		//este palindrom sau nu
		gasit = estePalindrom(a, i, i + n - 1);
		i++;
	}
	if (gasit)
		return i - 1;
	else
		return -1;
}
//in cazul unui numar (primit ca parametru) pozitiv, afiseaza mesajul "da" si
//valoarea numarului
//in cazul unui numar (primit ca parametru) negativ, afiseaza mesajul "nu"
void afisare(int nr){
	if (nr >= 0)
		fout << "DA " << nr ;
	else
		fout << "NU" ;
}
//Program principal
int main()
{
	int nrElemente = 0;
	int sir[2001];
	citireSir(nrElemente, sir);
	int nrPerm = numarPermutari(nrElemente, sir);
	afisare(nrPerm);
	return 0;
}