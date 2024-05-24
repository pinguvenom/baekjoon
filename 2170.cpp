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
  int l = vec[0].first;
  int r = vec[0].second;

  int sum = 0;
  for (int i = 1; i < n; i++) {
    int l_new = vec[i].first;
    int r_new = vec[i].second;

    if (r < l_new) {
      sum += (r - l);
      l = l_new;
      r = r_new;
    } else if (r_new > r) {
      r = r_new;
    }
  }
  sum += (r - l);

  cout << sum;
  return 0;
}