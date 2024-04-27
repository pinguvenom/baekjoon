#include <bits/stdc++.h>
using namespace std;

int r, c;
char arr[1000][1000];

int visited_f[1000][1000];
int visited_j[1000][1000];

queue<pair<int, int>> q_f;
queue<pair<int, int>> q_j;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < c; j++) {
      arr[i][j] = s[j];
      if (arr[i][j] == 'J') {
        q_j.push({i, j});
        visited_j[i][j] = 1;
      } else if (arr[i][j] == 'F') {
        q_f.push({i, j});
        visited_f[i][j] = 1;
      }
    }
  }

  int y, x;
  while (q_j.size()) {
    // 1. spread fire
    queue<pair<int, int>> q_f_tmp;
    while (q_f.size()) {
      tie(y, x) = q_f.front();
      q_f.pop();

      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
          continue;
        }
        if (arr[ny][nx] == '#' || visited_f[ny][nx]) {
          continue;
        }
        visited_f[ny][nx] = visited_f[y][x] + 1;
        q_f_tmp.push({ny, nx});
      }
    }
    q_f = q_f_tmp;

    // 2. move jihwoon
    queue<pair<int, int>> q_j_tmp;
    while (q_j.size()) {
      tie(y, x) = q_j.front();
      q_j.pop();

      // check escape condition
      if (y == 0 || y == (r - 1) || x == 0 || x == (c - 1)) {
        cout << visited_j[y][x];
        exit(0);
      }

      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
          continue;
        }
        if (arr[ny][nx] == '#' || visited_j[ny][nx]) {
          continue;
        }
        visited_j[ny][nx] = visited_j[y][x] + 1;
        // 불이 이미 퍼져있으면 지나갈 수 없음.
        if (visited_f[ny][nx] != 0 && visited_j[ny][nx] >= visited_f[ny][nx]) {
          continue;
        }
        q_j_tmp.push({ny, nx});
      }
    }
    q_j = q_j_tmp;

    // 3. check die condition
    if (q_j.empty()) {
      cout << "IMPOSSIBLE";
      exit(0);
    }
  }

  return 0;
}