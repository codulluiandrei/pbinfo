#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char S[11];
int m , n , x[11];
void Afisare(int L)
{
    for(int i = 0 ; i < L ; i ++)
        cout << S[x[i]];
    cout << '\n';
}
bool ok(int k)
{
	if(k == 0)
		return true;
	if(strchr("aeiou" , S[x[k]]) != NULL && strchr("aeiou" , S[x[k-1]]) != NULL)
		return false;
    return true;
}
void Back(int k)
{
	int start = 0;
	if(k > 0)
		start = x[k-1] + 1;
    for(int i = start ; i < n ; i ++)
    {
        x[k] = i;
        if(ok(k))
        {
			if(k >= m - 1 && strchr("aeiou", S[x[k]]) == NULL)
				Afisare(k + 1);
            Back(k+1);
        }
    }
}
int main()
{
    cin >> S >> m;
    n = strlen(S);
    sort(S , S + n);
    Back(0);
    return 0;
}