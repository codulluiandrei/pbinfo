#include <fstream>
using namespace std;
ifstream in("tbile.in");
ofstream out("tbile.out");
long long n,x[64000],y,k,m,v,p,br,c,nivg,nivr;
long long s=0;
void AdunaRosu(long long f)
{
    long long r=k-1,t;
    if(br+r<=f){
        t=(f-br-r)/m;
        s+=(br+r)*(t+1)+m*t*(t+1)/2;
        br+=m*(t+1);}
}
int main()
{
    in>>v>>n>>m;
    if(v==2)
        in>>c;
    x[1]=1;x[2]=3;
    y=4;p=3;
    k=2;nivg=2;
    br=c;
    while(x[k]+y<=n)
    {
        k++;
        nivg++;
        if(nivg>m)nivg=1;
        x[k]=x[k-1]+y;
        if(nivg==c) s+=x[k];
        AdunaRosu(x[k]-1);
        y++;
        if(y==x[p]){y++;p++;}
    }
    if(v==1)
        {
            br=n-k;
            if(br%m==0)
                out<<br/m;
            else
                out<<br/m+1;
            out<<' '<<br<<'\n';
        }
    else
    {
        if(x[k]<n)
            {
                k++;
                AdunaRosu(n);
            }
        out<<s<<'\n';
    }
    return 0;
}