#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int h, w, n;
    cin >> h >> w >> n;

    cout << ((n - 1) % h + 1) * 100 + ((n - 1) / h) + 1 << '\n';
  }

  return 0;
}