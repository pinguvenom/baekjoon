#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  map<int, int> mp;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mp[x]++;
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    cout << mp[x] << ' ';
  }

  return 0;
}