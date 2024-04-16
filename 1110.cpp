#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int raw_n;
  cin >> raw_n;

  int n = raw_n;
  int cnt = 1;
  while (true) {
    if (n < 10) {
      n *= 10;
      n = (n / 10 + n % 10) % 10 + (n / 10 % 10) * 10;
    } else {
      n = (n / 10 + n % 10) % 10 + (n % 10) * 10;
    }

    if (n == raw_n) {
      break;
    } else {
      cnt++;
    }
  }

  cout << cnt;
  return 0;
}