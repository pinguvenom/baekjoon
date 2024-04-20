#include <bits/stdc++.h>
using namespace std;

int arr[10001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  arr[1] = 1;
  for (int i = 2; i < 10002; i++) {
    if (arr[i] == 0) {
      int j = 2;
      while (true) {
        if (i * j > 10001) {
          break;
        }
        arr[i * j] = 1;
        j++;
      }
    }
  }

  int m, n;
  cin >> m >> n;

  int sum = 0;
  int min = 0;
  for (int i = n; i >= m; i--) {
    if (arr[i] == 0) {
      sum += i;
      min = i;
    }
  }

  if (min == 0) {
    cout << "-1";
  } else {
    cout << sum << '\n';
    cout << min;
  }

  return 0;
}