#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int max = INT_MIN;
  int max_idx = 0;
  for (int i = 0; i < 9; i++) {
    int n;
    std::cin >> n;
    if (n > max) {
      max = n;
      max_idx = i + 1;
    }
  }

  std::cout << max << '\n' << max_idx;

  return 0;
}