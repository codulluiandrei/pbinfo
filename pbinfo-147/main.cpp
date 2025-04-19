#include <fstream>
using namespace std;
ifstream fin("expresie1.in");
ofstream fout("expresie1.out");
int f[1005], n, i, j, A, B, C, V, iA,iB,iC;
char o1, o2;
void cit(){
int i,k;
fin>>V>>n;
for(i=1;i<=n;i++){
fin>>k;
f[k]=i;
}
fin.get();
o1=fin.get();
o2=fin.get();
fin.close();
}
int evalexp(int A, int B){
float t;
if(o1=='+')
    if(o2=='+')
        t=V-(A+B);
        else
        t=(V-A)/(float)B;
    else
    if(o2=='+')
        t=V-A*B;
        else
        t=(float)V/(A*B);
if (t>0 && t==int(t))
  return (int)t;
return -1;
}
int rezolva(){
int E;
for(iA=0;iA<1001;iA++)
 if(f[iA]>0)
  for(iB=0;iB<1001;iB++)
   if(f[iB]>0)
    {
     iC=evalexp(iA,iB);
     if(iC<1001 && iC>=0 && f[iC]>0){
      fout<<f[iA]<<" "<<f[iB]<<" "<<f[iC];
      return 1;
     }
     }
return 0;
}
int main()
{
    cit();
    if(rezolva()==0)
        fout<<"0 0 0";
    fout.close();
    return 0;
}