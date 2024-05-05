#include <bits/stdc++.h>
using namespace std;

int r, c, k;
char arr[5][5];
int visited[5][5];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int cnt;
void dfs(int y, int x) {
  if (y == 0 && x == c - 1) {
    if (visited[y][x] == k) {
      cnt++;
    }
    return;
  }

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
      continue;
    }

    if (visited[ny][nx] || arr[ny][nx] == 'T') {
      continue;
    }
    visited[ny][nx] = visited[y][x] + 1;
    dfs(ny, nx);
    visited[ny][nx] = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> r >> c >> k;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> arr[i][j];
    }
  }
  visited[r - 1][0] = 1;
  dfs(r - 1, 0);

  cout << cnt;

  return 0;
}