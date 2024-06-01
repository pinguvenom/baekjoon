#include <bits/stdc++.h>
using namespace std;

map<int, bool> mp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mp[x] = true;
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    if (mp[x]) {
      cout << "1\n";
    } else {
      cout << "0\n";
    }
  }

  return 0;
}