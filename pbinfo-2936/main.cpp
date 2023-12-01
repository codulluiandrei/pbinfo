#include<bits/stdc++.h>
using namespace std;

ifstream in("amprenta.in");
ofstream out("amprenta.out");

long long cerinta,n,p,q,r,sol;

int main()
{
    in>>cerinta;
    if(cerinta==1)
    {
        in>>n;
        if(n%11>=6)
            out<<11-n%11<<'\n';
        else
            out<<n%11<<'\n';
    }
    else
    {
        in>>p>>q>>r;
        if(p>q)
            swap(p,q);
        while(p%11!=0 && p<=q)
        {
            if(p%11==r || 11-p%11==r)
                sol++;
            p++;
        }
        while(q%11!=0 && q>=p)
        {
            if(q%11==r || 11-q%11==r)
                sol++;
            q--;
        }
        if(p<=q)
        {
            if(r==0)
                sol+=q/11-p/11+1;
            else
                sol+=2*(q/11-p/11);
        }
        out<<sol<<'\n';
    }
    return 0;
}
