#include <bits/stdc++.h>
using namespace std;
#define y1 daasge

int n, m, x1, y1, x2, y2;
char arr[300][300];
int visited[300][300];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

queue<pair<int, int>> wall_list;
bool b_found = false;

void dfs(int y, int x) {
  if (b_found) {
    return;
  }
  visited[y][x] = 1;
  if (y == (y2 - 1) && x == (x2 - 1)) {
    b_found = true;
    return;
  }
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) {
      continue;
    }
    if (arr[ny][nx] == '1') {
      wall_list.push({ny, nx});
      visited[ny][nx] = 1;
      continue;
    }
    dfs(ny, nx);
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  cin >> y1 >> x1 >> y2 >> x2;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  wall_list.push({y1 - 1, x1 - 1});
  int jump_cnt = 1;
  while (true) {
    int wall_size = wall_list.size();
    for (int i = 0; i < wall_size; i++) {
      pair<int, int> wall = wall_list.front();
      wall_list.pop();
      dfs(wall.first, wall.second);
      if (b_found) {
        break;
      }
    }
    if (b_found) {
      break;
    }
    jump_cnt++;
  }

  cout << jump_cnt;
  return 0;
}