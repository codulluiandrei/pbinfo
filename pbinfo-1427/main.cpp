// manager - solutie oficiala - 100 pct
#include <fstream>
#include <algorithm>
#define MAX 100005
using namespace std;
ifstream fin("manager.in");
ofstream fout("manager.out");
struct struct_A{long long int minut; bool esteInc;};
struct struct_B{long long int inc, sf;};
bool test_A(struct_A a, struct_A b)
{
    if(a.minut != b.minut)
        return a.minut<b.minut;
    else
        if(a.esteInc!=b.esteInc)
            return a.esteInc;
        else
            return false;
}
void citeste_A(struct_A sedinta[], long long int &nrSedinte)
{
    long long  inc,durata,timpPregatire;
    fin >> nrSedinte;
    for(int i=1;i<=nrSedinte;i++)
    {
        fin >> inc >> durata >> timpPregatire;
        sedinta[i*2-1].minut = inc - timpPregatire; sedinta[i*2-1].esteInc = true;
        sedinta[i*2].minut = inc + durata - 1; sedinta[i*2].esteInc = false;
    }
}
void rezolva_A()
{
    struct_A sedinta[MAX * 2];
    long long int nrSedinte,nrTure,nrMaxTure;
    nrTure = nrMaxTure = 0;
    citeste_A(sedinta,nrSedinte);
    sort(sedinta+1,sedinta+nrSedinte*2+1,test_A);
    for(int i=1;i<=nrSedinte*2;i++)
        if(sedinta[i].esteInc)
        {
            nrTure++;
            if(nrTure>nrMaxTure)
                nrMaxTure = nrTure;
        }
        else
            nrTure--;
    fout<<nrMaxTure;
}
bool test_B(struct_B a, struct_B b)
{
    if(a.inc != b.inc)
        return a.inc < b.inc;
    else
        return a.sf < b.sf;
}
void citeste_B(struct_B sedinta[],long long int &nrSedinte,long long int &timpSedinta)
{
    long long int aux, durata, inc, timpPregatire;
    fin>>nrSedinte;
    for(int i=1;i<=nrSedinte;i++)
    {
        fin >> inc >> durata >> timpPregatire;
        sedinta[i].inc = inc - timpPregatire;
        sedinta[i].sf = inc + durata - 1;
    }
    fin>>timpSedinta; fin>>aux;
    timpSedinta+=aux;
}
void rezolva_B()
{
    long long int nrSedinte, ultimulSf = 0, timpSedinta;
    struct_B sedinta[MAX];
    citeste_B(sedinta,nrSedinte,timpSedinta);
    sort(sedinta+1,sedinta+nrSedinte+1,test_B);
    for(int i=1;i<=nrSedinte;i++)
        if(sedinta[i].inc - ultimulSf - 1>=timpSedinta)
        {
            fout<<ultimulSf + 1;
            return;
        }
        else
            if(sedinta[i].sf > ultimulSf) ultimulSf = sedinta[i].sf;
    fout << ultimulSf + 1;
}
int main()
{
    char cerinta;
    fin>>cerinta;
    if(cerinta == 'a')
        rezolva_A();
    else
        rezolva_B();
    return 0;
}