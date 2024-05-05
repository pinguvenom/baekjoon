#include <bits/stdc++.h>
using namespace std;
int n, m, h;

int visited[30][10];

bool go_sadari() {
  for (int i = 0; i < n; i++) {
    int start = i;
    for (int j = 0; j < h; j++) {
      if (visited[j][start]) {
        start++;
      } else if (visited[j][start - 1]) {
        start--;
      }
    }
    if (start != i) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> h;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    visited[a - 1][b - 1] = 1;
  }

  bool b_meet_condition = false;
  if (go_sadari()) {
    b_meet_condition = true;
    cout << 0;
    exit(0);
  }
  vector<pair<int, int>> _line;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (visited[i][j] == 0) {
        _line.push_back({i, j});
      }
    }
  }

  for (int i = 0; i < _line.size(); i++) {
    int x, y;
    tie(x, y) = _line[i];
    visited[x][y] = 1;
    if (go_sadari()) {
      b_meet_condition = true;
      cout << 1;
      exit(0);
    }
    visited[x][y] = 0;
  }

  for (int i = 0; i < _line.size(); i++) {
    for (int j = 0; j < i; j++) {
      int x1, y1, x2, y2;
      tie(x1, y1) = _line[i];
      tie(x2, y2) = _line[j];
      if (x1 == x2 && abs(y1 - y2) == 1) {
        continue;
      }
      visited[x1][y1] = 1;
      visited[x2][y2] = 1;
      if (go_sadari()) {
        b_meet_condition = true;
        cout << 2;
        exit(0);
      }
      visited[x1][y1] = 0;
      visited[x2][y2] = 0;
    }
  }

  for (int i = 0; i < _line.size(); i++) {
    for (int j = 0; j < i; j++) {
      for (int k = 0; k < j; k++) {
        int x1, y1, x2, y2, x3, y3;
        tie(x1, y1) = _line[i];
        tie(x2, y2) = _line[j];
        tie(x3, y3) = _line[k];
        if (x1 == x2 && abs(y1 - y2) == 1) {
          continue;
        } else if (x1 == x3 && abs(y1 - y3) == 1) {
          continue;
        } else if (x2 == x3 && abs(y2 - y3) == 1) {
          continue;
        }
        visited[x1][y1] = 1;
        visited[x2][y2] = 1;
        visited[x3][y3] = 1;
        if (go_sadari()) {
          b_meet_condition = true;
          cout << 3;
          exit(0);
        }
        visited[x1][y1] = 0;
        visited[x2][y2] = 0;
        visited[x3][y3] = 0;
      }
    }
  }

  if (!b_meet_condition) {
    cout << -1;
  }

  return 0;
}