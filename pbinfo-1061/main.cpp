// autor Alin Burtza
#include <fstream>
#include <cstdlib>
#define Fin "cifru1.in"
#define Fou "cifru1.out"

using namespace std;

int main()
{
	ifstream IN(Fin); 
	ofstream OUT(Fou);
	int N;				//numarul discurilor
	int Apar[10];		//Apar[i] = 1 daca culoarea i apare pe cel putin un disc
	int MAX;            //cifra maxima
	int NrMin;			//numarul minim de mutari
	int Cif;			//cifra obtinuta in numarul minim de mutari
	int Cate;			//numarul posibilitatilor
	int i,j, Nr, x;
	//initializari
	for(i=0;i<=9;i++) Apar[i] = 0;

	//citesc datele de intrare si
	//determin cifrele care apar initial si cifra maxima
	IN>>N; MAX = 0; Cif = -1; Cate = 0;
	for(i=1;i<=N;i++)
	{
		IN>>x;
		Apar[x]++;
		if(MAX < x) MAX = x;
	}
	//calculez numarul de mutari pentru fiecare cifra care apare
	NrMin = 10 * N + 1;
	for(i=0;i<=9;i++) 
	{
			Nr = 0;
			for(j=0;j<=9;j++)
				if(Apar[j] && j!=i)
				  Nr += abs(j-i) <= 10 - abs(j-i) ? Apar[j]*abs(j-i) : Apar[j]*(10 - abs(j-i));
			if(Nr<NrMin) NrMin = Nr, Cif = i, Cate = 1;
			else if(Nr==NrMin) Cate++;
	}
	OUT<<MAX<<'\n'<<NrMin<<'\n'<<Cif<<'\n'<<Cate<<'\n';	
	
	IN.close();
	OUT.close();
	return 0;
}
