#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;
ifstream fin("magie.in");
ofstream fout("magie.out");
int N, C, A[5001];
int V[10001];
int main()
{
	fin >> C >> N;
	for(int i = 1 ; i <= N ; i ++)
	{
		fin >> A[i];
		assert(A[i] >= 1 && A[i] <= 5000);
	}
	int max;
    for(int i = 1; i <= 10000 ; i ++)
        V[i] = 0;
    max = -1;
    if(C == 1)
    {
        for(int i = 1 ; i <= N ; i ++)
            V[A[i]] ++;
        for(int i = 1 ; i <= 10000; i ++)
            if(V[i] > max)
            max = V[i];
    }
    if(C == 3)
    {
        for(int i = 1 ; i <= N ; i ++)
        {
            V[A[i]] ++;
            for(int d = 1 ; d <= A[i] ; d ++)
                if(A[i] % d == 0)
                V[A[i] + d] ++;
        }
        for(int i = 1 ; i <= 10000; i ++)
            if(V[i] > max)
            max = V[i];
    }
    if(C == 2)
    {
        for(int i = 1 ; i <= N ; i ++)
        {
            for(int j = 1 ; j <= 10000 ; j ++)
            {
                if(j < A[i])
                    V[j] = 0;
                else
                    if(j == A[i])
                    V[j] ++;
                    else
                    if(A[i] % (j - A[i]) != 0)
                    V[j] = 0;
                    else
                    V[j] ++;
                    if(V[j] > max)
                    max = V[j];	
                    }
        }
    }
    fout << max <<endl;
    cout << "C = " << C << ". Max = " << max <<endl;
	return 0;
}