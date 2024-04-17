#include <bits/stdc++.h>
using namespace std;

int adj[100][100];
int visited[100][100];
int m, n, k;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int area;
vector<int> area_vec;

void dfs(int y, int x) {
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= m || nx < 0 || nx >= n) {
      continue;
    }
    if (adj[ny][nx] == 0 || visited[ny][nx] == 1) {
      continue;
    }
    area++;
    dfs(ny, nx);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> m >> n >> k;
  fill(&adj[0][0], &adj[0][0] + 100 * 100, 1);

  while (k--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    for (int i = y1; i < y2; i++) {
      for (int j = x1; j < x2; j++) {
        adj[i][j] = 0;
      }
    }
  }

  int cnt = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (adj[i][j] == 1 && visited[i][j] == 0) {
        cnt++;
        area = 1;
        dfs(i, j);
        area_vec.push_back(area);
      }
    }
  }

  cout << cnt << '\n';
  sort(area_vec.begin(), area_vec.end());
  for (auto i : area_vec) {
    cout << i << ' ';
  }
  return 0;
}