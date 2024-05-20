#include <bits/stdc++.h>
using namespace std;

bool era[1000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 2; i < 1000001; i++) {
    if (era[i]) {
      continue;
    }
    for (int j = i * 2; j < 1000001; j += i) {
      era[j] = true;
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 2; i <= n / 2; i++) {
      if (!era[i] && !era[n - i]) {
        cnt++;
      }
    }
    cout << cnt << '\n';
  }

  return 0;
}