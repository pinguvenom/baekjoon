#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    int q = 0, d = 0, n = 0, p = 0;
    if (N / 25 != 0) {
      q = N / 25;
    }
    N = N % 25;

    if (N / 10 != 0) {
      d = N / 10;
    }
    N = N % 10;

    if (N / 5 != 0) {
      n = N / 5;
    }
    N = N % 5;

    p = N;

    cout << q << ' ' << d << ' ' << n << ' ' << p << '\n';
  }

  return 0;
}