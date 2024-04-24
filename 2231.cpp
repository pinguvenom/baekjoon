#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int rst = 0;
  for (int i = 1; i <= n; i++) {
    int tmp = i;
    int sum = tmp;
    while (tmp) {
      sum += (tmp % 10);
      tmp /= 10;
    }
    if (sum == n) {
      rst = i;
      break;
    }
  }

  cout << rst;

  return 0;
}