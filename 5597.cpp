#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int arr[30] = {0};
  for (int i = 0; i < 28; i++) {
    int n;
    std::cin >> n;
    arr[n - 1] = 1;
  }

  for (int i = 0; i < 30; i++) {
    if (arr[i] == 0) {
      std::cout << i + 1 << '\n';
    }
  }

  return 0;
}