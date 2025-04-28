#include <fstream>
#define Nmax 2000000
using namespace std;
ifstream fin("ghirlande.in");
ofstream fout("ghirlande.out");
long cerinta, i , n, first, last, x, y, ap[2000005], ant;
long a[2000005],b[2000005],poza[2000005],pozb[2000005];
int main()
{
    //citire
    fin>>cerinta;
    fin>>n;
    //punem toate ghirlandele in doi vectori de corespondenta (a si b) cu semnificatia: o ghirlanda care are un capat de culoare x are celalalt capat de culaore a[x] si cealalta ghirlanda care are un capat de culaore x are celalalt capat de culoare b[x]. Daca o culoare nu apare decat la o singura ghirlanda(adica aceasta este capatul lantului) b[x] va ramane 0.
    //in poza si pozb retinem pe ce pozitie a fisierului de intrare a aparut ghirlanda de culoare x
    for (i=1;i<=n;i++)
    {
        fin>>x>>y;
        if (a[x]==0)
        {
            a[x]=y;
            poza[x]=i;
        }
        else
        {
            b[x]=y;
            pozb[x]=i;
        }
        if (a[y]==0)
        {
            a[y]=x;
            poza[y]=i;
        }
        else
        {
            b[y]=x;
            pozb[y]=i;
        }
    }
    //rezolvam cerinta 1
    //parcurgem vectorul de corespondenta si cautam pozitiile care au o valoare diferita de 0 doar pe pozitia a[x].
    if (cerinta==1)
    {
        for (i=1;i<=Nmax;i++)
            if (a[i]!=0 && b[i]==0)
            {
                last=first;
                first=i;
            }
        fout<<first+last;
    }
    else
    {
        //pentru cerinta 2 cautam un capat la fel ca la cerinta 1 si parcurgem vectorul de corespondenta dupa cum urmeaza:
        //retinem de unde am venit ca sa nu ne intoarcem
        for (i=1;i<=Nmax;i++)
            if (a[i]!=0 && b[i]==0)
            {
                last=first;
                first=i;
            }
        if (first>last)
            first=last;
        fout<<poza[first]<<;
        ant=first;
        first=a[first];
        while (b[first]!=0)
        {
            if (a[first]==ant)
            {
                ant=first;
                fout<<pozb[first]<<;
                first=b[first];
            }
            else
            {
                ant=first;
                fout<<poza[first]<<;
                first=a[first];
            }
        }
    }
    return 0;
}