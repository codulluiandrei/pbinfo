#include <iostream>
#include <fstream>
using namespace std;
ifstream in("magic1.in");
ofstream out("magic1.out");
long long C;
long N,P;
int main()
{
    long i;
    long long nr;
    in>>C>>N>>P;
    N--;
    nr=1;
    while(N!=0){
        if(N%2==1)
        {
            nr=(nr*C)%P;
            if(nr==0)
                nr=P;
        }
        C=(C*C)%P;
        if(C==0)
            C=P;
        N/=2;
    }
    out<<nr;
    return 0;
}