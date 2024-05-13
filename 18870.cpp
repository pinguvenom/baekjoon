#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> vec;
map<long long, int> mp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    vec.push_back(x);
  }
  vector<long long> vec_sorted(n);
  copy(vec.begin(), vec.end(), vec_sorted.begin());
  sort(vec_sorted.begin(), vec_sorted.end());
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    mp[vec_sorted[i]] = cnt;
    if (i + 1 < vec_sorted.size() && vec_sorted[i] != vec_sorted[i + 1]) {
      cnt++;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << mp[vec[i]] << ' ';
  }

  return 0;
}