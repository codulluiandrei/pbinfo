//Problema cifre, solutie oficiala, prof. Ionel Maftei
#include <fstream>
using namespace std;
ifstream fin("cifre.in");
ofstream fout("cifre.out");
int n,i,j,x,c,cif,v[21],k,fr[10],img,maximg,nrap;
int main()
{
    fin>>c;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>x;
		k=0;
        while(x)
        {
            cif=x%10;
            if(cif%2==0)
                v[++k]=cif/2;
            v[++k]=cif;
            x=x/10;
        }
        if(c==1)
        {
            if(i<n)
            {
                for(j=k; j>=1; j--)
                    fout<<v[j];
                fout<<' ';
            }
            else if(i==n)
            {
                for(j=k; j>=1; j--)
                    fout<<v[j];
                fout<<'\n';
            }
        }
        else if(c==2)
        {
            for(j=0; j<=9; j++)
                fr[j]=0;
            for(j=1; j<=k; j++)
                fr[v[j]]++;
            img=0;
            for(j=0; j<=9; j++)
            {
                if(fr[j]>0)
                {
                    cif=fr[j]%10;
                    img=img*10+cif;
                }
            }
            if(img>maximg)
            {
                maximg=img;
                nrap=1;
            }
            else if(img==maximg)
            {
                nrap++;
            }
        }
        for(j=1; j<=21; j++)
            v[j]=0;
    }
    if(c==2)
        fout<<maximg<<" "<<nrap<<endl;
    return 0;
}