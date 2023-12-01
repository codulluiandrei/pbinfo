#include <bits/stdc++.h>
using namespace std;

class InParser
{
private:
    FILE *fin;
    char *buff;
    int sp;

    char read_ch()
    {
        ++sp;
        if(sp==4096)
        {
            sp=0;
            fread(buff,1,4096,fin);
        }
        return buff[sp];
    }

public:
    InParser(const char* nume)
    {
        fin=fopen(nume,"r");
        buff=new char[4096]();
        sp=4095;
    }

    InParser& operator >> (int &n)
    {
        char c;
        while(!isdigit(c=read_ch())&&c!='-');
        int sgn=1;
        if (c=='-')
        {
            n=0;
            sgn=-1;
        }
        else
        {
            n=c-'0';
        }
        while(isdigit(c=read_ch()))
        {
            n=10*n+c-'0';
        }
        n*=sgn;
        return *this;
    }

    InParser& operator >> (long long &n)
    {
        char c;
        n=0;
        while(!isdigit(c=read_ch())&&c!='-');
        long long sgn=1;
        if(c=='-')
        {
            n=0;
            sgn=-1;
        }
        else
        {
            n=c-'0';
        }
        while(isdigit(c=read_ch()))
        {
            n=10*n+c-'0';
        }
        n*=sgn;
        return *this;
    }
};

class OutParser
{
private:
    FILE *fout;
    char *buff;
    int sp;

    void write_ch(char ch)
    {
        if(sp==50000)
        {
            fwrite(buff,1,50000,fout);
            sp=0;
            buff[sp++]=ch;
        }
        else
        {
            buff[sp++]=ch;
        }
    }

public:
    OutParser(const char* name)
    {
        fout=fopen(name,"w");
        buff=new char[50000]();
        sp=0;
    }
    ~OutParser()
    {
        fwrite(buff,1,sp,fout);
        fclose(fout);
    }

    OutParser& operator <<(int vu32)
    {
        if(vu32<=9)
        {
            write_ch(vu32+'0');
        }
        else
        {
            (*this) <<(vu32/10);
            write_ch(vu32%10+'0');
        }
        return *this;
    }

    OutParser& operator <<(long long vu64)
    {
        if(vu64<=9)
        {
            write_ch(vu64+'0');
        }
        else
        {
            (*this) <<(vu64/10);
            write_ch(vu64%10+'0');
        }
        return *this;
    }

    OutParser& operator <<(char ch)
    {
        write_ch(ch);
        return *this;
    }
    OutParser& operator <<(const char *ch)
    {
        while(*ch)
        {
            write_ch(*ch);
            ++ch;
        }
        return *this;
    }
};
InParser f ("num_sum_div.in");
OutParser g ("num_sum_div.out");

const int NN = 70715;
bool ciur[NN + 1];
int prime[32768], np, k1, k2, k3;

int main ()
{
    for (int i = 2; i * i <= NN; i++)
    if (ciur[i] == 0)
    for (int j = 2; i * j <= NN; j++)
    ciur[i * j] = 1;

    prime[++np] = 2;
    for (int i = 3; i <= NN; i += 2)
    if (ciur[i] == 0)
    prime[++np] = i;

    long long n, x, m, S;
    f >> n;
    while (n--)
    {
        f >> x;
        m = x, S = 1;
        int d = 1;
        while (m > 1)
        {
            long long f = 1, t = 1;
            while (m % prime[d] == 0)
                t += (f *= prime[d]), m /= prime[d];
            S *= t;
            d++;
            if (1LL * prime[d] * prime[d] > m && m > 1)
                    S *= (m + 1), m = 1;
        }
        if (S < 2 * x) k1++;
        else if (S == 2 * x) k2++;
        else if (S > 2 * x) k3++;
    }
    g << k1 << " " << k2 << " " << k3;
    return 0;
}
