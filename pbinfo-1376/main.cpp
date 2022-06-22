#include <iostream>
using namespace std;
int main() {
  int lungime;
  char margine = '*', liber = ' ';
  cin >> lungime;
  int start = 2, baza = 4, temp;
  for (temp = start; temp <= lungime; temp++) {
    for (int temp2 = 0; temp2 <= lungime - temp; temp2++) {
      cout << liber;
    }
    if (temp > start) {
      cout << margine << " ";
      for (int temp3 = baza; temp3 <= temp; temp3++) {
        cout << liber << " ";
      }
    }  cout << margine << " "; cout << "\n";
  } for (int temp4 = baza; temp4 < lungime + baza; temp4++) {
    cout << margine << " ";
  } cout<<"\n";
  return 0;
}