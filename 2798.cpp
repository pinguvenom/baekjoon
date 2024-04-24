#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int max = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      for (int k = 0; k < j; k++) {
        int sum = arr[i] + arr[j] + arr[k];
        if (sum <= m && sum > max) {
          max = sum;
        }
      }
    }
  }

  cout << max;
  return 0;
}