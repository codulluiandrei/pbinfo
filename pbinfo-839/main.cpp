#include <iostream>
#include <vector>
using namespace std;

class Vraja2 {
public:
  Vraja2();
  void output();
private:
  int m_v[1001];
  int m_n;
  int m_cntv = 0;
  void input();
  void countV();
  void outputDebug();
};

void Vraja2::input() {
  cin >> m_n;
  for (int i = 0; i < m_n; ++i) {
    cin >> m_v[i];
  }
}

Vraja2::Vraja2() {
  input();
  countV();
}

void Vraja2::outputDebug() {
  cout << m_cntv << '\n';
  for (int i = 0; i < m_n; ++i) {
    cout << m_v[i] << ' ';
  }
  cout << "*\n";
}

void Vraja2::countV() {
  bool f = true;
  while (f) {
    f = false;
    for (int i = 0; i < m_n; ++i) {
      if (m_v[i] == 0) continue;
      int j = i, minval = 1000001;
      for (; m_v[j] && j < m_n; ++j)
        minval = min(minval, m_v[j]);
      for (int k = i; k < j; ++k)
        m_v[k] -= minval;
      m_cntv++;
      //outputDebug();
      f = true;
      break;
    }
  }
}

void Vraja2::output() {
  cout << m_cntv;
}

int main() {
  Vraja2 obj;
  obj.output();
  return 0;
}
