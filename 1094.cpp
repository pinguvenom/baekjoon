#include <bits/stdc++.h>
using namespace std;
int x;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> x;
  bool arr[7];
  memset(arr, 0, sizeof(arr));
  int idx = 0;
  while (x) {
    arr[idx] = x % 2;
    x /= 2;
    idx++;
  }
  int cnt = 0;
  for (auto i : arr) {
    if (i) {
      cnt++;
    }
  }
  cout << cnt;

  return 0;
}