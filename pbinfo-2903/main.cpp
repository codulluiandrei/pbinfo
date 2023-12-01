#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("smartphone1.in");
ofstream fout("smartphone1.out");

int A[10][10] = {
//   0 1 2 3 4 5 6 7 8 9
    {0,0,0,0,0,0,0,0,0,0}, // 0
    {0,0,1,0,1,1,0,0,0,0}, // 1
    {0,1,0,1,1,1,1,0,0,0}, // 2
    {0,0,2,0,0,5,6,0,0,0}, // 3
    {0,1,1,0,0,1,0,1,1,0}, // 4
    {0,1,1,1,1,0,1,1,1,1}, // 5
    {0,0,1,1,0,1,0,0,1,1}, // 6
    {0,0,0,0,1,1,0,0,1,0}, // 7
    {0,0,0,0,1,1,1,1,0,1}, // 8
    {0,0,0,0,0,1,1,0,1,0}  // 9
};

int main()
{
    int cnt = 0 , x , n;
    fin >> n;
    for(int i = 1; i <= n ; i ++)
    {
        fin >> x;
        bool ok = true;
        int a = x % 10;
        x /= 10;
        while(x > 0)
        {
            int b = x % 10;
            if(A[a][b] == 0)
                ok = false;
            x /= 10;
            a = b;
        }
        if(ok)
            cnt ++;
    }
    fout << cnt;
    fin.close();
    fout.close();
    return 0;
}
