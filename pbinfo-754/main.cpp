#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("inordine1.in");
ofstream fout("inordine1.out");
struct nod{
    int info;
    nod * st, *dr;
};
void citire(nod * & p)
{
    int x;
    fin >> x;
    if(x == 0)
        p = NULL;
    else
    {
        p = new nod;
        p -> info = x;
        citire(p -> st);
        citire(p -> dr);
    }
}
void inordine(nod * p)
{
	if(p != NULL)
	{
		inordine(p -> st);
		fout << p -> info << " ";
		inordine(p -> dr);
	}
}
void stergeTot(nod * & p)
{
	if(p != NULL)
	{
		stergeTot(p -> st);
		stergeTot(p -> dr);
		delete p;
		p = NULL;
	}
}
int main()
{
    nod * p = NULL;
    citire(p);
    inordine(p);
    stergeTot(p);
    return 0;
}