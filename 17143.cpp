#include <bits/stdc++.h>
using namespace std;

struct shark {
  int s, d, z;
};

int r, c, m;
shark arr[105][105];

void move_shark() {
  shark tmp[105][105];
  memset(tmp, 0, sizeof(tmp));

  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      if (arr[i][j].z == 0) {
        continue;
      }

      // move shark
      int new_r = i;
      int new_c = j;
      int new_d = arr[i][j].d;
      if (arr[i][j].d == 1) {
        int move_len = arr[i][j].s % (2 * (r - 1));
        new_r = i - move_len;
        if (new_r < 1) {
          new_r = 2 - new_r;
          new_d = 2;
        }
        if (new_r > r) {
          new_r = (r * 2) - new_r;
          new_d = 1;
        }
      } else if (arr[i][j].d == 2) {
        int move_len = arr[i][j].s % (2 * (r - 1));
        new_r = i + move_len;
        if (new_r > r) {
          new_r = (r * 2) - new_r;
          new_d = 1;
        }
        if (new_r < 1) {
          new_r = 2 - new_r;
          new_d = 2;
        }
      } else if (arr[i][j].d == 3) {
        int move_len = arr[i][j].s % (2 * (c - 1));
        new_c = j + move_len;
        if (new_c > c) {
          new_c = (c * 2) - new_c;
          new_d = 4;
        }
        if (new_c < 1) {
          new_c = 2 - new_c;
          new_d = 3;
        }
      } else if (arr[i][j].d == 4) {
        int move_len = arr[i][j].s % (2 * (c - 1));
        new_c = j - move_len;
        if (new_c < 1) {
          new_c = 2 - new_c;
          new_d = 3;
        }
        if (new_c > c) {
          new_c = (c * 2) - new_c;
          new_d = 4;
        }
      }
      // eat shark if shark is in same location
      if (tmp[new_r][new_c].z) {
        if (arr[i][j].z > tmp[new_r][new_c].z) {
          tmp[new_r][new_c] = {arr[i][j].s, new_d, arr[i][j].z};
        }
      } else {
        tmp[new_r][new_c] = {arr[i][j].s, new_d, arr[i][j].z};
      }
    }
  }

  memcpy(arr, tmp, sizeof(tmp));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> r >> c >> m;
  for (int i = 0; i < m; i++) {
    int r, c, s, d, z;
    cin >> r >> c >> s >> d >> z;
    arr[r][c] = {s, d, z};
  }

  int rst = 0;
  for (int i = 1; i <= c; i++) {
    // fish shark
    for (int j = 1; j <= r; j++) {
      if (arr[j][i].z) {
        rst += arr[j][i].z;
        arr[j][i] = {0, 0, 0};
        break;
      }
    }

    // move shark
    move_shark();
  }

  cout << rst;
  return 0;
}