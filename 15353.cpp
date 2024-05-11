#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string a, b;
  cin >> a >> b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  int n_size = max({a.size(), b.size()});
  int sum[10002];
  memset(sum, 0, sizeof(sum));

  for (int i = 0; i < n_size; i++) {
    if (i < a.size()) {
      sum[i] += (a[i] - '0');
    }
    if (i < b.size()) {
      sum[i] += (b[i] - '0');
    }

    if (sum[i] >= 10) {
      sum[i] -= 10;
      sum[i + 1]++;
    }
  }
  bool b_start = false;
  for (int i = 10001; i >= 0; i--) {
    if (sum[i] == 0 && !b_start) {
      continue;
    }
    b_start = true;
    cout << sum[i];
  }

  return 0;
}