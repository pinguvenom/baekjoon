#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  cin >> x;
  sort(vec.begin(), vec.end());

  int cnt = 0;
  int i1 = 0, i2 = n - 1;
  while (true) {
    if (i1 >= i2) {
      break;
    }
    int sum = vec[i1] + vec[i2];

    if (sum == x) {
      i1++;
      i2--;
      cnt++;
    } else if (sum > x) {
      i2--;
    } else if (sum < x) {
      i1++;
    }
  }

  cout << cnt;
  return 0;
}