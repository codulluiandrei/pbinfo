#include <bits/stdc++.h>
using namespace std;
ifstream fin("expresie10.in");
ofstream fout("expresie10.out");
char s[201];
int p, sum, x[200], k = 1;
int main()
{
    int i;
    fin >> s;
    x[0] = -1;
    for(i = 0; s[i]; i++)
        if(p >= 0)
        {
            if(s[i] == '[')
            {
                p++;
                x[k++] = -1;
                if (s[i + 1] == ']') break;///paranteza nu contine un numar!
            }
            else if(s[i] == ']')
            {
                p--;
                sum = 0;
                while(x[k] != -1)
                {
                    sum += x[k];
                    x[k--] = 0;
                }
                x[k++] = sum / 2;
            }
            else ///este cifra
            {
                if (s[i - 1] != '[') break;///numarul nu este precedat de paranteza deschisa!
                int c = 0;
                while(s[i] >= '0' && s[i] <= '9')
                    c = c * 10 + s[i++] - '0';
                if(s[i--] != ']') break;///nu urmeaza paranteza inchisa dupa numar!
                x[k] = c;
            }
        }
    if(p == 0 && !s[i])
    {
        sum = 0;
        while(x[k] != -1)
            sum += x[k--];
        fout << sum;
    }
    else fout << "expresie gresita";
    fin.close();
    fout.close();
    return 0;
}