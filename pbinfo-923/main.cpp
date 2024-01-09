#include <iostream>
#include <cmath>
using namespace std;

struct Fractie{
	int numarator, numitor;
};

void Citire(Fractie & P);
void Afisare(Fractie P);
void Simplificare(Fractie & P);
int Cmmdc(int a , int b);
int FCmp(Fractie A , Fractie B);

int main()
{
	Fractie A , B;
	Citire(A), Citire(B);
	if(FCmp(A,B) > 0)
		Afisare(A);
	else
		Afisare(B);
}

int Cmmdc(int a , int b)
{
	if(b == 0)
		return a;
	else
		return Cmmdc(b , a % b);
}

void Citire(Fractie & P)
{
	cin >> P.numarator >> P.numitor;
	Simplificare(P);
}


void Afisare(Fractie P)
{
	cout << P.numarator << " " << P.numitor;
}

void Simplificare(Fractie & P)
{
	int x = Cmmdc(P.numarator, P.numitor);
	P.numarator /= x;
	P.numitor /= x;
}

int FCmp(Fractie A , Fractie B)
{
	// returneaza -1 , 0 sau 1
	if(A.numarator * B.numitor < A.numitor * B.numarator)
		return -1;
	if(A.numarator * B.numitor > A.numitor * B.numarator)
		return 1;
	return 0;
}
