#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int x = 0, y = n / 5;

  if (n % 5 == 0) {
    cout << y;
  } else {
    for (y = n / 5; y >= 0; y--) {
      if ((n - 5 * y) % 3 == 0) {
        x = (n - 5 * y) / 3;
        break;
      }
    }
    if (x == 0 && y == 0) {
      cout << -1;
    } else {
      cout << x + y;
    }
  }

  return 0;
}