#include <bits/stdc++.h>
using namespace std;

int arr[8][8];
int arr_cpy[8][8];
int visited[8][8];

int n, m;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

vector<pair<int, int>> empty_space;
vector<pair<int, int>> virus;

void dfs(int y, int x) {
  visited[y][x] = 1;
  arr_cpy[y][x] = 2;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
      continue;
    }
    if (visited[ny][nx] == 1 || arr_cpy[ny][nx] == 1) {
      continue;
    }
    dfs(ny, nx);
  }
}

void spread_virus() {
  for (int i = 0; i < virus.size(); i++) {
    dfs(virus[i].first, virus[i].second);
  }
}

int get_safety_area() {
  int safety_area = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr_cpy[i][j] == 0) {
        safety_area++;
      }
    }
  }
  return safety_area;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 0) {
        empty_space.push_back({i, j});
      } else if (arr[i][j] == 2) {
        virus.push_back({i, j});
      }
    }
  }

  int max_safety_area = 0;
  for (int i = 0; i < empty_space.size(); i++) {
    for (int j = i + 1; j < empty_space.size(); j++) {
      for (int k = j + 1; k < empty_space.size(); k++) {
        copy(&arr[0][0], &arr[0][0] + 64, &arr_cpy[0][0]);
        memset(visited, 0, sizeof(visited));

        arr_cpy[empty_space[i].first][empty_space[i].second] = 1;
        arr_cpy[empty_space[j].first][empty_space[j].second] = 1;
        arr_cpy[empty_space[k].first][empty_space[k].second] = 1;

        spread_virus();

        int safety_area = get_safety_area();
        if (safety_area > max_safety_area) {
          max_safety_area = safety_area;
        }
      }
    }
  }

  cout << max_safety_area;

  return 0;
}