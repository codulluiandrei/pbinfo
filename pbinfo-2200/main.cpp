#include <iostream>
using namespace std;
int main() { 
	char x;    
	cin >> x;    
	if (x >= 'a' && x <= 'z')        
		cout << (char)(x - 32);    
	else        
		cout << x; 
}