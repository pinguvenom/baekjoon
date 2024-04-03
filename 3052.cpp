#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int arr[42] = {0};
  for (int i = 0; i < 10; i++) {
    int n;
    std::cin >> n;
    arr[n % 42] = 1;
  }

  int cnt = 0;
  for (int i = 0; i < 42; i++) {
    if (arr[i] == 1) {
      cnt++;
    }
  }

  std::cout << cnt;
  return 0;
}