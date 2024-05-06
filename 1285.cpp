#include <bits/stdc++.h>
using namespace std;

int n;
int arr[20];
int _min = 20 * 20;
void search(int idx) {
  if (idx == n) {
    int sum = 0;
    for (int i = 1; i <= (1 << n - 1); i *= 2) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        if (i & arr[j]) {
          cnt++;
        }
      }
      sum += min({cnt, n - cnt});
    }
    _min = min({_min, sum});
    return;
  }

  search(idx + 1);
  arr[idx] = ~arr[idx];
  search(idx + 1);
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    int base = 1;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == 'T') {
        arr[i] |= base;
      }
      base *= 2;
    }
  }

  search(0);
  cout << _min;

  return 0;
}