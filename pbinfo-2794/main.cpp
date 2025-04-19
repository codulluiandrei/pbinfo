#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s[101], t[101], c[101];
    cin >> s >> c;
    if(strlen(s) != strlen(c))
        cout << "cod incorect";
    else
    {
        t[0] = s[0]; t[1] = '\0';
        for(int i = 1 ; i < strlen(s) ; i ++)
            if( (c[i] - '0') % 2 == 0 )
            {
                char tmp[101];
                strcpy(tmp , t);
                t[0] = s[i];
                strcpy(t + 1 , tmp);
            }
            else
            {
                int n = strlen(t);
                t[n] = s[i]; 
                t[n + 1] = '\0';
            }
        cout << t;
    }
    return 0;
}