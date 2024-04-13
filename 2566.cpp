#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int max = 0;
  pair<int, int> max_idx = {0, 0};

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int val;
      cin >> val;

      if (val > max) {
        max = val;
        max_idx = {i, j};
      }
    }
  }

  cout << max << '\n';
  cout << max_idx.first + 1 << ' ' << max_idx.second + 1;

  return 0;
}