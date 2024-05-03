#include <bits/stdc++.h>
using namespace std;

int r, c;
int alp[26];
char arr[20][20];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int _max;

void solve(int y, int x, int cnt) {
  _max = max({cnt, _max});

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
      continue;
    }

    if (alp[arr[ny][nx] - 'A'] == 0) {
      alp[arr[ny][nx] - 'A']++;
      solve(ny, nx, cnt + 1);
      alp[arr[ny][nx] - 'A']--;
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> arr[i][j];
    }
  }

  alp[arr[0][0] - 'A']++;

  solve(0, 0, 1);
  cout << _max;

  return 0;
}