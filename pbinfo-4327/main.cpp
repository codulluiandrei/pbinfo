#include <bits/stdc++.h>
using namespace std;
int v[]={0,1,0,7,6,5,4,3,2,1,0,7,6,5,4,3,2,1,0,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
int fr[118];
int x, maxx, ap, nr;
int main()
{
    ifstream f("chimie.in");
    ofstream g("chimie.out");
    while(f >> x)
    {
        fr[x]++;
        if(v[x] > maxx) maxx = v[x], nr = x;
         else if(v[x] == maxx && x > nr) nr = x;
    }
    g << nr << " " << fr[nr];
    return 0;
}