#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("postordine1.in");
ofstream fout("postordine1.out");
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
void postordine(nod * p)
{
	if(p != NULL)
	{
		postordine(p -> st);
		postordine(p -> dr);
		fout << p -> info << " ";
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
    postordine(p);
    stergeTot(p);
    return 0;
}