#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
  long long val = 1;
  int cnt = 1;
  while (true) {
    if (val % n == 0) {
      return cnt;
    }

    val = (val % n * 10 % n) % n + 1;
    cnt++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (true) {
    int n;
    cin >> n;
    if (cin.eof()) {
      break;
    }
    cout << solve(n) << '\n';
  }

  return 0;
}