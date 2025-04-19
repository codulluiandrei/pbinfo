#include"iostream"
using namespace std;
typedef unsigned long long LL;
bool esteprim(LL a)
{
    if(a < 2)
        return false;
    if(a == 2)
        return true;
    if((a & 1) == 0)
        return false;
    for(LL i=3 ; i*i<=a ; ++i)
        if(a % i == 0)
            return false;
    return true;
}
LL putere(LL baza, LL exponent)
{
    LL rez = baza;
    for(LL i = 1 ; i < exponent ; ++i)
            rez *= baza;
        return rez;
}
int main()
{
    LL V[8]={}, k=0 , N, X[1000];
    for(LL y=1 ; y< 32 ; ++y)
        if(esteprim(putere(2, y)-1))
            V[k++]=(putere(2, y)-1)*putere(2,(y-1));
    cin>>N;
    for(int i=0 ; i< N ; ++i)
        cin>>X[i];
    for(int i=0 ; i< N ; ++i)
    {
        bool gasit = false;
        for(LL j=0 ; j< 8 ; ++j)
            if(X[i] == V[j])
            {
                cout<<"1 ";
                gasit = true;
            }
        if(!gasit)
            cout<<"0 ";
    }
}