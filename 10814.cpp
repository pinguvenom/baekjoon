#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, string>> vec;

bool cmp(pair<int, string> a, pair<int, string> b) {
  if (a.first < b.first) {
    return true;
  } else if (a.first > b.first) {
    return false;
  } else {
    return false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int age;
    string name;
    cin >> age >> name;
    vec.push_back({age, name});
  }
  stable_sort(vec.begin(), vec.end(), cmp);

  for (auto x : vec) {
    cout << x.first << ' ' << x.second << '\n';
  }

  return 0;
}