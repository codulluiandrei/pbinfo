#include <iostream>
using namespace std;
int a, b, c, s1 = 0, s2 = 0, s3 = 0;
int main() {
	cin >> a >> b >> c;
    for (int i = a; i <= b; i++) 
        s1 = s1 + i;
   	for (int i = b; i <= c; i++)
        s2 = s2 + i;
    for (int i = a; i <= c; i++)
        s3 = s3 + i;
    cout << s1 << " " << s2 << " " << s3;
    return 0;
}