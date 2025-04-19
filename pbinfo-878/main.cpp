#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("intervale4.in");
ofstream fout("intervale4.out");
int A[100005] , B[100005] , n , nrs;
bool Intersectie(int a , int b , int x , int y)
{
	//verificam daca intervalul [a,b] si intervalul [x,y] au intersectia nevida
	if(a <= x && x <= b)
		return true;
	if(a <= y && y <= b)
		return true;
	if(x <= a && a <= y)
		return true;
	if(x <= b && b <= y)
		return true;
	return false;
}
int main()
{
	fin >> n;
	nrs = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		nrs ++;
		fin >> A[nrs] >> B[nrs];
		while(nrs > 1 && Intersectie(A[nrs-1] , B[nrs-1] , A[nrs] , B[nrs]))
		{
			if(A[nrs-1] > A[nrs])
				A[nrs-1] = A[nrs];
			if(B[nrs-1] < B[nrs])
				B[nrs-1] = B[nrs];
			nrs --;
		}
	}
	fout << nrs << "\n";
	return 0;
}