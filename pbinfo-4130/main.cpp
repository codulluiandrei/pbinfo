#include <fstream>

using namespace std;

ifstream f("rotire25.in");
ofstream g("rotire25.out");

int c, x, k;

int main(){
	f >> c >> x >> k;

	if (c == 1){
		int first = x;
		while (first >= 10){
			first /= 10;
		}
		x %= 10;
		// perioada 1
		if (x == 0 || x == 1 || x == 5 || x == 6) {
			k = 1;
		}
		// perioada 2
		else if (x == 4 || x == 9) {
			k %= 2;
			if (k == 0) k = 2;
		}
		// perioada 4
		else {
			k %= 4;
			if (k == 0) k = 4;
		}

		int ans = x;
		for (int i=1;i<k;i++){
			ans = (ans * x) % 10;
		}

		g << ans * first << '\n';
	}
	else{
		int last1 = -1, last2 = -1;
		bool is_5 = true;
		while (x != last2 && k){
			last2 = last1; 
			last1 = x;

			// aplicam transformarea
			int p = (is_5 ? 5 : 2);
			x *= p;

			int ans = 0;
			while (x){
				if (x % 10){
					ans = ans * 10 + x % 10;
				}
				x /= 10;
			}

			x = ans;

			k--;
			is_5 = !is_5;
		}

		if (k % 2 == 1){
			int p = (is_5 ? 5 : 2);
			x *= p;

			int ans = 0;
			while (x){
				if (x % 10){
					ans = ans * 10 + x % 10;
				}
				x /= 10;
			}

			x = ans;
		}

		g << x << '\n';
	}

	return 0;
}