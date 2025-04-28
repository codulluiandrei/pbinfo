//Octavian Dumitrascu - 100 puncte
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int sf, liber, yy, m1, s1, h1, d, c, ss, n, ma, p, timp, start, stop, i, h[100005];
char s[10];
int main()
{
    freopen("tv.in", "r", stdin);
    freopen("tv.out", "w", stdout);
    scanf("%d\n%d\n", &p, &n);
    for (i=1; i<=n; i++)
    {
        scanf("%d ",&d);
        gets(s);
        h1=(s[0]-48)*10+s[1]-48;
        m1=(s[3]-48)*10+s[4]-48;
        s1=(s[6]-48)*10+s[7]-48;
        start = s1 + m1*60 + h1*60*60;
        stop = start + d;
        h[start]++;
        h[stop]--;
    }
            ss = 0;
            liber = 0;
            ma = 0;
            for (i = 0; i < 60*60*24; i++)
            {
                ss += h[i];
                if (ss > ma) {ma = ss; timp = i;}
                if (ss == 0) liber++;
            }
        if (p == 1) yy = liber;
            else yy = timp;
        strcpy(s,"");
        h1 = yy/3600;
        m1 = yy%3600/60;
        s1 = yy%60;
        s[0]=h1/10+48;
        s[1]=h1%10+48;
        s[2]=':';
        s[3]=m1/10+48;
        s[4]=m1%10+48;
        s[5]=':';
        s[6]=s1/10+48;
        s[7]=s1%10+48;
        s[8]='\0';
        printf("%s\n", s);
    return 0;
}