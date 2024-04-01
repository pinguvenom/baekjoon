#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N;
  std::cin >> N;

  int min = INT_MAX;
  int max = INT_MIN;
  for (int i = 0; i < N; i++) {
    int n;
    std::cin >> n;
    if (n > max) {
      max = n;
    }
    if (n < min) {
      min = n;
    }
  }
  std::cout << min << ' ' << max;
  return 0;
}