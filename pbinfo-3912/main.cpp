#include <iostream>
using namespace std;
int n , x[20], A[20] , uz[20], pp[20];
bool Prim(int n)
{
	if(n < 2)
		return false;
	if(n == 2)
		return true;
	if(n % 2 == 0)
		return false;
	for(int d = 3 ; d * d <= n ; d ++)
		if(n % d == 0)
			return false;
	return true;
}
void Afisare(int L)
{
    for(int i = 1 ; i <= L ; i ++)
        cout << A[x[i]] << " ";
    cout << '\n';
}
bool ok(int k)
{
	if(k == 1)
		return true;
    if(uz[ x[k] ] == 1)
        return false;
    if(pp[x[k]])
        if(pp[x[k-1]])
            return false;
    return true;
}
void Back(int k)
{
    for(int i = 1 ; i <= n ; i ++)
    {
        x[k] = i;
        if(ok(k))
        {
            uz[i] = 1;
            if(k == n)
                Afisare(n);
            else
                Back(k+1);
            uz[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
		cin >> A[i], pp[i] = Prim(A[i]);
	for(int i = 1 ; i < n ; i ++)
		for(int j = i + 1 ; j <= n ; j ++)
			if(A[i] > A[j])
				swap(A[i] , A[j]), swap(pp[i] , pp[j]);
    Back(1);
    return 0;
}