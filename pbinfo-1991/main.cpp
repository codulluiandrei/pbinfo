/// Solutie - Moca Andrei - 100p
#include <bits/stdc++.h>
int nr[100002]; /// nr[i] - nr de modalitati de a ajunge pe treapta i
int n, k;
int main()
{
	std::cin >> n >> k;
	nr[0] = 1;
	nr[1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= k && j < i; j++)
        {
            nr[i] += nr[i - j];
            if (nr[i] > 9001)
                nr[i] -= 9001;
        }
	std::cout << nr[n];
}
