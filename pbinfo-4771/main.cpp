#include <fstream>
using namespace std;
ifstream fin("institut.in");
ofstream fout("institut.out");
int categorie[100];// vector de frecventa pe categorie
struct obiect
{
    int categ,mat,nr;
} ob[20000];
int nrs,nr_ob,cerinta;// nrs- nr de santiere,nr_ob- nr de descoperiri
void afisare1()
{
    int i;
    for(i=1; i<=99; i++)
        if(categorie[i])
            fout<<i<<" "<<categorie[i]<<"\n";
}
void afisare2()
{
    int i,j;
    fout<<nr_ob<<"\n";
    for(i=1; i<nr_ob; i++)
        for(j=i+1; j<=nr_ob; j++)
            if(ob[i].categ>ob[j].categ)
                swap (ob[i],ob[j]);
            else if(ob[i].categ==ob[j].categ&&ob[i].mat>ob[j].mat)
                swap (ob[i],ob[j]);
    for(i=1; i<=nr_ob; i++)
        fout<<ob[i].categ<<" "<<ob[i].mat<<" "<<ob[i].nr<<"\n";
}
int main()
{
    int c,m,n,nd,j;
    fin>>cerinta>>nrs;
    for(int i=1; i<= nrs; i++)
    {
        fin>>nd;
        j=1;
        while(j<=nd)//c - categorie, m-material, nd -numar de valori din sir
        {
            nr_ob++;
            fin>>c>>m;
            ob[nr_ob].categ=c;
            j=j+2;
            ob[nr_ob].mat=m;
            fin>>n;
            j++;
            if(n>0)
            {
                categorie[c]+=n; // n exemplare de categoria c
                ob[nr_ob].nr+=n;
                fin>>n;
                j++;
            }
            else
            {
                categorie[c]++; // 1 exemplar de categoria c
                ob[nr_ob].nr++;
            }
        }
    }
    if(cerinta==1)
        afisare1();
    else afisare2();
    return 0;
}