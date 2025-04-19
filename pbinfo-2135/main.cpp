//Cardas Daniela
#include <fstream>
using namespace std;
ifstream in("roua.in");
ofstream out("roua.out");
int N,P,R,i,nroua,p1,p2,a,b,v[2500],x,p,j,ct;
char c;
int main()
{
    in>>P;
    if(P==1)
    {
        in>>N>>R>>c;i=1;
        while(c=='r'&&i<N)in>>c,i++;
        if(c!='r'){p2=i;if(p2>=R)nroua=1;}
        if(c=='r'&&i==N){out<<0<<'\n';return 0;}
        for(i=p2+1; i<=N; i++)
        {
            in>>c;
            if(c!='r')
            {
                if(i-p2+1>R){nroua++;}
                p1=p2;p2=i;
            }
            else
            if(p1<=i-R&&i>=R&&p2>i-R){nroua++;}
        }
        out<<nroua<<'\n';
    }
    else
    {
        ///P=2
        in>>N>>R;
        a=N%R;b=N/R;
        if(N<=70)
        {
            long long p=1;
            for(i=1;i<=b;i++,p*=3);
            p=p*(2*a+R);
            out<<p<<'\n';
            return 0;
        }
        ///initializam vectorul de cifre cu numarul 2a+R
        x=2*a+R;i=0;
        while(x)v[++i]=x%10,x/=10;
        v[0]=i;
        ///inmultim vectorul de cifre v cu 3 de b ori
        for(i=1;i<=b;i++)
        {
            for(ct=0,j=1;j<=v[0];j++)
            {
                v[j]*=3;
                x=v[j]+ct;v[j]=x%10;ct=x/10;
            }
            if(ct)
            {
                v[0]++;v[v[0]]=ct;
            }
        }
        for(i=v[0];i>=1;i--)
            out<<v[i];
        out<<'\n';
    }
}