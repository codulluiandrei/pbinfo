#include <iostream>
using namespace std;
class Generare3{
public:
  Generare3();
  void output();
private:
  void input();
  void outbin(int x);
  int m_val = 0;
  int m_n, m_lim;
};
void Generare3::outbin(int x) {
  for(int l = (m_lim >> 1); l > 0; l = (l >> 1)) {
    cout << (bool)(l & x);
  }
}
Generare3::Generare3() {
  input();
}
void Generare3::input() {
  cin >> m_n;
}
void Generare3::output() {
  m_lim = (1 << m_n);
  while(m_val < m_lim) {
    outbin(m_val);
    cout << '\n';
    m_val++;
  }
}
int main() {
  Generare3 obj;
  obj.output();
  return 0;
}
