//Emanuela Cerchez - 100 puncte
#include <fstream>
#include <cstring>
#define LGMAX 256
using namespace std;
ifstream fin("smiley.in");
ofstream fout("smiley.out");
char s[LGMAX];
int rez;
int is_smiley(int&);
int main()
{int i;
 while (fin.getline(s,LGMAX))
       {
         for (i=0; s[i]; )
             if (strchr(":;>8",s[i]))
                 rez+=is_smiley(i);
                 else  i++;
       }
 fout<<rez<<'\n';
 fout.close();
 return 0;
}
int is_smiley(int& i)
{
  i++; //sar peste primul caracter
  while (s[i]=='-') i++; //sar peste -
  if (s[i] && strchr("[]()DPOX3",s[i])) return 1;//verific ultimul caracter
  return 0;
}