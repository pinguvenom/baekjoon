#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::string s;
  std::getline(std::cin, s);

  for (auto c : s) {
    int temp;
    if (c >= 'a' && c <= 'z') {
      temp = c + 13;
      if (temp > 'z') {
        temp -= 26;
      }
    } else if (c >= 'A' && c <= 'Z') {
      temp = c + 13;
      if (temp > 'Z') {
        temp -= 26;
      }
    } else {
      temp = c;
    }
    std::cout << (char)temp;
  }

  return 0;
}