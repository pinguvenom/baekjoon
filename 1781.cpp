#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<pair<int, int>> vec(n);
  for (int i = 0; i < n; i++) {
    int deadline, num_cup;
    cin >> deadline >> num_cup;
    vec[i] = {deadline, num_cup};
  }
  sort(vec.begin(), vec.end());

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; i++) {
    pq.push(vec[i].second);
    if (pq.size() > vec[i].first) {
      pq.pop();
    }
  }

  int sum = 0;
  while (pq.size()) {
    sum += pq.top();
    pq.pop();
  }

  cout << sum;
  return 0;
}