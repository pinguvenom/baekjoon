#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[50][50];
int visited[50][50];
int room[50][50];

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

vector<int> area_vec;

void dfs(int y, int x, int& area, int room_num) {
  visited[y][x] = 1;
  room[y][x] = room_num;
  area++;

  for (int i = 0; i < 4; i++) {
    if (arr[y][x] & (1 << i)) {
      continue;
    }

    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= m || nx < 0 || nx >= n || visited[ny][nx]) {
      continue;
    }

    dfs(ny, nx, area, room_num);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  int cnt = 0;
  int max_area = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[i][j]) {
        int area = 0;
        dfs(i, j, area, cnt);
        max_area = max({area, max_area});
        area_vec.push_back(area);
        cnt++;
      }
    }
  }
  int max_area_sum = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 4; k++) {
        if (arr[i][j] & (1 << k)) {
          int ny = i + dy[k];
          int nx = j + dx[k];
          if (ny < 0 || ny >= m || nx < 0 || nx >= n) {
            continue;
          }
          if (room[i][j] != room[ny][nx]) {
            int area_sum = area_vec[room[i][j]] + area_vec[room[ny][nx]];
            max_area_sum = max({area_sum, max_area_sum});
          }
        }
      }
    }
  }

  cout << cnt << '\n';
  cout << max_area << '\n';
  cout << max_area_sum;

  return 0;
}