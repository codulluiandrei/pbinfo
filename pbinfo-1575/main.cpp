#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdarg>
using namespace std;
ifstream in("paritate.in");
ofstream out("paritate.out");
//ofstream out("paritate.out");
char raj[60001];
int rong[60001];
int main()
{
    char t,bin;
    bool wrong=false;
    int nr1,ctr=0;
    int rongctr=0;
    while(in)
    {
        nr1=0;
        t=0;
        in>>bin;
        if(bin=='1') nr1++;
        for(register int i=6;i>=0;i--)
        {
            in>>bin;
            if(bin=='1')
            {
                nr1++;
                t+=pow(2,i);
            }
        }
        if(nr1%2)
        {
            wrong=true;
            rong[rongctr]=ctr;
            rongctr++;
        }
        if(!wrong)
        {
            raj[ctr]=t;
        }
        ctr++;
    }
    if(wrong)
    {
        out<<"NU\n";
        for(register int i=0;i<=rongctr-1;i++)
        {
            out<<rong[i]<<" ";
        }
    }
    else
    {
        out<<"DA\n";
        for(register int i=0;i<=ctr-2;i++)
        {
            if(raj[i]==10)
            {
                out<<'\n';
            }
            else
            {
                out<<raj[i];
            }
        }
    }
}