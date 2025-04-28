#include <iostream>
using namespace std;
int elim[100];
int main()
{
    char s[101];
    cin.getline(s , 101);
    int lastzero = -1, amcifrenenule = 0, cnt = 0;
    for(int i = 0 ; s[i] ; i ++)
    {
        if(s[i] == '0')
        {
            if(! amcifrenenule)
                elim[i] = 1, lastzero = i, cnt ++;
        }
        else
            if(s[i] > '0' && s[i] <= '9')
                amcifrenenule = 1;
            else
                elim[i] = 1, cnt ++;
    }
    if(! amcifrenenule && lastzero != -1)
        elim[lastzero] = 0, cnt --;
    if(cnt == 0)
        cout << "CORECT";
    else
    {
        if(! amcifrenenule && lastzero == -1)
            cout << "NaN";
        else
        {
            for(int i = 0 ; s[i] ; i ++)
                if(elim[i] == 0)
                    cout << s[i];
            cout << endl;
            for(int i = 0 ; s[i] ; i ++)
                if(elim[i] == 1 && s[i] != ' ')
                    cout << s[i] << " ";
            cout << endl;
        }
    }
    return 0;
}