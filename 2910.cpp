#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, pair<int, int>>& a,
         const pair<int, pair<int, int>>& b) {
  if (a.second.first == b.second.first) {
    return a.second.second < b.second.second;
  }
  return a.second.first > b.second.first;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, c;
  cin >> n >> c;
  map<int, pair<int, int>> mp;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    if (mp.find(val) == mp.end()) {
      mp[val].first = 1;
      mp[val].second = i;
    } else {
      mp[val].first++;
    }
  }

  vector<pair<int, pair<int, int>>> vec(mp.begin(), mp.end());

  sort(vec.begin(), vec.end(), cmp);

  for (auto val : vec) {
    for (int i = 0; i < val.second.first; i++) {
      cout << val.first << ' ';
    }
  }

  return 0;
}