#include <bits/stdc++.h>
using namespace std;

int arr[100][100];
int visited[100][100];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int h, w;

vector<pair<int, int>> outside_cheeze;

void dfs(int y, int x) {
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
      continue;
    }
    if (visited[ny][nx] == 1) {
      continue;
    }
    if (arr[ny][nx] == 1) {
      outside_cheeze.push_back({ny, nx});
      visited[ny][nx] = 1;
      continue;
    }
    dfs(ny, nx);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> h >> w;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> arr[i][j];
    }
  }

  int cnt = 0;
  int prev_cheeze_len = 0;
  while (true) {
    dfs(0, 0);

    if (outside_cheeze.empty()) {
      break;
    }

    for (auto i : outside_cheeze) {
      arr[i.first][i.second] = 0;
    }

    prev_cheeze_len = outside_cheeze.size();
    outside_cheeze.clear();
    memset(visited, 0, sizeof(visited));
    cnt++;
  }

  cout << cnt << '\n';
  cout << prev_cheeze_len;
  return 0;
}