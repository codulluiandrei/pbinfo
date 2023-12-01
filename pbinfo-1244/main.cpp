
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector <int> vp,psta,pstb;
ifstream f("trapeze.in");
ofstream g("trapeze.out");
int n1,n2,a[100001],b[100001];
int i,j;
long long ariahdr, ariahst, ariamax, nrperechi, rez;
int main()
{
    cout << "Hello world!" << endl;
    f >> n1;
    for (i=0;i<n1;i++)
        f >> a[i];
    f >> n2;
    for (i=0;i<n2;i++)
        f >> b[i];
    i=j=0;
    while (i<n1 && j<n2)
        if (a[i]==b[j])
        {
            vp.push_back(a[i]);
            psta.push_back(i);
            pstb.push_back(j);
            i++;j++;
        }
        else
            if (a[i]<b[j])
                i++;
            else
                j++;

    nrperechi = vp.size();

    //cout << nrperechi << endl;
    //for (i=0;i<vp.size();i++)
    //    cout << vp[i]<<<<psta[i]<<<<pstb[i]<<endl;

    long long nrsta, nrstb, nrdra, nrdrb, baza1, baza2;
    for (i=0;i<vp.size();i++)
        {
            nrsta = psta[i];//cate puncte are in stanga pe a
            nrstb = pstb[i];//si pe b
            nrdra = n1 - 1 - psta[i];//cate puncte are in dreapta pe a
            nrdrb = n2 - 1 - pstb[i];//si pe b
            long long nrtrapst = nrsta*nrstb - i;
            long long nrtrapdr = nrdra*nrdrb - (nrperechi - i - 1);
            //cout << i <<  << nrtrapst <<  << nrtrapdr << endl;
            rez += nrtrapdr + nrtrapst;
        }
    cout << rez << endl;
    g << rez << endl;

    int xa1, xa2, xb1, xb2;

    // calculez aria trapezului cu inaltimea cea mai din stanga
    xa1 = xb1 = vp[0];
    nrdra = n1 - 1 - psta[0];//cate puncte are in dreapta a
    nrdrb = n2 - 1 - pstb[0];//cate puncte are in dreapta b
    //cout << nrdra <<  << nrdrb<<endl;
    if (nrdra==0 || nrdrb == 0)//evident
        ariahst = 0;
    else
        if (a[n1-1]!= b[n2-1])//punctele din capete nu sunt aliniate=>trapez cu ele
        {
            xa2 = a[n1-1];
            xb2 = b[n2-1];
            baza1 = xa2 - xa1;
            baza2 = xb2 - xb1;
            ariahst = baza1+baza2;
        }
        else    //punctele din capete sunt aliniate
        {
          if (nrdra==1 && nrdrb==1)//o singura pereche in dreapta aliniata=> niciun trapez spre dreapta
            ariahst=0;
          if (nrdra==1 && nrdrb>1)//1 punct pe a , mai multe pe b
            {
                xa2 = a[n1-1];//iau utimul si singurul de pe a
                xb2 = b[n2-2];//cu penultimul de pe b cu care sigur nu e aliniat
                baza1 = xa2 - xa1;baza2 = xb2 - xb1;
                ariahst = baza1+baza2;
            }
          if (nrdra>1 && nrdrb==1)//mai multe pe a, 1 pe b - analog
            {
                xa2 = a[n1-2];
                xb2 = b[n2-1];
                baza1 = xa2 - xa1;baza2 = xb2 - xb1;
                ariahst = baza1+baza2;
            }
          if (nrdra>1 && nrdrb>1)
            {
                xa2 = a[n1-1];//ultimul pe a, penultimul pe b
                xb2 = b[n2-2];
                baza1 = xa2 - xa1; baza2 = xb2 - xb1;
                ariahst = baza1+baza2;
                xa2 = a[n1-2];//penultimul pe a, ultimul pe b
                xb2 = b[n2-1];
                baza1 = xa2 - xa1; baza2 = xb2 - xb1;
                if (baza1+baza2 > ariahst)
                    ariahst = baza1+baza2;
            }

        }
    cout << ariahst<<endl;


    xa2 = xb2 = vp[nrperechi-1];
    nrsta = psta.size()-1; //cate puncte are in stanga pe a
    nrstb = pstb.size()-1; //cate puncte are in stanga pe b
   // cout << nrsta <<  << nrstb << endl;
    if (nrsta==0 || nrstb == 0)//evident
        ariahdr = 0;
    else
        if (a[0] != b[0])//punctele din capete nu sunt aliniate=>trapez cu ele
        {
            xa1 = a[0];
            xb1 = b[0];
            baza1 = xa2 - xa1;
            baza2 = xb2 - xb1;
            ariahdr = baza1+baza2;
        }
        else    //punctele din capete sunt aliniate
        {
          if (nrsta==1 && nrstb==1)//o singura pereche in dreapta aliniata=> niciun trapez spre dreapta
            ariahdr=0;
          if (nrsta==1 && nrstb>1)//1 punct pe a , mai multe pe b
            {
                xa1 = a[0];//iau primul si singurul de pe a
                xb1 = b[1];//cu al doilea de pe b cu care sigur nu e aliniat
                baza1 = xa2 - xa1;baza2 = xb2 - xb1;
                ariahdr = baza1+baza2;
            }
          if (nrsta>1 && nrstb==1)//mai multe pe a, 1 pe b - analog
            {
                xa1 = a[1];
                xb1 = b[0];
                baza1 = xa2 - xa1;baza2 = xb2 - xb1;
                ariahdr = baza1+baza2;
            }
          if (nrdra>1 && nrdrb>1)
            {
                xa1 = a[0];//primul pe a, al doilea pe b
                xb1 = b[1];
                baza1 = xa2 - xa1; baza2 = xb2 - xb1;
                ariahdr = baza1+baza2;
                xa1 = a[1];//penultimul pe a, ultimul pe b
                xb1 = b[0];
                baza1 = xa2 - xa1; baza2 = xb2 - xb1;
                if (baza1+baza2 > ariahdr)
                    ariahdr = baza1+baza2;
            }

        }
    cout << ariahdr<<endl;
    ariamax = ariahdr > ariahst? ariahdr: ariahst;
    cout << ariamax<<endl;
    g << ariamax<<endl;
    return 0;
}
