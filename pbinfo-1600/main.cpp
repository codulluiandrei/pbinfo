#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream fin ("s_p_c_2.in");
ofstream fout ("s_p_c_2.out");
///sirurile de caractere incep cu indicativul de parte de propozitie
char sub[101][41],pred[101][41],cpl[101][41];///memoram subiect, predicat, complemente in cpl
int s,p,c;///cate subiecte, cate pred....
void sortare(char a[101][41],int n)
{
    char aux[41];
    for(int i = 1;i <= n-1; i++)
        for(int j = i+1;j <= n; j++)
            if(strcmp(a[i],a[j]) > 0)
            {
                strcpy(aux,a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], aux);
            }
}
int main()
{
    char a[256];
    while(fin >> a)
    {
        if(a[0] == 'S')
        {
            ++s;
            strcpy(sub[s], a+2);///copiem  pe linia s cuvantul format incepand cu cracterul de indice 2(adica al treilea)
        }
        else
            if(a[0] == 'P')
            {
                ++p;
                strcpy(pred[p], a+2);
            }
            else
            {
                ++c;
                strcpy(cpl[c], a+2);
            }
    }
    sortare(sub,s);
    sortare(pred,p);
    sortare(cpl,c);
    for(int i = 1;i <= s; i++)
        for(int j = 1;j <= p; j++)
            for(int m = 1; m <= c; m++)
                fout << sub[i] << " " << pred[j] << " " << cpl[m] << '\n';
       return 0;
}