#include fstream
#include cstring
using namespace std;
int main() {
  ifstream in(constructpalindrom.in);
  ofstream out(constructpalindrom.out);
  int t;
  char s[100001];
  in  t;
  while(t--) {
    in  s;
    int l = strlen(s), cnt = 0;
    for(int i = 0, j = l - 1; cnt  2 && i = j; ++i, --j) {
      if(s[i] != s[j])++cnt, --j;
      if(s[i] != s[j])--i, ++j;
    }
    if(cnt  2) out  YESn;
    else out  NOn;
  }
  return 0;
}
