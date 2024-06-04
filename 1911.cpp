#include <bits/stdc++.h>
using namespace std;

int n, l;
vector<pair<int, int>> vec;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    int s, e;
    cin >> s >> e;
    vec.push_back({s, e});
  }
  sort(vec.begin(), vec.end());

  int idx = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (vec[i].second <= idx) {
      continue;
    }
    int inc;
    if (idx < vec[i].first) {
      inc = (vec[i].second - vec[i].first + (l - 1)) / l;
      idx = vec[i].first + inc * l;
    } else {
      inc = (vec[i].second - idx + (l - 1)) / l;
      idx = idx + inc * l;
    }
    cnt += inc;
  }

  cout << cnt;
  return 0;
}