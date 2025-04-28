#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("nrnod.in");
ofstream fout("nrnod.out");
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
int nrnod(nod * p)
{
	if(p != NULL)
	{
		int s = nrnod(p -> st) + nrnod(p -> dr);
		int nrd = 0;
		if(p->st)
			nrd ++;
		if(p->dr)
			nrd ++;
		if(nrd == 1)
			return s + 1;
		else
			return s;
	}
	else
		return 0;
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
    fout << nrnod(p);
    stergeTot(p);
    return 0;
}