#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int arr[100] = {0};

  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }

  while (m--) {
    int i, j;
    std::cin >> i >> j;
    std::reverse(arr + i - 1, arr + j);
  }

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << ' ';
  }

  return 0;
}