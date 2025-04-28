/// Szabo Zoltan   Comlexitate O(n^2)    100 de puncte
#include <fstream>
using namespace std;
ifstream cin("birocratie.in");
ofstream cout("birocratie.out");
/*void tipar(int B[][302],int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            fout<<B[i][j]<<" ";
        fout<<endl;
    }
}
*/
int d,n,B[1002][1002],SUM, MAXIM[1002][1002],VECTMAX1[1002],VECTMAX2[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>B[i][j];
    for(int i=0 ; i<=n ; i++)
        for(int j=0 ; j<=n ; j++)
            MAXIM[i][j]=-2000000000;
    MAXIM[1][1]=B[1][1];
    for(int i=2 ; i<=n ; i++)
    {
        for(int j=1;j<=n;j++)
            VECTMAX1[j]=-2000000000;
        int l=i;
        int c=1;
        if(l-1>0 and MAXIM[l-1][c]+B[l][c]>VECTMAX1[c])
            VECTMAX1[c]=MAXIM[l-1][c]+B[l][c];
        if(c-1>0 and MAXIM[l][c-1]+B[l][c]>VECTMAX1[c])
            VECTMAX1[c]=MAXIM[l][c-1]+B[l][c];
        while(l>1 and c<n)
        {
            l--;c++;
            if(l-1>0 and MAXIM[l-1][c]+B[l][c]>VECTMAX1[c])
                VECTMAX1[c]=MAXIM[l-1][c]+B[l][c];
            if(c-1>0 and MAXIM[l][c-1]+B[l][c]>VECTMAX1[c])
                VECTMAX1[c]=MAXIM[l][c-1]+B[l][c];
            if(c-1>0 and VECTMAX1[c-1]+B[l][c]>VECTMAX1[c])
                VECTMAX1[c]=VECTMAX1[c-1]+B[l][c];
        }
        for(int j=1;j<=n;j++)
            VECTMAX2[j]=-2000000000;
        l=1;
        c=i;
        if(l-1>0 and MAXIM[l-1][c]+B[l][c]>VECTMAX2[c])
            VECTMAX2[c]=MAXIM[l-1][c]+B[l][c];
        if(c-1>0 and MAXIM[l][c-1]+B[l][c]>VECTMAX2[c])
            VECTMAX2[c]=MAXIM[l][c-1]+B[l][c];
        MAXIM[l][c]=max(VECTMAX1[c],VECTMAX2[c]);
        while(l<n and c>1)
        {
            l++;c--;
            if(c-1>0 and MAXIM[l-1][c]+B[l][c]>VECTMAX2[c])
                VECTMAX2[c]=MAXIM[l-1][c]+B[l][c];
            if(l-1>0 and MAXIM[l][c-1]+B[l][c]>VECTMAX2[c])
                VECTMAX2[c]=MAXIM[l][c-1]+B[l][c];
            if(c+1<=n and VECTMAX2[c+1]+B[l][c]>VECTMAX2[c])
                VECTMAX2[c]=VECTMAX2[c+1]+B[l][c];
            MAXIM[l][c]=max(VECTMAX1[c],VECTMAX2[c]);
        }
    }
    for(int j=2 ; j<=n ; j++)
    {
        for(int i=1;i<=n;i++)
            VECTMAX1[i]=-2000000000;
        int l=n;
        int c=j;
        if(l-1>0 and MAXIM[l-1][c]+B[l][c]>VECTMAX1[c])
            VECTMAX1[c]=MAXIM[l-1][c]+B[l][c];
        if(c-1>0 and MAXIM[l][c-1]+B[l][c]>VECTMAX1[c])
            VECTMAX1[c]=MAXIM[l][c-1]+B[l][c];
        while(l>1 and c<n)
        {
            l--;c++;
            if(l-1>0 and MAXIM[l-1][c]+B[l][c]>VECTMAX1[c])
                VECTMAX1[c]=MAXIM[l-1][c]+B[l][c];
            if(c-1>0 and MAXIM[l][c-1]+B[l][c]>VECTMAX1[c])
                VECTMAX1[c]=MAXIM[l][c-1]+B[l][c];
            if(c-1>0 and VECTMAX1[c-1]+B[l][c]>VECTMAX1[c])
                VECTMAX1[c]=VECTMAX1[c-1]+B[l][c];
        }
        for(int i=1;i<=n;i++)
            VECTMAX2[i]=-2000000000;
        l=j;
        c=n;
        if(l-1>0 and MAXIM[l-1][c]+B[l][c]>VECTMAX2[c])
            VECTMAX2[c]=MAXIM[l-1][c]+B[l][c];
        if(c-1>0 and MAXIM[l][c-1]+B[l][c]>VECTMAX2[c])
            VECTMAX2[c]=MAXIM[l][c-1]+B[l][c];
        MAXIM[l][c]=max(VECTMAX1[c],VECTMAX2[c]);
        while(l<n and c>1)
        {
            l++;c--;
            if(c-1>0 and MAXIM[l-1][c]+B[l][c]>VECTMAX2[c])
                VECTMAX2[c]=MAXIM[l-1][c]+B[l][c];
            if(l-1>0 and MAXIM[l][c-1]+B[l][c]>VECTMAX2[c])
                VECTMAX2[c]=MAXIM[l][c-1]+B[l][c];
            if(c+1<=n and VECTMAX2[c+1]+B[l][c]>VECTMAX2[c])
                VECTMAX2[c]=VECTMAX2[c+1]+B[l][c];
            MAXIM[l][c]=max(VECTMAX1[c],VECTMAX2[c]);
        }
    }
    cout<<MAXIM[n][n];
    return 0;
}