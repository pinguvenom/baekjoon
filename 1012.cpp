#include <bits/stdc++.h>
using namespace std;

int adj[50][50];
int visited[50][50];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int N, M, K;

void dfs(int y, int x) {
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= N || nx < 0 || nx >= M || !adj[ny][nx]) {
      continue;
    }
    if (visited[ny][nx]) {
      continue;
    }
    dfs(ny, nx);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    cin >> N >> M >> K;

    memset(adj, 0, sizeof(adj));
    memset(visited, 0, sizeof(visited));

    while (K--) {
      int x, y;
      cin >> x >> y;
      adj[x][y] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (adj[i][j] == 1 && !visited[i][j]) {
          dfs(i, j);
          cnt++;
        }
      }
    }
    cout << cnt << '\n';
  }

  return 0;
}