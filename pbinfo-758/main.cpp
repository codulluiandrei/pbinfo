#include <fstream>
#include <iostream>
#define INFINIT 2000000000
using namespace std;
ifstream fin("biminprim.in");
ofstream fout("biminprim.out");
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
int prim(int x)
{
	if(x < 2)
		return 0;
	for(int d = 2 ; d * d <= x ; d ++)
		if(x % d == 0)
			return 0;
	return 1;
}
int Minim(nod * p)
{
	if(p != NULL)
	{
		int x = Minim(p->st);
		int y = Minim(p->dr);
		if(x > y)
			x = y;
		if(x > p->info && prim(p->info))
			x = p -> info;
		return x;
	}
	else
		return INFINIT;
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
    int x = Minim(p->st);
    int y = Minim(p->dr);
    if(x == INFINIT)
		x = -1;
	if(y == INFINIT)
		y = -1;
    fout << x << " " << y;
    stergeTot(p);
    return 0;
}