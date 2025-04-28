#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("biarbore.in");
ofstream fout("biarbore.out");
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
        fout << p -> st -> info <<" ";
    else
        fout << 0 <<" ";
    if(p -> dr)
        fout << p -> dr -> info <<" ";
    else
        fout << 0 <<" ";
    stergeTot(p);
    return 0;
}