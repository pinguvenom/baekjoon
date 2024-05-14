#include <bits/stdc++.h>
using namespace std;

int n, m;
map<long long, bool> mp;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    mp[x] = true;
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    long long x;
    cin >> x;
    cout << (int)mp[x] << ' ';
  }

  return 0;
}