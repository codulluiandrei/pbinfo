#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <queue>
#include <algorithm>
#include <tuple>
#include <limits>
using namespace std;
static const int dx[4] = {-1, 0, 1, 0};
static const int dy[4] = {0, -1, 0, 1};
static const int kInfinite = numeric_limits<int>::max() / 2;
vector< vector<int> > get_distances(const vector<string> &board, pair<int, int> start, int plus_time) {
    queue< pair<int, int> > normal_queue, plus_queue;
    vector< vector<int> > distances(board.size(), vector<int>(board[0].size(), kInfinite));
    normal_queue.push(start);
    distances[start.first][start.second] = 0;
    while (!normal_queue.empty() || !plus_queue.empty()) {
        int x, y;
        if (plus_queue.empty()) {
            tie(x, y) = normal_queue.front();
            normal_queue.pop();
        } else if (normal_queue.empty()) {
            tie(x, y) = plus_queue.front();
            plus_queue.pop();
        } else {
            int x1, y1, x2, y2;
            tie(x1, y1) = normal_queue.front();
            tie(x2, y2) = plus_queue.front();
            if (distances[x1][y1] <= distances[x2][y2]) {
                x = x1;
                y = y1;
                normal_queue.pop();
            } else {
                x = x2;
                y = y2;
                plus_queue.pop();
            }
        }
        for (int i = 0; i < 4; ++i) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx < 0 || newy < 0 || newx >= int(board.size()) || newy >= int(board[0].size()))
                continue;
            if (distances[newx][newy] == kInfinite) {
                distances[newx][newy] = distances[x][y] + 1;
                if (board[newx][newy] == '+') {
                    distances[newx][newy] += plus_time;
                    plus_queue.emplace(newx, newy);
                } else if (board[newx][newy] == '.')
                    normal_queue.emplace(newx, newy);
            }
        }            
    }
    return distances;
}
int main() {
    ifstream cin("walle.in");
    ofstream cout("walle.out");
    int N, M, T;
    assert(cin >> N >> M >> T);
    assert(1 <= N && N <= 500);
    assert(1 <= M && M <= 500);
    assert(0 <= T && T <= 1000);
    vector<string> board(N);
    for (int i = 0; i < N; ++i) {
        assert(cin >> board[i]);
        for (auto &c : board[i])
            assert(c == '.' || c == '+' || c == 'E' || c == 'P' || c == 'W' || c == '#');
    }
    pair<int, int> start(-1, -1), end(-1, -1);
    int portals = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] == 'W') {
                assert(start == make_pair(-1, -1));
                start = make_pair(i, j);
            } else if (board[i][j] == 'E') {
                assert(end == make_pair(-1, -1));
                end = make_pair(i, j);
            } else if (board[i][j] == 'P')
                ++portals;
    assert(start != make_pair(-1, -1));
    assert(end != make_pair(-1, -1));
    assert(portals > 1);
    auto start_distances = get_distances(board, start, T);
    auto end_distances = get_distances(board, end, T);
    int answer = kInfinite;
    // first lets test directly
    answer = min(answer, start_distances[end.first][end.second]);
    // then through a portal, best to know max distance from a portal to the end
    // and second max
    // and closest to start (we'll need that later)
    int max_distance = 0;
    int second_max_distance = 0;
    int closest = kInfinite;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] == 'P') {
                if (end_distances[i][j] > max_distance) {
                    second_max_distance = max_distance;
                    max_distance = end_distances[i][j];
                } else if (end_distances[i][j] > second_max_distance) {
                    second_max_distance = end_distances[i][j];
                }
                closest = min(closest, start_distances[i][j]);
            }
    // going strictly through a portal and then to the end
    vector< vector<int> > then_to_end(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] == 'P') {
                // let's say we hop into this portal
                if (end_distances[i][j] == max_distance)
                    then_to_end[i][j] = second_max_distance;
                else
                    then_to_end[i][j] = max_distance;
                answer = min(answer, start_distances[i][j] + then_to_end[i][j]);
            }
    // now here's the thing, we might take 2 hops (we know 3 ore more are useless)
    // and it's a MAYBEEEE. Why?
    // let's say our strategy is to always take 2 hops.
    // So going from A -> B -> Hop in B
    //             or A -> C -> Hop in C,
    // then we make the hop in B go to C and viceversa,and we destroyed this strategy
    // so we take the 2nd hop only from a fixed "bad" portal
    // let's fix that
    // we can just assume worst case is to go through closest portal
    // then pop out of this one, go nearby (in an empty space), go back in
    // and then however much it takes to the end
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] == 'P') {
                if (closest == kInfinite || then_to_end[i][j] == kInfinite)
                    continue;
                int cost_empty = kInfinite;
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || y < 0 || x >= N || y >= M)
                        continue;
                    if (board[x][y] == '.')
                        cost_empty = min(cost_empty, 2);
                    else if (board[x][y] == '+')
                        cost_empty = min(cost_empty, 2 + T);
                }
                // well we got a shot here
                answer = min(answer, closest + cost_empty + then_to_end[i][j]);
            }
    if (answer == kInfinite)
        answer = -1;
    cout << answer << "\n";
} 