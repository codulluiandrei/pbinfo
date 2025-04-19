#include<fstream>
#include<iostream>
using namespace std;
ifstream fin("joc.in");
ofstream fout("joc.out");
int n,v[40003],m;
int main()
{
    int i,x,cx,j,s;
    fin>>n;
for(i=1;i<=n;i++)
{ fin>>x;
cx=x; s=0;
while(cx>9)
    { s=s+cx%10;
       cx=cx/10;
     }
if (cx==s)
    { m++;
    v[m]=x;
      }
}
for(i=1;i<m;i++)
for(j=i+1;j<=m;j++)
if (v[i]>v[j])
swap(v[i], v[j]);
for(i=1;i<=m;i++)
fout<<v[i]<<" ";
fin.close();
fout.close();
return 0;
}