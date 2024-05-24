#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  priority_queue<float> pq;
  for (int i = 0; i < n; i++) {
    float score;
    cin >> score;
    pq.push(score);

    if (pq.size() > 7) {
      pq.pop();
    }
  }

  vector<float> vec;
  while (pq.size()) {
    vec.push_back(pq.top());
    pq.pop();
  }
  reverse(vec.begin(), vec.end());
  cout << fixed;
  cout.precision(3);
  for (auto x : vec) {
    cout << x << '\n';
  }

  return 0;
}