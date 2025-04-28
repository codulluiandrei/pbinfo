#include <fstream>
#include <iostream>
#define INFINIT 2000000000
using namespace std;
ifstream fin("bilatime.in");
ofstream fout("bilatime.out");
struct nod{
    int info;
    nod * st, * dr;
};
struct elem{
	nod * adr;
	elem * next;
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
void Adauga(nod * ce, elem * & ultim)
{
	elem * aux = new elem;
	aux -> adr = ce;
	aux -> next = NULL;
	ultim -> next = aux;
	ultim = aux; 
}
void Elimina(elem * & prim)
{
	elem * aux = prim;
	prim = prim -> next;
	delete aux;
}
void BFS(nod * p)
{
	elem * prim, * ultim;
	prim  = new elem;
	ultim = prim;
	prim -> next = NULL;
	prim -> adr = p;
	while(prim != NULL)
	{
		nod * aux = prim -> adr;
		fout << aux -> info << " ";
		if(aux -> st != NULL)
			Adauga(aux -> st , ultim);
		if(aux -> dr != NULL)
			Adauga(aux -> dr , ultim);
		Elimina(prim);
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
    BFS(p);
    stergeTot(p);
    return 0;
}