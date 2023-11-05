#include <iostream>
using namespace std;
int main() {
    for (short a = 1; a <= 5; ++a)
        for (short b = a + 1; b <= 6; ++b)
            for (short c = b + 1; c <= 7; ++c)
            	for (short d = c + 1; d <= 8; ++d)
            		for (short e = d + 1; e <= 9; ++e)
            			cout << a << b << c << d << e << d << c << b << a << "\n";
	return 0;
}