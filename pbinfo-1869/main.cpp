#include <fstream>
#include <cstring>
using namespace std;
int main ()
{
    char s[210], t[210], voc[]="aeiou";
    ifstream f("prosirz.in");
    ofstream g("prosirz.out");
    f.getline(s,210);
    int i, nr=0,n;
    strcpy(t,s);
    n=strlen(s);
    ///cerinta a)
    for(i=0; i<n; i++)
        if(strchr(voc,t[i]))nr++;
    g<<nr<<endl;
///cerinta b)
    t[n-1]='Z';
    for(i=0; i<n-1; i++)
        if((t[i+1]==' ') && (t[i]!=' '))t[i]='Z';
    g<<t<<endl;
    ///cerinta c)
    t[0]='\0';
    char *p, cuv[200][200];
    int k=0,j;
    p=strtok(s," ");
    while(p)
    {
        k++;
        strcpy(cuv[k],p);
        p=strtok(NULL, " ");
    }
    for(i=1; i<k; i++)
        for(j=i+1; j<=k; j++)
            if(strcmp(cuv[i],cuv[j])<0)swap(cuv[i],cuv[j]);
    strcpy(t,cuv[1]);
    for(i=2; i<=k; i++)
    {
        strcat(t," ");
        strcat(t, cuv[i]);
    }
    g<<t;
    return 0;
}