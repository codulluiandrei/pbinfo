#include <bits/stdc++.h>
#define LMax 1001
using namespace std;
char s[LMax];
int v[26], uz[26];
void eliminspatii()
{
int i;
for (i=0; s[i];)
    if (s[i]==' ')
       {s[i]=0;
        strcat(s,s+i+1);
       }
       else i++;
}
void detvar()
{
int i;
for (i=0; s[i]; i++)
    if (s[i]>='a' && s[i]<='z')
       uz[s[i]-'a']=1;
}
int main()
{
  int i, semn;
  int e=0;
  ifstream fin("eval.in");
  ofstream fout("eval.out");
  fin.getline(s,LMax);
  fin.close();
  for (i=0; i<26; i++) v[i]=i+1;
  eliminspatii();
  detvar();
  i=0;
  if (s[i]=='+')
     {
      if (s[i+1]!='+') {cout<<"Eroare in expresie\n"; return 0;}
      if (s[i+2]>'z' || s[i+2]<'a'){cout<<"Eroare in expresie\n"; return 0;}
      v[s[i+2]-'a']++;
      e=v[s[i+2]-'a'];
      i+=3;
     }
    else
    if (s[i]=='-')
     {
      if (s[i+1]!='-') {cout<<"Eroare in expresie\n"; return 0;}
      if (s[i+2]>'z' || s[i+2]<'a'){cout<<"Eroare in expresie\n"; return 0;}
      v[s[i+2]-'a']--;
      e=v[s[i+2]-'a'];
      i+=3;
    }
    else
    {
    if (s[i]>'z' || s[i]<'a'){cout<<"Eroare in expresie\n"; return 0;}
    e=v[s[i]-'a'];
    i++;
    }
    if (s[i]=='+'&& s[i+1]=='+')
       {v[s[i-1]-'a']++;
        i+=2;}
        else
        if (s[i]=='-'&& s[i+1]=='-')
           {v[s[i-1]-'a']--;
            i+=2;}
    //+/- operand
    while (s[i])
          {
           if (s[i]=='+') semn=1;
              else
              if (s[i]=='-') semn=-1;
                 else
                 {cout<<"Eroare in expresie\n"; return 0;}
           i++;
           //ma ocup de operand
           if (s[i]=='+')
              {
              if (s[i+1]!='+') {cout<<"Eroare in expresie\n"; return 0;}
              if (s[i+2]>'z' || s[i+2]<'a'){cout<<"Eroare in expresie\n"; return 0;}
              v[s[i+2]-'a']++;
              e=e+semn*v[s[i+2]-'a'];
              i+=3;
              }
              else
              if (s[i]=='-')
              {
              if (s[i+1]!='-') {cout<<"Eroare in expresie\n"; return 0;}
              if (s[i+2]>'z' || s[i+2]<'a'){cout<<"Eroare in expresie\n"; return 0;}
              v[s[i+2]-'a']--;
              e=e+semn*v[s[i+2]-'a'];
              i+=3;
              }
              else
              {
              if (s[i]>'z' || s[i]<'a'){cout<<"Eroare in expresie\n"; return 0;}
               e=e+semn*v[s[i]-'a'];
               i++;
              }
              if (s[i]=='+'&& s[i+1]=='+')
                 {v[s[i-1]-'a']++;
                 i+=2;}
                 else
                 if (s[i]=='-'&& s[i+1]=='-')
                 {v[s[i-1]-'a']--;
                 i+=2;}
         }
   fout<<e<<'\n';
   for (i=0; i<26; i++)
       if (uz[i])
          fout<<v[i]<<'\n';
     fout.close();
   return 0;
}