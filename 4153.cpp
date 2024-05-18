#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (true) {
    long long a, b, c;
    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0) {
      break;
    }

    long long _max = max({a, b, c});
    if (_max == a) {
      if (c * c + b * b == a * a) {
        cout << "right\n";
      } else {
        cout << "wrong\n";
      }
    } else if (_max == b) {
      if (c * c + a * a == b * b) {
        cout << "right\n";
      } else {
        cout << "wrong\n";
      }

    } else if (_max == c) {
      if (a * a + b * b == c * c) {
        cout << "right\n";
      } else {
        cout << "wrong\n";
      }
    }
  }

  return 0;
}