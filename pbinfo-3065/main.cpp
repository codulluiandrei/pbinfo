/**
    problema: trio
*/
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
ifstream f("trio.in");
ofstream g("trio.out");
int N,C,nr,ap[1000],c[4],max_identice,nr_ord,nr_grupuri;
bool grup[1000]= {0}; //cerinta2
int ultima_poz[1000],prima_poz[1000]= {0},max_echivalente; //cerinta3
int main()
{
    int i;
    f>>C>>N;
    for(int i=1; i<=N; i++)
    {
        f>>c[1]>>c[2]>>c[3];
        if(c[3]>c[1])
            swap(c[1],c[3]);
        nr=(c[1]*100+c[2]*10+c[3]);
        ap[nr]++;
        if(ap[nr]>max_identice)
            max_identice=ap[nr];
        sort(c+1,c+4);//ordonez cifrele de pe o piesa pentru a determina cele ce aprtin aceluiasi grup
        nr_ord=c[1]*100+c[2]*10+c[3];
        grup[nr_ord]=1;// vector de aparitii ptr grup
        if(prima_poz[nr_ord]==0)
            prima_poz[nr_ord]=i;//memorez primul nr de ordine al unei piese din grup
        else
            ultima_poz[nr_ord]=i;//memorez ultimul numar de ordine al unei piese din acelasi grup
    }
    if (C==1)
        g<<max_identice-1<<'\n';
    else
        if (C==2)
        {
            for(i=0; i<=999; i++)
                if(grup[i]) nr_grupuri++;
            g<<nr_grupuri<<'\n';
        }
    else
    {
        for(i=0; i<=999; i++)
            if(ultima_poz[i]-prima_poz[i]>max_echivalente)
                max_echivalente=ultima_poz[i]-prima_poz[i];
        g<<max_echivalente+1<<'\n';
    }
    return 0;
}