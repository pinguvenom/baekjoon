#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int x;

vector<int> vec;

bool search(int x) {
  int l = 0;
  int r = vec.size() - 1;
  int m;

  while (l <= r) {
    m = (l + r) / 2;
    if (x < vec[m]) {
      r = m - 1;
    } else if (x > vec[m]) {
      l = m + 1;
    } else {
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x;
      vec.push_back(x);
    }
    sort(vec.begin(), vec.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> x;
      cout << search(x) << '\n';
    }
    vec.clear();
  }

  return 0;
}