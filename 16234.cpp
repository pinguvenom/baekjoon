#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int arr[50][50];
int visited[50][50];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, vector<pair<int, int>>& neighbor) {
  visited[y][x] = 1;
  neighbor.push_back({y, x});
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) {
      continue;
    }
    if (abs(arr[ny][nx] - arr[y][x]) >= l &&
        abs(arr[ny][nx] - arr[y][x]) <= r) {
      dfs(ny, nx, neighbor);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> l >> r;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  int cnt = 0;
  while (true) {
    memset(visited, 0, sizeof(visited));
    vector<vector<pair<int, int>>> neighbor_list;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (visited[i][j] == 0) {
          vector<pair<int, int>> neighbor;
          dfs(i, j, neighbor);
          neighbor_list.push_back(neighbor);
        }
      }
    }

    for (auto neighbor : neighbor_list) {
      int sum = 0;
      for (auto i : neighbor) {
        sum += arr[i.first][i.second];
      }
      int new_val = (int)(sum / neighbor.size());

      for (auto i : neighbor) {
        arr[i.first][i.second] = new_val;
      }
    }

    if (neighbor_list.size() == n * n) {
      break;
    }
    cnt++;
  }

  cout << cnt;
  return 0;
}