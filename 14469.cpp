#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<pair<int, int>> vec(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    vec[i] = {a, b};
  }
  sort(vec.begin(), vec.end());

  int end_time = 0;
  for (int i = 0; i < vec.size(); i++) {
    int arrival = vec[i].first;
    int duration = vec[i].second;

    if (arrival > end_time) {
      end_time = arrival + duration;
    } else {
      end_time += duration;
    }
  }
  cout << end_time;

  return 0;
}