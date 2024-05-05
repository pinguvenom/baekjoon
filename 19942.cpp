#include <bits/stdc++.h>
using namespace std;

int n, mp, mf, ms, mv;
int arr[15][5];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  cin >> mp >> mf >> ms >> mv;

  for (int i = 0; i < n; i++) {
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3] >> arr[i][4];
  }

  int min_price = INT_MAX;
  vector<int> _idx;
  bool b_meet_condition = false;
  for (int i = 0; i < (1 << n); i++) {
    int p_sum = 0, f_sum = 0, s_sum = 0, v_sum = 0, price_sum = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        p_sum += arr[j][0];
        f_sum += arr[j][1];
        s_sum += arr[j][2];
        v_sum += arr[j][3];
        price_sum += arr[j][4];
      }
    }
    if (p_sum >= mp && f_sum >= mf && s_sum >= ms && v_sum >= mv) {
      b_meet_condition = true;
      if (min_price > price_sum) {
        min_price = price_sum;
        _idx.clear();
        for (int j = 0; j < n; j++) {
          if (i & (1 << j)) {
            _idx.push_back(j + 1);
          }
        }
      } else if (min_price == price_sum) {
        vector<int> __idx;
        for (int j = 0; j < n; j++) {
          if (i & (1 << j)) {
            __idx.push_back(j + 1);
          }
        }
        if (__idx < _idx) {
          _idx = __idx;
        }
      }
    }
  }

  if (!b_meet_condition) {
    cout << -1;
  } else {
    cout << min_price << '\n';
    for (auto x : _idx) {
      cout << x << ' ';
    }
  }

  return 0;
}