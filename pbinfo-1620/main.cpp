// prof. Nicu Vlad
#include <algorithm>
#include <fstream>
#include <cstring>
#define N 205
#define M 10010
using namespace std;
ifstream cin("interesant.in");
ofstream cout("interesant.out");
char A[N][M], AX[M],AY[M];
bool viz[N];
bool verif(char A[], char B[])
{
    int x=strlen(A);
    int y=strlen(B);
    int i=0,j=0;
    bool ok=false;
    while(i<x&&j<y)
    {
        if(A[i]!=B[j]);
        else j++;
        i++;
        if(i==x && j<y) return false;
    }
    if(j==y) return true;
    return false;
}
int main()
{
    int cer=0,n;
    cin>>cer>>n;
    if(cer==1)
    {
        int   i=0,maxi=0;
       for(i=0; i<n; i++)
        {
            cin>>AX;
            int x=strlen(AX);
            if(x>maxi)
            {
                maxi=x;
                strcpy(AY,AX);
            }
            else if(x==maxi)
            {
                if(strcmp(AY,AX)>0) strcpy(AY,AX);
            }
        }
        cout<<AY;
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            cin>>A[i];
            int l=strlen(A[i]);
            for(int j=0;j<i;j++)
            {
                if(!viz[j])
                {
                    int k=strlen(A[j]);
                    if(l>=k)
                    {
                        if(verif(A[i],A[j])) viz[j]=1;
                    }
                    else
                    {
                        if(verif(A[j], A[i])) viz[i]=1;
                    }
                }
            }
        }
        int nr=n;
        for(int j=0; j<n; j++)
            if(viz[j]) nr--;
        cout<<nr<<"\n";
        for(int j=0; j<n; j++)
            if(!viz[j]) cout<<A[j]<<"\n";
    }
    return 0;
}