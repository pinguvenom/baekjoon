#include <bits/stdc++.h>
using namespace std;

char arr[50][50];

bool w_map[50][50];
bool b_map[50][50];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2 == 0) {
        if (arr[i][j] == 'W') {
          b_map[i][j] = true;
        } else {
          w_map[i][j] = true;
        }
      } else {
        if (arr[i][j] == 'W') {
          w_map[i][j] = true;
        } else {
          b_map[i][j] = true;
        }
      }
    }
  }

  int _min = INT_MAX;

  for (int i = 0; i <= n - 8; i++) {
    for (int j = 0; j <= m - 8; j++) {
      int w_map_sum = 0;
      int b_map_sum = 0;
      for (int y = i; y < i + 8; y++) {
        for (int x = j; x < j + 8; x++) {
          if (w_map[y][x]) {
            w_map_sum++;
          }
          if (b_map[y][x]) {
            b_map_sum++;
          }
        }
      }
      _min = min({_min, w_map_sum, b_map_sum});
    }
  }

  cout << _min;

  return 0;
}