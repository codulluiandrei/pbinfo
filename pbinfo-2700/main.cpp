#include<fstream> 
using namespace std; 
int arr[1000005]; 
int output[1000005];
// Calculeaza maximul din vectorul initial
int getMax(int n) 
{ 
	int maxX = arr[0]; 
	for (int i = 1; i < n; i++) 
		if (arr[i] > maxX) 
			maxX = arr[i]; 
	return maxX; 
} 
// Counting Sort - se afla la baza RadixSort
void countSort(int n, int exp) 
{ 
	int i, count[32] = {0}; 
	// Tinem minte numarul de aparitii in vectorul count
	for (i = 0; i < n; i++) 
		count[ (arr[i]/exp)%32 ]++; 
	// Modificam count[i] astfel incat count[i] sa contina
	// pozitia cifrei din output[]
	for (i = 1; i < 32; i++) 
		count[i] += count[i - 1]; 
	// Cream vectorul output
	for (i = n - 1; i >= 0; i--) 
	{ 
		output[count[ (arr[i]/exp)%32 ] - 1] = arr[i]; 
		count[ (arr[i]/exp)%32 ]--; 
	} 
	// Copiem continutul vectorului output[] in arr[]
	for (i = 0; i < n; i++) 
		arr[i] = output[i]; 
} 
// Radix Sort 
void radixsort(int n) 
{ 
	// Calculam cel mai mare element pentru a afla numarul
	// de cifre al acestuia
	int m = getMax(n); 
	// Folosim Counting Sort pentru fiecare cifra
	for (int exp = 1; m/exp > 0; exp *= 32) 
		countSort(n, exp); 
}
int main() 
{ 
	ifstream fin("radixsort.in");
	ofstream fout("radixsort.out");
	int n, i; fin >> n;
	for(i = 0; i < n; ++i)
		fin >> arr[i];
	radixsort(n);
	for (i = 0; i < n; i++)
		(fout << arr[i]).put(' '); 
	return 0;
} 