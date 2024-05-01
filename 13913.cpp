#include <bits/stdc++.h>
using namespace std;

int n, k;
int visited[200001];
int _from[200001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;

  queue<int> q;
  q.push(n);
  visited[n] = 1;
  _from[n] = -1;

  while (q.size()) {
    int x = q.front();
    q.pop();

    if (x == k) {
      break;
    }

    for (int i = 0; i < 3; i++) {
      int nx;
      if (i == 0) {
        nx = x + 1;
      } else if (i == 1) {
        nx = x - 1;
      } else {
        nx = x * 2;
      }

      if (nx < 0 || nx > 200000) {
        continue;
      }

      if (!visited[nx]) {
        q.push(nx);
        visited[nx] = visited[x] + 1;
        _from[nx] = x;
      }
    }
  }

  vector<int> path;
  for (int i = k; i != -1; i = _from[i]) {
    path.push_back(i);
  }

  reverse(path.begin(), path.end());

  cout << visited[k] - 1 << '\n';
  for (auto x : path) {
    cout << x << ' ';
  }

  return 0;
}