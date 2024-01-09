#include <iostream>

int m[50][50];

int main()
{
    unsigned int n;

    std::cin >> n;

    for(size_t i = 0; i < n / 2 + 1; i += 2)
        for(size_t k = i; k < n - i; k++)
            m[i][k] = m[k][i] = m[n - i - 1][k] = m[k][n - i - 1] = 1;


    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
            std::cout << m[i][j] << ' ';
        std::cout << '\n';
    }

    return 0;
}
