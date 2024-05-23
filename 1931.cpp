#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> vec;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;
    vec.push_back({start, end});
  }

  sort(vec.begin(), vec.end());

  int val;
  int cnt = 0;
  while (vec.size()) {
    val = vec[vec.size() - 1].first;
    vec.pop_back();
    while (true) {
      if (vec.size() && vec[vec.size() - 1].second > val) {
        vec.pop_back();
      } else {
        break;
      }
    }
    cnt++;
  }

  cout << cnt;
  return 0;
}