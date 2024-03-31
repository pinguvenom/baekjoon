#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;

  for (int i = 0; i < T; i++) {
    int a, b;
    std::cin >> a >> b;
    std::cout << "Case #" << i + 1 << ": " << a + b << '\n';
  }

  return 0;
}