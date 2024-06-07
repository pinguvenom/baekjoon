#include <bits/stdc++.h>
using namespace std;

int n, sum;

int _max = INT_MIN;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    sum += x;
    _max = max(_max, sum);
    if (sum < 0) {
      sum = 0;
    }
  }

  cout << _max;
  return 0;
}