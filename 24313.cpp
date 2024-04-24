#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a1, a0, c, n0;
  cin >> a1 >> a0 >> c >> n0;

  if (c == a1) {
    if (a0 > 0) {
      cout << "0";
    } else {
      cout << "1";
    }
  } else if (c > a1) {
    if (n0 >= a0 / (c - a1)) {
      cout << "1";
    } else {
      cout << "0";
    }
  } else {
    cout << "0";
  }

  return 0;
}