#include <bits/stdc++.h>
using namespace std;

int k;
vector<int> _input;
int idx;

void solve(int i, vector<vector<int>>& vec) {
  if (i == 0) {
    vec[0].push_back(_input[idx++]);
    return;
  }
  solve(i - 1, vec);
  vec[i].push_back(_input[idx++]);
  solve(i - 1, vec);

  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> k;
  for (int i = 0; i < (int)pow(2, k) - 1; i++) {
    int x;
    cin >> x;
    _input.push_back(x);
  }
  vector<vector<int>> vec(k);
  solve(k - 1, vec);

  for (int i = k - 1; i >= 0; i--) {
    for (int x : vec[i]) {
      cout << x << ' ';
    }
    cout << '\n';
  }

  return 0;
}