#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream f("inserarechar.in");
ofstream g("inserarechar.out");
char s[512],c[16],t[512],*p;
int i, OK;
int main()
{
    f >> c;
    f.get();
    f.get(s,256);
    for(i = strlen(c); i >= 1; i--)
        c[i] = c[i-1];
    c[0] = ' ';
    c[strlen(c)] = ' ';
    for(i = strlen(s); i >= 1; i--)
        s[i] = s[i-1];
    s[0] = ' ';
    s[strlen(s)] = ' ';
    p = strstr(s,c);
    OK = 0;
    while(p)
    {
        strcpy(t,p + strlen(c) - 1);
        p[strlen(c)-1] = '?';
        strcpy(p + strlen(c),t);
        p = strstr(s,c);
        OK = 1;
    }
    strcpy(s,s + 1);
    s[strlen(s) - 1] = NULL;
    if (!OK) g << "NU APARE";
        else g << s;

    return 0;
}
