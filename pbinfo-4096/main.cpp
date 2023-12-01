// Gheorghe Liviu Armand
// 100 de puncte
// O(N)
#include<bits/stdc++.h>
using namespace std;
ifstream f("balba.in");
ofstream g("balba.out");
int v[100002],fv[12];
int main()
{
    int p,n,i,k1=0,k2=0,l,cif,b=0,k=0,mij=-1,par=1,d=-1,minim;
    f>>p>>n;
    for(i=1;i<=n;i++)
        f>>v[i];
    if(p==1)
    {
        for(i=1;i<=n;i++)
        {
            l=1;
            while(i<n&&v[i]==v[i+1])
                i++,l++;
            k1++;
            if(l>=2)
               k2++;
        }
        g<<k1<<'\n'<<k2;
    }
    else
    {
        for(i=1;i<=n;i++)
            fv[v[i]]++;
        for(i=0;i<=9;i++)
        if(fv[i]%2!=0)
            par=0;
        for(i=0;i<=9;i++)
        if(fv[i]!=0&&fv[i]>=2)
        {
            minim=i;
            break;
        }
        for(cif=9;cif>=0;cif--)
        {
            if(!(cif==0&&k==0))
            {
                for(i=1;i<=fv[cif]/2;i++)
                    g<<cif,k++;
            }
            if(fv[cif]%2==1)
            {
                if(b==0&&fv[cif]!=1&&!(cif==0&&k==0))
                {
                    if(cif>=mij)
                        g<<cif;
                    else
                    {
                        if(cif==minim)
                            d=cif;
                        else
                            g<<cif;
                    }
                    b=1;
                }
                else
                if(mij==-1)
                    mij=cif;
            }
            if(par==1&&fv[cif]>=4)
            {
                fv[cif]--;
                mij=cif;
                par=0;
            }
        }
        if(mij!=-1)
            g<<mij;
        for(cif=0;cif<=9;cif++)
        {
            if(!(cif==0&&k==0))
            for(i=1;i<=fv[cif]/2;i++)
            {
                g<<cif;
                if(cif==d)
                    g<<d,d=-1;
            }
        }
    }
    return 0;
}
