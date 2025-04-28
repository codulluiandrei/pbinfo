#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("inaltime1.in");
ofstream fout("inaltime1.out");
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
    if(p)
    {
        stergeTot(p->st);
        stergeTot(p->dr);
        delete p;
        p = NULL;
    }
}
int inaltime (nod * & p , int nc)
{
    if(p == NULL)
        return nc - 1;
    else
    {
        int x = inaltime(p -> st , nc + 1);
        int y = inaltime(p -> dr , nc + 1);
        if(x > y)
            return x;
        else
            return y;
    }
}
int main()
{
    nod * p = NULL;
    citire(p);
    fout << inaltime(p,1);
    return 0;
}