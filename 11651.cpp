#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> vec;

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.second > b.second) {
    return false;
  } else if (a.second < b.second) {
    return true;
  } else {
    if (a.first > b.first) {
      return false;
    } else {
      return true;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    vec.push_back({x, y});
  }

  sort(vec.begin(), vec.end(), cmp);

  for (auto x : vec) {
    cout << x.first << ' ' << x.second << '\n';
  }
  return 0;
}