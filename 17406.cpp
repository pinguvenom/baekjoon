#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int src[51][51];
int tmp[51][51];
vector<int> _order;
vector<tuple<int, int, int>> _operation;

int g_min = INT_MAX;

int calc_val() {
  int _min = INT_MAX;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < m; j++) {
      sum += tmp[i][j];
    }

    if (sum < _min) {
      _min = sum;
    }
  }
  return _min;
}

void rotate(int r, int c, int s) {
  int l_tmp[51][51];
  memcpy(l_tmp, tmp, sizeof(tmp));

  for (int i = 1; i <= s; i++) {
    int y0 = r - i;
    int x0 = c - i;
    int y1 = r + i;
    int x1 = c + i;

    for (int i = x0; i < x1; i++) {
      l_tmp[y0][i + 1] = tmp[y0][i];
    }
    for (int i = y0; i < y1; i++) {
      l_tmp[i + 1][x1] = tmp[i][x1];
    }
    for (int i = x1; i > x0; i--) {
      l_tmp[y1][i - 1] = tmp[y1][i];
    }
    for (int i = y1; i > y0; i--) {
      l_tmp[i - 1][x0] = tmp[i][x0];
    }
  }
  memcpy(tmp, l_tmp, sizeof(l_tmp));
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> src[i][j];
    }
  }

  for (int i = 0; i < k; i++) {
    int r, c, s;
    cin >> r >> c >> s;
    r--;
    c--;
    _operation.push_back(make_tuple(r, c, s));
  }

  for (int i = 0; i < k; i++) {
    _order.push_back(i);
  }

  do {
    memcpy(tmp, src, sizeof(src));

    for (auto x : _order) {
      int r = get<0>(_operation[x]);
      int c = get<1>(_operation[x]);
      int s = get<2>(_operation[x]);
      rotate(r, c, s);
    }

    int val = calc_val();
    if (val < g_min) {
      g_min = val;
    }

  } while (std::next_permutation(_order.begin(), _order.end()));

  cout << g_min;
  return 0;
}