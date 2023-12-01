#include <fstream>

using namespace std;

ifstream fin("smartphone.in");
ofstream fout("smartphone.out");

int main()
{
    int c , n , x , max = -1, max2 = -2;
    fin >> c >> n;
    for(int i = 1; i <= n ; i ++)
    {
        fin >> x;
        if(x > max)
            max2 = max, max = x;
        else
            if(x > max2)
                max2 = x;
    }
    if(c == 1)
        fout << max;
    else
        fout << max2;
    return 0;
}
