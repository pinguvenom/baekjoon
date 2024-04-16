#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n, vector<int>(m, 0));
  vector<vector<int>> visited(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      adj[i][j] = (int)(s[j] - '0');
    }
  }

  int dy[4] = {-1, 0, 1, 0};
  int dx[4] = {0, 1, 0, -1};

  queue<pair<int, int>> q;
  visited[0][0] = 1;
  q.push({0, 0});
  while (q.size()) {
    int y, x;
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m || adj[ny][nx] == 0) {
        continue;
      }
      if (visited[ny][nx]) {
        continue;
      }
      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
    }
  }

  cout << visited[n - 1][m - 1];
  return 0;
}