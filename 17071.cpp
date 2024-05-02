#include <bits/stdc++.h>
using namespace std;

int visited[2][500001];
int n, k;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  if (n == k) {
    cout << 0;
    return 0;
  }

  queue<int> q;
  q.push(n);
  visited[0][n] = 1;
  int _time = 1;
  bool b_meet = false;
  while (q.size()) {
    // 수빈이 이동 (bfs)
    int q_size = q.size();
    for (int i = 0; i < q_size; i++) {
      int x = q.front();
      q.pop();
      for (int nx : {x + 1, x - 1, 2 * x}) {
        if (nx < 0 || nx > 500000 || visited[_time % 2][nx]) {
          continue;
        }
        visited[_time % 2][nx] = visited[(_time - 1) % 2][x] + 1;
        q.push(nx);
      }
    }

    // 동생 이동
    k += _time;
    if (k > 500000) {
      break;
    }

    if (visited[_time % 2][k]) {
      b_meet = true;
      break;
    }

    _time++;
  }
  if (b_meet) {
    cout << _time;
  } else {
    cout << -1;
  }

  return 0;
}