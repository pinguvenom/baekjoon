#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int x_min = 10000, y_min = 10000, x_max = -10000, y_max = -10000;
  while (n--) {
    int x, y;
    cin >> x >> y;

    x_min = min({x, x_min});
    y_min = min({y, y_min});
    x_max = max({x, x_max});
    y_max = max({y, y_max});
  }

  cout << (x_max - x_min) * (y_max - y_min);

  return 0;
}