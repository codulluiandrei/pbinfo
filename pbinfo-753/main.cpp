#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("preordine1.in");
ofstream fout("preordine1.out");
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
void preordine(nod * p)
{
	if(p != NULL)
	{
		fout << p -> info << " ";
		preordine(p -> st);
		preordine(p -> dr);
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
    if(p -> st)
        preordine(p -> st);
    stergeTot(p);
    return 0;
}