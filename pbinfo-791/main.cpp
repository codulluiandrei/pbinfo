#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("bifrunze1.in");
ofstream fout("bifrunze1.out");
struct nod{
    int info;
    nod * st, *dr;
};
int v[5000], n;
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
void Determinare(nod * p)
{
    if(p)
    {
        if(!p->st && !p->dr)
            v[n++] = p->info;
        Determinare(p->st);
        Determinare(p->dr);
    }
}
int main()
{
    nod * p = NULL;
    citire(p);
    Determinare(p);
    stergeTot(p);
    for(int i = 0 ; i + 1 < n ; i ++)
        for(int j = i + 1 ; j < n ; j ++)
            if(v[i]>v[j])
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
    for(int i= 0 ; i < n ; i ++)
        fout << v[i] << " ";
    return 0;
}