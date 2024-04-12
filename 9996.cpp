#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N;
  std::cin >> N;

  std::string pattern;
  std::cin >> pattern;

  auto pos = pattern.find("*");
  std::string prefix = pattern.substr(0, pos);
  std::string suffix = pattern.substr(pos + 1);

  while (N--) {
    std::string s;
    std::cin >> s;

    if (s.size() < (prefix.size() + suffix.size())) {
      std::cout << "NE\n";
    } else {
      if (s.substr(0, prefix.size()) == prefix &&
          s.substr(s.size() - suffix.size()) == suffix) {
        std::cout << "DA\n";
      } else {
      std:
        std::cout << "NE\n";
      }
    }
  }
  return 0;
}