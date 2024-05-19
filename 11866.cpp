#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  vector<int> vec;
  for (int i = 1; i <= n; i++) {
    vec.push_back(i);
  }

  int idx = -1;
  cout << "<";
  while (vec.size() > 1) {
    idx += k;
    while (true) {
      if (idx >= vec.size()) {
        idx -= vec.size();
      } else {
        break;
      }
    }
    cout << vec[idx] << ", ";
    vec.erase(vec.begin() + idx);
    idx--;
  }

  cout << vec[0] << ">";

  return 0;
}