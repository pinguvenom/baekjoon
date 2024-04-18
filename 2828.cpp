#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  int j;
  cin >> j;

  int x = 1;
  int prev_x = 1;
  int moving_cnt = 0;
  while (j--) {
    int app;
    cin >> app;

    if (app >= x && app <= x + m - 1) {
      continue;
    } else if (app > x + m - 1) {
      x = app - m + 1;
      moving_cnt += x - prev_x;
    } else {
      x = app;
      moving_cnt += prev_x - x;
    }
    prev_x = x;
  }

  cout << moving_cnt;
  return 0;
}