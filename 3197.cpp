#include <bits/stdc++.h>
using namespace std;

int r, c;
char arr[1500][1500];
int visited[1500][1500];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

queue<pair<int, int>> q_swan, q_water, q_swan_tmp, q_water_tmp;
int visited_swan[1500][1500];
int visited_water[1500][1500];

void clear_q(queue<pair<int, int>> &q) {
  queue<pair<int, int>> empty;
  swap(q, empty);
}

void move_water() {
  while (q_water.size()) {
    int y, x;
    tie(y, x) = q_water.front();
    q_water.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited_water[ny][nx] ||
          arr[ny][nx] != 'X') {
        continue;
      }
      visited_water[ny][nx] = 1;
      q_water_tmp.push({ny, nx});
      arr[ny][nx] = '.';
    }
  }
}

bool move_swan() {
  while (q_swan.size()) {
    int y, x;
    tie(y, x) = q_swan.front();
    q_swan.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited_swan[ny][nx]) {
        continue;
      }
      visited_swan[ny][nx] = 1;

      if (arr[ny][nx] == '.') {
        q_swan.push({ny, nx});
      } else if (arr[ny][nx] == 'X') {
        q_swan_tmp.push({ny, nx});
      } else if (arr[ny][nx] == 'L') {
        return true;
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int swan_x, swan_y;
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 'L') {
        swan_y = i;
        swan_x = j;
        q_water.push({i, j});
        visited_water[i][j] = 1;
      } else if (arr[i][j] == '.') {
        q_water.push({i, j});
        visited_water[i][j] = 1;
      }
    }
  }
  q_swan.push({swan_y, swan_x});
  visited_swan[swan_y][swan_x] = 1;

  int cnt = 0;
  while (true) {
    if (move_swan()) {
      break;
    }
    move_water();

    q_swan = q_swan_tmp;
    clear_q(q_swan_tmp);

    q_water = q_water_tmp;
    clear_q(q_water_tmp);

    cnt++;
  }

  cout << cnt;

  return 0;
}