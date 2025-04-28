#include <iostream>
#include <iomanip>
using namespace std;
int n , m , A[21][21], T[21][21], lgmin;
const int di[]={0,0,1,-1}, dj[]={1,-1,0,0};
bool OK(int i ,int j , int H)
{
	if(i < 1 || i > n || j < 1 || j > m)
		return false;
	if(T[i][j] != 0)
		return false;
	if(A[i][j] < H)
		return false;
	return true;
}
void Back(int i , int j , int pas)
{
	T[i][j] = pas;
	if(i == n && j == m)
	{
		if(pas < lgmin)
			lgmin = pas;
	}
	else
		for(int k = 0 ; k < 4 ; k ++)
		{
			int iv = i + di[k], jv = j + dj[k];
			if(OK(iv , jv, A[i][j]))
				Back(iv , jv , pas + 1);
		}
	T[i][j] = 0;
}
int main()
{
	cin >> n >> m;
	for(int i = 1;  i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			cin >> A[i][j];
	lgmin = n * m + 1;
	Back(1 , 1 , 1);
	if(lgmin == n * m + 1)
		cout << "imposibil" << endl;
	else
		cout << lgmin << endl;
	return 0;
}