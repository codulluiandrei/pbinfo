#include <fstream>
#include<cstring>
#include<algorithm>
using namespace std;
ifstream fin("criptare.in");
ofstream fout("criptare.out");
int n, i, c, j, poz, nr, A[101], ord[101], fr[26], amax, nraria;
char s[101], cs[101], cuv[101][101], rez[101], cmax;
int imax, jmax, kmax, undef;
void aria(char c)
{
     int i,j,unde,k;
     for(i=0; i<n; i++)
        for(j=i; j<n; j++)
        {
                unde=-1;///unde gasesc prima data acelasi caracter
                for(k=0; k<n; k++)
                    if(cuv[i][k]==c&&cuv[j][k]==c){
                    if(unde==-1)unde=k;
                    if(unde>=0&&(k-unde+1)*(j-i+1)>amax){amax=(k-unde+1)*(j-i+1);}
                    }
        }
}
int main()
{
    fin>>c>>s;
    if(c==1)
    {
        strcpy(cuv[0], s);
        n=strlen(s);
        ///permut circular
        for(i=1; i<n; i++)
        {
            for(int j=0; j<n-1; j++)
                cuv[i][j]=cuv[i-1][j+1];
            cuv[i][n-1]=cuv[i-1][0];
        }
        ///ordonare lexicografica
        for(i=0; i<n-1; i++)
            for(j=i+1; j<n; j++)
                if(strcmp(cuv[i], cuv[j])>0)swap(cuv[i], cuv[j]);
        for(i=0; i<n; i++)
            if(strcmp(cuv[i], s)==0)
            {
                poz=i;
                break;
            }
        for(i=0; i<n; i++)
            fout<<cuv[i][n-1];
        fout<<poz;
    }
    if(c==2)
    {
        ///determin prima cifra din stanga
        n=strlen(s);
        for(i=0; i<n; i++)
            if(s[i]>='0'&&s[i]<='9')
            {
                poz=i;
                break;
            }
        nr=0;
        for(i=poz; i<n; i++)
            nr=nr*10+(s[i]-'0');
        s[poz]='\0';
        n=strlen(s);
        for(i=0; i<n; i++)
            ord[i]=i;
        ///ordonez crescator caracterele din s
        strcpy(cs,s);
        for(i=0; i<n-1; i++)
            for(j=i+1; j<n; j++)
                if(s[i]>s[j]||s[i]==s[j]&&ord[i]>ord[j])
                {
                    swap(s[i],s[j]);
                    swap(ord[i],ord[j]);
                }
        ///construiesc sirul decriptat
        for(i=0; i<n; i++)A[i]=ord[i];
        int t=nr;
        for(i=0; i<n; i++)
        {
            rez[i]=cs[A[t]];
            t=A[t];
        }
        fout<<rez;
    }
    if(c==3)
    {
        strcpy(cuv[0], s);
        n=strlen(s);
        for(i=0; i<n; i++)fr[s[i]-'A']++;
        ///permut circular
        for(i=1; i<n; i++)
        {
            for(int j=0; j<n-1; j++)
                cuv[i][j]=cuv[i-1][j+1];
            cuv[i][n-1]=cuv[i-1][0];
        }
        ///ordonare lexicografica
        for(i=0; i<n-1; i++)
            for(j=i+1; j<n; j++)
                if(strcmp(cuv[i], cuv[j])>0)swap(cuv[i], cuv[j]);
        for(char c='A'; c<='Z'; c++)
            if(fr[c-'A']!=0)
            {
                aria(c);
            }
        fout<<amax;
    }
    return 0;
}