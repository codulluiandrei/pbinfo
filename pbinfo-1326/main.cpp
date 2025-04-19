#include <iostream>
using namespace std;
int main()
{
    int a[1001],n,i;
    bool cr,de;
    cin>>n;
    for(i=0;i<n;++i)
        cin>>a[i];
    cr=de=false;
    for(i=0;i<n-1;++i)
        if (a[i]==a[i+1])
        {
            cout<<"NU";   //  daca gasim doua elementele egale, nu poate fi vale
            return 0;
        }
        else
            if (a[i]<a[i+1])
                if (de)
                    cr=true;  // am gasit elemente crescatoare se accepta numai daca avem deja parte descrescatoare
                else
                {
                    cout<<"NU";// elemente crescatoare si nu a fost parte descrescatoare
                    return 0;  // nu poate fi vale
                }
            else
                if (a[i]>a[i+1])
                    if (!cr)
                        de=true;   // am gasit elemente descrescatoare
                    else
                    {
                        cout<<"NU";// elemente descrescatoare dupa parte crescatoare
                        return 0;  // nu poate fi vale
                    }
    if (cr and de)
        cout<<"DA";  // sirul contine atat parte crescatoare cat si descrescatoare
    else
        cout<<"NU";  // nu are parte crescatoare
    return 0;
}