#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  while (true) {
    std::string s, bufferflush;
    std::getline(std::cin, s);
    std::cout << s;
    if (std::cin.eof()) {
      break;
    } else {
      std::cout << '\n';
    }
  }

  return 0;
}