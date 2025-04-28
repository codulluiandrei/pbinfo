/*
    Autor: Andrei Onut (Yale University)
    Problema: "Golf" (OJI 2025, clasa a X-a)
*/
#include <algorithm>
#include <fstream>
#include <queue>
#include <string>
#include <vector>
int my_min(const int a, const int b) {
  return ((a < b) ? a : b);
}
int my_max(const int a, const int b) {
  return ((a > b) ? a : b);
}
struct island {
  int first_line, first_column;
  int last_line, last_column;
  int size;
  island(const int x, const int y)
      : first_line(x), first_column(y), last_line(x),
        last_column(y), size(1) {}
  void update(const int x, const int y) {
    first_line = my_min(first_line, x),
    first_column = my_min(first_column, y);
    last_line = my_max(last_line, x),
    last_column = my_max(last_column, y);
    ++size;
    return;
  }
};
template <typename T> std ::string T_to_string(T x) {
  if (x == (T)0)
    return "0";
  std ::string answer;
  while (x)
    answer += ((char)((x % (T)10) + '0')), x /= (T)10;
  reverse(answer.begin(), answer.end());
  return answer;
}
class golf_solver {
  const std ::string problem_name = "golf", dot = ".",
                     input_format = "in",
                     output_format = "out";
  const int dx[4] = {(-1), 0, (+1), 0},
            dy[4] = {0, (+1), 0, (-1)};
  int T, n, m, q;
  std ::vector<std ::string> A;
  std ::vector<std ::pair<char, int>> queries;
  std ::vector<long long> answer;
  std ::vector<island> islands_arr;
  int answer_1, answer_2;
  island find_island(const int i, const int j,
                     std ::vector<std ::vector<bool>> &used) {
    island answer(i, j);
    std ::queue<std ::pair<int, int>> Q;
    used[i][j] = true, Q.push({i, j});
    while (!Q.empty()) {
      for (int dir = 0; dir < 4; ++dir) {
        int x(Q.front().first + dx[dir]),
            y(Q.front().second + dy[dir]);
        if ((x < 0) || (x >= n) || (y < 0) || (y >= m))
          continue;
        if (A[x][y] == '0')
          continue;
        if (used[x][y] == true)
          continue;
        used[x][y] = true, Q.push({x, y});
        answer.update(x, y);
      }
      Q.pop();
    }
    return answer;
  }
  void solve_T_1() {
    for (const island &it : islands_arr)
      answer_1 += it.size;
    return;
  }
  void solve_T_2() {
    if (islands_arr.empty())
      return;
    int max_size(-1);
    for (const island &it : islands_arr)
      if (it.size > max_size)
        max_size = it.size, answer_2 = 1;
      else if (it.size == max_size)
        ++answer_2;
    return;
  }
  std ::vector<std ::pair<std ::pair<int, int>, int>>
  extract_segments(const int axis) {
    std ::vector<std ::pair<std ::pair<int, int>, int>> answer;
    for (const island &it : islands_arr)
      if (axis == 0)
        answer.push_back(
            {{it.first_column, it.last_column}, it.size});
      else
        answer.push_back(
            {{it.first_line, it.last_line}, it.size});
    return answer;
  }
  std ::pair<std ::vector<int>, std ::vector<int>>
  get_sums(const int axis, const int elements) {
    std ::vector<int> prefix(elements, 0), suffix(elements, 0);
    std ::vector<std ::pair<std ::pair<int, int>, int>>
        segments = extract_segments(axis);
    std ::vector<int> end_num(elements, 0),
        start_num(elements, 0);
    for (const std ::pair<std ::pair<int, int>, int> &it :
         segments)
      end_num[it.first.second] += it.second,
          start_num[it.first.first] += it.second;
    prefix[0] = end_num[0],
    suffix[(elements - 1)] = start_num[(elements - 1)];
    for (int i = 1; i < elements; ++i)
      prefix[i] = (prefix[(i - 1)] + end_num[i]),
      suffix[(elements - 1 - i)] =
          (suffix[(elements - i)] +
           start_num[(elements - 1 - i)]);
    return {prefix, suffix};
  }
  long long evaluate(const int q_idx, const int elements,
                     const std ::pair<std ::vector<int>,
                                      std ::vector<int>> &V) {
    if ((q_idx == 1) || (q_idx == elements))
      return 0LL;
    return (1LL * V.first[(q_idx - 2)] * V.second[q_idx]);
  }
  void solve_T_3() {
    std ::pair<std ::vector<int>, std ::vector<int>>
        columns = get_sums(0, m),
        lines = get_sums(1, n);
    int i = 0;
    for (const std ::pair<char, int> &it : queries)
      answer[(i++)] =
          ((it.first == 'C') ? evaluate(it.second, m, columns)
                             : evaluate(it.second, n, lines));
    return;
  }
public:
  golf_solver()
      : T(0), n(0), m(0), q(0), answer_1(0), answer_2(0) {}
  void read() {
    std ::ifstream f(problem_name + dot + input_format);
    f >> T >> n >> m;
    A = std ::vector<std ::string>(n, std ::string(m, ' '));
    for (int i(0); i < n; ++i)
      f >> A[i];
    if (T == 3) {
      f >> q;
      queries = std ::vector<std ::pair<char, int>>(q),
      answer = std ::vector<long long>(q);
      for (int i(0); i < q; ++i)
        f >> queries[i].first >> queries[i].second;
    }
    f.close();
    return;
  }
  void pre_compute() {
    std ::vector<std ::vector<bool>> used(
        n, std ::vector<bool>(m, false));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if ((A[i][j] == '1') && (used[i][j] == false))
          islands_arr.push_back(find_island(i, j, used));
    return;
  }
  void solve() {
    ((T == 1) ? solve_T_1()
              : ((T == 2) ? solve_T_2() : solve_T_3()));
    return;
  }
  void print() {
    std ::ofstream g(problem_name + dot + output_format);
    std ::vector<std ::string> output_lines(
        ((T <= 2) ? 1 : q));
    if (T == 1)
      output_lines[0] = T_to_string<int>(answer_1);
    else if (T == 2)
      output_lines[0] = T_to_string<int>(answer_2);
    else
      for (int i = 0; i < q; ++i)
        output_lines[i] = T_to_string<long long>(answer[i]);
    for (const std ::string &line : output_lines)
      g << line << '\n';
    g.close();
    return;
  }
};
int main() {
  golf_solver S;
  S.read();
  S.pre_compute();
  S.solve();
  S.print();
  return 0;
} 