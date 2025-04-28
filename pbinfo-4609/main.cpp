// 100p, Oprea Mihai-Adrian
#include <fstream>
#include <string>
#include <cassert>
using namespace std;
ifstream cin("opsir.in");
ofstream cout("opsir.out");
int n, m, sum_n, sum_m;
string a, b;
void read_verif()
{
    cin >> n >> m >> a >> b;
    assert(1 <= n && n <= 200000);
    assert(1 <= m && m <= 200000);
    sum_n += n;
    sum_m += m;
    assert(1 <= sum_n && sum_n <= 200000);
    assert(1 <= sum_m && sum_m <= 200000);
    for (char c : a)
        assert(islower(c));
    for (char c : b)
        assert(islower(c));
}
void test_a()
{
    read_verif();
    int freq_a[26] = {0}, freq_b[26] = {0};
    for (char c : a)
        freq_a[c - 'a']++;
    for (char c : b)
        freq_b[c - 'a']++;
    int cnt = 0;
    for (int i = 0; i < 26; i++)
        if (freq_a[i] + freq_b[i] > 0)
            cnt++;
    cout << cnt << '\n';
    for (int i = 0; i < 26; i++)
        if (freq_a[i] + freq_b[i] > 0)
        {
            if (freq_a[i] > freq_b[i])
                cout << (char)(i + 'a') << " S\n";
            else
                cout << (char)(i + 'a') << " T\n";
        }
}
void test_b()
{
    read_verif();
    bool ok = true;
    int freq_a[26] = {0};
    int sum_freq_a = 0;
    int left_a = 0;
    int ptr_b = 0;
    for (int right_a = 0; right_a < (int)a.size(); right_a++)
    {
        // secventa descrescatoare in primul sir care nu poate fi prelungita la dreapta
        if (right_a == (int)a.size() - 1 || a[right_a + 1] < a[right_a])
        {
            sum_freq_a = 0;
            for (int i = 0; i < 26; i++)
                freq_a[i] = 0;
            for (int i = left_a; i <= right_a; i++)
            {
                freq_a[a[i] - 'a']++;
                sum_freq_a++;
            }
            // determinam cea mai scurta secventa din al doilea sir care acopera caracterele din primul sir
            while (ptr_b < (int)b.size() && sum_freq_a > 0)
            {
                if (freq_a[b[ptr_b] - 'a'] > 0)
                {
                    freq_a[b[ptr_b] - 'a']--;
                    sum_freq_a--;
                }
                ptr_b++;
            }
            // nu am putut acoperi toate caracterele din primul sir, nu avem solutie
            if (sum_freq_a > 0)
            {
                ok = false;
                break;
            }
            left_a = right_a + 1;
        }
    }
    if (ok)
        cout << "DA\n";
    else
        cout << "NU\n";
}
int main()
{
    int c;
    cin >> c;
    assert(1 <= c && c <= 2);
    int t;
    cin >> t;
    assert(1 <= t && t <= 100);
    while (t--)
    {
        if (c == 1)
            test_a();
        else
            test_b();
    }
    return 0;
} 