#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("bimax.in");
ofstream fout("bimax.out");
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
int Maxim(nod * p)
{
	if(p != NULL)
	{
		int x = Maxim(p->st);
		int y = Maxim(p->dr);
		if(x < y)
			x = y;
		if(x < p -> info)
			x = p -> info;
		return x;
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
    fout << Maxim(p->st) << " " << Maxim(p->dr);
    stergeTot(p);
    return 0;
}