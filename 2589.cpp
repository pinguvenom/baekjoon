#include <bits/stdc++.h>
using namespace std;

int n, m;
char arr[50][50];
int visited[50][50];
vector<pair<int, int>> land_list;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int search(int y, int x) {
  queue<pair<int, int>> q;
  visited[y][x] = 1;
  q.push({y, x});

  int treasure_dist = 0;
  while (q.size()) {
    tie(y, x) = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
        continue;
      }
      if (arr[ny][nx] == 'W' || visited[ny][nx]) {
        continue;
      }
      visited[ny][nx] = visited[y][x] + 1;
      treasure_dist = max({treasure_dist, visited[ny][nx]});
      q.push({ny, nx});
    }
  }

  return treasure_dist;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    for (int j = 0; j < m; j++) {
      arr[i][j] = s[j];
      if (arr[i][j] == 'L') {
        land_list.push_back({i, j});
      }
    }
  }

  int rst = 0;
  for (auto i : land_list) {
    memset(visited, 0, sizeof(visited));
    rst = max({rst, search(i.first, i.second)});
  }

  cout << rst - 1;
  return 0;
}