    #include <fstream>
    #include <iostream>
    #include <vector>
     
    using namespace std;
     
    ifstream fin("excel.in");
    ofstream fout("excel.out");
     
    const int NMAX = 200001;
     
    int fr[2 * NMAX];
     
    int n, s, x;
     
    vector<int> v;
     
    int main()
    {
      fin >> n >> s;
      for (int i = 1; i <= n; ++i)
      {
        fin >> x;
        v.push_back(x);
      }
     
      int total_count = 0;
     
      for (int i = 0; i < n - 1; ++i)
      {
        for (int j = i + 1; j < n; ++j)
        {
          int remaining_sum = s - v[i] - v[j];
          total_count += fr[remaining_sum + NMAX];
        }
        for (int j = 0; j < i; ++j)
          fr[v[i] + v[j] + NMAX]++;
      }
     
      fout << total_count << '\n';
     
      return 0;
    }