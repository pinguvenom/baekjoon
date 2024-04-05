#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;

  while (T--) {
    std::string S;
    std::cin >> S;

    std::cout << *S.begin() << *(S.end() - 1) << '\n';
  }

  return 0;
}