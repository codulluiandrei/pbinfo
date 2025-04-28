#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;
ifstream f("dvorak.in");
ofstream g("dvorak.out");
int N,Q,S,D;
char parola[510], cod[200],perm[50],sir[510];
void citeste()
{
    f>>Q;
    f>>perm;
    f>>parola;
}
void codificare()
{
    int i=0;
    for(char x='a'; x<='z'; x++)
        cod[x]=perm[i++];
}
void operatie1()
{
    for(int i=S-1; i<=D-1; i++)
        parola[i]=cod[parola[i]];
}
void operatie2()
{
    if(strstr(parola,sir)!=NULL)g<<"Da\n";
    else g<<"Nu\n";
}
int main()
{
    citeste();
    codificare();
    int op;
    for(int i=1; i<=Q; i++)
    {
        f>>op;
        if(op==1)
        {
            f>>S>>D;
            operatie1();
        }
        else
        {
            f>>sir;
            operatie2();
        }
    }
    return 0;
}