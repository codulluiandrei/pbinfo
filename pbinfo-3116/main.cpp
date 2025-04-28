#include <fstream>
#define N 1000001
using namespace std;
ifstream fin("cifrab.in");
ofstream fout("cifrab.out");
char c;
 int A[N];
int  Mod(int  A[N], int b, int X)
{ int i;
  int R=0;
  for (i=A[0];i;i--)
    R=(b*R+A[i])%X;
  return R;
}
void citire( int &b, int A[N])
{
    int max=0,n=0;
    while(fin>>c)
    {
        if(c>='A' && c<='Z'){ A[++n]=int(c-'A'+10); A[0]++;}
        else { A[++n]=int(c-'0'); A[0]++;}
        if(max<A[n]) max=A[n];
    }
    b=(max?max+1:2);
}
int main()
{
    int n,b,S=0,x;
    citire(b, A);
    fout<<b<<"\n";
    x=Mod(A,b,b-1);
    char bc=(x<10?x+'0':x-10+'A');
    if (x==0) fout<<char(b-1<10?b-1+'0':b-1-10+'A');
    else fout<<bc;
}