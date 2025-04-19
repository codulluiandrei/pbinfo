#include <bits/stdc++.h>
using namespace std;
ifstream in ("trafalet.in");
ofstream out("trafalet.out");
const int N_MAX = 5002;
int N, M;
int input[1 + N_MAX][1 + N_MAX];
long long sum[1 + N_MAX];
int main() {
  in >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      in >> input[i][j];
      if ((i + j) % 2 == 0)
        input[i][j] = -input[i][j];
    }
  }
  long long answer = 0;
  for (int line_1 = 1; line_1 <= N; line_1++) {
    for (int j = 1; j <= M; j++)
      sum[j] = 0;
    for (int line_2 = line_1; line_2 <= N; line_2++) {
      for (int j = 1; j <= M; j++)
        sum[j] += input[line_2][j];
      long long currSum = 0, minSum = 0, maxSum = 0;
      for (int j = 1; j <= M; j++) {
        currSum += sum[j];
        minSum = min(minSum, currSum);
        maxSum = max(maxSum, currSum);
      }
      answer = max(answer, maxSum - minSum);
    }
  }
  out << answer;
  return 0;
}