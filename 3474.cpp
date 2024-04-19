#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int cnt_2 = 0;
    int cnt_5 = 0;

    for (int i = 2; i <= n; i *= 2) {
      cnt_2 += (n / i);
    }
    for (int i = 5; i <= n; i *= 5) {
      cnt_5 += (n / i);
    }

    cout << min({cnt_2, cnt_5}) << '\n';
  }

  return 0;
}