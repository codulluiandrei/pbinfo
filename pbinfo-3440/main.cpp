//Bodnariuc Danut
//O(n*log(mediaElementelor)) - 100p

#include <fstream>
#define MAX 100003
using namespace std;
ifstream fi("buldo.in");
ofstream fo("buldo.out");
long long H,h[MAX],N,i,C,Lama,s,LamaMax;
bool gasitC;
bool verif(long long H){  //returneaza true  daca cu lama
long long i,Lama=0;             //de inaltime  H se poate nivela
 for(i=1;i<=N;i++)
    {
      if(h[i]>=H)Lama+=h[i]-H;
      else
        if(Lama>=H-h[i])Lama-=H-h[i];
        else return false;
    }
  return true;
}
long long CautareBinara(){ //returneaza cel mai mic H
long long st,dr,mij;       //pentru care nu se poate nivela
st=1;dr=LamaMax;
while(st<dr){
    mij=(st+dr)/2;
    if(verif(mij)==true)st=mij+1;
    else dr=mij;
}
return dr;
}
int main()
{
    fi>>N;
    for(i=1;i<=N;i++)fi>>h[i];
    for(i=1;i<=N;i++)s+=h[i];
    LamaMax=s/N+1; //valoarea maxima pt. Lama este media aritm. a sirului
    fo<<CautareBinara()-1;
    return 0;
}
