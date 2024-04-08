#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::string s;
  std::getline(std::cin, s);

  bool is_alpha = false;
  int cnt = 0;
  for (auto c : s) {
    if (c != ' ' && is_alpha == false) {
      is_alpha = true;
      cnt++;
    } else if (c == ' ') {
      is_alpha = false;
    }
  }
  std::cout << cnt;
  return 0;
}