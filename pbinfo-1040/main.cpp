// sursa prof. Zoltan Szabo - 100 puncte
#include <fstream>
#include<iostream>
using namespace std;
int c[1003][2];   // c si c1 memoreaza doua stari consecutive ale clepsidrului
int main()
{   int n,b,i,k,timp,stare,sus,jos,bsus,bjos;
    ifstream fin ("clepsidru.in");
    ofstream fout("clepsidru.out");
    fin>>n>>b;
    fout<<n+b-1<<"\n";
    sus=0;     // pozitia celui mai de sus bob
    bsus=b;    // boabe sus
    jos=0;     // pozitia celui mai de jos bob
    bjos=1;    // valoare initiala din oficiu atatea boabe sunt jos,
               // cand nu s-a ajuns la fundul clepsidrului
    fin>>k;
    for (i=0;i<k;++i)
    {   fin>>timp>>stare;
        if (stare==1)
        {   jos=jos+timp;
            if (jos<n) //in acest caz boabele nu au timp sa ajunga pana jos
            {   bjos=1;
                bsus=b-jos; // restul a ramas sus
                if (bsus<=0)     // iar daca acest numar e negativ
                {   sus=1-bsus;      //corectam nivelul de sus
                    bsus=1;          // numarul de boabe va fi 1
                }
            }
            else    // in acest caz boabele se acumuleaza jos
            {   bjos=bjos+jos-n; // numarul boabelor  calculate
                jos=n;       // boabele se acumuleaza la nivelul n
                if (bjos>=b)    // daca s-a calculat mai mult decat exista
                {   sus=n;   // atunci
                    bjos=b;  // toate boabele sunt jos
                    bsus=1;  // valoare din oficiu
                }
                else
                {   sus=0;
                    bsus=b-bjos-n+1;  // atatea boabe au ramas sus
                    if (bsus<=0)     // iar daca acest numar e negativ
                    {   sus=1-bsus;      //corectam pozitia
                        bsus=1;          // numarul de boabe va fi 1
                    }
                }
            }
        }
        else
        {   sus=sus-timp;
            if (sus>0) //     comentariile la fel c si la stare==1
            {   bsus=1;
                bjos=b-n+sus; // atatea boabe sunt jos
                if (bjos<=0)     // iar daca acest numar e negativ
                {   jos=n+bjos-1;      //corectam nivelul de jos
                    bjos=1;          // numarul de boabe va fi 1
                }
            }
            else    //
            {   bsus=bsus-sus; //
                sus=0;       // boabele se acumuleaza la nivelul n
                if (bsus>=b)    // daca s-a calculat mai mult decat exista
                {   jos=0;   // atunci
                    bsus=b;  // toate boabele sunt sus
                    bjos=1;  // valoare din oficiu
                }
                else
                {   jos=n;
                    bjos=b-bsus-n+1;  // atatea boabe au ramas sus
                    if (bjos<=0)     // iar daca acest numar e negativ
                    {   jos=n+bjos-1;      //corectam pozitia
                        bjos=1;          // numarul de boabe va fi 1
                    }
                }
            }
        }
    }
    if (sus==0 && jos==0)
        c[1][1]=bsus;
    if (sus==n && jos==n)
        c[n][2]=bjos;
    if (sus==0 && jos==n && stare==1)
    {
        c[1][1]=bsus;
        c[n][2]=bjos;
        for (i=2;i<=n;i++)
            c[i][1]=1;
    }
    if (sus==0 && jos==n && stare==2)
    {
        c[1][1]=bsus;
        c[n][2]=bjos;
        for (i=1;i<=n-1;i++)
            c[i][2]=1;
    }
    if(sus==0 && jos<n && stare==1)
    {
        c[1][1]=bsus;
        c[jos+1][1]=1;
        for (i=2;i<=jos;i++)
            c[i][1]=1;
    }
    if(sus==0 && jos<n && stare==2)
    {
        c[1][1]=bsus;
        for (i=1;i<=jos;i++)
            c[i][2]=1;
    }
    if (sus>0 && jos==n && stare==1)
    {
        c[n][2]=bjos;
        for(i=sus+1;i<=jos;++i)
            c[i][1]=1;
    }
    if (sus>0 && jos==n && stare==2)
    {
        c[n][2]=bjos;
        for(i=sus;i<jos;++i)
            c[i][2]=1;
    }
    if (sus>0 && jos<n && stare==1)
    {
        for(i=sus+1;i<=jos+1;++i)
            c[i][1]=1;
    }
    if (sus>0 && jos<n && stare==2)
    {
        for(i=sus;i<=jos;++i)
            c[i][2]=1;
    }
    for (i=1;i<=n;++i)
        fout<<c[i][1]<<" "<<c[i][2]<<"\n";
    fin.close();
    fout.close();
    return 0;
}