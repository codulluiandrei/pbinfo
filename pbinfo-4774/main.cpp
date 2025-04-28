/// sursa Lift Alina Scutaru
#include <fstream>
using namespace std;
ifstream fin("lift.in");
ofstream fout("lift.out");
int n, cer, x,  a, b, c;
long long fv[10], maxi1, maxi2, mini;
int main()
{
    fin>>cer>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>x;
        do{
            fv[x%10]++;
            x/=10;
        }while(x);
    }
    for(int i=0;i<=9;i++){
        if(fv[i]>maxi1){maxi2=maxi1;
                        maxi1=fv[i];
                        }
        else if(fv[i]>maxi2)maxi2=fv[i];
        if(fv[i])
            if(mini==0 || fv[i]<mini)mini=fv[i];
                        }
    if(cer==1){
        a=0;
        while(fv[a]!=mini)a++;
        fout<<a;
                }
    else {
            for(int i=0;i<=9;i++)
                if(fv[i]==maxi1){b=c;c=i;}
            if (b==0) for(int i=0;i<=9;i++)
                        if(fv[i]==maxi2)b=i;
            if (b>c)swap(b,c);
            fout<<b<<" "<<c;
        }
    return 0;
}