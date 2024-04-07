#include <bits/stdc++.h>

int main() {
  int T;
  std::cin >> T;

  while (T--) {
    int R;
    std::string S;
    std::cin >> R >> S;

    for (auto c : S) {
      for (int i = 0; i < R; i++) {
        std::cout << c;
      }
    }
    std::cout << '\n';
  }

  return 0;
}