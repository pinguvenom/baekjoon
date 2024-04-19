#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  arr[1] = -1;
  for (int i = 2; i < 1002; i++) {
    if (arr[i] == -1) {
      continue;
    }
    arr[i] = 1;

    int mul = 2;
    while (true) {
      if (i * mul > 1002) {
        break;
      }
      arr[i * mul] = -1;
      mul++;
    }
  }

  int n;
  cin >> n;
  int cnt = 0;
  while (n--) {
    int x;
    cin >> x;

    if (arr[x] == 1) {
      cnt++;
    }
  }

  cout << cnt;

  return 0;
}