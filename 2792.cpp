#include <bits/stdc++.h>
using namespace std;

long long n;
long long arr[300001];
int m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  long long l = 1;
  long long r = 1;

  for (int i = 0; i < m; i++) {
    cin >> arr[i];
    r = max(arr[i], r);
  }

  long long ret;
  while (l <= r) {
    long long mid = (l + r) / 2;

    long long num = 0;
    for (int i = 0; i < m; i++) {
      num += (arr[i] / mid);
      if (arr[i] % mid) {
        num++;
      }
    }

    if (num <= n) {
      r = mid - 1;
      ret = mid;
    } else if (num > n) {
      l = mid + 1;
    }
  }
  cout << ret;

  return 0;
}