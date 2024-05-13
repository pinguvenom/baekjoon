#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vec;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vec.push_back(x);
  }

  sort(vec.begin(), vec.end());

  for (auto x : vec) {
    cout << x << '\n';
  }

  return 0;
}