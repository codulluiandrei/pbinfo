#include <iostream>
#include <fstream>
using namespace std;
int max1[1000001], max2[1000001],n,v;
ifstream  fin("platou.in");
ofstream fout("platou.out");
//ofstream fout("platou.out");
int lcrt=1,lmax,valmax,rezmax;
int x,y;
int main()
{
    fin >> v >> n;
    if (v==1)
    {
        fin >> x;
        for (int i=1;i<=n-1;i++)
        {
            fin >> y;
            if(x==y)
                lcrt++;
            else
                lcrt=1;
            //cout << y << lcrt << endl;
            if (lcrt > lmax)
            {
                lmax = lcrt;
                valmax = x;
            }
            else
                if (lmax == lcrt)
                    if (x > valmax)
                        valmax = x;
            x = y;
        }
//        cout << lmax << ' ' << valmax;
        fout << lmax << ' ' << valmax;
        return 0;
    }
    fin >> x;
    for (int i=1;i<=n-1;i++)
    {
        fin >> y;
        if(x==y)
            lcrt++;
        else
        {
            if (lcrt >= max1[x])
            {
                max2[x] = max1[x];
                max1[x] = lcrt;
            }
            else
                if (lcrt > max2[x])
                    max2[x] = lcrt;
            lcrt = 1;
        }
        x = y;
    }
    if (lcrt >= max1[x])
            {
                max2[x] = max1[x];
                max1[x] = lcrt;
            }
            else
                if (lcrt > max2[x])
                    max2[x] = lcrt;
    for (int i=1000000;i>=0;i--)
    {
        //if (max1[i]>0)
        //    cout << i << ' ' << max1[i] << ' ' << max2[i] << endl;
        if (max1[i]+max2[i]>rezmax)
        {
            rezmax = max1[i]+max2[i];
            valmax = i;
        }
    }
//    cout << rezmax << ' ' << valmax <<endl;
    fout << rezmax << ' ' << valmax <<endl;
    return 0;
}