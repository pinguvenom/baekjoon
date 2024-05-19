#include <bits/stdc++.h>
using namespace std;

bool era[1000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m, n;
  cin >> m >> n;

  era[1] = true;
  for (int i = 2; i <= 1000000; i++) {
    if (era[i]) {
      continue;
    }
    for (int j = 2 * i; j < 1000000; j += i) {
      era[j] = true;
    }
  }

  for (int i = m; i <= n; i++) {
    if (!era[i]) {
      cout << i << '\n';
    }
  }

  return 0;
}