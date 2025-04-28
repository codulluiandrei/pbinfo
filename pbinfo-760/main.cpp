#include <fstream>
#include <iostream>
#define INFINIT 2000000000
using namespace std;
ifstream fin("knivel1.in");
ofstream fout("knivel1.out");
struct nod{
    int info;
    nod * st, * dr;
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
int Sum(nod * p, int i , int k)
{
	// i reprezinta nivelul curent din arbore
	if(p)
	{
		if(i == k)
			return p->info;
		else
			return Sum(p->st , i + 1 , k) + Sum(p->dr , i + 1 , k);
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
    int k;
    citire(p);
    fin >> k;
    fout << Sum(p, 0 , k);
    stergeTot(p);
    return 0;
}